#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Timer.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/loader/Log.hpp>
#include <fmt/args.h>
#include <filesystem>
#include <array>
#include <unordered_set>
#include <functional>
#include <cstdint>
#include <algorithm>
#include <exception>
#include <utility>
#include <regex>

namespace quartz {

class LuaManager::Impl {
public:
	bool init() {
		if (isInit) {
			return true;
		}

		if (!createScriptsDir()) {
			return false;
		}

		createGlobals();
		runQueuedBindings();
		isInit = true;
		return true;
	}

	void cleanup() {
		if (!isInit) {
			return;
		}

		for (auto& [name, hooks] : luaHooks) {
			hooks.clear();
		}

		luaHooks.clear();
		validHooks.clear();
		environments.clear();
		luaState.collect_garbage();
		luaState = sol::state();
		isLibsInit = false;
		isInit = false;
	}

	bool loadScripts() {
		if (!isInit || !initLibs()) {
			return false;
		}

		std::vector<std::filesystem::path> scripts = collectScripts();

		if (scripts.empty()) {
			return false;
		}

		runScripts(scripts);

		return true;
	}

	bool initLibs() {
		if (isLibsInit) {
			return true;
		}

		using enum sol::lib;
		luaState.open_libraries(base, string, table, math, utf8);
		isLibsInit = true;
		return true;
	}

	bool createScriptsDir() {
		scriptsDir = geode::Mod::get()->getSettingValue<std::filesystem::path>("scripts-dir");

		if (!std::filesystem::exists(scriptsDir)) {
			try {
				std::filesystem::create_directories(scriptsDir);
				geode::log::debug("Created missing scripts directory | location: \"{}\"", scriptsDir);
			} catch (const std::filesystem::filesystem_error& e) {
				geode::log::error(
					"Failed to create missing scripts directory | path: \"{}\" | what: {}",
					e.path1().string(),
					e.what());
				return false;
			}
		}

		return true;
	}

	void createGlobals() {
		sol::table quartz = luaState["quartz"].get_or_create<sol::table>();
		quartz.set_function(
			"hook", [this](const std::string& name, sol::protected_function&& callback) {
				if (!validHooks.contains(name)) {
					geode::log::warn("\"{}\" is not a hookable function", name);
					return;
				}

				luaHooks[name].push_back(std::move(callback));
			}
		);

		sol::table fmt = luaState["fmt"].get_or_create<sol::table>();
		fmt.set_function(
			"format", [](const std::string& fmtStr, sol::variadic_args va) {
				fmt::dynamic_format_arg_store<fmt::format_context> store;

				for (auto v : va) {

#define CHECK_ARG(TYPE)					\
	if (v.is<TYPE>()) {					\
		store.push_back(v.get<TYPE>());	\
		continue;						\
	}

					CHECK_ARG(std::string);
					CHECK_ARG(char const*);
					CHECK_ARG(int);
					CHECK_ARG(float);
					CHECK_ARG(double);
					CHECK_ARG(bool);

#undef CHECK_ARG

					store.push_back("<unsupported>");
				}

				return fmt::vformat(fmtStr, store);
			}
		);

		sol::table geode = luaState["geode"].get_or_create<sol::table>();
		sol::table log = geode["log"].get_or_create<sol::table>();

#define CREATE_LUA_LOG_FN(LEVEL)															\
	log.set_function(																		\
		#LEVEL,																				\
		[this](const std::string& fmtStr, sol::variadic_args va) {							\
			sol::protected_function formatFn = luaState["fmt"]["format"];					\
			if (!formatFn.valid()) {														\
				geode::log::error("Lua's reference `for fmt.format()` is/became invalid");	\
				return;																		\
			}																				\
			sol::protected_function_result formatted = formatFn(fmtStr, va);				\
			if (!formatted.valid()) {														\
				sol::error err = formatted;													\
				geode::log::error("Lua caught a formatting error | what: {}", err.what());	\
				return;																		\
			}																				\
			std::string msg = formatted;													\
			geode::log::LEVEL("{}", msg);													\
		}																					\
	)

		CREATE_LUA_LOG_FN(debug);
		CREATE_LUA_LOG_FN(error);
		CREATE_LUA_LOG_FN(info);
		CREATE_LUA_LOG_FN(trace);
		CREATE_LUA_LOG_FN(warn);

#undef CREATE_LUA_LOG_FN
	}

	void runQueuedBindings() {
		geode::log::debug("Running bindings...");
		auto timer = startTimer();

		// initializaiton of bindings run first before units
		for (const auto& exec : initBindings) {
			exec();
		}

		for (const auto& exec : unitBindings) {
			exec();
		}

		initBindings.clear();
		unitBindings.clear();
		geode::log::debug("Took {}s", endTimer(timer));
	}

	std::vector<std::filesystem::path> collectScripts() {
		geode::log::debug("Attempting to gather scripts...");
		std::vector<std::filesystem::path> scripts;

		try {
			auto timer = startTimer();

			for (const auto& entry : std::filesystem::directory_iterator(scriptsDir)) {
				if (entry.path().extension() == ".lua") {
					scripts.push_back(entry.path());
					geode::log::debug("Added script \"{}\" | current total: {}",
						entry.path().filename().string(),
						scripts.size());
				}
			}

			geode::log::debug("Took {}s", endTimer(timer));
		} catch (const std::filesystem::filesystem_error& error) {
			geode::log::error("Failed to add scripts due to filesystem error | what: {}", error.what());
			return {};
		}

		return scripts;
	}

	void runScripts(std::vector<std::filesystem::path>& scripts) {
		geode::log::debug("Attempting to run {}...",
			(scripts.size() > 1)
			? "scripts"
			: "script");

		environments.clear();

		for (auto& hook : luaHooks) {
			hook.second.clear();
		}

		luaHooks.clear();

		auto timer = startTimer();

		for (auto it = scripts.begin(); it != scripts.end();) {
			sol::environment env;
			sol::protected_function_result result;

			try {
				env = sol::environment(luaState, sol::create, luaState.globals());
				result = luaState.script_file((*it).string(), env, sol::load_mode::any);
			} catch (const std::exception& exception) {
				geode::log::error("Script \"{}\" caused an exception | what: {}",
					(*it).filename().string(), exception.what());
				it = scripts.erase(it);
				continue;
			}

			if (!result.valid()) {
				sol::error err = result;
				geode::log::error("Script \"{}\" invalid | what: {}", (*it).filename().string(), err.what());
				it = scripts.erase(it);
				continue;
			}

			environments.emplace_back(std::move(env));
			++it;
		}

		geode::log::debug("Took {}s", endTimer(timer));
	}

	bool isInit = false;
	bool isLibsInit = false;
	bool allowNotifs = false;
	sol::state luaState;
	std::filesystem::path scriptsDir;
	std::vector<sol::environment> environments;
	LuaHooks luaHooks;
	std::unordered_set<std::string> validHooks;
	std::vector<std::function<void()>> initBindings;
	std::vector<std::function<void()>> unitBindings;
};

LuaManager::LuaManager() : m_impl(std::make_unique<Impl>()) {}
LuaManager::~LuaManager() = default;

LuaManager& LuaManager::get() {
	static LuaManager instance;
	return instance;
}

bool LuaManager::init() {
	return m_impl->init();
}

bool LuaManager::isOpen() const {
	return m_impl->isInit;
}

bool LuaManager::loadScripts() {
	return m_impl->loadScripts();
}

void LuaManager::addValidHook(std::string const& hookName) {
	m_impl->validHooks.insert(hookName);
}

void LuaManager::addInitBinding(std::function<void()> && exec) {
	m_impl->initBindings.push_back(std::move(exec));
}

void LuaManager::addUnitBinding(std::function<void()>&& exec) {
	m_impl->unitBindings.push_back(std::move(exec));
}

void LuaManager::cleanup() {
	m_impl->cleanup();
}

sol::state& LuaManager::luaState() {
	return m_impl->luaState;
}

std::vector<sol::environment>& LuaManager::environments() {
	return m_impl->environments;
}

LuaHooks& LuaManager::luaHooks() {
	return m_impl->luaHooks;
}

} // namespace quartz