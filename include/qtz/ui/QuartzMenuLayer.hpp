#pragma once
#include <Geode/modify/MenuLayer.hpp>

namespace qtz::ui {

struct QuartzMenuLayer : geode::Modify<QuartzMenuLayer, MenuLayer> {
	bool init() override;
	void onQuartz(cocos2d::CCObject*);
};

} // namespace qtz::ui