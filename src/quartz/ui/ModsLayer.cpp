#include <quartz/ui/ModsLayer.hpp>
#include <Geode/cocos/CCDirector.h>
#include <Geode/binding/MenuLayer.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCTransition.h>
#include <Geode/cocos/sprite_nodes/CCSprite.h>
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

    auto bg = cocos2d::CCSprite::create("GJ_gradientBG.png");
    auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    bg->setAnchorPoint(cocos2d::CCPoint(0.f, 0.f));
    bg->setColor(cocos2d::ccColor3B(0, 102, 255));
    bg->setScaleX(winSize.width / bg->getContentWidth());
    bg->setScaleY(winSize.height / bg->getContentHeight());
    this->addChild(bg);

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