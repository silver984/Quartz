#include <quartz/core/LuaManager.hpp>
#include <Geode/Geode.hpp>

$on_mod(Loaded)
{
	auto& luaManager = quartz::LuaManager::get();
	luaManager.createScriptsDir();
	luaManager.openLibs();
	luaManager.createGlobals();
}

$on_game(Loaded)
{
	quartz::LuaManager::get().loadScripts();
}

$on_game(Exiting)
{
	quartz::LuaManager::get().cleanup();
}