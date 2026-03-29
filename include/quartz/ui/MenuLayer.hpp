#pragma once
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/cocos/sprite_nodes/CCSprite.h>

namespace quartz
{
namespace ui
{

struct __MenuLayer : geode::Modify<__MenuLayer, MenuLayer>
{
	bool init() override;
	void onQuartz(cocos2d::CCObject* sender);

	struct Fields
	{
		cocos2d::CCSprite* m_quartzBtnBg = nullptr;
		cocos2d::CCSprite* m_goldQuartz = nullptr;
		CCMenuItemSpriteExtra* m_quartzBtn = nullptr;
	};
};

} // ui
} // quartz