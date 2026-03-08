#pragma once

#define QUARTZ_BIND(BASE, CLASS, ...)\
    BASE.new_usertype<CLASS>(#CLASS, sol::no_constructor, __VA_ARGS__)\

#define QUARTZ_DEFINE_HOOKID(CLASS, LUA_CALL)\
    hookID_##CLASS##_table[#LUA_CALL] = static_cast<int>(quartz::HookIDs::CLASS##_##LUA_CALL);

#define QUARTZ_REGISTER_HOOKIDS(CLASS, DEFINITIONS)\
    auto& state = QUARTZ_LUAMANAGER.luaState();\
    sol::table hookIDs_table = state["hook_ids"];\
    sol::table hookID_##CLASS##_table = state.create_table();\
    DEFINITIONS\
    hookIDs_table[#CLASS] = hookID_##CLASS##_table

#define QUARTZ_BIND_RETURNING_METHOD(CLASS, RETURN_TYPE, DEFAULT_RETURN, CALL, LUA_CALL, ARGS, ...)\
    #LUA_CALL, []ARGS -> RETURN_TYPE { if (auto cast = static_cast<quartz::lua_##CLASS*>(obj__)) { return cast->CALL##__(__VA_ARGS__); } return DEFAULT_RETURN; }

#define QUARTZ_BIND_VOID_METHOD(CLASS, CALL, LUA_CALL, ARGS, ...)\
    #LUA_CALL, []ARGS { if (auto cast = static_cast<quartz::lua_##CLASS*>(obj__)) { cast->CALL##__(__VA_ARGS__); } }

#define QUARTZ_BIND_FIELD(CLASS, LUA_NAME, TYPE, GETTER, SETTER)\
    #LUA_NAME, sol::property([](CLASS* obj__) -> TYPE { return obj__->GETTER; }, [](CLASS* obj__, const TYPE& val) { obj__->SETTER; })

#define QUARTZ_CREATE_TABLE(BASE, NAME)\
    do\
    {\
	    sol::table newTable = BASE.create_table();\
	    BASE[#NAME] = newTable;\
    } while(false)

#define QUARTZ_CHECK_CALLBACKS(CLASS, CALL, LUA_CALL, ...)\
    auto& hooks = QUARTZ_LUAMANAGER.hooks();\
    auto it = hooks.find(quartz::HookIDs::CLASS##_##LUA_CALL);\
    if (it == hooks.end() || it->second.empty())\
    {\
        return CLASS::CALL(__VA_ARGS__);\
    }\
    auto& callbacks = it->second

#define QUARTZ_INVALID_CALLBACK_ERROR(RESULT, LUA_CALL)\
    sol::error error = RESULT;\
    geode::log::error("{} callback invalid | what: {}", #LUA_CALL, error.what())\

#define QUARTZ_RUN_RETURNING_HOOK(CLASS, RETURN_TYPE, DEFAULT_RETURN, CALL, LUA_CALL, ...)\
    QUARTZ_CHECK_CALLBACKS(CLASS, CALL, LUA_CALL, ##__VA_ARGS__);\
    for (const auto& callback : callbacks)\
    {\
        sol::protected_function_result result = callback(static_cast<CLASS*>(this), ##__VA_ARGS__);\
        if (!result.valid())\
        {\
            QUARTZ_INVALID_CALLBACK_ERROR(result, LUA_CALL);\
            return DEFAULT_RETURN;\
        }\
        if (result.return_count() > 0)\
        {\
            return result.get<RETURN_TYPE>(0);\
        }\
    }

#define QUARTZ_RUN_VOID_HOOK(CLASS, CALL, LUA_CALL, ...)\
    QUARTZ_CHECK_CALLBACKS(CLASS, CALL, LUA_CALL, ##__VA_ARGS__);\
    for (const auto& callback : callbacks)\
    {\
        sol::protected_function_result result = callback(static_cast<CLASS*>(this), ##__VA_ARGS__);\
        if (!result.valid())\
        {\
            QUARTZ_INVALID_CALLBACK_ERROR(result, LUA_CALL);\
        }\
    }

#define QUARTZ_CREATE_CLASS(CLASS, ...)\
	class $modify(lua_##CLASS, CLASS)\
	{\
		__VA_ARGS__\
	}

#define QUARTZ_DECLARE_HOOK(RETURN_TYPE, CALL, ARGS)\
	RETURN_TYPE CALL ARGS;\
	RETURN_TYPE CALL##__ ARGS;

#define QUARTZ_DEFINE_RETURNING_HOOK(CLASS, RETURN_TYPE, DEFAULT_RETURN, CALL, LUA_CALL, ARGS, ...)\
    RETURN_TYPE quartz::lua_##CLASS::CALL ARGS { QUARTZ_RUN_RETURNING_HOOK(CLASS, RETURN_TYPE, DEFAULT_RETURN, CALL, LUA_CALL, ##__VA_ARGS__); }\
    RETURN_TYPE quartz::lua_##CLASS::CALL##__ ARGS { return CLASS::CALL(__VA_ARGS__); }

#define QUARTZ_DEFINE_VOID_HOOK(CLASS, CALL, LUA_CALL, ARGS, ...)\
    void quartz::lua_##CLASS::CALL ARGS{ QUARTZ_RUN_VOID_HOOK(CLASS, CALL, LUA_CALL, ##__VA_ARGS__); }\
    void quartz::lua_##CLASS::CALL##__ ARGS{ CLASS::CALL(__VA_ARGS__); }