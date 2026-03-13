#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Macros.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/loader/Mod.hpp>
#include <algorithm>
#include <exception>

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

	using enum sol::lib;
	m_luaState.open_libraries(base, string, table, math, utf8);

	$quartz_create_table(m_luaState, "hook_ids");
	$quartz_create_table(m_luaState, "cocos2d");

	m_luaState.set_function("modify", [this](int id, sol::function callback)
							{
								quartz::HookIDs hookID = static_cast<quartz::HookIDs>(id);

								if (!quartz::isValidHookID(hookID))
								{
									geode::log::warn("Invalid hook id: {}", id);
									return;
								}

								geode::log::debug("Adding hook with id {} at registry index {}", id, callback.registry_index());
								m_hooks[hookID].emplace_back(std::move(callback));
							});

	m_setup = true;
}

void LuaManager::cleanup()
{
	if (!m_setup)
	{
		return;
	}

	for (auto& [id, vec] : m_hooks)
	{
		vec.clear();
	}

	m_hooks.clear();
	m_luaState.collect_garbage();
	m_luaState = sol::state();

	m_setup = false;
}

void LuaManager::loadScripts()
{
	if (!m_setup)
	{
		return;
	}

	m_scripts.clear();

	try
	{
		for (const auto& entry : std::filesystem::directory_iterator(m_scriptsDir))
		{
			if (entry.path().extension() == ".lua")
			{
				m_scripts.push_back(entry.path());
				geode::log::debug("Added script \"{}\" to global scripts", entry.path().filename().string());
			}
		}
	}
	catch (const std::filesystem::filesystem_error& error)
	{
		geode::log::error("Failed to add scripts due to filesystem error | what: {}", error.what());
		return;
	}

	std::ranges::sort(m_scripts);

	for (const auto& path : m_scripts)
	{
		auto filename = path.filename().string();
		auto result = m_luaState.script_file(path.string());

		if (result.valid())
		{
			geode::log::debug("Global script \"{}\" running", filename);
		}
		else
		{
			sol::error err = result;
			geode::log::error("Global script \"{}\" invalid | what: {}", filename, err.what());
		}
	}
}
} // quartz