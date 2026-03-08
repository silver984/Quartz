#include <quartz/PlayerObject.hpp>
#include <Geode/Geode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <sol/sol.hpp>

QUARTZ_DEFINE_RETURNING_HOOK(PlayerObject, bool, false, init, init, (int p0, int p1, GJBaseGameLayer* p2, cocos2d::CCLayer* p3, bool p4), p0, p1, p2, p3, p4)
QUARTZ_DEFINE_VOID_HOOK(PlayerObject, update, update, (float p0), p0)

$on_mod(Loaded)
{
    QUARTZ_REGISTER_HOOKIDS(PlayerObject,
                            QUARTZ_DEFINE_HOOKID(PlayerObject, init)
                            QUARTZ_DEFINE_HOOKID(PlayerObject, update));
    
    QUARTZ_BIND(QUARTZ_LUAMANAGER.luaState(), PlayerObject,
                QUARTZ_BIND_RETURNING_METHOD(PlayerObject, bool, false, init, init, (PlayerObject* obj__, int p0, int p1, GJBaseGameLayer* p2, cocos2d::CCLayer* p3, bool p4), p0, p1, p2, p3, p4),
                QUARTZ_BIND_VOID_METHOD(PlayerObject, update, update, (PlayerObject* obj__, float p0), p0),
                QUARTZ_BIND_FIELD(PlayerObject, pos, cocos2d::CCPoint, m_position, m_position = val));
}