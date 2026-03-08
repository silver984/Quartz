#include <Geode/cocos/cocoa/CCGeometry.h>
#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <quartz/core/macros.hpp>
#include <sol/sol.hpp>

using namespace cocos2d;

$on_mod(Loaded)
{
    sol::table cocos2d_table = QUARTZ_LUAMANAGER.luaState()["cocos2d"];

    // TODO factories
    QUARTZ_BIND(cocos2d_table, CCPoint,
                QUARTZ_BIND_FIELD(CCPoint, x, float, x, x = val),
                QUARTZ_BIND_FIELD(CCPoint, y, float, y, y = val));
}