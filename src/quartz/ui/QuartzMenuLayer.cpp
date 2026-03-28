#include <quartz/ui/QuartzMenuLayer.hpp>
#include <Geode/cocos/cocoa/CCGeometry.h>
#include <quartz/core/LuaManager.hpp>
#include <Geode/ui/Notification.hpp>
#include <string>

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

		m_fields->m_quartzBtn = CCMenuItemSpriteExtra::create(m_fields->m_quartzBtnBg, this, (cocos2d::SEL_MenuHandler)(&QuartzMenuLayer::onQuartz));

		if (m_fields->m_quartzBtn)
		{
			m_fields->m_quartzBtn->setID("quartz-button"_spr);
		}
	}

	auto bottomMenu = getChildByID("bottom-menu");

	if (bottomMenu && m_fields->m_quartzBtn)
	{
		bottomMenu->addChild(m_fields->m_quartzBtn);
		bottomMenu->updateLayout();
	}

	return true;
}

void QuartzMenuLayer::onQuartz(cocos2d::CCObject* sender)
{
	auto& luaManager = quartz::LuaManager::get();

	luaManager.loadScripts();

	std::string statusLog;
	geode::NotificationIcon statusIcon;
	size_t scriptCount = luaManager.environments().size();

	if (scriptCount > 0)
	{
		statusLog = fmt::format("Loaded {} {}",
								scriptCount, (scriptCount > 1) ? "scripts" : "script");
		statusIcon = geode::NotificationIcon::Success;
	}
	else
	{
		statusLog = "No valid scripts";
		statusIcon = geode::NotificationIcon::None;
	}

	geode::Notification::create(statusLog, statusIcon, 3.f)->show();
}

} // quartz