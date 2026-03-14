#pragma once

#include <Geode/modify/PlayerObject.hpp>

namespace quartz
{
class $modify(lua_PlayerObject, PlayerObject)
{
	static void onModify(auto& self);
	// TODO: init
	// bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
	void update(float dt) override;
};
} // quartz