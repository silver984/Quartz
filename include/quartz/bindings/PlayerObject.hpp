#pragma once

#include <Geode/modify/PlayerObject.hpp>

namespace quartz
{
class $modify(lua_PlayerObject, PlayerObject)
{
	static void onModify(auto& self);

	bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
	bool initDummy(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
	void update(float dt) override;
	void updateDummy(float dt);
};
} // quartz