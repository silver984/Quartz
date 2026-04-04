#pragma once
#include <sol/sol.hpp>

namespace quartz {

struct LuaFields {
	struct Fields {
		sol::table m_luaFields;
	};
};

} // namespace quartz