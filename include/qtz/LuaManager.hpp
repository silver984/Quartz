#pragma once
#include <sol/sol.hpp>
#include <vector>
#include <filesystem>

namespace qtz {

class LuaManager final {
public:
	LuaManager(const LuaManager&) = delete;
	LuaManager(LuaManager&&) = delete;
	LuaManager& operator=(const LuaManager&) = delete;
	LuaManager& operator=(LuaManager&&) = delete;

	[[nodiscard]] static LuaManager& get();
	bool init();
	[[nodiscard]] bool isOpen() const;
	bool loadScripts();
	void cleanup();
	[[nodiscard]] sol::state_view luaState();
	[[nodiscard]] std::vector<sol::environment>& environments();

private:
	LuaManager() = default;
	~LuaManager() = default;
	
	void tryOpenLibs();
	bool createScriptsDir();
	std::vector<std::filesystem::path> collectScripts();
	void runScripts(std::vector<std::filesystem::path>& scripts);

	bool m_isInitialized = false;
	bool m_isLibsInitialized = false;
	bool m_allowNotifs = false;
	sol::state m_luaState;
	std::filesystem::path m_scriptsDir;
	std::vector<sol::environment> m_environments;
};

} // namespace qtz