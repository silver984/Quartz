#pragma once
#include <Geode/loader/Log.hpp>
#include <quartz/core/LuaManager.hpp>
#include <exception>
#include <utility>
#include <cstdint>
#include <type_traits>
#include <functional>

namespace quartz {

/// @brief Executes Lua hook chain for instance member functions
/// 
/// Returns original if Lua closed or no hooks, otherwise chains hooks in registration order with proceed callback support
/// 
/// @tparam Ret Function return type
/// @tparam Self Instance class type
/// @tparam Original Original function pointer type
/// @tparam ...Args Function argument types
/// @param hookName Identifier for the hook chain
/// @param self Pointer to class instance
/// @param original Original function to call as fallback
/// @param ...args Arguments to pass through
/// @return Value from hook chain or original function
template <typename Ret, typename Self, typename Original, typename... Args>
Ret runHookChain(std::string const& hookName, Self* self, Original original, Args... args) {
    auto& luaManager = LuaManager::get();

    if (!luaManager.isOpen()) {
        return std::invoke(original, self, args...);
    }

    auto& hooks = luaManager.luaHooks();
    auto it = hooks.find(hookName);
    if (it == hooks.end()) {
        return std::invoke(original, self, args...);
    }

    auto& vec = it->second;
    std::function<Ret(size_t, Self*, Args...)> chain;
    chain = [&](size_t index, Self* chainSelf, Args... chainArgs) -> Ret {
        if (index >= vec.size()) {
            return std::invoke(original, chainSelf, chainArgs...);
        }

        sol::protected_function_result result;

        try {
            std::function<Ret(Args...)> proceed = [&](Args... proceedArgs) -> Ret {
                return chain(index + 1, chainSelf, proceedArgs...);
                };

            result = vec[index](chainSelf, proceed, chainArgs...);
        } catch (std::exception const& e) {
            geode::log::error("Lua exception: {}", e.what());
            return std::invoke(original, chainSelf, chainArgs...);
        }

        if (!result.valid()) {
            sol::error err = result;
            geode::log::error("Lua error: {}", err.what());
            return std::invoke(original, chainSelf, chainArgs...);
        }

        if constexpr (!std::is_void_v<Ret>) {
            if (result.return_count() <= 0) {
                return std::invoke(original, chainSelf, chainArgs...);
            }

            return result.get<Ret>();
        }
        };

    return chain(0, self, args...);
}

/// @brief Executes Lua hook chain for static functions
/// 
/// Similar to runHookChain but without instance pointer, suited for static methods
/// 
/// @tparam Ret Function return type
/// @tparam Original Original function pointer type
/// @tparam ...Args Function argument types
/// @param hookName Identifier for the hook chain
/// @param original Original function to call as fallback
/// @param ...args Arguments to pass through
/// @return Value from hook chain or original function
template <typename Ret, typename Original, typename... Args>
Ret runStaticHookChain(const std::string& hookName, Original original, Args... args) {
    auto& luaManager = LuaManager::get();

    if (!luaManager.isOpen()) {
        return original(args...);
    }

    auto& hooks = luaManager.luaHooks();
    auto it = hooks.find(hookName);
    if (it == hooks.end()) {
        return original(args...);
    }

    auto& vec = it->second;
    std::function<Ret(size_t, Args...)> chain;
    chain = [&](size_t index, Args... chainArgs) -> Ret {
        if (index >= vec.size()) {
            return original(chainArgs...);
        }

        sol::protected_function_result result;

        try {
            std::function<Ret(Args...)> proceed = [&](Args... proceedArgs) -> Ret {
                return chain(index + 1, proceedArgs...);
                };

            result = vec[index](proceed, chainArgs...);
        } catch (const std::exception& e) {
            geode::log::error("Lua exception: {}", e.what());
            return original(chainArgs...);
        }

        if (!result.valid()) {
            sol::error err = result;
            geode::log::error("Lua error: {}", err.what());
            return original(chainArgs...);
        }

        if constexpr (!std::is_void_v<Ret>) {
            if (result.return_count() <= 0) {
                return original(chainArgs...);
            }

            return result.get<Ret>();
        }
        };

    return chain(0, args...);
}

} // namespace quartz