#include <quartz/core/LuaManager.hpp>
#include <quartz/core/Macros.hpp>

// this C++ file gets executed last apparently
// a little bit hacky but it works

ON_QUARTZ_LOADED
{
	quartz::LuaManager::get().loadScripts();
}