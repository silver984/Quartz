#pragma once
#include <Geode/cocos/layers_scenes_transitions_nodes/CCLayer.h>
#include <Geode/cocos/robtop/keyboard_dispatcher/CCKeyboardDelegate.h>
#include <Geode/cocos/cocoa/CCObject.h>

namespace quartz {

class ModsLayer : public cocos2d::CCLayer {
public:
	static ModsLayer* create();
	static cocos2d::CCScene* scene();
	bool init() override;
	void keyDown(cocos2d::enumKeyCodes keyCode, double unk) override;

private:
	void goBackToLastScene(cocos2d::CCObject*);
};

} // namespace quartz