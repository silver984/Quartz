#include <Geode/loader/GameEvent.hpp>
#include <Geode/loader/ModEvent.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/loader/Log.hpp>
#include <quartz/LuaManager.hpp>

$on_mod(Loaded) {
	auto& luaManager = quartz::LuaManager::get();

	if (!luaManager.init()) {
		geode::log::error("Failed to initialize Lua");
		return;
	}

	static_cast<void>(luaManager.loadScripts());
}

$on_game(Exiting) {
	quartz::LuaManager::get().cleanup();
}