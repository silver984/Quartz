#pragma once
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/cocos/sprite_nodes/CCSprite.h>

namespace quartz::ui {

struct QuartzMenuLayer : geode::Modify<QuartzMenuLayer, MenuLayer> {
	bool init() override;
	void onQuartz(cocos2d::CCObject*);
};

} // namespace quartz::ui