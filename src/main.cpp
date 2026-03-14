#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/RefTypes.hpp>
#include <quartz/core/SnakeCase.hpp>
#include <string>

#define $quartz_define_enum_val(PREFIX, X) \
    (std::string(#PREFIX "_") + quartz::camelToSnake(#X)), quartz::HookIDs::PREFIX##_##X

#define $quartz_bind_ref_type(BASE, TYPE)\
	BASE.new_usertype<TYPE##_ref>(#TYPE "_ref", sol::no_constructor, "value", sol::property(&TYPE##_ref::get, &TYPE##_ref::set))

// just for distinction between quartz and geode
#define $geode_on_mod(X) $on_mod(X)
#define $geode_on_game(X) $on_game(X)

$geode_on_mod(Loaded)
{
	auto& luaManager = quartz::LuaManager::get();

	luaManager.setup();

	auto& luaState = luaManager.luaState();
	sol::table quartz = luaState.create_table(); // global quartz for lua
	luaState["quartz"] = quartz;

	{
		using namespace quartz;
		$quartz_bind_ref_type(quartz, int);
		$quartz_bind_ref_type(quartz, float);
		$quartz_bind_ref_type(quartz, double);
		$quartz_bind_ref_type(quartz, bool);
	}

	quartz.new_enum("HookIDs",
					$quartz_define_enum_val(PlayerObject, init),
					$quartz_define_enum_val(PlayerObject, update));	
	
	quartz.set_function("add_hook_callback",
						[&luaManager](quartz::HookIDs id, sol::protected_function&& callback)
						{
							auto& hookCallbacks = luaManager.getHookCallbacks(id);
							hookCallbacks.emplace_back(std::move(callback));
							geode::log::debug("Successfully added callback for hook #{} | registry_index: {} | current total: {}",
											  static_cast<int>(id), hookCallbacks.back().registry_index(), hookCallbacks.size());
						});
}

$geode_on_game(Loaded)
{
	quartz::LuaManager::get().runScripts();
}

$geode_on_game(Exiting)
{
	quartz::LuaManager::get().cleanup();
}