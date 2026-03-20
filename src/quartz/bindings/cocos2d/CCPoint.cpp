#include <quartz/core/LuaManager.hpp>
#include <Geode/Geode.hpp>
#include <Geode/cocos/cocoa/CCGeometry.h>

using namespace cocos2d;

$on_mod(Loaded)
{
    sol::table cocos2d = quartz::LuaManager::get().luaState()["cocos2d"];

    if (!cocos2d["CCPoint"].valid())
    {
        cocos2d.new_usertype<CCPoint>(
            "CCPoint",
            sol::constructors<CCPoint(), CCPoint(float, float), CCPoint(const CCPoint&), CCPoint(const CCSize&)>(),
            "x", &CCPoint::x,
            "y", &CCPoint::y
        );
    }
}