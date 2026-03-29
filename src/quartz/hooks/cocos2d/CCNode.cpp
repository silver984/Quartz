#include <quartz/hooks/cocos2d/CCNode.hpp>
#include <quartz/core/Templates.hpp>
#include <quartz/core/Macros.hpp>

namespace quartz
{
namespace hooks
{
namespace __cocos2d
{

void __CCNode::onModify(auto& self)
{
    HOOK_PRIO(cocos2d::CCNode, _setZOrder);
    HOOK_PRIO(cocos2d::CCNode, create);
    HOOK_PRIO(cocos2d::CCNode, description);
    HOOK_PRIO(cocos2d::CCNode, getVertexZ);
    HOOK_PRIO(cocos2d::CCNode, getZOrder);
    HOOK_PRIO(cocos2d::CCNode, init);
    HOOK_PRIO(cocos2d::CCNode, setScaleX);
    HOOK_PRIO(cocos2d::CCNode, setVertexZ);
    HOOK_PRIO(cocos2d::CCNode, setZOrder);
}

void __CCNode::_setZOrder(int z)
{
    quartz::runHookChain<void>(
        "cocos2d.CCNode:_set_zorder",
        static_cast<cocos2d::CCNode*>(this),
        FUNCTION(cocos2d::CCNode, _setZOrder),
        z
    );
}

cocos2d::CCNode* __CCNode::create()
{
    return quartz::runStaticHookChain<cocos2d::CCNode*>(
        "cocos2d.CCNode.create",
        &CCNode::create
    );
}

const char* __CCNode::description()
{
    return quartz::runHookChain<const char*>(
        "cocos2d.CCNode:description",
        static_cast<cocos2d::CCNode*>(this),
        FUNCTION(cocos2d::CCNode, description)
    );
}

float __CCNode::getVertexZ()
{
    return quartz::runHookChain<float>(
        "cocos2d.CCNode:get_vertex_z",
        static_cast<cocos2d::CCNode*>(this),
        FUNCTION(cocos2d::CCNode, getVertexZ)
    );
}

int __CCNode::getZOrder()
{
    return quartz::runHookChain<int>(
        "cocos2d.CCNode:get_zorder",
        static_cast<cocos2d::CCNode*>(this),
        FUNCTION(cocos2d::CCNode, getZOrder)
    );
}

bool __CCNode::init()
{
    return quartz::runHookChain<bool>(
        "cocos2d.CCNode:init",
        static_cast<cocos2d::CCNode*>(this),
        FUNCTION(cocos2d::CCNode, init)
    );
}

void __CCNode::setScaleX(float fScaleX)
{
    quartz::runHookChain<void>(
        "cocos2d.CCNode:set_scale_x",
        static_cast<cocos2d::CCNode*>(this),
        FUNCTION(cocos2d::CCNode, setScaleX),
        fScaleX
    );
}

void __CCNode::setVertexZ(float vertexZ)
{
    quartz::runHookChain<void>(
        "cocos2d.CCNode:set_vertex_z",
        static_cast<cocos2d::CCNode*>(this),
        FUNCTION(cocos2d::CCNode, setVertexZ),
        vertexZ
    );
}

void __CCNode::setZOrder(int zOrder)
{
    quartz::runHookChain<void>(
        "cocos2d.CCNode:set_zorder",
        static_cast<cocos2d::CCNode*>(this),
        FUNCTION(cocos2d::CCNode, setZOrder),
        zOrder
    );
}

} // __cocos2d
} // hooks
} // quartz