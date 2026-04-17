#include <qtz/ui/ModsLayer.hpp>
#include <Geode/cocos/CCDirector.h>
#include <Geode/binding/MenuLayer.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCTransition.h>
#include <Geode/cocos/menu_nodes/CCMenu.h>
#include <Geode/binding/CCMenuItemSpriteExtra.hpp>
#include <Geode/cocos/extensions/GUI/CCControlExtension/CCScale9Sprite.h>
#include <Geode/loader/Mod.hpp>
#include <Geode/cocos/label_nodes/CCLabelBMFont.h>
#include <Geode/ui/ScrollLayer.hpp>
#include <fmt/format.h>
#include <cstddef>

namespace qtz {

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
    this->scheduleUpdate();

    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();

    m_bg = cocos2d::CCSprite::create("game_bg_01_001.png");
    m_bg->setScale(1.125f);
    m_bg->setAnchorPoint(cocos2d::CCPoint(0.f, 0.5f));
    auto& texRect = m_bg->getTextureRect();
    cocos2d::CCRect newTexRect;
    newTexRect.setRect(0.f, 0.f, texRect.size.width * 2, texRect.size.height);
    m_bg->setTextureRect(newTexRect);
    m_bg->setColor(cocos2d::ccColor3B(0, 102, 255));
    m_bg->setPosition(
        cocos2d::CCPoint(
            0.f,
            winSize.height / 2.f
        )
    );

    this->addChild(m_bg);

    auto bgPlate = cocos2d::extension::CCScale9Sprite::create("GJ_square02.png");
    bgPlate->setContentSize(cocos2d::CCPoint(400.f, 250.f));
    bgPlate->setPosition(winSize / 2.f);
    this->addChild(bgPlate);

    auto text = cocos2d::CCLabelBMFont::create("Addons", "bigFont.fnt");
    bgPlate->addChild(text);
    text->setScale(0.8f);
    text->setPositionX(text->getParent()->getContentWidth() / 2.f);
    text->setPositionY(text->getParent()->getContentHeight() - 3.f);
    text->setAnchorPoint(cocos2d::CCPoint(0.5f, 1.f));

    auto scrollLayer = geode::ScrollLayer::create(cocos2d::CCSize(300, 200));
    bgPlate->addChild(scrollLayer);
    scrollLayer->getChildByID("content-layer")->addChild(cocos2d::CCSprite::create("fallbackModLogo.png"_spr));
    scrollLayer->setPositionX((scrollLayer->getParent()->getContentWidth() / 2.f) - (scrollLayer->getContentWidth() / 2.f));
    scrollLayer->setPositionY(15.f);
    // scrollLayer->setPosition(bgPlate->getContentSize() / 2.f);
    
    auto menu = cocos2d::CCMenu::create();
    auto closeBtn = CCMenuItemSpriteExtra::create(
        cocos2d::CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png"), this,
        menu_selector(ModsLayer::goBackToLastScene)
    );

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

    return true;
}

void ModsLayer::update(float delta) {
    if (!m_bg) {
        return;
    }

    m_bg->setPositionX(m_bg->getPositionX() - (20.f * delta));
    if (m_bg->getPositionX() <= -m_bg->getScaledContentSize().width / 2.f) {
        m_bg->setPositionX(0.f);
    }
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