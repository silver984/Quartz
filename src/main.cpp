#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Macros.hpp>

ON_QUARTZ_LOADED
{
	auto& luaManager = quartz::LuaManager::get();
	luaManager.createScriptsDir();
	luaManager.openLibs();
	luaManager.createGlobals();
	luaManager.loadScripts();
}

ON_GD_EXITING
{
	quartz::LuaManager::get().cleanup();
}