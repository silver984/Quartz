#include <quartz/bindings/gd/PlayerObject.hpp>
#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Templates.hpp>
#include <exception>
#include <functional>
#include <cstdint>

namespace quartz
{

void lua_PlayerObject::onModify(auto& self)
{
    quartz::enableHookPriority(self, "PlayerObject::init");
    quartz::enableHookPriority(self, "PlayerObject::update");
}

bool lua_PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    auto& hooks = quartz::LuaManager::get().hooks();
    auto it = hooks.find("gd.PlayerObject.init");
    if (it != hooks.end())
    {
        auto& vec = it->second;
        std::function<bool(size_t, lua_PlayerObject*, int, int, GJBaseGameLayer*, cocos2d::CCLayer*, bool)> chain =
            [&chain, &vec](size_t index, lua_PlayerObject* self, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
            {
                if (index >= vec.size())
                {
                    return self->PlayerObject::init(player, ship, gameLayer, layer, playLayer);
                }

                sol::protected_function_result result;

                try
                {
                    auto next =
                        [&chain, index](lua_PlayerObject* self, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
                        {
                            return chain(index + 1, self, player, ship, gameLayer, layer, playLayer);
                        };

                    result = vec[index].call(self, next, player, ship, gameLayer, layer, playLayer);
                }
                catch (const std::exception& exception)
                {
                    geode::log::error("Lua caught an exception | what: {}", exception.what());
                    return self->PlayerObject::init(player, ship, gameLayer, layer, playLayer);
                }

                if (!result.valid())
                {
                    sol::error error = result;
                    geode::log::error("Lua caught an error | what: {}", error.what());
                    return self->PlayerObject::init(player, ship, gameLayer, layer, playLayer);
                }

                if (result.return_count() <= 0)
                {
                    return self->PlayerObject::init(player, ship, gameLayer, layer, playLayer);
                }

                sol::object obj = result.get<sol::object>(0);
                return obj.as<bool>();
            };

        return chain(0, this, player, ship, gameLayer, layer, playLayer);
    }

    return PlayerObject::init(player, ship, gameLayer, layer, playLayer);
}

void lua_PlayerObject::update(float dt)
{
    auto& hooks = quartz::LuaManager::get().hooks();
    auto it = hooks.find("gd.PlayerObject.update");
    if (it != hooks.end())
    {
        auto& vec = it->second;
        std::function<void(size_t, lua_PlayerObject*, float)> chain =
            [&chain, &vec](size_t index, lua_PlayerObject* self, float dt)
            {
                if (index >= vec.size())
                {
                    self->PlayerObject::update(dt);
                    return;
                }

                sol::protected_function_result result;

                try
                {
                    auto next =
                        [&chain, index](lua_PlayerObject* self, float dt)
                        {
                            chain(index + 1, self, dt);
                        };

                    result = vec[index].call(self, next, dt);
                }
                catch (const std::exception& exception)
                {
                    geode::log::error("Lua caught an exception | what: {}", exception.what());
                    self->PlayerObject::update(dt);
                    return;
                }

                if (!result.valid())
                {
                    sol::error error = result;
                    geode::log::error("Lua caught an error | what: {}", error.what());
                    self->PlayerObject::update(dt);
                    return;
                }
            };

        chain(0, this, dt);
        return;
    }

    PlayerObject::update(dt);
}

} // quartz

$on_mod(Loaded)
{
    sol::table gd = quartz::LuaManager::get().luaState()["gd"];
    if (!gd["PlayerObject"].valid())
    {
        gd.new_usertype<quartz::lua_PlayerObject>(
            "PlayerObject",
            sol::no_constructor,
            "init", &quartz::lua_PlayerObject::init,
            "update", &quartz::lua_PlayerObject::update
        );
    }
}