#include <quartz/ui/QuartzMenuLayer.hpp>
#include <quartz/LuaManager.hpp>
#include <quartz/ui/ModsLayer.hpp>
#include <Geode/cocos/cocoa/CCGeometry.h>
#include <Geode/ui/Notification.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/cocos/CCDirector.h>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCTransition.h>
#include <string>
#include <cstddef>

namespace quartz::ui {

bool QuartzMenuLayer::init() {
	if (!MenuLayer::init()) {
		return false;
	}

	m_fields->m_quartzBtnBg = cocos2d::CCSprite::createWithSpriteFrameName("geode.loader/baseCircle_MediumAlt_Green.png");
	m_fields->m_goldQuartz = cocos2d::CCSprite::create("quartzGold.png"_spr);

	if (m_fields->m_quartzBtnBg) {
		if (m_fields->m_goldQuartz) {
			m_fields->m_goldQuartz->setPosition(m_fields->m_quartzBtnBg->getScaledContentSize() / 2.f);
			m_fields->m_quartzBtnBg->addChild(m_fields->m_goldQuartz);
		}

		m_fields->m_quartzBtn = CCMenuItemSpriteExtra::create(
			m_fields->m_quartzBtnBg, this,
			menu_selector(QuartzMenuLayer::onQuartz)
		);

		if (m_fields->m_quartzBtn) {
			m_fields->m_quartzBtn->setID("quartz-button"_spr);
		}
	}

	auto bottomMenu = getChildByID("bottom-menu");
	if (bottomMenu && m_fields->m_quartzBtn) {
		bottomMenu->addChild(m_fields->m_quartzBtn);
		bottomMenu->updateLayout();
	}

	return true;
}

void QuartzMenuLayer::onQuartz(cocos2d::CCObject*) {
	/*
	auto& luaManager = quartz::LuaManager::get();
	luaManager.loadScripts();

	std::string statusLog;
	geode::NotificationIcon statusIcon;
	size_t scriptCount = luaManager.environments().size();

	if (scriptCount > 0) {
		statusLog = fmt::format("Loaded {} {}",
			scriptCount,
			(scriptCount > 1)
			? "scripts"
			: "script"
		);
		statusIcon = geode::NotificationIcon::Success;
	} else {
		statusLog = "No valid scripts";
		statusIcon = geode::NotificationIcon::None;
	}

	geode::Notification::create(statusLog, statusIcon, 3.f)->show();
	*/

	cocos2d::CCDirector::sharedDirector()->replaceScene(
		cocos2d::CCTransitionFade::create(
			0.5f,
			ModsLayer::scene()
		)
	);
}

} // namespace quartz::ui