#include <quartz/core/LuaManager.hpp>
#include <Geode/Geode.hpp>
#include <Geode/cocos/base_nodes/CCNode.h>

using namespace cocos2d;

$on_mod(Loaded)
{
    sol::table cocos2d = quartz::LuaManager::get().luaState()["cocos2d"];

    if (!cocos2d["CCNode"].valid())
    {
        cocos2d.new_usertype<CCNode>(
            "CCNode",
            sol::no_constructor,
            "create", &CCNode::create,
            "description", &CCNode::description,
            "get_position", sol::overload(
                static_cast<const CCPoint& (CCNode::*)()>(&CCNode::getPosition),
                static_cast<void (CCNode::*)(float*, float*)>(&CCNode::getPosition)
            ),
            "get_position_x", &CCNode::getPositionX,
            "get_position_y", &CCNode::getPositionY,
            "get_scale", &CCNode::getScale,
            "get_scale_x", &CCNode::getScaleX,
            "get_scale_y", &CCNode::getScaleY,
            "get_skew_x", &CCNode::getSkewX,
            "get_skew_y", &CCNode::getSkewY,
            "get_vertex_z", &CCNode::getVertexZ,
            "get_zorder", &CCNode::getZOrder,
            "init", &CCNode::init,
            "set_position", sol::overload(
                static_cast<void (CCNode::*)(const CCPoint&)>(&CCNode::setPosition),
                static_cast<void (CCNode::*)(float, float)>(&CCNode::setPosition)
            ),
            "set_position_x", &CCNode::setPositionX,
            "set_position_y", &CCNode::setPositionY,
            "set_scale", sol::overload(
                static_cast<void (CCNode::*)(float)>(&CCNode::setScale),
                static_cast<void (CCNode::*)(float, float)>(&CCNode::setScale)
            ),
            "set_scale_x", &CCNode::setScaleX,
            "set_scale_y", &CCNode::setScaleY,
            "set_skew_x", &CCNode::setSkewX,
            "set_skew_y", &CCNode::setSkewY,
            "set_vertex_z", &CCNode::setVertexZ,
            "set_zorder", &CCNode::setZOrder,
            "_set_zorder", &CCNode::_setZOrder
            // TODO: automation via python maybe
        );
    }
}