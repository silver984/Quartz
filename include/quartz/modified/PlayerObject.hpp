#pragma once
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/binding/GJBaseGameLayer.hpp>

namespace quartz::modified {

struct PlayerObject : geode::Modify<PlayerObject, ::PlayerObject> {
    static void onModify(geode::modifier::ModifyBase<geode::modifier::ModifyDerive<PlayerObject, ::PlayerObject>>& self);
    static ::PlayerObject* create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
    void update(float dt) override;
    bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);
};

} // namespace quartz::modified