#include <quartz/bindings/cocos2d/CCNode.hpp>
#include <quartz/core/Macros.hpp>

namespace quartz
{

void lua_CCNode::onModify(auto& self)
{
    QUARTZ_ENABLE_HOOK_PRIORITY(cocos2d::CCNode, description);
    QUARTZ_ENABLE_HOOK_PRIORITY(cocos2d::CCNode, init);
}

const char* lua_CCNode::description()
{
    using namespace cocos2d;
	return QUARTZ_RUN_HOOK_CHAIN(const char*, cocos2d, CCNode, description);
}

bool lua_CCNode::init()
{
    using namespace cocos2d;
    return QUARTZ_RUN_HOOK_CHAIN(bool, cocos2d, CCNode, init);
}

} // quartz

ON_QUARTZ_LOADED
{
    sol::table cocos2d = quartz::LuaManager::get().luaState()["cocos2d"];
    cocos2d.new_usertype<cocos2d::CCNode>(
        "CCNode",
        
        sol::no_constructor,
        
        "create", &cocos2d::CCNode::create,
        
        "description",
        [](cocos2d::CCNode* self)
        {
            return static_cast<quartz::lua_CCNode*>(self)->description();
        },

        "init",
        [](cocos2d::CCNode* self)
        {
            return static_cast<quartz::lua_CCNode*>(self)->init();
        }
    );
}