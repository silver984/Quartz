#include <quartz/ui/QuartzMenuLayer.hpp>
#include <Geode/cocos/cocoa/CCGeometry.h>
#include <quartz/core/LuaManager.hpp>

namespace quartz
{
	bool QuartzMenuLayer::init()
	{
		if (!MenuLayer::init())
		{
			return false;
		}

		m_fields->m_quartzBtnBg = cocos2d::CCSprite::createWithSpriteFrameName("geode.loader/baseCircle_MediumAlt_Green.png");
		m_fields->m_goldQuartz = cocos2d::CCSprite::create("quartzGold.png"_spr);

		if (m_fields->m_quartzBtnBg)
		{
			if (m_fields->m_goldQuartz)
			{
				m_fields->m_goldQuartz->setPosition(m_fields->m_quartzBtnBg->getScaledContentSize() / 2.f);
				m_fields->m_quartzBtnBg->addChild(m_fields->m_goldQuartz);
			}

			m_fields->m_quartzBtn = CCMenuItemSpriteExtra::create(m_fields->m_quartzBtnBg, this, menu_selector(QuartzMenuLayer::onQuartz));

			if (m_fields->m_quartzBtn)
			{
				m_fields->m_quartzBtn->setID("quartz-button"_spr);
			}
		}

		auto bottomMenu = this->getChildByID("bottom-menu");

		if (bottomMenu && m_fields->m_quartzBtn)
		{
			bottomMenu->addChild(m_fields->m_quartzBtn);
			bottomMenu->updateLayout();
		}

		return true;
	}

	void QuartzMenuLayer::onQuartz(cocos2d::CCObject* sender)
	{
		quartz::LuaManager::get().loadScripts();
	}
}