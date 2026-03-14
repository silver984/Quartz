#pragma once

#include <quartz/core/HookIDs.hpp>
#include <sol/sol.hpp>
#include <filesystem>
#include <vector>
#include <array>
#include <cstdint>

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
	void runScripts();
	// TODO: reloading

	inline std::vector<sol::function>& getHookCallbacks(HookIDs id)
	{
		return m_hookCallbacks[static_cast<size_t>(id)];
	}

	inline sol::state& luaState()
	{
		return m_luaState;
	}

private:
	bool m_setup = false;
	sol::state m_luaState;
	std::filesystem::path m_scriptsDir;
	std::vector<std::filesystem::path> m_scriptsDict;
	std::array<std::vector<sol::function>, quartz::HookIDs::_COUNT> m_hookCallbacks;
};
} // quartz