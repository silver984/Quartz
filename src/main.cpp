#include <Geode/loader/GameEvent.hpp>
#include <Geode/loader/ModEvent.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/modify/Modify.hpp>
#include <quartz/LuaManager.hpp>
#include <quartz/HookStorage.hpp>

$on_mod(Loaded) {
	quartz::HookStorage::get().setGeodeHooksPriority(geode::Priority::Last);

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