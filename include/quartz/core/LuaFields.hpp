#pragma once
#include <sol/sol.hpp>

namespace quartz {

/// @brief Modified classes must inherit from this struct in order to expose custom fields storage to Lua
struct LuaFields {
	struct Fields {
		sol::table m_luaFields;
	};
};

} // namespace quartz