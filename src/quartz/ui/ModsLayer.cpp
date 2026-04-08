#include <quartz/ui/ModsLayer.hpp>
#include <Geode/cocos/CCDirector.h>
#include <Geode/binding/MenuLayer.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCTransition.h>
#include <cstddef>

namespace quartz {

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

    this->setKeyboardEnabled(true);

    m_background = cocos2d::CCSprite::create("GJ_gradientBG.png");
    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    m_background->setAnchorPoint(cocos2d::CCPoint(0.f, 0.f));
    m_background->setColor(cocos2d::ccColor3B(0, 102, 255));
    m_background->setScaleX(winSize.width / m_background->getContentWidth());
    m_background->setScaleY(winSize.height / m_background->getContentHeight());
    this->addChild(m_background);

    // GJ_GameSheet03.png
    // GJ_sideArt_001.png

    return true;
}

void ModsLayer::keyDown(cocos2d::enumKeyCodes keyCode, double unk) {
    switch (keyCode) {
        using enum cocos2d::enumKeyCodes;
    case KEY_Escape:
        cocos2d::CCDirector::sharedDirector()->replaceScene(
            cocos2d::CCTransitionFade::create(
                0.5f,
                MenuLayer::scene(false)
            )
        );
        break;
    default: break;
    }
}

}