#include <quartz/bindings/PlayerObject.hpp>
#include <quartz/hooks/PlayerObject.hpp>
#include <quartz/core/LuaManager.hpp>
#include <Geode/loader/Log.hpp>
#include <new>

namespace quartz
{
namespace bindings
{

__PlayerObject::__PlayerObject()
{
    auto& luaManager = quartz::LuaManager::get();
    luaManager.queueBinding(
        [&luaManager]()
        {
            auto& state = luaManager.luaState();

            state.new_usertype<PlayerObject>(
                "PlayerObject",
                sol::constructors<PlayerObject()>(),
                sol::base_classes, sol::bases<cocos2d::CCNode>()
            );

            sol::table usertype = state["PlayerObject"];

            usertype.set_function(
                "fields", [](sol::this_state s, PlayerObject* self)
                {
                    auto __self = static_cast<quartz::hooks::__PlayerObject*>(self);
                    auto& luaFields = __self->m_fields->m_luaFields;

                    if (!luaFields.valid())
                    {
                        sol::state_view lua(s);
                        luaFields = lua.create_table();
                    }

                    return luaFields;
                }
            );

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
                    return quartz::hooks::__PlayerObject::create(player, ship, gameLayer, layer, playLayer);
                }
            );

            luaManager.addValidHook("PlayerObject:init");
            usertype.set_function(
                "init", [](PlayerObject* self, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
                {
                    auto __self = static_cast<quartz::hooks::__PlayerObject*>(self);
                    return __self->init(player, ship, gameLayer, layer, playLayer);
                }
            );

            luaManager.addValidHook("PlayerObject:update");
            usertype.set_function(
                "update", [](PlayerObject* self, float dt)
                {
                    auto __self = static_cast<quartz::hooks::__PlayerObject*>(self);
                    __self->update(dt);
                }
            );

            geode::log::debug("Successfully bound PlayerObject to Lua");
        }
    );
}

} // bindings
} // quartz