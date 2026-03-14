#include <quartz/bindings/PlayerObject.hpp>
#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Macros.hpp>
#include <quartz/core/CamelToSnake.hpp>
#include <quartz/core/RefTypes.hpp>
#include <sol/sol.hpp>
#include <exception>

namespace quartz
{
void lua_PlayerObject::onModify(auto& self)
{
    $quartz_enable_hook_priority(PlayerObject, init, self);
    $quartz_enable_hook_priority(PlayerObject, update, self);
}

bool lua_PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    $quartz_run_hook_callbacks(PlayerObject, init, $quartz_check_type_return(bool),
                               (static_cast<PlayerObject*>(this), quartz::int_ref(&player), quartz::int_ref(&ship), gameLayer, layer, quartz::bool_ref(&playLayer)),
                               player, ship, gameLayer, layer, playLayer);
}

bool lua_PlayerObject::initDummy(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    return PlayerObject::init(player, ship, gameLayer, layer, playLayer);
}

void lua_PlayerObject::update(float dt)
{
    $quartz_run_hook_callbacks(PlayerObject, update, $quartz_check_nil_return(),
                               (static_cast<PlayerObject*>(this), quartz::float_ref(&dt)),
                               dt);
}

void lua_PlayerObject::updateDummy(float dt)
{
    return PlayerObject::update(dt);
}
} // quartz

$geode_on_mod(Loaded)
{
    auto& luaState = quartz::LuaManager::get().luaState();

    sol::table hookIDs = luaState["quartz"]["HookIDs"];

    if (hookIDs.valid())
    {
        hookIDs.new_enum("PlayerObject",
                         $quartz_define_enum_val(PlayerObject, init),
                         $quartz_define_enum_val(PlayerObject, update));
    }

    luaState.new_usertype<PlayerObject>("PlayerObject", sol::no_constructor,
                                        $quartz_bind_function(PlayerObject, init, (PlayerObject* obj_, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer), player, ship, gameLayer, layer, playLayer),
                                        $quartz_bind_function(PlayerObject, update, (PlayerObject* obj_, float dt), dt));
}