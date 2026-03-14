#pragma once

// ---------- GEODE RELATED ---------- //

#define $geode_on_mod(X) $on_mod(X)
#define $geode_on_game(X) $on_game(X)

// ---------- BINDING RELATED ---------- //

#define $quartz_enable_hook_priority(CLASS, HOOK, SELF)\
    if (!SELF.setHookPriority(#CLASS "::" #HOOK, geode::Priority::EarlyPre))\
    {\
        geode::log::warn("Failed to enable hook priority for " #CLASS "::" #HOOK);\
    }\
    else\
    {\
        geode::log::debug("Enabled hook priority for " #CLASS "::" #HOOK);\
    }

#define $quartz_define_enum_val(PREFIX, X) \
    quartz::camelToSnake(#X), quartz::HookIDs::PREFIX##_##X

#define $quartz_bind_function(CLASS, FUNCTION, ARGS, ...)\
    quartz::camelToSnake(#FUNCTION), [] ARGS\
    {\
        if (obj_)\
        {\
            static_cast<quartz::lua_##CLASS*>(obj_)->FUNCTION##Dummy(__VA_ARGS__);\
        }\
    }

// ---------- HOOK CALLBACK RELATED ---------- //

#define $quartz_log_callback_exception(CLASS, HOOK, ERR)\
    geode::log::error("Callback for hook id #{} caused an exception | what: {}", static_cast<int>(quartz::HookIDs::CLASS##_##HOOK), ERR.what())

#define $quartz_log_callback_error(CLASS, HOOK, RESULT)\
    sol::error err = RESULT;\
    geode::log::error("Callback for hook id #{} caused an error | what: {}", static_cast<int>(quartz::HookIDs::CLASS##_##HOOK), err.what())

#define $quartz_check_nil_return()\
    if (result.return_count() > 0)\
    {\
        sol::object obj = result.get<sol::object>(0);\
        if (obj.is<sol::lua_nil_t>())\
        {\
            return;\
        }\
    }

#define $quartz_check_type_return(TYPE)\
    if (result.return_count() > 0)\
    {\
        sol::object obj = result.get<sol::object>(0);\
        if (obj.is<TYPE>())\
        {\
            return obj.as<TYPE>();\
        }\
    }

#define $quartz_run_hook_callbacks(CLASS, HOOK, RETURN_CHECK, CALLBACK_ARGS, ...)\
    auto& hookCallbacks = quartz::LuaManager::get().getHookCallbacks(quartz::HookIDs::CLASS##_##HOOK);\
    if (hookCallbacks.empty())\
    {\
        return CLASS::HOOK(__VA_ARGS__);\
    }\
    for (auto it = hookCallbacks.begin(); it != hookCallbacks.end();)\
    {\
        sol::protected_function_result result;\
        try\
        {\
            result = (*it) CALLBACK_ARGS;\
        }\
        catch (const std::exception& e)\
        {\
            $quartz_log_callback_exception(CLASS, HOOK, e);\
            it = hookCallbacks.erase(it);\
            continue;\
        }\
        if (!result.valid())\
        {\
            $quartz_log_callback_error(CLASS, HOOK, result);\
            it = hookCallbacks.erase(it);\
            continue;\
        }\
        RETURN_CHECK\
        ++it;\
    }\
    return CLASS::HOOK(__VA_ARGS__)