#pragma once

#include <quartz/core/HookIDs.hpp>
#include <sol/sol.hpp>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include <string>

namespace quartz
{
class LuaManager
{
private:
	LuaManager() = default;
	~LuaManager() = default;

public:
	static LuaManager& get()
	{
		static LuaManager instance;
		return instance;
	}

	LuaManager(const LuaManager&) = delete;
	LuaManager& operator=(const LuaManager&) = delete;
	LuaManager(LuaManager&&) = delete;
	LuaManager& operator=(LuaManager&&) = delete;

	void setup();
	void cleanup();
	void loadScripts();
	// TODO: reloading

	inline std::unordered_map<quartz::HookIDs, std::vector<sol::function>>& hooks()
	{
		return m_hooks;
	}

	inline sol::state& luaState()
	{
		return m_luaState;
	}

private:
	bool m_setup = false;
	sol::state m_luaState;
	std::filesystem::path m_scriptsDir;
	std::vector<std::filesystem::path> m_scripts;
	std::unordered_map<quartz::HookIDs, std::vector<sol::function>> m_hooks;
};
} // quartz

#ifndef QUARTZ_LUAMANAGER
#define QUARTZ_LUAMANAGER quartz::LuaManager::get()
#endif