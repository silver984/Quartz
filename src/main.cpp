#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Macros.hpp>
#include <Geode/loader/Log.hpp>

// this C++ file gets executed first
// so we initialize stuff here

ON_QUARTZ_LOADED
{
	auto& luaManager = quartz::LuaManager::get();
	if (!luaManager.init())
	{
		geode::log::error("Failed to initialize LuaManager");
		return;
	}
}

ON_GD_EXITING
{
	quartz::LuaManager::get().cleanup();
}