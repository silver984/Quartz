#pragma once

#include <Geode/modify/PlayerObject.hpp>

namespace quartz
{

// @lua[usertype] PlayerObject
struct lua_PlayerObject : public geode::Modify<lua_PlayerObject, PlayerObject>
{
	static void onModify(auto& self);

	// @lua[static] PlayerObject.create(player, ship, game_layer, layer, play_layer) -> PlayerObject
	static PlayerObject* create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);

	// @lua[method] PlayerObject:init(player, ship, game_layer, layer, play_layer) -> boolean
	bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
	
	// @lua[method] PlayerObject:update(dt)
	void update(float dt) override;
};

} // quartz
