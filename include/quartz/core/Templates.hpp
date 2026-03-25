#pragma once

#include <Geode/modify/Modify.hpp>
#include <Geode/loader/Log.hpp>
#include <quartz/core/LuaManager.hpp>
#include <sol/sol.hpp>
#include <exception>
#include <functional>
#include <cstdint>
#include <type_traits>

namespace quartz
{

template <typename Self>
void enableHookPriority(Self& self, const char* hook)
{
    if (!self.setHookPriority(hook, geode::Priority::Last))
    {
        geode::log::warn("Failed to enable hook priority for {}", hook);
    }
}

template <typename Ret, typename Self, typename Original, typename... Args>
Ret runHookChain(const std::string& hookName, Self* self, Original original, Args... args)
{
    auto& hooks = quartz::LuaManager::get().hooks();

    auto it = hooks.find(hookName);

    if (it == hooks.end())
    {
        return std::invoke(original, self, args...);
    }

    auto& vec = it->second;

    std::function<Ret(size_t, Self*, Args...)> chain =
        [&chain, &vec, original](size_t index, Self* chainSelf, Args... chainArgs) -> Ret
        {
            if (index >= vec.size())
            {
                return std::invoke(original, chainSelf, chainArgs...);
            }

            sol::protected_function_result result;

            try
            {
                std::function<Ret(Args...)> proceed =
                    [&chain, index, chainSelf](Args... proceedArgs) -> Ret
                    {
                        return chain(index + 1, chainSelf, proceedArgs...);
                    };

                result = vec[index].call(chainSelf, proceed, chainArgs...);
            }
            catch (const std::exception& e)
            {
                geode::log::error("Lua exception: {}", e.what());
                return std::invoke(original, chainSelf, chainArgs...);
            }

            if (!result.valid())
            {
                sol::error err = result;
                geode::log::error("Lua error: {}", err.what());
                return std::invoke(original, chainSelf, chainArgs...);
            }

            if constexpr (!std::is_void_v<Ret>)
            {
                if (result.return_count() <= 0)
                {
                    return std::invoke(original, chainSelf, chainArgs...);
                }

                return result.get<Ret>();
            }
        };

    return chain(0, self, args...);
}

} // quartz