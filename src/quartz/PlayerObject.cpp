#include <quartz/PlayerObject.hpp>
#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Macros.hpp>
#include <quartz/core/Helpers.hpp>
#include <quartz/core/RefTypes.hpp>
#include <sol/sol.hpp>

using namespace quartz;

/*
bool lua_PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    auto& hooks = $quartz_LuaManager.hooks();
    
    auto it = hooks.find(HookIDs::PlayerObject_init);
    
    if (it == hooks.end() || it->second.empty())
    {
        return PlayerObject::init(player, ship, gameLayer, layer, playLayer);
    }
    
    auto& callbacks = it->second;
    
    for (const auto& callback : callbacks)
    {
        sol::protected_function_result result = callback(static_cast<PlayerObject*>(this), &player, &ship, gameLayer, layer, &playLayer);

        if (!result.valid())
        {
            $quartz_log_callback_error(result, init);
            continue;
        }
    }

    return PlayerObject::init(player, ship, gameLayer, layer, playLayer);
}
*/

void lua_PlayerObject::update(float dt)
{
    auto& hooks = $quartz_LuaManager.hooks();

    auto it = hooks.find(HookIDs::PlayerObject_update);

    if (it == hooks.end() || it->second.empty())
    {
        PlayerObject::update(dt);
        return;
    }

    auto& callbacks = it->second;

    for (const auto& callback : callbacks)
    {
        sol::protected_function_result result = callback(static_cast<PlayerObject*>(this), float_ref(&dt));

        if (!result.valid())
        {
            $quartz_log_callback_error(result, update);
            continue;
        }
    }

    PlayerObject::update(dt);
}

$on_mod(Loaded)
{
    $quartz_create_hook_ids(PlayerObject,
                            $quartz_define_hook_id(PlayerObject, init)
                            $quartz_define_hook_id(PlayerObject, update));
}