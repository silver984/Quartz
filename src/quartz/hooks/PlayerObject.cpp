#include <quartz/hooks/PlayerObject.hpp>
#include <quartz/core/Templates.hpp>
#include <quartz/core/Macros.hpp>

namespace quartz
{
namespace hooks
{

void __PlayerObject::onModify(auto& self)
{
    HOOK_PRIO(PlayerObject, create);
    HOOK_PRIO(PlayerObject, init);
    HOOK_PRIO(PlayerObject, update);
}

PlayerObject* __PlayerObject::create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    return quartz::runStaticHookChain<PlayerObject*>(
        "PlayerObject.create",
        &PlayerObject::create,
        player, ship, gameLayer, layer, playLayer
    );
}

bool __PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer)
{
    return quartz::runHookChain<bool>(
        "PlayerObject:init",
        static_cast<PlayerObject*>(this),
        FUNCTION(PlayerObject, init),
        player, ship, gameLayer, layer, playLayer
    );
}

void __PlayerObject::update(float dt)
{
    quartz::runHookChain<void>(
        "PlayerObject:update",
        static_cast<PlayerObject*>(this),
        FUNCTION(PlayerObject, update),
        dt
    );
}

} // hooks
} // quartz