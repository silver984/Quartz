#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/RefTypes.hpp>
#include <quartz/core/CamelToSnake.hpp>
#include <string>

#define $quartz_bind_ref_type(BASE, TYPE)\
	BASE.new_usertype<quartz::TYPE##_ref>(#TYPE "_ref", sol::no_constructor, "value", sol::property(&quartz::TYPE##_ref::get, &quartz::TYPE##_ref::set))

// just for distinction between quartz and geode
#define $geode_on_mod(X) $on_mod(X)
#define $geode_on_game(X) $on_game(X)

$geode_on_mod(Loaded)
{
	auto& luaManager = quartz::LuaManager::get();

	luaManager.setup();

	auto& luaState = luaManager.luaState();
	sol::table quartz = luaState.create_table();
	sol::table hookIDs = luaState.create_table();
	luaState["quartz"] = quartz;
	luaState["quartz"]["HookIDs"] = hookIDs;

	quartz.set_function("add_hook_callback",
						[&luaManager](quartz::HookIDs id, sol::protected_function&& callback)
						{
							auto& hookCallbacks = luaManager.getHookCallbacks(id);
							hookCallbacks.emplace_back(std::move(callback));
							geode::log::debug("Successfully added callback for hook #{} | registry_index: {} | current total: {}",
											  static_cast<int>(id), hookCallbacks.back().registry_index(), hookCallbacks.size());
						});

	$quartz_bind_ref_type(quartz, int);
	$quartz_bind_ref_type(quartz, float);
	$quartz_bind_ref_type(quartz, double);
	$quartz_bind_ref_type(quartz, bool);	
}

$geode_on_game(Loaded)
{
	quartz::LuaManager::get().runScripts();
}

$geode_on_game(Exiting)
{
	quartz::LuaManager::get().cleanup();
}