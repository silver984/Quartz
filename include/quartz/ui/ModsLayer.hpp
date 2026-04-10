#pragma once
#include <cocos2d.h>
#include <Geode/cocos/layers_scenes_transitions_nodes/CCLayer.h>
#include <Geode/cocos/robtop/keyboard_dispatcher/CCKeyboardDelegate.h>

namespace quartz {

class ModsLayer : public cocos2d::CCLayer {
public:
	CREATE_FUNC(ModsLayer);
	static cocos2d::CCScene* scene();
	virtual bool init();
	void keyDown(cocos2d::enumKeyCodes keyCode, double unk) override;
};

} // namespace quartz