#pragma once

#include <Geode/modify/PlayerObject.hpp>

namespace quartz
{
class $modify(lua_PlayerObject, PlayerObject)
{
	// bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
	void update(float dt) override;
};
} // quartz