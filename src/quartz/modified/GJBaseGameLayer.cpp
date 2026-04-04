#include <quartz/modified/GJBaseGameLayer.hpp>
#include <quartz/core/Templates.hpp>
#include <utility>

namespace quartz {

void GJBaseGameLayerModified::activateEventTrigger(EventLinkTrigger* object, gd::vector<int> const& remapKeys) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_event_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activateEventTrigger(std::forward<decltype(args)>(args)...); 
        }, object, remapKeys);
}

void GJBaseGameLayerModified::activateItemCompareTrigger(ItemTriggerGameObject* object, gd::vector<int> const& remapKeys) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_item_compare_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activateItemCompareTrigger(std::forward<decltype(args)>(args)...); 
        }, object, remapKeys);
}

void GJBaseGameLayerModified::activateItemEditTrigger(ItemTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_item_edit_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activateItemEditTrigger(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::activatePersistentItemTrigger(ItemTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_persistent_item_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activatePersistentItemTrigger(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::activatePlayerControlTrigger(PlayerControlGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_player_control_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activatePlayerControlTrigger(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::activateSFXEditTrigger(SFXTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_sfxedit_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activateSFXEditTrigger(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::activateSFXTrigger(SFXTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_sfxtrigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activateSFXTrigger(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::activateSongEditTrigger(SongTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_song_edit_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activateSongEditTrigger(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::activateSongTrigger(SongTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_song_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activateSongTrigger(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::activateTimerTrigger(TimerTriggerGameObject* object, gd::vector<int> const& remapKeys) {
    quartz::runHookChain<void>("GJBaseGameLayer:activate_timer_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activateTimerTrigger(std::forward<decltype(args)>(args)...); 
        }, object, remapKeys);
}

void GJBaseGameLayerModified::activatedAudioTrigger(SFXTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:activated_audio_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activatedAudioTrigger(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::activatedAudioTrigger(SFXTriggerGameObject* object, float levelTime) {
    quartz::runHookChain<void>("GJBaseGameLayer:activated_audio_trigger@2",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::activatedAudioTrigger(std::forward<decltype(args)>(args)...); 
        }, object, levelTime);
}

void GJBaseGameLayerModified::addAreaEffect(EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJAreaActionType type) {
    quartz::runHookChain<void>("GJBaseGameLayer:add_area_effect",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addAreaEffect(std::forward<decltype(args)>(args)...); 
        }, object, instances, type);
}

void GJBaseGameLayerModified::addCustomEnterEffect(EnterEffectObject* object, bool enter) {
    quartz::runHookChain<void>("GJBaseGameLayer:add_custom_enter_effect",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addCustomEnterEffect(std::forward<decltype(args)>(args)...); 
        }, object, enter);
}

bool GJBaseGameLayerModified::addGuideArt(GameObject* object) {
    return quartz::runHookChain<bool>("GJBaseGameLayer:add_guide_art",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addGuideArt(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::addKeyframe(KeyframeGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:add_keyframe",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addKeyframe(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::addProximityVolumeEffect(int channelID, int targetType, SFXTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:add_proximity_volume_effect",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addProximityVolumeEffect(std::forward<decltype(args)>(args)...); 
        }, channelID, targetType, object);
}

void GJBaseGameLayerModified::addRemapTargets(gd::set<int>& targets) {
    quartz::runHookChain<void>("GJBaseGameLayer:add_remap_targets",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addRemapTargets(std::forward<decltype(args)>(args)...); 
        }, targets);
}

void GJBaseGameLayerModified::addToGroup(GameObject* object, int groupID, bool triggerGroup) {
    quartz::runHookChain<void>("GJBaseGameLayer:add_to_group",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addToGroup(std::forward<decltype(args)>(args)...); 
        }, object, groupID, triggerGroup);
}

void GJBaseGameLayerModified::addToGroups(GameObject* object, bool duplicateTrigger) {
    quartz::runHookChain<void>("GJBaseGameLayer:add_to_groups",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addToGroups(std::forward<decltype(args)>(args)...); 
        }, object, duplicateTrigger);
}

void GJBaseGameLayerModified::addToSection(GameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:add_to_section",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addToSection(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::addUIObject(GameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:add_uiobject",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::addUIObject(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::animateInDualGroundNew(GameObject* object, float height, bool instant, float duration) {
    quartz::runHookChain<void>("GJBaseGameLayer:animate_in_dual_ground_new",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::animateInDualGroundNew(std::forward<decltype(args)>(args)...); 
        }, object, height, instant, duration);
}

void GJBaseGameLayerModified::applyRemap(EffectGameObject* object, gd::vector<int> const& remapKeys, gd::unordered_map<int, int>& remap) {
    quartz::runHookChain<void>("GJBaseGameLayer:apply_remap",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::applyRemap(std::forward<decltype(args)>(args)...); 
        }, object, remapKeys, remap);
}

void GJBaseGameLayerModified::applySFXEditTrigger(int channelID, int targetType, SFXTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:apply_sfxedit_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::applySFXEditTrigger(std::forward<decltype(args)>(args)...); 
        }, channelID, targetType, object);
}

void GJBaseGameLayerModified::applyTimeWarp(float timeWarp) {
    quartz::runHookChain<void>("GJBaseGameLayer:apply_time_warp",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::applyTimeWarp(std::forward<decltype(args)>(args)...); 
        }, timeWarp);
}

void GJBaseGameLayerModified::assignNewStickyGroups(cocos2d::CCArray* objects) {
    quartz::runHookChain<void>("GJBaseGameLayer:assign_new_sticky_groups",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::assignNewStickyGroups(std::forward<decltype(args)>(args)...); 
        }, objects);
}

void GJBaseGameLayerModified::bumpPlayer(PlayerObject* player, EffectGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:bump_player",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::bumpPlayer(std::forward<decltype(args)>(args)...); 
        }, player, object);
}

bool GJBaseGameLayerModified::buttonIsRelevant(PlayerButtonCommand const& button) {
    return quartz::runHookChain<bool>("GJBaseGameLayer:button_is_relevant",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::buttonIsRelevant(std::forward<decltype(args)>(args)...); 
        }, button);
}

void GJBaseGameLayerModified::calculateColorGroups() {
    quartz::runHookChain<void>("GJBaseGameLayer:calculate_color_groups",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::calculateColorGroups(std::forward<decltype(args)>(args)...); 
        });
}

bool GJBaseGameLayerModified::canBeActivatedByPlayer(PlayerObject* player, EffectGameObject* object) {
    return quartz::runHookChain<bool>("GJBaseGameLayer:can_be_activated_by_player",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::canBeActivatedByPlayer(std::forward<decltype(args)>(args)...); 
        }, player, object);
}

bool GJBaseGameLayerModified::canProcessSFX(SFXTriggerState& state, gd::unordered_map<int, int>& stateIndices, gd::unordered_map<int, float>& times, gd::vector<SFXTriggerState>& states) {
    return quartz::runHookChain<bool>("GJBaseGameLayer:can_process_sfx",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::canProcessSFX(std::forward<decltype(args)>(args)...); 
        }, state, stateIndices, times, states);
}

void GJBaseGameLayerModified::checkCameraLimitAfterTeleport(PlayerObject* player, float yOffset) {
    quartz::runHookChain<void>("GJBaseGameLayer:check_camera_limit_after_teleport",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::checkCameraLimitAfterTeleport(std::forward<decltype(args)>(args)...); 
        }, player, yOffset);
}

bool GJBaseGameLayerModified::checkCollision(int blockAID, int blockBID) {
    return quartz::runHookChain<bool>("GJBaseGameLayer:check_collision",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::checkCollision(std::forward<decltype(args)>(args)...); 
        }, blockAID, blockBID);
}

void GJBaseGameLayerModified::checkCollisionBlocks(EffectGameObject* object, gd::vector<EffectGameObject *>* blocks, int blockCount) {
    quartz::runHookChain<void>("GJBaseGameLayer:check_collision_blocks",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::checkCollisionBlocks(std::forward<decltype(args)>(args)...); 
        }, object, blocks, blockCount);
}

int GJBaseGameLayerModified::checkCollisions(PlayerObject* object, float dt, bool ignoreDamage) {
    return quartz::runHookChain<int>("GJBaseGameLayer:check_collisions",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::checkCollisions(std::forward<decltype(args)>(args)...); 
        }, object, dt, ignoreDamage);
}

void GJBaseGameLayerModified::checkRepellPlayer() {
    quartz::runHookChain<void>("GJBaseGameLayer:check_repell_player",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::checkRepellPlayer(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::checkSpawnObjects() {
    quartz::runHookChain<void>("GJBaseGameLayer:check_spawn_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::checkSpawnObjects(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::checkpointActivated(CheckpointGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:checkpoint_activated",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::checkpointActivated(std::forward<decltype(args)>(args)...); 
        }, object);
}

cocos2d::CCParticleSystemQuad* GJBaseGameLayerModified::claimCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int zLayer, int zOrder, int uiObject, bool dontAdd) {
    return quartz::runHookChain<cocos2d::CCParticleSystemQuad*>("GJBaseGameLayer:claim_custom_particle",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::claimCustomParticle(std::forward<decltype(args)>(args)...); 
        }, key, particleStruct, zLayer, zOrder, uiObject, dontAdd);
}

cocos2d::CCPoint GJBaseGameLayerModified::claimMoveAction(int groupID, bool ignoreStaticGroups) {
    return quartz::runHookChain<cocos2d::CCPoint>("GJBaseGameLayer:claim_move_action",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::claimMoveAction(std::forward<decltype(args)>(args)...); 
        }, groupID, ignoreStaticGroups);
}

cocos2d::CCParticleSystemQuad* GJBaseGameLayerModified::claimParticle(gd::string key, int zLayer) {
    return quartz::runHookChain<cocos2d::CCParticleSystemQuad*>("GJBaseGameLayer:claim_particle",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::claimParticle(std::forward<decltype(args)>(args)...); 
        }, key, zLayer);
}

void GJBaseGameLayerModified::claimRotationAction(int targetID, int centerID, float& rotation, float& offset, bool ignoreStaticGroups, bool unused) {
    quartz::runHookChain<void>("GJBaseGameLayer:claim_rotation_action",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::claimRotationAction(std::forward<decltype(args)>(args)...); 
        }, targetID, centerID, rotation, offset, ignoreStaticGroups, unused);
}

void GJBaseGameLayerModified::collisionCheckObjects(PlayerObject* object, gd::vector<GameObject *>* objects, int objectCount, float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:collision_check_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::collisionCheckObjects(std::forward<decltype(args)>(args)...); 
        }, object, objects, objectCount, dt);
}

void GJBaseGameLayerModified::controlAreaEffect(EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJActionCommand command) {
    quartz::runHookChain<void>("GJBaseGameLayer:control_area_effect",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::controlAreaEffect(std::forward<decltype(args)>(args)...); 
        }, object, instances, command);
}

void GJBaseGameLayerModified::controlAreaEffectWithID(int uniqueID, int controlID, GJActionCommand command) {
    quartz::runHookChain<void>("GJBaseGameLayer:control_area_effect_with_id",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::controlAreaEffectWithID(std::forward<decltype(args)>(args)...); 
        }, uniqueID, controlID, command);
}

void GJBaseGameLayerModified::controlEventLink(int uniqueID, int controlID, GJActionCommand command) {
    quartz::runHookChain<void>("GJBaseGameLayer:control_event_link",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::controlEventLink(std::forward<decltype(args)>(args)...); 
        }, uniqueID, controlID, command);
}

void GJBaseGameLayerModified::controlTriggersInGroup(int group, GJActionCommand command) {
    quartz::runHookChain<void>("GJBaseGameLayer:control_triggers_in_group",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::controlTriggersInGroup(std::forward<decltype(args)>(args)...); 
        }, group, command);
}

void GJBaseGameLayerModified::controlTriggersWithControlID(int controlID, GJActionCommand command) {
    quartz::runHookChain<void>("GJBaseGameLayer:control_triggers_with_control_id",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::controlTriggersWithControlID(std::forward<decltype(args)>(args)...); 
        }, controlID, command);
}

float GJBaseGameLayerModified::convertToClosestDirection(float angle, float bound) {
    return quartz::runStaticHookChain<float>("GJBaseGameLayer.convert_to_closest_direction",
        &GJBaseGameLayer::convertToClosestDirection,
        angle, bound);
}

void GJBaseGameLayerModified::createBackground(int background) {
    quartz::runHookChain<void>("GJBaseGameLayer:create_background",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::createBackground(std::forward<decltype(args)>(args)...); 
        }, background);
}

cocos2d::CCParticleSystemQuad* GJBaseGameLayerModified::createCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int minimum, bool dontAdd) {
    return quartz::runHookChain<cocos2d::CCParticleSystemQuad*>("GJBaseGameLayer:create_custom_particle",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::createCustomParticle(std::forward<decltype(args)>(args)...); 
        }, key, particleStruct, minimum, dontAdd);
}

void GJBaseGameLayerModified::createGroundLayer(int ground, int line) {
    quartz::runHookChain<void>("GJBaseGameLayer:create_ground_layer",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::createGroundLayer(std::forward<decltype(args)>(args)...); 
        }, ground, line);
}

void GJBaseGameLayerModified::createMiddleground(int middleground) {
    quartz::runHookChain<void>("GJBaseGameLayer:create_middleground",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::createMiddleground(std::forward<decltype(args)>(args)...); 
        }, middleground);
}

cocos2d::CCParticleSystemQuad* GJBaseGameLayerModified::createParticle(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType) {
    return quartz::runHookChain<cocos2d::CCParticleSystemQuad*>("GJBaseGameLayer:create_particle",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::createParticle(std::forward<decltype(args)>(args)...); 
        }, objectType, plistName, tag, positionType);
}

void GJBaseGameLayerModified::createPlayer() {
    quartz::runHookChain<void>("GJBaseGameLayer:create_player",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::createPlayer(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::createPlayerCollisionBlock() {
    quartz::runHookChain<void>("GJBaseGameLayer:create_player_collision_block",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::createPlayerCollisionBlock(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::createTextLayers() {
    quartz::runHookChain<void>("GJBaseGameLayer:create_text_layers",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::createTextLayers(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCArray* GJBaseGameLayerModified::damagingObjectsInRect(cocos2d::CCRect rect, bool enabledGroups) {
    return quartz::runHookChain<cocos2d::CCArray*>("GJBaseGameLayer:damaging_objects_in_rect",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::damagingObjectsInRect(std::forward<decltype(args)>(args)...); 
        }, rect, enabledGroups);
}

void GJBaseGameLayerModified::destroyObject(GameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:destroy_object",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::destroyObject(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::exitStaticCamera(bool exitX, bool exitY, float time, int easingType, float easingRate, bool smoothVelocity, float smoothVelocityMod, bool exitInstant) {
    quartz::runHookChain<void>("GJBaseGameLayer:exit_static_camera",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::exitStaticCamera(std::forward<decltype(args)>(args)...); 
        }, exitX, exitY, time, easingType, easingRate, smoothVelocity, smoothVelocityMod, exitInstant);
}

void GJBaseGameLayerModified::flipGravity(PlayerObject* object, bool flip, bool noEffects) {
    quartz::runHookChain<void>("GJBaseGameLayer:flip_gravity",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::flipGravity(std::forward<decltype(args)>(args)...); 
        }, object, flip, noEffects);
}

void GJBaseGameLayerModified::flipObjects() {
    quartz::runHookChain<void>("GJBaseGameLayer:flip_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::flipObjects(std::forward<decltype(args)>(args)...); 
        });
}

gd::string GJBaseGameLayerModified::gameEventToString(GJGameEvent event) {
    return quartz::runStaticHookChain<gd::string>("GJBaseGameLayer.game_event_to_string",
        &GJBaseGameLayer::gameEventToString,
        event);
}

void GJBaseGameLayerModified::gameEventTriggered(GJGameEvent event, int material, int playerID) {
    quartz::runHookChain<void>("GJBaseGameLayer:game_event_triggered",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::gameEventTriggered(std::forward<decltype(args)>(args)...); 
        }, event, material, playerID);
}

int GJBaseGameLayerModified::generateEnterEasingBuffer(int easingType, float easingRate) {
    return quartz::runHookChain<int>("GJBaseGameLayer:generate_enter_easing_buffer",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::generateEnterEasingBuffer(std::forward<decltype(args)>(args)...); 
        }, easingType, easingRate);
}

void GJBaseGameLayerModified::generateSpawnRemap() {
    quartz::runHookChain<void>("GJBaseGameLayer:generate_spawn_remap",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::generateSpawnRemap(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::generateTargetGroups() {
    quartz::runHookChain<void>("GJBaseGameLayer:generate_target_groups",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::generateTargetGroups(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::generateVisibilityGroups() {
    quartz::runHookChain<void>("GJBaseGameLayer:generate_visibility_groups",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::generateVisibilityGroups(std::forward<decltype(args)>(args)...); 
        });
}

float GJBaseGameLayerModified::getAreaObjectValue(EnterEffectInstance* instance, GameObject* object, cocos2d::CCPoint& position, bool& show) {
    return quartz::runHookChain<float>("GJBaseGameLayer:get_area_object_value",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getAreaObjectValue(std::forward<decltype(args)>(args)...); 
        }, instance, object, position, show);
}

cocos2d::CCPoint GJBaseGameLayerModified::getFollowSpeedVal(GameObject* object, int startSpeedRef, int startDirRef, float startDir, float startSpeed) {
    return quartz::runHookChain<cocos2d::CCPoint>("GJBaseGameLayer:get_follow_speed_val",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getFollowSpeedVal(std::forward<decltype(args)>(args)...); 
        }, object, startSpeedRef, startDirRef, startDir, startSpeed);
}

cocos2d::CCArray* GJBaseGameLayerModified::getGroup(int id) {
    return quartz::runHookChain<cocos2d::CCArray*>("GJBaseGameLayer:get_group",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getGroup(std::forward<decltype(args)>(args)...); 
        }, id);
}

double GJBaseGameLayerModified::getItemValue(int type, int id) {
    return quartz::runHookChain<double>("GJBaseGameLayer:get_item_value",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getItemValue(std::forward<decltype(args)>(args)...); 
        }, type, id);
}

float GJBaseGameLayerModified::getMaxPortalY() {
    return quartz::runHookChain<float>("GJBaseGameLayer:get_max_portal_y",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getMaxPortalY(std::forward<decltype(args)>(args)...); 
        });
}

float GJBaseGameLayerModified::getMinDistance(cocos2d::CCPoint position, cocos2d::CCArray* objects, float minNear, int mode) {
    return quartz::runHookChain<float>("GJBaseGameLayer:get_min_distance",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getMinDistance(std::forward<decltype(args)>(args)...); 
        }, position, objects, minNear, mode);
}

float GJBaseGameLayerModified::getMinPortalY() {
    return quartz::runHookChain<float>("GJBaseGameLayer:get_min_portal_y",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getMinPortalY(std::forward<decltype(args)>(args)...); 
        });
}

double GJBaseGameLayerModified::getModifiedDelta(float dt) {
    return quartz::runHookChain<double>("GJBaseGameLayer:get_modified_delta",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getModifiedDelta(std::forward<decltype(args)>(args)...); 
        }, dt);
}

gd::string GJBaseGameLayerModified::getParticleKey(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType) {
    return quartz::runHookChain<gd::string>("GJBaseGameLayer:get_particle_key",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getParticleKey(std::forward<decltype(args)>(args)...); 
        }, objectType, plistName, tag, positionType);
}

gd::string GJBaseGameLayerModified::getParticleKey2(gd::string key) {
    return quartz::runHookChain<gd::string>("GJBaseGameLayer:get_particle_key2",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getParticleKey2(std::forward<decltype(args)>(args)...); 
        }, key);
}

gd::string GJBaseGameLayerModified::getRecordString(bool compress) {
    return quartz::runHookChain<gd::string>("GJBaseGameLayer:get_record_string",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getRecordString(std::forward<decltype(args)>(args)...); 
        }, compress);
}

cocos2d::CCPoint GJBaseGameLayerModified::getSavedPosition(int groupID, float delay) {
    return quartz::runHookChain<cocos2d::CCPoint>("GJBaseGameLayer:get_saved_position",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::getSavedPosition(std::forward<decltype(args)>(args)...); 
        }, groupID, delay);
}

void GJBaseGameLayerModified::groupStickyObjects(cocos2d::CCArray* objects) {
    quartz::runHookChain<void>("GJBaseGameLayer:group_sticky_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::groupStickyObjects(std::forward<decltype(args)>(args)...); 
        }, objects);
}

void GJBaseGameLayerModified::handleButton(bool down, int button, bool isPlayer1) {
    quartz::runHookChain<void>("GJBaseGameLayer:handle_button",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::handleButton(std::forward<decltype(args)>(args)...); 
        }, down, button, isPlayer1);
}

bool GJBaseGameLayerModified::hasUniqueCoin(EffectGameObject* object) {
    return quartz::runHookChain<bool>("GJBaseGameLayer:has_unique_coin",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::hasUniqueCoin(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::increaseBatchNodeCapacity() {
    quartz::runHookChain<void>("GJBaseGameLayer:increase_batch_node_capacity",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::increaseBatchNodeCapacity(std::forward<decltype(args)>(args)...); 
        });
}

bool GJBaseGameLayerModified::init() {
    return quartz::runHookChain<bool>("GJBaseGameLayer:init",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::init(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::lightningFlash(cocos2d::CCPoint from, cocos2d::CCPoint to, cocos2d::ccColor3B color, float lineWidth, float duration, int displacement, bool flash, float opacity) {
    quartz::runHookChain<void>("GJBaseGameLayer:lightning_flash@2",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::lightningFlash(std::forward<decltype(args)>(args)...); 
        }, from, to, color, lineWidth, duration, displacement, flash, opacity);
}

void GJBaseGameLayerModified::loadGroupParentsFromString(GameObject* object, gd::string groupList) {
    quartz::runHookChain<void>("GJBaseGameLayer:load_group_parents_from_string",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::loadGroupParentsFromString(std::forward<decltype(args)>(args)...); 
        }, object, groupList);
}

void GJBaseGameLayerModified::loadLevelSettings() {
    quartz::runHookChain<void>("GJBaseGameLayer:load_level_settings",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::loadLevelSettings(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::loadStartPosObject() {
    quartz::runHookChain<void>("GJBaseGameLayer:load_start_pos_object",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::loadStartPosObject(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::loadUpToPosition(float position, int order, int channel) {
    quartz::runHookChain<void>("GJBaseGameLayer:load_up_to_position",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::loadUpToPosition(std::forward<decltype(args)>(args)...); 
        }, position, order, channel);
}

int GJBaseGameLayerModified::maxZOrderForShaderZ(int zLayer) {
    return quartz::runHookChain<int>("GJBaseGameLayer:max_zorder_for_shader_z",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::maxZOrderForShaderZ(std::forward<decltype(args)>(args)...); 
        }, zLayer);
}

int GJBaseGameLayerModified::minZOrderForShaderZ(int zLayer) {
    return quartz::runHookChain<int>("GJBaseGameLayer:min_zorder_for_shader_z",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::minZOrderForShaderZ(std::forward<decltype(args)>(args)...); 
        }, zLayer);
}

void GJBaseGameLayerModified::modifyGroupPhysics(AdvancedFollowEditObject* object, cocos2d::CCArray* group) {
    quartz::runHookChain<void>("GJBaseGameLayer:modify_group_physics",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::modifyGroupPhysics(std::forward<decltype(args)>(args)...); 
        }, object, group);
}

void GJBaseGameLayerModified::moveObjectToStaticGroup(GameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:move_object_to_static_group",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::moveObjectToStaticGroup(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::moveObjects(cocos2d::CCArray* objects, double dx, double dy, bool lockPlayerY) {
    quartz::runHookChain<void>("GJBaseGameLayer:move_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::moveObjects(std::forward<decltype(args)>(args)...); 
        }, objects, dx, dy, lockPlayerY);
}

GJGameEvent GJBaseGameLayerModified::objectTypeToGameEvent(int type) {
    return quartz::runHookChain<GJGameEvent>("GJBaseGameLayer:object_type_to_game_event",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::objectTypeToGameEvent(std::forward<decltype(args)>(args)...); 
        }, type);
}

void GJBaseGameLayerModified::objectsCollided(int blockAID, int blockBID) {
    quartz::runHookChain<void>("GJBaseGameLayer:objects_collided",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::objectsCollided(std::forward<decltype(args)>(args)...); 
        }, blockAID, blockBID);
}

float GJBaseGameLayerModified::opacityForObject(GameObject* object) {
    return quartz::runHookChain<float>("GJBaseGameLayer:opacity_for_object",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::opacityForObject(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::optimizeMoveGroups() {
    quartz::runHookChain<void>("GJBaseGameLayer:optimize_move_groups",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::optimizeMoveGroups(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::orderSpawnObjects() {
    quartz::runHookChain<void>("GJBaseGameLayer:order_spawn_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::orderSpawnObjects(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCNode* GJBaseGameLayerModified::parentForZLayer(int zLayer, bool blending, int parentMode, int uiObject) {
    return quartz::runHookChain<cocos2d::CCNode*>("GJBaseGameLayer:parent_for_zlayer",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::parentForZLayer(std::forward<decltype(args)>(args)...); 
        }, zLayer, blending, parentMode, uiObject);
}

void GJBaseGameLayerModified::pauseAudio() {
    quartz::runHookChain<void>("GJBaseGameLayer:pause_audio",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::pauseAudio(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::pickupItem(EffectGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:pickup_item",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::pickupItem(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::playExitDualEffect(PlayerObject* player) {
    quartz::runHookChain<void>("GJBaseGameLayer:play_exit_dual_effect",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::playExitDualEffect(std::forward<decltype(args)>(args)...); 
        }, player);
}

void GJBaseGameLayerModified::playKeyframeAnimation(KeyframeAnimTriggerObject* object, gd::vector<int> const& remapKeys) {
    quartz::runHookChain<void>("GJBaseGameLayer:play_keyframe_animation",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::playKeyframeAnimation(std::forward<decltype(args)>(args)...); 
        }, object, remapKeys);
}

bool GJBaseGameLayerModified::playerCircleCollision(PlayerObject* player, GameObject* object) {
    return quartz::runHookChain<bool>("GJBaseGameLayer:player_circle_collision",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::playerCircleCollision(std::forward<decltype(args)>(args)...); 
        }, player, object);
}

void GJBaseGameLayerModified::playerTouchedRing(PlayerObject* player, RingObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:player_touched_ring",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::playerTouchedRing(std::forward<decltype(args)>(args)...); 
        }, player, object);
}

void GJBaseGameLayerModified::playerTouchedTrigger(PlayerObject* player, EffectGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:player_touched_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::playerTouchedTrigger(std::forward<decltype(args)>(args)...); 
        }, player, object);
}

void GJBaseGameLayerModified::playerWillSwitchMode(PlayerObject* player, GameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:player_will_switch_mode",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::playerWillSwitchMode(std::forward<decltype(args)>(args)...); 
        }, player, object);
}

cocos2d::CCPoint GJBaseGameLayerModified::positionForShaderTarget(int groupID) {
    return quartz::runHookChain<cocos2d::CCPoint>("GJBaseGameLayer:position_for_shader_target",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::positionForShaderTarget(std::forward<decltype(args)>(args)...); 
        }, groupID);
}

void GJBaseGameLayerModified::positionUIObjects() {
    quartz::runHookChain<void>("GJBaseGameLayer:position_uiobjects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::positionUIObjects(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::preUpdateVisibility(float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:pre_update_visibility",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::preUpdateVisibility(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void GJBaseGameLayerModified::prepareSavePositionObjects() {
    quartz::runHookChain<void>("GJBaseGameLayer:prepare_save_position_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::prepareSavePositionObjects(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::processActivatedAudioTriggers(float levelTime) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_activated_audio_triggers",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processActivatedAudioTriggers(std::forward<decltype(args)>(args)...); 
        }, levelTime);
}

void GJBaseGameLayerModified::processAdvancedFollowAction(AdvancedFollowInstance& instance, bool started, float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_advanced_follow_action",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processAdvancedFollowAction(std::forward<decltype(args)>(args)...); 
        }, instance, started, dt);
}

void GJBaseGameLayerModified::processAdvancedFollowActions(float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_advanced_follow_actions",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processAdvancedFollowActions(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void GJBaseGameLayerModified::processAreaActions(float dt, bool visibleFrame) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_area_actions",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processAreaActions(std::forward<decltype(args)>(args)...); 
        }, dt, visibleFrame);
}

void GJBaseGameLayerModified::processAreaEffects(gd::vector<EnterEffectInstance>* effects, GJAreaActionType type, float dt, bool visibleFrame) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_area_effects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processAreaEffects(std::forward<decltype(args)>(args)...); 
        }, effects, type, dt, visibleFrame);
}

void GJBaseGameLayerModified::processAreaMoveGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_area_move_group_action",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processAreaMoveGroupAction(std::forward<decltype(args)>(args)...); 
        }, objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset);
}

void GJBaseGameLayerModified::processAreaRotateGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_area_rotate_group_action",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processAreaRotateGroupAction(std::forward<decltype(args)>(args)...); 
        }, objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset);
}

void GJBaseGameLayerModified::processAreaTintGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, bool targetGroups) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_area_tint_group_action",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processAreaTintGroupAction(std::forward<decltype(args)>(args)...); 
        }, objects, instance, position, targetGroups);
}

void GJBaseGameLayerModified::processAreaTransformGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_area_transform_group_action",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processAreaTransformGroupAction(std::forward<decltype(args)>(args)...); 
        }, objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset);
}

void GJBaseGameLayerModified::processCommands(float dt, bool isHalfTick, bool isLastTick) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_commands",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processCommands(std::forward<decltype(args)>(args)...); 
        }, dt, isHalfTick, isLastTick);
}

void GJBaseGameLayerModified::processDynamicObjectActions(int type, float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_dynamic_object_actions",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processDynamicObjectActions(std::forward<decltype(args)>(args)...); 
        }, type, dt);
}

void GJBaseGameLayerModified::processFollowActions() {
    quartz::runHookChain<void>("GJBaseGameLayer:process_follow_actions",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processFollowActions(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::processItems() {
    quartz::runHookChain<void>("GJBaseGameLayer:process_items",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processItems(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::processMoveActions() {
    quartz::runHookChain<void>("GJBaseGameLayer:process_move_actions",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processMoveActions(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::processMoveActionsStep(float dt, bool visibleFrame) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_move_actions_step",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processMoveActionsStep(std::forward<decltype(args)>(args)...); 
        }, dt, visibleFrame);
}

void GJBaseGameLayerModified::processOptionsTrigger(GameOptionsTrigger* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_options_trigger",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processOptionsTrigger(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::processPlayerFollowActions(float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_player_follow_actions",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processPlayerFollowActions(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void GJBaseGameLayerModified::processQueuedAudioTriggers() {
    quartz::runHookChain<void>("GJBaseGameLayer:process_queued_audio_triggers",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processQueuedAudioTriggers(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::processQueuedButtons(float dt, bool clearInputQueue) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_queued_buttons",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processQueuedButtons(std::forward<decltype(args)>(args)...); 
        }, dt, clearInputQueue);
}

void GJBaseGameLayerModified::processRotationActions() {
    quartz::runHookChain<void>("GJBaseGameLayer:process_rotation_actions",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processRotationActions(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::processSFXObjects() {
    quartz::runHookChain<void>("GJBaseGameLayer:process_sfxobjects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processSFXObjects(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::processSFXState(SFXTriggerState* state1, SFXTriggerState* state2, int type, float levelTime) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_sfxstate",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processSFXState(std::forward<decltype(args)>(args)...); 
        }, state1, state2, type, levelTime);
}

bool GJBaseGameLayerModified::processSongState(int musicID, float spawnDelay, float levelTime, int songOffset, float volume, float speed, gd::vector<SongTriggerState>* states, SongTriggerGameObject* object) {
    return quartz::runHookChain<bool>("GJBaseGameLayer:process_song_state",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processSongState(std::forward<decltype(args)>(args)...); 
        }, musicID, spawnDelay, levelTime, songOffset, volume, speed, states, object);
}

void GJBaseGameLayerModified::processTransformActions(bool visibleFrame) {
    quartz::runHookChain<void>("GJBaseGameLayer:process_transform_actions",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::processTransformActions(std::forward<decltype(args)>(args)...); 
        }, visibleFrame);
}

void GJBaseGameLayerModified::refreshCounterLabels() {
    quartz::runHookChain<void>("GJBaseGameLayer:refresh_counter_labels",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::refreshCounterLabels(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::refreshKeyframeAnims() {
    quartz::runHookChain<void>("GJBaseGameLayer:refresh_keyframe_anims",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::refreshKeyframeAnims(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::removeFromGroup(GameObject* object, int groupID) {
    quartz::runHookChain<void>("GJBaseGameLayer:remove_from_group",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::removeFromGroup(std::forward<decltype(args)>(args)...); 
        }, object, groupID);
}

void GJBaseGameLayerModified::removeFromGroups(GameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:remove_from_groups",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::removeFromGroups(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::removeGroupParent(int groupID) {
    quartz::runHookChain<void>("GJBaseGameLayer:remove_group_parent",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::removeGroupParent(std::forward<decltype(args)>(args)...); 
        }, groupID);
}

void GJBaseGameLayerModified::removeObjectFromSection(GameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:remove_object_from_section",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::removeObjectFromSection(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::removeReleasedButtons() {
    quartz::runHookChain<void>("GJBaseGameLayer:remove_released_buttons",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::removeReleasedButtons(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::resetActiveEnterEffects() {
    quartz::runHookChain<void>("GJBaseGameLayer:reset_active_enter_effects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetActiveEnterEffects(std::forward<decltype(args)>(args)...); 
        });
}

bool GJBaseGameLayerModified::resetAreaObjectValues(GameObject* object, bool update) {
    return quartz::runHookChain<bool>("GJBaseGameLayer:reset_area_object_values",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetAreaObjectValues(std::forward<decltype(args)>(args)...); 
        }, object, update);
}

void GJBaseGameLayerModified::resetAudio() {
    quartz::runHookChain<void>("GJBaseGameLayer:reset_audio",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetAudio(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::resetCamera() {
    quartz::runHookChain<void>("GJBaseGameLayer:reset_camera",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetCamera(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::resetGradientLayers() {
    quartz::runHookChain<void>("GJBaseGameLayer:reset_gradient_layers",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetGradientLayers(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::resetLevelVariables() {
    quartz::runHookChain<void>("GJBaseGameLayer:reset_level_variables",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetLevelVariables(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::resetPlayer() {
    quartz::runHookChain<void>("GJBaseGameLayer:reset_player",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetPlayer(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::resetRecord(int steps, bool noFullReset) {
    quartz::runHookChain<void>("GJBaseGameLayer:reset_record",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetRecord(std::forward<decltype(args)>(args)...); 
        }, steps, noFullReset);
}

void GJBaseGameLayerModified::resetSpawnChannelIndex() {
    quartz::runHookChain<void>("GJBaseGameLayer:reset_spawn_channel_index",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetSpawnChannelIndex(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::resetStaticCamera(bool resetX, bool resetY) {
    quartz::runHookChain<void>("GJBaseGameLayer:reset_static_camera",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resetStaticCamera(std::forward<decltype(args)>(args)...); 
        }, resetX, resetY);
}

void GJBaseGameLayerModified::restoreRemap(EffectGameObject* object, gd::unordered_map<int, int>& remap) {
    quartz::runHookChain<void>("GJBaseGameLayer:restore_remap",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::restoreRemap(std::forward<decltype(args)>(args)...); 
        }, object, remap);
}

void GJBaseGameLayerModified::resumeAudio() {
    quartz::runHookChain<void>("GJBaseGameLayer:resume_audio",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::resumeAudio(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::reverseDirection(EffectGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:reverse_direction",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::reverseDirection(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::rotateAreaObjects(GameObject* object, cocos2d::CCArray* objects, float rotation, bool reset) {
    quartz::runHookChain<void>("GJBaseGameLayer:rotate_area_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::rotateAreaObjects(std::forward<decltype(args)>(args)...); 
        }, object, objects, rotation, reset);
}

void GJBaseGameLayerModified::rotateGameplay(RotateGameplayGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:rotate_gameplay",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::rotateGameplay(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::rotateObject(GameObject* object, float rotation) {
    quartz::runHookChain<void>("GJBaseGameLayer:rotate_object",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::rotateObject(std::forward<decltype(args)>(args)...); 
        }, object, rotation);
}

void GJBaseGameLayerModified::rotateObjects(cocos2d::CCArray* objects, float rotation, cocos2d::CCPoint position, cocos2d::CCPoint offset, bool finished, bool unused) {
    quartz::runHookChain<void>("GJBaseGameLayer:rotate_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::rotateObjects(std::forward<decltype(args)>(args)...); 
        }, objects, rotation, position, offset, finished, unused);
}

void GJBaseGameLayerModified::setGroupParent(GameObject* object, int groupID) {
    quartz::runHookChain<void>("GJBaseGameLayer:set_group_parent",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::setGroupParent(std::forward<decltype(args)>(args)...); 
        }, object, groupID);
}

void GJBaseGameLayerModified::setupLayers() {
    quartz::runHookChain<void>("GJBaseGameLayer:setup_layers",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::setupLayers(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::setupLevelStart(LevelSettingsObject* settings) {
    quartz::runHookChain<void>("GJBaseGameLayer:setup_level_start",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::setupLevelStart(std::forward<decltype(args)>(args)...); 
        }, settings);
}

void GJBaseGameLayerModified::shakeCamera(float duration, float strength, float interval) {
    quartz::runHookChain<void>("GJBaseGameLayer:shake_camera",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::shakeCamera(std::forward<decltype(args)>(args)...); 
        }, duration, strength, interval);
}

bool GJBaseGameLayerModified::shouldExitHackedLevel() {
    return quartz::runHookChain<bool>("GJBaseGameLayer:should_exit_hacked_level",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::shouldExitHackedLevel(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::sortGroups() {
    quartz::runHookChain<void>("GJBaseGameLayer:sort_groups",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::sortGroups(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::sortSectionVector() {
    quartz::runHookChain<void>("GJBaseGameLayer:sort_section_vector",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::sortSectionVector(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::sortStickyGroups() {
    quartz::runHookChain<void>("GJBaseGameLayer:sort_sticky_groups",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::sortStickyGroups(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::spawnGroup(int group, bool ordered, double delay, gd::vector<int> const& remapKeys, int triggerID, int controlID) {
    quartz::runHookChain<void>("GJBaseGameLayer:spawn_group",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::spawnGroup(std::forward<decltype(args)>(args)...); 
        }, group, ordered, delay, remapKeys, triggerID, controlID);
}

void GJBaseGameLayerModified::spawnObject(GameObject* object, double delay, gd::vector<int> const& remapKeys) {
    quartz::runHookChain<void>("GJBaseGameLayer:spawn_object",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::spawnObject(std::forward<decltype(args)>(args)...); 
        }, object, delay, remapKeys);
}

void GJBaseGameLayerModified::spawnObjectsInOrder(cocos2d::CCArray* objects, double delay, gd::vector<int> const& remapKeys, int uniqueID, int controlID) {
    quartz::runHookChain<void>("GJBaseGameLayer:spawn_objects_in_order",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::spawnObjectsInOrder(std::forward<decltype(args)>(args)...); 
        }, objects, delay, remapKeys, uniqueID, controlID);
}

cocos2d::CCParticleSystemQuad* GJBaseGameLayerModified::spawnParticle(char const* plist, int zOrder, cocos2d::tCCPositionType positionType, cocos2d::CCPoint position) {
    return quartz::runHookChain<cocos2d::CCParticleSystemQuad*>("GJBaseGameLayer:spawn_particle",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::spawnParticle(std::forward<decltype(args)>(args)...); 
        }, plist, zOrder, positionType, position);
}

void GJBaseGameLayerModified::spawnParticleTrigger(int particleID, cocos2d::CCPoint position, float rotation, float scale) {
    quartz::runHookChain<void>("GJBaseGameLayer:spawn_particle_trigger@2",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::spawnParticleTrigger(std::forward<decltype(args)>(args)...); 
        }, particleID, position, rotation, scale);
}

cocos2d::CCPoint GJBaseGameLayerModified::speedForShaderTarget(int groupID) {
    return quartz::runHookChain<cocos2d::CCPoint>("GJBaseGameLayer:speed_for_shader_target",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::speedForShaderTarget(std::forward<decltype(args)>(args)...); 
        }, groupID);
}

cocos2d::CCArray* GJBaseGameLayerModified::staticObjectsInRect(cocos2d::CCRect rect, bool enabledGroups) {
    return quartz::runHookChain<cocos2d::CCArray*>("GJBaseGameLayer:static_objects_in_rect",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::staticObjectsInRect(std::forward<decltype(args)>(args)...); 
        }, rect, enabledGroups);
}

void GJBaseGameLayerModified::stopCustomEnterEffect(EnterEffectObject* object, bool enter) {
    quartz::runHookChain<void>("GJBaseGameLayer:stop_custom_enter_effect@2",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::stopCustomEnterEffect(std::forward<decltype(args)>(args)...); 
        }, object, enter);
}

void GJBaseGameLayerModified::switchToRobotMode(PlayerObject* player, GameObject* object, bool noPortal) {
    quartz::runHookChain<void>("GJBaseGameLayer:switch_to_robot_mode",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::switchToRobotMode(std::forward<decltype(args)>(args)...); 
        }, player, object, noPortal);
}

void GJBaseGameLayerModified::switchToRollMode(PlayerObject* player, GameObject* object, bool noPortal) {
    quartz::runHookChain<void>("GJBaseGameLayer:switch_to_roll_mode",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::switchToRollMode(std::forward<decltype(args)>(args)...); 
        }, player, object, noPortal);
}

void GJBaseGameLayerModified::switchToSpiderMode(PlayerObject* player, GameObject* object, bool noPortal) {
    quartz::runHookChain<void>("GJBaseGameLayer:switch_to_spider_mode",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::switchToSpiderMode(std::forward<decltype(args)>(args)...); 
        }, player, object, noPortal);
}

void GJBaseGameLayerModified::syncBGTextures() {
    quartz::runHookChain<void>("GJBaseGameLayer:sync_bgtextures",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::syncBGTextures(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::teleportPlayer(TeleportPortalObject* object, PlayerObject* player) {
    quartz::runHookChain<void>("GJBaseGameLayer:teleport_player",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::teleportPlayer(std::forward<decltype(args)>(args)...); 
        }, object, player);
}

void GJBaseGameLayerModified::toggleAudioVisualizer(bool visible) {
    quartz::runHookChain<void>("GJBaseGameLayer:toggle_audio_visualizer",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::toggleAudioVisualizer(std::forward<decltype(args)>(args)...); 
        }, visible);
}

void GJBaseGameLayerModified::toggleDualMode(GameObject* object, bool dual, PlayerObject* player, bool noEffects) {
    quartz::runHookChain<void>("GJBaseGameLayer:toggle_dual_mode",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::toggleDualMode(std::forward<decltype(args)>(args)...); 
        }, object, dual, player, noEffects);
}

void GJBaseGameLayerModified::toggleFlipped(bool flip, bool noEffects) {
    quartz::runHookChain<void>("GJBaseGameLayer:toggle_flipped",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::toggleFlipped(std::forward<decltype(args)>(args)...); 
        }, flip, noEffects);
}

void GJBaseGameLayerModified::toggleGroup(int id, bool activate) {
    quartz::runHookChain<void>("GJBaseGameLayer:toggle_group",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::toggleGroup(std::forward<decltype(args)>(args)...); 
        }, id, activate);
}

void GJBaseGameLayerModified::toggleGroupTriggered(int group, bool activate, gd::vector<int> const& remapKeys, int triggerID, int controlID) {
    quartz::runHookChain<void>("GJBaseGameLayer:toggle_group_triggered",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::toggleGroupTriggered(std::forward<decltype(args)>(args)...); 
        }, group, activate, remapKeys, triggerID, controlID);
}

void GJBaseGameLayerModified::transformAreaObjects(GameObject* object, cocos2d::CCArray* objects, float scaleX, float scaleY, bool reset) {
    quartz::runHookChain<void>("GJBaseGameLayer:transform_area_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::transformAreaObjects(std::forward<decltype(args)>(args)...); 
        }, object, objects, scaleX, scaleY, reset);
}

void GJBaseGameLayerModified::triggerAdvancedFollowEditCommand(AdvancedFollowEditObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:trigger_advanced_follow_edit_command",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::triggerAdvancedFollowEditCommand(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::triggerAreaEffect(EnterEffectObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:trigger_area_effect",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::triggerAreaEffect(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::triggerDynamicRotateCommand(EnhancedTriggerObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:trigger_dynamic_rotate_command",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::triggerDynamicRotateCommand(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::triggerGradientCommand(GradientTriggerObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:trigger_gradient_command",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::triggerGradientCommand(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::triggerMoveCommand(EffectGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:trigger_move_command",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::triggerMoveCommand(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::triggerShaderCommand(ShaderGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:trigger_shader_command",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::triggerShaderCommand(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::triggerTransformCommand(TransformTriggerGameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:trigger_transform_command",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::triggerTransformCommand(std::forward<decltype(args)>(args)...); 
        }, object);
}

GameObject* GJBaseGameLayerModified::tryGetMainObject(int groupID) {
    return quartz::runHookChain<GameObject*>("GJBaseGameLayer:try_get_main_object",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::tryGetMainObject(std::forward<decltype(args)>(args)...); 
        }, groupID);
}

GameObject* GJBaseGameLayerModified::tryGetObject(int groupID) {
    return quartz::runHookChain<GameObject*>("GJBaseGameLayer:try_get_object",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::tryGetObject(std::forward<decltype(args)>(args)...); 
        }, groupID);
}

void GJBaseGameLayerModified::unclaimCustomParticle(gd::string const& key, cocos2d::CCParticleSystemQuad* particle) {
    quartz::runHookChain<void>("GJBaseGameLayer:unclaim_custom_particle",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::unclaimCustomParticle(std::forward<decltype(args)>(args)...); 
        }, key, particle);
}

void GJBaseGameLayerModified::unclaimParticle(char const* key, cocos2d::CCParticleSystemQuad* particle) {
    quartz::runHookChain<void>("GJBaseGameLayer:unclaim_particle",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::unclaimParticle(std::forward<decltype(args)>(args)...); 
        }, key, particle);
}

void GJBaseGameLayerModified::ungroupStickyObjects(cocos2d::CCArray* objects) {
    quartz::runHookChain<void>("GJBaseGameLayer:ungroup_sticky_objects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::ungroupStickyObjects(std::forward<decltype(args)>(args)...); 
        }, objects);
}

void GJBaseGameLayerModified::update(float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:update",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::update(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void GJBaseGameLayerModified::updateAudioVisualizer() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_audio_visualizer",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateAudioVisualizer(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateCamera(float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_camera",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateCamera(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void GJBaseGameLayerModified::updateCameraBGArt(cocos2d::CCPoint position, float zoom) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_camera_bgart",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateCameraBGArt(std::forward<decltype(args)>(args)...); 
        }, position, zoom);
}

void GJBaseGameLayerModified::updateCameraOffsetX(float offsetX, float duration, int easingType, float easingRate, int uniqueID, int controlID) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_camera_offset_x",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateCameraOffsetX(std::forward<decltype(args)>(args)...); 
        }, offsetX, duration, easingType, easingRate, uniqueID, controlID);
}

void GJBaseGameLayerModified::updateCameraOffsetY(float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_camera_offset_y",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateCameraOffsetY(std::forward<decltype(args)>(args)...); 
        }, offsetY, duration, easingType, easingRate, uniqueID, controlID);
}

void GJBaseGameLayerModified::updateCollisionBlocks() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_collision_blocks",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateCollisionBlocks(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_color",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateColor(std::forward<decltype(args)>(args)...); 
        }, color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2);
}

void GJBaseGameLayerModified::updateCounters(int itemId, int value) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_counters",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateCounters(std::forward<decltype(args)>(args)...); 
        }, itemId, value);
}

void GJBaseGameLayerModified::updateDebugDraw() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_debug_draw",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateDebugDraw(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateDualGround(PlayerObject* object, int mode, bool instant, float duration) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_dual_ground",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateDualGround(std::forward<decltype(args)>(args)...); 
        }, object, mode, instant, duration);
}

void GJBaseGameLayerModified::updateEnterEffects(float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_enter_effects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateEnterEffects(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void GJBaseGameLayerModified::updateExtraGameLayers() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_extra_game_layers",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateExtraGameLayers(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateGradientLayers() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_gradient_layers",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateGradientLayers(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateGroundShadows() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_ground_shadows",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateGroundShadows(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateGuideArt() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_guide_art",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateGuideArt(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateKeyframeOrder(int keyframeGroup) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_keyframe_order",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateKeyframeOrder(std::forward<decltype(args)>(args)...); 
        }, keyframeGroup);
}

void GJBaseGameLayerModified::updateLayerCapacity(gd::string capacityString) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_layer_capacity",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateLayerCapacity(std::forward<decltype(args)>(args)...); 
        }, capacityString);
}

void GJBaseGameLayerModified::updateLevelColors() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_level_colors",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateLevelColors(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateMGOffsetY(float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_mgoffset_y",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateMGOffsetY(std::forward<decltype(args)>(args)...); 
        }, offsetY, duration, easingType, easingRate, uniqueID, controlID);
}

void GJBaseGameLayerModified::updateMaxGameplayY() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_max_gameplay_y",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateMaxGameplayY(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateObjectSection(GameObject* object) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_object_section",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateObjectSection(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GJBaseGameLayerModified::updateParticles(float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_particles",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateParticles(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void GJBaseGameLayerModified::updatePlatformerTime() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_platformer_time",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updatePlatformerTime(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updatePlayerCollisionBlocks() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_player_collision_blocks",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updatePlayerCollisionBlocks(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateProximityVolumeEffects() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_proximity_volume_effects",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateProximityVolumeEffects(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateScreenRotation(float rotation, bool add, bool convert, float duration, int easingType, float easingRate, int uniqueID, int controlID) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_screen_rotation",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateScreenRotation(std::forward<decltype(args)>(args)...); 
        }, rotation, add, convert, duration, easingType, easingRate, uniqueID, controlID);
}

void GJBaseGameLayerModified::updateShaderLayer(float dt) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_shader_layer",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateShaderLayer(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void GJBaseGameLayerModified::updateSpecialGroupData() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_special_group_data",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateSpecialGroupData(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateSpecialLabels() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_special_labels",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateSpecialLabels(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateStaticCameraPos(cocos2d::CCPoint pos, bool staticX, bool staticY, bool followOrSmoothEase, float time, int easingType, float easingRate) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_static_camera_pos",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateStaticCameraPos(std::forward<decltype(args)>(args)...); 
        }, pos, staticX, staticY, followOrSmoothEase, time, easingType, easingRate);
}

void GJBaseGameLayerModified::updateStaticCameraPosToGroup(int centerID, bool updateX, bool updateY, bool followObject, float followEase, float duration, int easingType, float easingRate, bool smoothVelocity, float velocityMod) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_static_camera_pos_to_group",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateStaticCameraPosToGroup(std::forward<decltype(args)>(args)...); 
        }, centerID, updateX, updateY, followObject, followEase, duration, easingType, easingRate, smoothVelocity, velocityMod);
}

void GJBaseGameLayerModified::updateTimeWarp(float timeWarp) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_time_warp",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateTimeWarp(std::forward<decltype(args)>(args)...); 
        }, timeWarp);
}

void GJBaseGameLayerModified::updateTimerLabels() {
    quartz::runHookChain<void>("GJBaseGameLayer:update_timer_labels",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateTimerLabels(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::updateZoom(float zoom, float duration, int easing, float rate, int uniqueID, int controlID) {
    quartz::runHookChain<void>("GJBaseGameLayer:update_zoom",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::updateZoom(std::forward<decltype(args)>(args)...); 
        }, zoom, duration, easing, rate, uniqueID, controlID);
}

void GJBaseGameLayerModified::visit() {
    quartz::runHookChain<void>("GJBaseGameLayer:visit",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::visit(std::forward<decltype(args)>(args)...); 
        });
}

void GJBaseGameLayerModified::visitWithColorFlash() {
    quartz::runHookChain<void>("GJBaseGameLayer:visit_with_color_flash",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::visitWithColorFlash(std::forward<decltype(args)>(args)...); 
        });
}

float GJBaseGameLayerModified::volumeForProximityEffect(SFXTriggerInstance& instance) {
    return quartz::runHookChain<float>("GJBaseGameLayer:volume_for_proximity_effect",
        static_cast<GJBaseGameLayer*>(this),
        [](GJBaseGameLayer* self, auto&&... args) -> decltype(auto) {
            return self->GJBaseGameLayer::volumeForProximityEffect(std::forward<decltype(args)>(args)...); 
        }, instance);
}

} // namespace quartz