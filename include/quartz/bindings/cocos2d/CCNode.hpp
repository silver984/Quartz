#pragma once

#include <Geode/modify/CCNode.hpp>

namespace quartz
{

struct lua_CCNode : public geode::Modify<lua_CCNode, cocos2d::CCNode>
{
	static void onModify(auto& self);
	const char* description();
	bool init() override;
};

} // quartz