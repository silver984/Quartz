#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/RefTypes.hpp>

using namespace quartz;

#define $quartz_bind_ref_type(STATE, TYPE)\
	STATE.new_usertype<TYPE##_ref>(#TYPE "_ref", sol::no_constructor, "val", sol::property(&TYPE##_ref::get, &TYPE##_ref::set))

$on_mod(Loaded)
{
	$quartz_LuaManager.setup();

	auto& luaState = $quartz_LuaManager.luaState();
	$quartz_bind_ref_type(luaState, int);
	$quartz_bind_ref_type(luaState, float);
	$quartz_bind_ref_type(luaState, double);
	$quartz_bind_ref_type(luaState, bool);
}

$on_game(ModsLoaded)
{
	$quartz_LuaManager.loadScripts();
}

$on_game(Exiting)
{
	$quartz_LuaManager.cleanup();
}