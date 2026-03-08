#pragma once

#include <Geode/modify/PlayerObject.hpp>
#include <quartz/core/macros.hpp>

namespace quartz
{
QUARTZ_CREATE_CLASS(PlayerObject,
					QUARTZ_DECLARE_HOOK(bool, init, (int p0, int p1, GJBaseGameLayer* p2, cocos2d::CCLayer* p3, bool p4))
					QUARTZ_DECLARE_HOOK(void, update, (float p0)));
} // quartz