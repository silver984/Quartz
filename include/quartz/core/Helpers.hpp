#pragma once

#include <Geode/modify/Modify.hpp>
#include <quartz/core/TypeRef.hpp>
#include <type_traits>
#include <functional>

namespace quartz
{

// only TypeRef for primitive types
template <typename TYPE>
using maybe_type_ref_t = std::conditional_t<std::is_arithmetic_v<TYPE> && !std::is_pointer_v<TYPE>, quartz::TypeRef<TYPE>, TYPE>;

void enableHookPriority(auto& self, const char* hook)
{
    if (self.setHookPriority(hook, geode::Priority::First))
    {
        geode::log::debug("Enabled hook priority for {}", hook);
    }
    else
    {
        geode::log::warn("Failed to enable hook priority for {}", hook);
    }
}

template <typename TYPE, typename SELF, typename HOOK, typename... ARGS>
TYPE runHookCallbacks(quartz::HookIDs hookID, SELF&& self, HOOK&& hook, ARGS&&... args)
{
    auto& hookCallbacks = quartz::LuaManager::get().getHookCallbacks(hookID);

    if (hookCallbacks.empty())
    {
        return std::invoke(std::forward<HOOK>(hook), std::forward<SELF>(self), std::forward<ARGS>(args)...);
    }

    for (auto it = hookCallbacks.begin(); it != hookCallbacks.end();)
    {
        sol::protected_function_result result;

        try
        {
            result = (*it)(self, quartz::maybe_type_ref_t<std::remove_reference_t<ARGS>>(&args)...);
        }
        catch (const std::exception& error)
        {
            geode::log::error("Callback for hook id #{} caused an exception | what: {}", static_cast<int>(hookID), error.what());
            it = hookCallbacks.erase(it);
            continue;
        }

        if (!result.valid())
        {
            sol::error error = result;
            geode::log::error("Callback for hook id #{} caused an error | what: {}", static_cast<int>(hookID), error.what());
            it = hookCallbacks.erase(it);
            continue;
        }

        if (result.return_count() > 0)
        {
            sol::object obj = result.get<sol::object>(0);

            if constexpr (std::is_void_v<TYPE>)
            {
                if (obj.is<sol::lua_nil_t>())
                {
                    return;
                }
            }
            else
            {
                if (obj.is<TYPE>())
                {
                    return obj.as<TYPE>();
                }
            }
        }

        ++it;
    }

    return std::invoke(std::forward<HOOK>(hook), std::forward<SELF>(self), std::forward<ARGS>(args)...);
}

} // quartz

#define RUN_HOOK_CALLBACKS(CLASS, TYPE, HOOK, ...)\
    quartz::runHookCallbacks<TYPE>(quartz::HookIDs::CLASS##_init, static_cast<CLASS*>(this), &CLASS::HOOK, ##__VA_ARGS__)