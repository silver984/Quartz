#pragma once
#include <Geode/modify/CCNode.hpp>
#include <quartz/core/LuaFields.hpp>

namespace quartz
{
namespace hooks
{
namespace __cocos2d
{

struct __CCNode : geode::Modify<__CCNode, cocos2d::CCNode>, quartz::LuaFields
{
	static void onModify(auto& self);
	void _setZOrder(int z) override;
	static cocos2d::CCNode* create();
	const char* description();
	float getVertexZ() override;
	int getZOrder() override;
	bool init() override;
	void setScaleX(float fScaleX) override;
	void setVertexZ(float vertexZ) override;
	void setZOrder(int zOrder) override;
};

} // __cocos2d
} // hooks
} // quartz
