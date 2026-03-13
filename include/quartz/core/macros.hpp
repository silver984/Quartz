#pragma once

#define $quartz_create_table(BASE, NAME)\
	{\
		sol::table newTable = BASE.create_table();\
		BASE[NAME] = newTable;\
	}

#define $quartz_define_hook_id(CLASS, HOOK)\
	hookID_##CLASS##_table[quartz::camelToSnake(#HOOK)] = static_cast<int>(quartz::HookIDs::CLASS##_##HOOK);

#define $quartz_create_hook_ids(CLASS, DEFINITIONS)\
	auto& state = $quartz_LuaManager.luaState();\
	sol::table hookIDs_table = state["hook_ids"];\
	sol::table hookID_##CLASS##_table = state.create_table();\
	DEFINITIONS\
	hookIDs_table[#CLASS] = hookID_##CLASS##_table

#define $quartz_log_callback_error(RESULT, HOOK)\
    sol::error err = RESULT;\
    geode::log::error("Callback error on \"{}\" | what: {}", quartz::camelToSnake(#HOOK), err.what())