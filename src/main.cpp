#include <Geode/loader/GameEvent.hpp>
#include <Geode/loader/ModEvent.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/modify/Modify.hpp>
#include <qtz/LuaManager.hpp>
#include <qtz/HookStorage.hpp>

$on_mod(Loaded) {
	qtz::HookStorage::get().setGeodeHooksPriority(geode::Priority::Last);

	auto& luaManager = qtz::LuaManager::get();

	if (!luaManager.init()) {
		geode::log::error("Failed to initialize Lua");
		return;
	}

	static_cast<void>(luaManager.loadScripts());
}

$on_game(Exiting) {
	qtz::LuaManager::get().cleanup();
}