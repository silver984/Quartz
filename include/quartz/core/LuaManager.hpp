#pragma once

#include <quartz/core/HookIDs.hpp>
#include <sol/sol.hpp>
#include <filesystem>
#include <vector>
#include <array>
#include <cstdint>
#include <chrono>

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

	void createScriptsDir();
	void openLibs();
	void createGlobals();
	void cleanup();
	void loadScripts();

	inline std::vector<sol::function>& getHookCallbacks(quartz::HookIDs id)
	{
		return m_hookCallbacks[static_cast<size_t>(id)];
	}

	inline sol::state& luaState()
	{
		return m_luaState;
	}

private:
	inline std::chrono::steady_clock::time_point startTimer()
	{
		return std::chrono::high_resolution_clock::now();
	}

	void endTimer(const std::chrono::steady_clock::time_point& start);

	bool m_openedLibs = false;
	bool m_scriptsLoadedOnce = false;
	sol::state m_luaState;
	std::filesystem::path m_scriptsDir;
	std::vector<std::filesystem::path> m_scriptDict;
	std::array<std::vector<sol::function>, static_cast<size_t>(quartz::HookIDs::COUNT)> m_hookCallbacks;
};

} // quartz