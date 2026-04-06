#pragma once
#include <sol/sol.hpp>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>

namespace quartz {

using LuaHooks = std::unordered_map<std::string, std::vector<sol::protected_function>>;

class LuaManager {
public:
	LuaManager(const LuaManager&) = delete;
	LuaManager& operator=(const LuaManager&) = delete;
	LuaManager(LuaManager&&) = delete;
	LuaManager& operator=(LuaManager&&) = delete;
	
	/// @brief Get instance of LuaManager
	/// @return An instance of LuaManager
	static LuaManager& get();

	/// @brief Setup Lua
	/// 
	/// Internally creates a new scripts folder, specified by the mod setting: "scripts-dir"
	/// 
	/// Also runs Lua bindings, so make sure to add bindings before calling this
	/// 
	/// @return Boolean for state of succession
	bool init();

	/// @return Whether Lua is open/setup
	bool isOpen() const;
	
	/// @brief Load the scripts
	/// @return Boolean for state of succession
	bool loadScripts();
	
	/// @brief Add a valid hook by its Lua name
	/// 
	/// This internally adds onto the list of hookable functions
	/// 
	/// @param hookName The valid hook's name
	void addValidHook(std::string const& hookName);
	
	/// @brief Add Lua binding to be executed before unit bindings
	/// @param exec Function to execute
	void addInitBinding(std::function<void()>&& exec);
	
	/// @brief Add Lua binding to be executed after initialized bindings
	/// @param exec Function to execute
	void addUnitBinding(std::function<void()>&& exec);
	
	/// @brief Clean up Lua
	void cleanup();
	
	/// @return Global Lua state
	sol::state& luaState();
	
	/// @return All running Lua environments
	std::vector<sol::environment>& environments();
	
	/// @return All Lua hooks
	LuaHooks& luaHooks();

private:
	LuaManager();
	~LuaManager();
	class Impl;
	std::unique_ptr<Impl> m_impl;	
};

} // namespace quartz