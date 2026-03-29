#pragma once
#include <Geode/modify/PlayerObject.hpp>
#include <quartz/core/LuaFields.hpp>

namespace quartz
{
namespace hooks
{

struct __PlayerObject : geode::Modify<__PlayerObject, PlayerObject>, quartz::LuaFields
{
	static void onModify(auto& self);
	static PlayerObject* create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
	bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
	void update(float dt) override;
};

} // hooks
} // quartz