#include <quartz/bindings/PlayerObject.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Helpers.hpp>
#include <quartz/core/HookIDs.hpp>
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
    return RUN_HOOK_CALLBACKS(PlayerObject, bool, init, player, ship, gameLayer, layer, playLayer);
}

void lua_PlayerObject::update(float dt)
{
    return RUN_HOOK_CALLBACKS(PlayerObject, void, update, dt);
}

} // quartz

$on_mod(Loaded)
{
    auto& luaState = quartz::LuaManager::get().luaState();

    sol::table hookIDs = luaState["quartz"]["hook_ids"];
    using enum quartz::HookIDs;
    hookIDs.new_enum(
        "PlayerObject",
        "init", PlayerObject_init,
        "update", PlayerObject_update
    );

    using namespace cocos2d;
    luaState.new_usertype<PlayerObject>(
        "PlayerObject",
        sol::no_constructor,
        sol::base_classes, sol::bases<CCNode>(),
        "init", &PlayerObject::init,
        "reset_object", &PlayerObject::resetObject,
        "toggle_player_scale", &PlayerObject::togglePlayerScale,
        "update", &PlayerObject::update,
        "update_player_scale", &PlayerObject::updatePlayerScale
        // TODO: automation maybe
    );
}