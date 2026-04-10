#include <quartz/ui/ModsLayer.hpp>
#include <Geode/cocos/CCDirector.h>
#include <Geode/binding/MenuLayer.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCTransition.h>
#include <Geode/cocos/sprite_nodes/CCSprite.h>
#include <Geode/cocos/menu_nodes/CCMenu.h>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <vector>
#include <cstddef>

namespace quartz {

ModsLayer* ModsLayer::create() {
    ModsLayer* pRet = new ModsLayer();

    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    } else {
        delete pRet; pRet = 0;
        return 0;
    }
};

cocos2d::CCScene* ModsLayer::scene() {
    auto scene = cocos2d::CCScene::create();
    auto layer = ModsLayer::create();
    scene->addChild(layer);
    return scene;
}

bool ModsLayer::init() {
    if (!CCLayer::init()) {
        return false;
    }

    this->setTouchEnabled(true);
    this->setKeyboardEnabled(true);

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

    auto bg = cocos2d::CCSprite::create("GJ_gradientBG.png");
    if (bg) {
        bg->setAnchorPoint(cocos2d::CCPoint(0.f, 0.f));
        bg->setColor(cocos2d::ccColor3B(0, 102, 255));
        bg->setScaleX(winSize.width / bg->getContentWidth());
        bg->setScaleY(winSize.height / bg->getContentHeight());
        this->addChild(bg);
    }

    std::vector<cocos2d::CCSprite*> sideArts{ nullptr, nullptr };
    for (size_t i = 0; i < sideArts.size(); ++i) {
        auto& sideArt = sideArts[i];
        sideArt = cocos2d::CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");

        if (!sideArt) {
            continue;
        }

        sideArt->setAnchorPoint(
            cocos2d::CCPoint(
                i < 1 ? 0.f : 1.f,
                0.f
            )
        );

        if (i > 0) {
            sideArt->setFlipX(true);
            sideArt->setPositionX(winSize.width);
        }

        this->addChild(sideArt);
    }

    auto menu = cocos2d::CCMenu::create();
    if (menu) {
        auto closeBtn = CCMenuItemSpriteExtra::create(
            cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), this,
            menu_selector(ModsLayer::goBackToLastScene)
        );

        if (closeBtn) {
            menu->setContentSize(closeBtn->getContentSize());
            menu->addChild(closeBtn);
            closeBtn->setPosition(closeBtn->getParent()->getContentSize() / 2.f);

            float padding = 5.f;
            menu->setPosition(
                cocos2d::CCPoint(
                    padding,
                    winSize.height - menu->getContentSize().height - padding
                )
            );

            this->addChild(menu);
        }
    }

    return true;
}

void ModsLayer::keyDown(cocos2d::enumKeyCodes keyCode, double unk) {
    switch (keyCode) {
        using enum cocos2d::enumKeyCodes;
    case KEY_Escape:
        goBackToLastScene(nullptr);
        break;
    default: break;
    }
}

void ModsLayer::goBackToLastScene(cocos2d::CCObject*) {
    cocos2d::CCDirector::sharedDirector()->replaceScene(
        cocos2d::CCTransitionFade::create(
            0.5f,
            MenuLayer::scene(false)
        )
    );
}

}