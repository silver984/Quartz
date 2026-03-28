#include <quartz/bindings/PlayerObject.hpp>
#include <quartz/core/Macros.hpp>
#include <new>

#define SELF static_cast<PlayerObject*>(this)
void quartz::lua_PlayerObject::onModify(auto& self)
{
    ENABLE_HOOK_PRIORITY(PlayerObject, create);
    ENABLE_HOOK_PRIORITY(PlayerObject, init);
    ENABLE_HOOK_PRIORITY(PlayerObject, update);
}

PlayerObject* quartz::lua_PlayerObject::create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    return quartz::runStaticHookChain<PlayerObject*>(
        "PlayerObject.create",
        &PlayerObject::create,
        player, ship, gameLayer, layer, playLayer
    );
}

bool quartz::lua_PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    return quartz::runHookChain<bool>(
        "PlayerObject:init",
        SELF, NON_STATIC_FN(PlayerObject, init),
        player, ship, gameLayer, layer, playLayer
    );
}

void quartz::lua_PlayerObject::update(float dt)
{
    quartz::runHookChain<void>(
        "PlayerObject:update",
        SELF, NON_STATIC_FN(PlayerObject, update),
        dt
    );
}
#undef SELF
#define SELF static_cast<quartz::lua_PlayerObject*>(self)
ON_QUARTZ_LOADED
{
    auto& luaManager = quartz::LuaManager::get();
    
    auto& state = luaManager.luaState();
    
    state.new_usertype<PlayerObject>(
        "PlayerObject",
        sol::no_constructor,
        sol::base_classes, sol::bases<cocos2d::CCNode>()
    );

    sol::table usertype = state["PlayerObject"];

    usertype.set_function(
        "alloc", []()
        {
            PlayerObject* ptr = new (std::nothrow) PlayerObject();
            return ptr;
        }
    );

    usertype.set_function(
        "free", [](PlayerObject* self)
        {
            delete self;
        }
    );

    luaManager.addValidHook("PlayerObject.create");
    usertype.set_function(
        "create", [](int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
        {
            return quartz::lua_PlayerObject::create(player, ship, gameLayer, layer, playLayer);
        }
    );

    luaManager.addValidHook("PlayerObject:init");
    usertype.set_function(
        "init", [](PlayerObject* self, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
        {
            return SELF->init(player, ship, gameLayer, layer, playLayer);
        }
    );

    luaManager.addValidHook("PlayerObject:update");
    usertype.set_function(
        "update", [](PlayerObject* self, float dt)
        {
            SELF->update(dt);
        }
    );
}
