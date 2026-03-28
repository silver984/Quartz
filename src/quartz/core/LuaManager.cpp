#include <quartz/core/LuaManager.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/loader/Mod.hpp>
#include <algorithm>
#include <exception>
#include <fmt/args.h>

namespace quartz
{

bool LuaManager::init()
{
	if (m_isInit)
	{
		return true;
	}

	if (!createScriptsDir())
	{
		return false;
	}

	createGlobals();

	m_isInit = true;
	return true;
}

void LuaManager::cleanup()
{
	if (!m_isInit)
	{
		return;
	}

	m_environments.clear();

	for (auto& hook : m_luaHooks)
	{
		hook.second.clear();
	}

	m_luaHooks.clear();
	m_validHooks.clear();

	m_luaState.collect_garbage();
	m_luaState = sol::state();

	m_initLibs = false;
	m_isInit = false;
}

bool LuaManager::loadScripts()
{
	if (!m_isInit || !initLibs())
	{
		return false;
	}

	std::vector<std::filesystem::path> scripts = collectScripts();

	if (scripts.empty())
	{
		return false;
	}

	runScripts(scripts);
	return true;
}

// private
bool LuaManager::initLibs()
{
	if (m_initLibs)
	{
		return true;
	}

	using enum sol::lib;
	m_luaState.open_libraries(base, string, table, math, utf8);

	m_initLibs = true;
	return true;
}

// private
bool LuaManager::createScriptsDir()
{
	m_scriptsDir = geode::Mod::get()->getSettingValue<std::filesystem::path>("scripts-dir");

	if (!std::filesystem::exists(m_scriptsDir))
	{
		try
		{
			std::filesystem::create_directories(m_scriptsDir);
			geode::log::debug("Created missing scripts directory | location: \"{}\"", m_scriptsDir);
		}
		catch (const std::exception& e)
		{
			geode::log::error("Failed to create missing scripts directory | what: {}", e.what());
			return false;
		}
	}

	return true;
}

// private
void LuaManager::createGlobals()
{
	m_luaState["quartz"] = m_luaState.create_table();
	m_luaState["geode"] = m_luaState.create_table();
	m_luaState["fmt"] = m_luaState.create_table();
	m_luaState["cocos2d"] = m_luaState.create_table();
	m_luaState["geode"]["log"] = m_luaState.create_table();

	sol::table quartz = m_luaState["quartz"];
	quartz.set_function(
		"hook", [this](const std::string& name, sol::protected_function&& callback)
		{
			if (!m_validHooks.contains(name))
			{
				geode::log::warn("A lua script attempted to insert an invalid hook: {}", name);
				return;
			}

			m_luaHooks[name].push_back(std::move(callback));
		}
	);

	sol::table fmt = m_luaState["fmt"];
	fmt.set_function(
		"format", [](const std::string& fmtStr, sol::variadic_args va)
		{
			fmt::dynamic_format_arg_store<fmt::format_context> store;

			for (auto v : va)
			{

#define CHECK_ARG(TYPE)					\
	if (v.is<TYPE>())					\
	{									\
		store.push_back(v.get<TYPE>());	\
		continue;						\
	}

				CHECK_ARG(std::string);
				CHECK_ARG(const char*);
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

	sol::table log = m_luaState["geode"]["log"];

#define CREATE_LUA_LOG_FN(LEVEL)															\
	log.set_function(																		\
		#LEVEL, [this](const std::string& fmtStr, sol::variadic_args va)					\
		{																					\
			sol::protected_function formatFn = m_luaState["fmt"]["format"];					\
			if (!formatFn.valid())															\
			{																				\
				geode::log::error("Lua's reference for fmt.format() is/became invalid");	\
				return;																		\
			}																				\
			sol::protected_function_result formatted = formatFn(fmtStr, va);				\
			if (!formatted.valid())															\
			{																				\
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

// private
void LuaManager::endTimer(const std::chrono::steady_clock::time_point& start)
{
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	geode::log::debug("Took {}s", elapsed.count());
}

// private
std::vector<std::filesystem::path> LuaManager::collectScripts()
{
	geode::log::debug("Attempting to gather scripts...");

	std::vector<std::filesystem::path> scripts;

	try
	{
		auto start = startTimer();

		for (const auto& entry : std::filesystem::directory_iterator(m_scriptsDir))
		{
			if (entry.path().extension() == ".lua")
			{
				scripts.push_back(entry.path());
				geode::log::debug("Added script \"{}\" | current total: {}",
								  entry.path().filename().string(), scripts.size());
			}
		}

		endTimer(start);
	}
	catch (const std::filesystem::filesystem_error& error)
	{
		geode::log::error("Failed to add scripts due to filesystem error | what: {}",
						  error.what());

		return {};
	}

	return scripts;
}

// private
void LuaManager::runScripts(std::vector<std::filesystem::path>& scripts)
{
	geode::log::debug("Attempting to run {}...",
					  (scripts.size() > 1) ? "scripts" : "script");

	m_environments.clear();

	for (auto& hook : m_luaHooks)
	{
		hook.second.clear();
	}

	m_luaHooks.clear();

	auto start = startTimer();

	for (auto it = scripts.begin(); it != scripts.end();)
	{
		sol::environment env;
		sol::protected_function_result result;

		try
		{
			env = sol::environment(m_luaState, sol::create, m_luaState.globals());
			result = m_luaState.script_file((*it).string(), env, sol::load_mode::any);
		}
		catch (const std::exception& exception)
		{
			geode::log::error("Script \"{}\" caused an exception | what: {}",
							  (*it).filename().string(), exception.what());

			it = scripts.erase(it);

			continue;
		}

		if (!result.valid())
		{
			sol::error err = result;

			geode::log::error("Script \"{}\" invalid | what: {}",
							  (*it).filename().string(), err.what());

			it = scripts.erase(it);

			continue;
		}

		m_environments.emplace_back(std::move(env));

		++it;
	}

	endTimer(start);
}

} // quartz