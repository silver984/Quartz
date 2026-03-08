#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>

// main.cpp is guaranteed to execute first
// therefore it should be safe to start up the mod here

$on_mod(Loaded) // once THIS mod is loaded
{
	QUARTZ_LUAMANAGER.setup();
}

$on_game(ModsLoaded) // once ALL mods are loaded
{
	QUARTZ_LUAMANAGER.loadScripts();
}

$on_game(Exiting)
{
	QUARTZ_LUAMANAGER.cleanup();
}