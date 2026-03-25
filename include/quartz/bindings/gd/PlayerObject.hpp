#pragma once

#include <Geode/modify/PlayerObject.hpp>

namespace quartz
{

struct lua_PlayerObject : public geode::Modify<lua_PlayerObject, PlayerObject>
{
	static void onModify(auto& self);
	bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
	void update(float dt) override;
};

} // quartz