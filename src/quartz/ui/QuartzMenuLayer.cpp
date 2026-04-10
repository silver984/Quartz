#include <quartz/ui/QuartzMenuLayer.hpp>
#include <quartz/LuaManager.hpp>
#include <quartz/ui/ModsLayer.hpp>
#include <Geode/cocos/cocoa/CCGeometry.h>
#include <Geode/ui/Notification.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/cocos/CCDirector.h>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCTransition.h>
#include <Geode/cocos/sprite_nodes/CCSprite.h>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <string>
#include <cstddef>

namespace quartz::ui {

bool QuartzMenuLayer::init() {
	if (!MenuLayer::init()) {
		return false;
	}

	auto quartzBtnBg = cocos2d::CCSprite::createWithSpriteFrameName("geode.loader/baseCircle_MediumAlt_Green.png");
	auto goldQuartz = cocos2d::CCSprite::create("quartzGold.png"_spr);
	auto quartzBtn = CCMenuItemSpriteExtra::create(
		quartzBtnBg, this,
		menu_selector(QuartzMenuLayer::onQuartz)
	);

	if (quartzBtnBg) {
		if (goldQuartz) {
			goldQuartz->setPosition(quartzBtnBg->getScaledContentSize() / 2.f);
			quartzBtnBg->addChild(goldQuartz);
		}

		if (quartzBtn) {
			quartzBtn->setID("quartz-button"_spr);
		}
	}

	auto bottomMenu = getChildByID("bottom-menu");
	if (bottomMenu && quartzBtn) {
		bottomMenu->addChild(quartzBtn);
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