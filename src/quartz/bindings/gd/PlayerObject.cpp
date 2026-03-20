#include <quartz/bindings/gd/PlayerObject.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Helpers.hpp>
#include <Geode/cocos/base_nodes/CCNode.h>

namespace quartz
{
    void lua_PlayerObject::onModify(auto& self)
    {
        quartz::enableHookPriority(self, "PlayerObject::init");
        quartz::enableHookPriority(self, "PlayerObject::update");
    }

    bool lua_PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
    {
        sol::function fn = quartz::LuaManager::get().luaState()["gd"]["PlayerObject"]["init"];

        if (!fn.valid())
        {
            return PlayerObject::init(player, ship, gameLayer, layer, playLayer);
        }

        sol::object ret = fn.call(static_cast<PlayerObject*>(this), player, ship, gameLayer, layer, playLayer);
        
        return ret.as<bool>();
    }

    void lua_PlayerObject::update(float dt)
    {
        sol::function fn = quartz::LuaManager::get().luaState()["gd"]["PlayerObject"]["update"];

        if (!fn.valid())
        {
            return PlayerObject::update(dt);
        }
        
        fn.call(static_cast<PlayerObject*>(this), dt);
    }
}

$on_mod(Loaded)
{
    sol::table gd = quartz::LuaManager::get().luaState()["gd"];

    if (!gd["PlayerObject"].valid())
    {
        gd.new_usertype<PlayerObject>(
            "PlayerObject",
            sol::no_constructor,
            sol::base_classes, sol::bases<cocos2d::CCNode>(),
            "init", &PlayerObject::init,
            "reset_object", &PlayerObject::resetObject,
            "toggle_player_scale", &PlayerObject::togglePlayerScale,
            "update", &PlayerObject::update,
            "update_player_scale", &PlayerObject::updatePlayerScale
        );
    }
}