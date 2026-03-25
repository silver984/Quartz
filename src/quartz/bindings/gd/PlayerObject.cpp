#include <quartz/bindings/gd/PlayerObject.hpp>
#include <quartz/core/Macros.hpp>

namespace quartz
{

void lua_PlayerObject::onModify(auto& self)
{
    QUARTZ_ENABLE_HOOK_PRIORITY(PlayerObject, init);
    QUARTZ_ENABLE_HOOK_PRIORITY(PlayerObject, update);
}

bool lua_PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    return QUARTZ_RUN_HOOK_CHAIN(bool, gd, PlayerObject, init, player, ship, gameLayer, layer, playLayer);
}

void lua_PlayerObject::update(float dt)
{
    QUARTZ_RUN_HOOK_CHAIN(void, gd, PlayerObject, update, dt);
}

} // quartz

ON_QUARTZ_LOADED
{
    sol::table gd = quartz::LuaManager::get().luaState()["gd"];
    gd.new_usertype<PlayerObject>(
        "PlayerObject",

        sol::no_constructor,
        
        sol::base_classes, sol::bases<cocos2d::CCNode>(),
        
        "create", &PlayerObject::create,
        
        "init",
        [](PlayerObject* self, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
        {
            return static_cast<quartz::lua_PlayerObject*>(self)->init(player, ship, gameLayer, layer, playLayer);
        },
        
        "update",
        [](PlayerObject* self, float dt)
        {
            static_cast<quartz::lua_PlayerObject*>(self)->update(dt);
        }
    );
}
