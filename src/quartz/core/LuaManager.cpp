#include <quartz/core/LuaManager.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/ui/Notification.hpp>
#include <algorithm>
#include <exception>
#include <chrono>

namespace quartz
{
void LuaManager::setup()
{
	if (m_setup)
	{
		return;
	}

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

	{
		using enum sol::lib;
		m_luaState.open_libraries(base, string, table, math, utf8);
	}

	m_setup = true;
}

void LuaManager::cleanup()
{
	if (!m_setup)
	{
		return;
	}

	for (auto& callbacks : m_hookCallbacks)
	{
		callbacks.clear();
	}

	m_luaState.collect_garbage();
	m_luaState = sol::state();

	m_setup = false;
}

void LuaManager::runScripts()
{
	auto errorNotif = geode::Notification::create("Failed to run script/s", geode::NotificationIcon::Error);

	if (!m_setup)
	{
		if (errorNotif)
		{
			errorNotif->show();
		}

		return;
	}

	for (auto& callbacks : m_hookCallbacks)
	{
		callbacks.clear();
	}

	geode::log::debug("Attempting to add script/s...");

	try
	{
		auto start = std::chrono::high_resolution_clock::now();

		for (const auto& entry : std::filesystem::directory_iterator(m_scriptsDir))
		{
			if (entry.path().extension() == ".lua")
			{
				m_scriptsDict.push_back(entry.path());
				geode::log::debug("Added script \"{}\" | current total: {}", entry.path().filename().string(), m_scriptsDict.size());
			}
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		geode::log::debug("Took {}s", elapsed.count());
	}
	catch (const std::filesystem::filesystem_error& error)
	{
		geode::log::error("Failed to add scripts due to filesystem error | what: {}", error.what());
		
		m_scriptsDict.clear();
		
		if (errorNotif)
		{
			errorNotif->show();
		}

		return;
	}

	std::ranges::sort(m_scriptsDict);

	geode::log::debug("Attempting to run added script/s...");
	
	auto start = std::chrono::high_resolution_clock::now();

	for (auto it = m_scriptsDict.begin(); it != m_scriptsDict.end();)
	{
		sol::protected_function_result scriptResult;

		try
		{
			sol::table env = m_luaState.create_table();
			scriptResult = m_luaState.load_file((*it).string())(env);
		}
		catch (const std::exception& e)
		{
			geode::log::error("Script \"{}\" caused an exception | what: {}", (*it).filename().string(), e.what());
			it = m_scriptsDict.erase(it);
			continue;
		}

		if (!scriptResult.valid())
		{
			sol::error err = scriptResult;
			geode::log::error("Script \"{}\" invalid | what: {}", (*it).filename().string(), err.what());
			it = m_scriptsDict.erase(it);
			continue;
		}

		++it;
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	geode::log::debug("Took {}s", elapsed.count());
	
	geode::Notification::create(fmt::format("Successfully ran {} script/s", m_scriptsDict.size()), geode::NotificationIcon::Success)->show();
	
	m_scriptsDict.clear();
}
} // quartz