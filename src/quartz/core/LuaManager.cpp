#include <quartz/core/LuaManager.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/loader/Mod.hpp>
#include <algorithm>
#include <exception>

namespace quartz
{

void LuaManager::createScriptsDir()
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
		}
	}
}

void LuaManager::openLibs()
{
	if (m_openedLibs)
	{
		return;
	}

	using enum sol::lib;
	m_luaState.open_libraries(base, string, table, math, utf8);

	m_openedLibs = true;
}

void LuaManager::createGlobals()
{
	if (!m_openedLibs)
	{
		return;
	}

	m_luaState["quartz"] = m_luaState.create_table();
	m_luaState["gd"] = m_luaState.create_table();
	m_luaState["cocos2d"] = m_luaState.create_table();

	sol::table quartz = m_luaState["quartz"];
	quartz.set_function(
		"hook",
		[this](const std::string& name, sol::protected_function&& callback)
		{
			m_hooks[name].emplace_back(std::move(callback));
		}
	);
}

void LuaManager::cleanup()
{
	if (!m_openedLibs)
	{
		return;
	}

	m_environments.clear();

	for (auto& hook : m_hooks)
	{
		hook.second.clear();
	}

	m_hooks.clear();

	m_luaState.collect_garbage();
	m_luaState = sol::state();

	m_openedLibs = false;
}

void LuaManager::loadScripts()
{
	if (!m_openedLibs)
	{
		return;
	}

	std::vector<std::filesystem::path> scripts = collectScripts();
	runScripts(scripts);
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

	std::ranges::sort(scripts);

	return scripts;
}

// private
void LuaManager::runScripts(std::vector<std::filesystem::path>& scripts)
{
	if (scripts.empty())
	{
		return;
	}

	geode::log::debug("Attempting to run {}...",
					  (scripts.size() > 1) ? "scripts" : "script");

	m_environments.clear();

	for (auto& hook : m_hooks)
	{
		hook.second.clear();
	}

	m_hooks.clear();

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