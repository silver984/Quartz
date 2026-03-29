#include <quartz/bindings/cocos2d/CCNode.hpp>
#include <quartz/hooks/cocos2d/CCNode.hpp>
#include <quartz/core/LuaManager.hpp>
#include <Geode/loader/Log.hpp>
#include <new>

namespace quartz
{
namespace bindings
{
namespace __cocos2d
{

__CCNode::__CCNode()
{
    auto& luaManager = quartz::LuaManager::get();
    luaManager.queueBinding(
        [&luaManager]()
        {
            auto& state = luaManager.luaState();

            sol::table cocos2d = state["cocos2d"].get_or_create<sol::table>();

            cocos2d.new_usertype<cocos2d::CCNode>(
                "CCNode",
                sol::constructors<cocos2d::CCNode()>(),
                sol::base_classes, sol::bases<cocos2d::CCObject>()
            );

            sol::table usertype = cocos2d["CCNode"];

            usertype.set_function(
                "fields", [](sol::this_state s, cocos2d::CCNode* self)
                {
                    auto __self = static_cast<quartz::hooks::__cocos2d::__CCNode*>(self);
                    auto& luaFields = __self->m_fields->m_luaFields;

                    if (!luaFields.valid())
                    {
                        sol::state_view lua(s);
                        luaFields = lua.create_table();
                    }

                    return luaFields;
                }
            );

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
                    auto __self = static_cast<quartz::hooks::__cocos2d::__CCNode*>(self);
                    __self->_setZOrder(z);
                }
            );

            luaManager.addValidHook("cocos2d.CCNode.create");
            usertype.set_function(
                "create", []()
                {
                    return quartz::hooks::__cocos2d::__CCNode::create();
                }
            );

            luaManager.addValidHook("cocos2d.CCNode:description");
            usertype.set_function(
                "description", [](cocos2d::CCNode* self)
                {
                    auto __self = static_cast<quartz::hooks::__cocos2d::__CCNode*>(self);
                    return __self->description();
                }
            );

            luaManager.addValidHook("cocos2d.CCNode:get_vertex_z");
            usertype.set_function(
                "get_vertex_z", [](cocos2d::CCNode* self)
                {
                    auto __self = static_cast<quartz::hooks::__cocos2d::__CCNode*>(self);
                    return __self->getVertexZ();
                }
            );

            luaManager.addValidHook("cocos2d.CCNode:get_zorder");
            usertype.set_function(
                "get_zorder", [](cocos2d::CCNode* self)
                {
                    auto __self = static_cast<quartz::hooks::__cocos2d::__CCNode*>(self);
                    return __self->getZOrder();
                }
            );

            luaManager.addValidHook("cocos2d.CCNode:init");
            usertype.set_function(
                "init", [](cocos2d::CCNode* self)
                {
                    auto __self = static_cast<quartz::hooks::__cocos2d::__CCNode*>(self);
                    return __self->init();
                }
            );

            luaManager.addValidHook("cocos2d.CCNode:set_scale_x");
            usertype.set_function(
                "set_scale_x", [](cocos2d::CCNode* self, float fScaleX)
                {
                    auto __self = static_cast<quartz::hooks::__cocos2d::__CCNode*>(self);
                    __self->setScaleX(fScaleX);
                }
            );

            luaManager.addValidHook("cocos2d.CCNode:set_vertex_z");
            usertype.set_function(
                "set_vertex_z", [](cocos2d::CCNode* self, float vertexZ)
                {
                    auto __self = static_cast<quartz::hooks::__cocos2d::__CCNode*>(self);
                    __self->setVertexZ(vertexZ);
                }
            );

            luaManager.addValidHook("cocos2d.CCNode:set_zorder");
            usertype.set_function(
                "set_zorder", [](cocos2d::CCNode* self, int zOrder)
                {
                    auto __self = static_cast<quartz::hooks::__cocos2d::__CCNode*>(self);
                    __self->setZOrder(zOrder);
                }
            );

            geode::log::debug("Successfully bound cocos2d::CCNode to Lua");
        }  
    );
}

} // __cocos2d
} // bindings
} // quartz