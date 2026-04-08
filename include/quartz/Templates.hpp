#pragma once
#include <Geode/loader/Log.hpp>
#include <quartz/LuaManager.hpp>
#include <quartz/HookStorage.hpp>
#include <string_view>
#include <exception>
#include <utility>
#include <type_traits>
#include <functional>
#include <cstddef>

namespace quartz {

template <typename Ret, typename Self, typename Original, typename... Args>
Ret runHookChain(std::string_view hookName, Self* self, Original original, Args... args) {
    if (!LuaManager::get().isOpen()) {
        return std::invoke(original, self, args...);
    }

    auto* callbacks = HookStorage::get().getLuaCallbacks(hookName);
    if (!callbacks) {
        return std::invoke(original, self, args...);
    }

    std::function<Ret(size_t, Self*, Args...)> chain =
        [&](size_t index, Self* chainSelf, Args... chainArgs) -> Ret {
        if (index >= (*callbacks).size()) {
            return std::invoke(original, chainSelf, chainArgs...);
        }

        sol::protected_function_result result;

        try {
            std::function<Ret(Args...)> proceed =
                [&](Args... proceedArgs) -> Ret {
                return chain(index + 1, chainSelf, proceedArgs...);
                };

            result = (*callbacks)[index](chainSelf, proceed, chainArgs...);
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

template <typename Ret, typename Original, typename... Args>
Ret runStaticHookChain(std::string_view hookName, Original original, Args... args) {
    if (!LuaManager::get().isOpen()) {
        return original(args...);
    }

    auto* callbacks = HookStorage::get().getLuaCallbacks(hookName);
    if (!callbacks) {
        return original(args...);
    }

    std::function<Ret(size_t, Args...)> chain =
        [&](size_t index, Args... chainArgs) -> Ret {
        if (index >= (*callbacks).size()) {
            return original(chainArgs...);
        }

        sol::protected_function_result result;

        try {
            std::function<Ret(Args...)> proceed =
                [&](Args... proceedArgs) -> Ret {
                return chain(index + 1, proceedArgs...);
                };

            result = (*callbacks)[index](proceed, chainArgs...);
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