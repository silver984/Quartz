#include <quartz/LuaManager.hpp>
#include <quartz/BindingsManager.hpp>
#include <quartz/HookStorage.hpp>
#include <quartz/core/Timer.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/loader/Log.hpp>
#include <exception>
#include <utility>

namespace quartz {

LuaManager& LuaManager::get() {
	static LuaManager instance;
	return instance;
}

bool LuaManager::init() {
	if (m_isInitialized) {
		return true;
	}

	if (!createScriptsDir()) {
		return false;
	}

	BindingsManager::get().runQueue();
	m_isInitialized = true;
	return true;
}

bool LuaManager::isOpen() const {
	return m_isInitialized;
}

bool LuaManager::loadScripts() {
	if (!m_isInitialized) {
		return false;
	}

	tryOpenLibs();
	
	std::vector<std::filesystem::path> scripts = collectScripts();
	if (scripts.empty()) {
		return false;
	}

	runScripts(scripts);

	return true;
}

void LuaManager::cleanup() {
	if (!m_isInitialized) {
		return;
	}

	HookStorage::get().resetState();
	m_environments.clear();
	m_luaState.collect_garbage();
	m_luaState = sol::state();
	m_isLibsInitialized = false;
	m_isInitialized = false;
}

sol::state_view LuaManager::luaState() {
	return m_luaState;
}

std::vector<sol::environment>& LuaManager::environments() {
	return m_environments;
}

// private
void LuaManager::tryOpenLibs() {
	if (m_isLibsInitialized) {
		return;
	}

	using enum sol::lib;
	m_luaState.open_libraries(base, string, table, math, utf8);
	m_isLibsInitialized = true;
}

// private
bool LuaManager::createScriptsDir() {
	m_scriptsDir = geode::Mod::get()->getSettingValue<std::filesystem::path>("scripts-dir");

	if (!std::filesystem::exists(m_scriptsDir)) {
		try {
			std::filesystem::create_directories(m_scriptsDir);
		} catch (const std::filesystem::filesystem_error& e) {
			geode::log::error(
				"Failed to create missing scripts directory | path: \"{}\" | what: {}",
				e.path1().string(),
				e.what()
			);
			
			return false;
		}
	}

	return true;
}

// private
std::vector<std::filesystem::path> LuaManager::collectScripts() {
	geode::log::debug("Gathering scripts...");
	std::vector<std::filesystem::path> scripts;
	std::chrono::steady_clock::time_point timer;

	try {
		timer = startTimer();
		for (const auto& entry : std::filesystem::directory_iterator(m_scriptsDir)) {
			if (entry.path().extension() == ".lua") {
				scripts.emplace_back(entry.path());
			}
		}
	} catch (const std::filesystem::filesystem_error& error) {
		geode::log::error(
			"Failed to add scripts due to filesystem error | what: {}",
			error.what()
		);
		return {};
	}

	geode::log::debug("Took {}s", endTimer(timer));
	return scripts;
}

// private
void LuaManager::runScripts(std::vector<std::filesystem::path>& scripts) {
	geode::log::debug("Attempting to run {}...", (scripts.size() > 1) ? "scripts" : "script");
	m_environments.clear();

	auto& hookStorage = HookStorage::get();
	hookStorage.resetState();
	
	auto timer = startTimer();

	for (auto it = scripts.begin(); it != scripts.end();) {
		sol::environment env;
		sol::protected_function_result result;

		try {
			env = sol::environment(m_luaState, sol::create, m_luaState.globals());
			result = m_luaState.script_file((*it).string(), env, sol::load_mode::any);
		} catch (const std::exception& exception) {
			geode::log::error(
				"Script \"{}\" caused an exception | what: {}",
				(*it).filename().string(), exception.what()
			);
			it = scripts.erase(it);
			continue;
		}

		if (!result.valid()) {
			sol::error err = result;
			geode::log::error(
				"Script \"{}\" invalid | what: {}",
				(*it).filename().string(),
				err.what()
			);
			it = scripts.erase(it);
			continue;
		}

		m_environments.emplace_back(std::move(env));
		++it;
	}

	hookStorage.autoEnableGeodeHooks();

	geode::log::debug("Took {}s", endTimer(timer));
}

} // namespace quartz