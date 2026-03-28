#pragma once

#include <sol/sol.hpp>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <cstdint>
#include <string>
#include <functional>

namespace quartz
{

class LuaManager
{
private:
	LuaManager() = default;
	~LuaManager() = default;

public:
	static inline LuaManager& get()
	{
		static LuaManager instance;
		return instance;
	}

	LuaManager(const LuaManager&) = delete;
	LuaManager& operator=(const LuaManager&) = delete;
	LuaManager(LuaManager&&) = delete;
	LuaManager& operator=(LuaManager&&) = delete;

	bool init();
	void cleanup();
	bool loadScripts();

	inline sol::state& luaState()
	{
		return m_luaState;
	}

	inline std::vector<sol::environment>& environments()
	{
		return m_environments;
	}

	inline std::unordered_map<std::string, std::vector<sol::protected_function>>& luaHooks()
	{
		return m_luaHooks;
	}

	inline void addValidHook(const std::string& hookName)
	{
		m_validHooks.insert(hookName);
	}

	constexpr bool isOpen() const
	{
		return m_isInit;
	}

private:
	bool initLibs();
	bool createScriptsDir();
	void createGlobals();
	void endTimer(const std::chrono::steady_clock::time_point& start);
	std::vector<std::filesystem::path> collectScripts();
	void runScripts(std::vector<std::filesystem::path>& scripts);

	inline std::chrono::steady_clock::time_point startTimer()
	{
		return std::chrono::high_resolution_clock::now();
	}

	bool m_isInit = false;
	bool m_initLibs = false;
	bool m_allowNotifs = false;
	sol::state m_luaState;
	std::filesystem::path m_scriptsDir;
	std::vector<sol::environment> m_environments;
	std::unordered_map<std::string, std::vector<sol::protected_function>> m_luaHooks;
	std::unordered_set<std::string> m_validHooks;
};

} // quartz