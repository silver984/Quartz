#pragma once

#include <Geode/modify/CCNode.hpp>

namespace quartz
{

// @lua[usertype] cocos2d.CCNode
struct lua_CCNode : public geode::Modify<lua_CCNode, cocos2d::CCNode>
{
	static void onModify(auto& self);

	// @lua[method] cocos2d.CCNode:_set_zorder(z)
	void _setZOrder(int z) override;
	
	// @lua[static] cocos2d.CCNode.create() -> cocos2d.CCNode
	static cocos2d::CCNode* create();
	
	// @lua[method] cocos2d.CCNode:description() -> string
	const char* description();
	
	// @lua[method] cocos2d.CCNode:get_vertex_z() -> number
	float getVertexZ() override;

	// @lua[method] cocos2d.CCNode:get_zorder() -> integer
	int getZOrder() override;
	
	// @lua[method] cocos2d.CCNode:init() -> boolean
	bool init() override;
	
	// @lua[method] cocos2d.CCNode:set_scale_x(scale_x)
	void setScaleX(float fScaleX) override;

	// @lua[method] cocos2d.CCNode:set_vertex_z(vertex_z)
	void setVertexZ(float vertexZ) override;
	
	// @lua[method] cocos2d.CCNode:set_zorder(z_order)
	void setZOrder(int zOrder) override;
};

} // quartz
