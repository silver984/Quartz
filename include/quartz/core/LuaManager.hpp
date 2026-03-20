#pragma once

#include <sol/sol.hpp>
#include <filesystem>
#include <vector>
#include <chrono>
#include <cstdint>
#include <string>

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

		void createScriptsDir();
		void openLibs();
		void createGlobals();
		void cleanup();
		void loadScripts();
	
		inline sol::state& luaState()
		{
			return m_luaState;
		}

	private:
		void endTimer(const std::chrono::steady_clock::time_point& start);
		std::vector<std::filesystem::path> collectScripts();
		void runScripts(std::vector<std::filesystem::path>& scripts);
	
		inline std::chrono::steady_clock::time_point startTimer()
		{
			return std::chrono::high_resolution_clock::now();
		}

		bool m_openedLibs = false;
		sol::state m_luaState;
		std::filesystem::path m_scriptsDir;
		std::vector<sol::environment> m_environments;
	};
}