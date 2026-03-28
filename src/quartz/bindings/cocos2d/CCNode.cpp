#include <quartz/bindings/cocos2d/CCNode.hpp>
#include <quartz/core/Macros.hpp>
#include <new>

void quartz::lua_CCNode::onModify(auto& self)
{
    ENABLE_HOOK_PRIORITY(cocos2d::CCNode, _setZOrder);
    ENABLE_HOOK_PRIORITY(cocos2d::CCNode, create);
    ENABLE_HOOK_PRIORITY(cocos2d::CCNode, description);
    ENABLE_HOOK_PRIORITY(cocos2d::CCNode, getVertexZ);
    ENABLE_HOOK_PRIORITY(cocos2d::CCNode, getZOrder);
    ENABLE_HOOK_PRIORITY(cocos2d::CCNode, init);
    ENABLE_HOOK_PRIORITY(cocos2d::CCNode, setScaleX);
    ENABLE_HOOK_PRIORITY(cocos2d::CCNode, setVertexZ);
    ENABLE_HOOK_PRIORITY(cocos2d::CCNode, setZOrder);
}

void quartz::lua_CCNode::_setZOrder(int z)
{
    quartz::runHookChain<void>(
        "cocos2d.CCNode:_set_zorder",
        static_cast<cocos2d::CCNode*>(this),
        NON_STATIC_FN(cocos2d::CCNode, _setZOrder),
        z
    );
}

cocos2d::CCNode* quartz::lua_CCNode::create()
{
    return quartz::runStaticHookChain<cocos2d::CCNode*>(
        "cocos2d.CCNode.create",
        &CCNode::create
    );
}

const char* quartz::lua_CCNode::description()
{
    return quartz::runHookChain<const char*>(
        "cocos2d.CCNode:description",
        static_cast<cocos2d::CCNode*>(this),
        NON_STATIC_FN(cocos2d::CCNode, description)
    );
}

float quartz::lua_CCNode::getVertexZ()
{
    return quartz::runHookChain<float>(
        "cocos2d.CCNode:get_vertex_z",
        static_cast<cocos2d::CCNode*>(this),
        NON_STATIC_FN(cocos2d:: CCNode, getVertexZ)
    );
}

int quartz::lua_CCNode::getZOrder()
{
    return quartz::runHookChain<int>(
        "cocos2d.CCNode:get_zorder",
        static_cast<cocos2d::CCNode*>(this),
        NON_STATIC_FN(cocos2d::CCNode, getZOrder)
    );
}

bool quartz::lua_CCNode::init()
{
    return quartz::runHookChain<bool>(
        "cocos2d.CCNode:init",
        static_cast<cocos2d::CCNode*>(this),
        NON_STATIC_FN(cocos2d::CCNode, init)
    );
}

void quartz::lua_CCNode::setScaleX(float fScaleX)
{
    quartz::runHookChain<void>(
        "cocos2d.CCNode:set_scale_x",
        static_cast<cocos2d::CCNode*>(this),
        NON_STATIC_FN(cocos2d::CCNode, setScaleX),
        fScaleX
    );
}

void quartz::lua_CCNode::setVertexZ(float vertexZ)
{
    quartz::runHookChain<void>(
        "cocos2d.CCNode:set_vertex_z",
        static_cast<cocos2d::CCNode*>(this),
        NON_STATIC_FN(cocos2d::CCNode, setVertexZ),
        vertexZ
    );
}

void quartz::lua_CCNode::setZOrder(int zOrder)
{
    quartz::runHookChain<void>(
        "cocos2d.CCNode:set_zorder",
        static_cast<cocos2d::CCNode*>(this),
        NON_STATIC_FN(cocos2d::CCNode, setZOrder),
        zOrder
    );
}

ON_QUARTZ_LOADED
{
    auto& luaManager = quartz::LuaManager::get();
    
    sol::table cocos2d = luaManager.luaState()["cocos2d"];
    
    cocos2d.new_usertype<cocos2d::CCNode>(
        "CCNode",
        sol::constructors<cocos2d::CCNode()>(),
        sol::base_classes, sol::bases<cocos2d::CCObject>()
    );

    sol::table usertype = cocos2d["CCNode"];

    usertype.set_function(
        "alloc", []()
        {
            cocos2d::CCNode* ptr = new (std::nothrow) cocos2d::CCNode();
            return ptr;
        }
    );

    usertype.set_function(
        "free", [](cocos2d::CCNode* self)
        {
            delete self;
        }
    );

    luaManager.addValidHook("cocos2d.CCNode:_set_zorder");
    usertype.set_function(
        "_set_zorder", [](cocos2d::CCNode* self, int z)
        {
            auto __self = static_cast<quartz::lua_CCNode*>(self);
            __self->_setZOrder(z);
        }
    );

    luaManager.addValidHook("cocos2d.CCNode.create");
    usertype.set_function(
        "create", []()
        {
            return quartz::lua_CCNode::create();
        }
    );

    luaManager.addValidHook("cocos2d.CCNode:description");
    usertype.set_function(
        "description", [](cocos2d::CCNode* self)
        {
            auto __self = static_cast<quartz::lua_CCNode*>(self);
            return __self->description();
        }
    );

    luaManager.addValidHook("cocos2d.CCNode:get_vertex_z");
    usertype.set_function(
        "get_vertex_z", [](cocos2d::CCNode* self)
        {
            auto __self = static_cast<quartz::lua_CCNode*>(self);
            return __self->getVertexZ();
        }
    );

    luaManager.addValidHook("cocos2d.CCNode:get_zorder");
    usertype.set_function(
        "get_zorder", [](cocos2d::CCNode* self)
        {
            auto __self = static_cast<quartz::lua_CCNode*>(self);
            return __self->getZOrder();
        }
    );

    luaManager.addValidHook("cocos2d.CCNode:init");
    usertype.set_function(
        "init", [](cocos2d::CCNode* self)
        {
            auto __self = static_cast<quartz::lua_CCNode*>(self);
            return __self->init();
        }
    );

    luaManager.addValidHook("cocos2d.CCNode:set_scale_x");
    usertype.set_function(
        "set_scale_x", [](cocos2d::CCNode* self, float fScaleX)
        {
            auto __self = static_cast<quartz::lua_CCNode*>(self);
            __self->setScaleX(fScaleX);
        }
    );

    luaManager.addValidHook("cocos2d.CCNode:set_vertex_z");
    usertype.set_function(
        "set_vertex_z", [](cocos2d::CCNode* self, float vertexZ)
        {
            auto __self = static_cast<quartz::lua_CCNode*>(self);
            __self->setVertexZ(vertexZ);
        }
    );

    luaManager.addValidHook("cocos2d.CCNode:set_zorder");
    usertype.set_function(
        "set_zorder", [](cocos2d::CCNode* self, int zOrder)
        {
            auto __self = static_cast<quartz::lua_CCNode*>(self);
            __self->setZOrder(zOrder);
        }
    );
}