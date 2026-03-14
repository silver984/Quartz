#include <quartz/bindings/PlayerObject.hpp>
#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/SnakeCase.hpp>
#include <quartz/core/RefTypes.hpp>
#include <sol/sol.hpp>
#include <exception>

// TODO: move these somewhere else once finalized

// make sure quartz's callbacks happens before everything else
#define $quartz_enable_hook_priority(CLASS, HOOK, SELF)\
    if (!SELF.setHookPriority(#CLASS "::" #HOOK, geode::Priority::EarlyPre))\
    {\
        geode::log::warn("Failed to enable hook priority for " #CLASS "::" #HOOK);\
    }\
    else\
    {\
        geode::log::debug("Successfully enabled hook priority for " #CLASS "::" #HOOK);\
    }

#define $quartz_log_callback_exception(CLASS, HOOK, ERR)\
    geode::log::error("Callback for hook id #{} caused an exception | what: {}", static_cast<int>(quartz::HookIDs::CLASS##_##HOOK), ERR.what())

#define $quartz_log_callback_error(CLASS, HOOK, RESULT)\
    sol::error err = RESULT;\
    geode::log::error("Callback for hook id #{} caused an error | what: {}", static_cast<int>(quartz::HookIDs::CLASS##_##HOOK), err.what())

namespace quartz
{
void lua_PlayerObject::onModify(auto& self)
{
    $quartz_enable_hook_priority(PlayerObject, update, self);
}

/* TODO: return value hooks
bool lua_PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    return PlayerObject::init(player, ship, gameLayer, layer, playLayer);
}
*/

void lua_PlayerObject::update(float dt)
{
    auto& hookCallbacks = quartz::LuaManager::get().getHookCallbacks(quartz::HookIDs::PlayerObject_update);

    if (hookCallbacks.empty())
    {
        PlayerObject::update(dt);
        return;
    }

    for (auto it = hookCallbacks.begin(); it != hookCallbacks.end();)
    {
        sol::protected_function_result result;

        try
        {
            result = (*it)(static_cast<PlayerObject*>(this), quartz::float_ref(&dt));
        }
        catch (const std::exception& e)
        {
            $quartz_log_callback_exception(PlayerObject, update, e);
            it = hookCallbacks.erase(it);
            continue;
        }

        if (!result.valid())
        {
            $quartz_log_callback_error(PlayerObject, update, result);
            it = hookCallbacks.erase(it);
            continue;
        }

        if (result.return_count() > 0)
        {
            sol::object obj = result.get<sol::object>(0);

            if (obj.is<sol::lua_nil_t>())
            {
                return;
            }
        }

        ++it;
    }

    PlayerObject::update(dt);
}
} // quartz