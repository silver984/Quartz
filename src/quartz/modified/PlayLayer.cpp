#include <quartz/modified/PlayLayer.hpp>
#include <quartz/core/Templates.hpp>
#include <utility>

namespace quartz {

void PlayLayerModified::activatePlatformerEndTrigger(EndTriggerGameObject* object, gd::vector<int> const& remapKeys) {
    quartz::runHookChain<void>("PlayLayer:activate_platformer_end_trigger",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::activatePlatformerEndTrigger(std::forward<decltype(args)>(args)...); 
        }, object, remapKeys);
}

void PlayLayerModified::addObject(GameObject* object) {
    quartz::runHookChain<void>("PlayLayer:add_object",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::addObject(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayLayerModified::applyCustomEnterEffect(GameObject* object, bool isRight) {
    quartz::runHookChain<void>("PlayLayer:apply_custom_enter_effect",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::applyCustomEnterEffect(std::forward<decltype(args)>(args)...); 
        }, object, isRight);
}

void PlayLayerModified::applyEnterEffect(GameObject* object, int enterType, bool isRight) {
    quartz::runHookChain<void>("PlayLayer:apply_enter_effect",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::applyEnterEffect(std::forward<decltype(args)>(args)...); 
        }, object, enterType, isRight);
}

void PlayLayerModified::checkForEnd() {
    quartz::runHookChain<void>("PlayLayer:check_for_end",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::checkForEnd(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::checkpointActivated(CheckpointGameObject* object) {
    quartz::runHookChain<void>("PlayLayer:checkpoint_activated",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::checkpointActivated(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayLayerModified::circleWaveWillBeRemoved(CCCircleWave* circleWave) {
    quartz::runHookChain<void>("PlayLayer:circle_wave_will_be_removed",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::circleWaveWillBeRemoved(std::forward<decltype(args)>(args)...); 
        }, circleWave);
}

CheckpointObject* PlayLayerModified::createCheckpoint() {
    return quartz::runHookChain<CheckpointObject*>("PlayLayer:create_checkpoint",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::createCheckpoint(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::createObjectsFromSetupFinished() {
    quartz::runHookChain<void>("PlayLayer:create_objects_from_setup_finished",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::createObjectsFromSetupFinished(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::currencyWillExit(CurrencyRewardLayer* layer) {
    quartz::runHookChain<void>("PlayLayer:currency_will_exit",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::currencyWillExit(std::forward<decltype(args)>(args)...); 
        }, layer);
}

void PlayLayerModified::delayedResetLevel() {
    quartz::runHookChain<void>("PlayLayer:delayed_reset_level",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::delayedResetLevel(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::destroyPlayer(PlayerObject* player, GameObject* object) {
    quartz::runHookChain<void>("PlayLayer:destroy_player",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::destroyPlayer(std::forward<decltype(args)>(args)...); 
        }, player, object);
}

void PlayLayerModified::dialogClosed(DialogLayer* layer) {
    quartz::runHookChain<void>("PlayLayer:dialog_closed",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::dialogClosed(std::forward<decltype(args)>(args)...); 
        }, layer);
}

void PlayLayerModified::flipArt(bool flip) {
    quartz::runHookChain<void>("PlayLayer:flip_art",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::flipArt(std::forward<decltype(args)>(args)...); 
        }, flip);
}

void PlayLayerModified::fullReset() {
    quartz::runHookChain<void>("PlayLayer:full_reset",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::fullReset(std::forward<decltype(args)>(args)...); 
        });
}

float PlayLayerModified::getCurrentPercent() {
    return quartz::runHookChain<float>("PlayLayer:get_current_percent",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::getCurrentPercent(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::gravityEffectFinished() {
    quartz::runHookChain<void>("PlayLayer:gravity_effect_finished",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::gravityEffectFinished(std::forward<decltype(args)>(args)...); 
        });
}

bool PlayLayerModified::init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
    return quartz::runHookChain<bool>("PlayLayer:init",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::init(std::forward<decltype(args)>(args)...); 
        }, level, useReplay, dontCreateObjects);
}

void PlayLayerModified::levelComplete() {
    quartz::runHookChain<void>("PlayLayer:level_complete",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::levelComplete(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::loadDefaultColors() {
    quartz::runHookChain<void>("PlayLayer:load_default_colors",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::loadDefaultColors(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::loadFromCheckpoint(CheckpointObject* object) {
    quartz::runHookChain<void>("PlayLayer:load_from_checkpoint",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::loadFromCheckpoint(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayLayerModified::manualUpdateObjectColors(GameObject* object) {
    quartz::runHookChain<void>("PlayLayer:manual_update_object_colors",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::manualUpdateObjectColors(std::forward<decltype(args)>(args)...); 
        }, object);
}

CheckpointObject* PlayLayerModified::markCheckpoint() {
    return quartz::runHookChain<CheckpointObject*>("PlayLayer:mark_checkpoint",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::markCheckpoint(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::onEnterTransitionDidFinish() {
    quartz::runHookChain<void>("PlayLayer:on_enter_transition_did_finish",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::onEnterTransitionDidFinish(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::onExit() {
    quartz::runHookChain<void>("PlayLayer:on_exit",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::onExit(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::onQuit() {
    quartz::runHookChain<void>("PlayLayer:on_quit",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::onQuit(std::forward<decltype(args)>(args)...); 
        });
}

float PlayLayerModified::opacityForObject(GameObject* object) {
    return quartz::runHookChain<float>("PlayLayer:opacity_for_object",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::opacityForObject(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayLayerModified::optimizeColorGroups() {
    quartz::runHookChain<void>("PlayLayer:optimize_color_groups",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::optimizeColorGroups(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::optimizeOpacityGroups() {
    quartz::runHookChain<void>("PlayLayer:optimize_opacity_groups",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::optimizeOpacityGroups(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::pauseGame(bool unfocused) {
    quartz::runHookChain<void>("PlayLayer:pause_game",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::pauseGame(std::forward<decltype(args)>(args)...); 
        }, unfocused);
}

void PlayLayerModified::playEndAnimationToPos(cocos2d::CCPoint position) {
    quartz::runHookChain<void>("PlayLayer:play_end_animation_to_pos",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::playEndAnimationToPos(std::forward<decltype(args)>(args)...); 
        }, position);
}

void PlayLayerModified::playGravityEffect(bool flip) {
    quartz::runHookChain<void>("PlayLayer:play_gravity_effect",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::playGravityEffect(std::forward<decltype(args)>(args)...); 
        }, flip);
}

void PlayLayerModified::playPlatformerEndAnimationToPos(cocos2d::CCPoint position, bool instant) {
    quartz::runHookChain<void>("PlayLayer:play_platformer_end_animation_to_pos",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::playPlatformerEndAnimationToPos(std::forward<decltype(args)>(args)...); 
        }, position, instant);
}

cocos2d::CCPoint PlayLayerModified::posForTime(float time) {
    return quartz::runHookChain<cocos2d::CCPoint>("PlayLayer:pos_for_time",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::posForTime(std::forward<decltype(args)>(args)...); 
        }, time);
}

void PlayLayerModified::postUpdate(float dt) {
    quartz::runHookChain<void>("PlayLayer:post_update",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::postUpdate(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void PlayLayerModified::prepareCreateObjectsFromSetup(gd::string& levelString) {
    quartz::runHookChain<void>("PlayLayer:prepare_create_objects_from_setup",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::prepareCreateObjectsFromSetup(std::forward<decltype(args)>(args)...); 
        }, levelString);
}

void PlayLayerModified::prepareMusic(bool dontWait) {
    quartz::runHookChain<void>("PlayLayer:prepare_music",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::prepareMusic(std::forward<decltype(args)>(args)...); 
        }, dontWait);
}

void PlayLayerModified::processCheckpoints() {
    quartz::runHookChain<void>("PlayLayer:process_checkpoints",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::processCheckpoints(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::processCreateObjectsFromSetup() {
    quartz::runHookChain<void>("PlayLayer:process_create_objects_from_setup",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::processCreateObjectsFromSetup(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::processLoadedMoveActions() {
    quartz::runHookChain<void>("PlayLayer:process_loaded_move_actions",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::processLoadedMoveActions(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::removeAllCheckpoints() {
    quartz::runHookChain<void>("PlayLayer:remove_all_checkpoints",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::removeAllCheckpoints(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::removeAllObjects() {
    quartz::runHookChain<void>("PlayLayer:remove_all_objects",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::removeAllObjects(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::removeCheckpoint(bool first) {
    quartz::runHookChain<void>("PlayLayer:remove_checkpoint",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::removeCheckpoint(std::forward<decltype(args)>(args)...); 
        }, first);
}

void PlayLayerModified::resetLevel() {
    quartz::runHookChain<void>("PlayLayer:reset_level",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::resetLevel(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::resetLevelFromStart() {
    quartz::runHookChain<void>("PlayLayer:reset_level_from_start",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::resetLevelFromStart(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::resetSPTriggered() {
    quartz::runHookChain<void>("PlayLayer:reset_sptriggered",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::resetSPTriggered(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::resume() {
    quartz::runHookChain<void>("PlayLayer:resume",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::resume(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::resumeAndRestart(bool fromStart) {
    quartz::runHookChain<void>("PlayLayer:resume_and_restart",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::resumeAndRestart(std::forward<decltype(args)>(args)...); 
        }, fromStart);
}

void PlayLayerModified::saveActiveSaveObjects(gd::vector<SavedActiveObjectState>& activeObjects, gd::vector<SavedSpecialObjectState>& specialObjects) {
    quartz::runHookChain<void>("PlayLayer:save_active_save_objects",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::saveActiveSaveObjects(std::forward<decltype(args)>(args)...); 
        }, activeObjects, specialObjects);
}

void PlayLayerModified::saveDynamicSaveObjects(gd::vector<SavedObjectStateRef>& dynamicObjects) {
    quartz::runHookChain<void>("PlayLayer:save_dynamic_save_objects",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::saveDynamicSaveObjects(std::forward<decltype(args)>(args)...); 
        }, dynamicObjects);
}

void PlayLayerModified::scanDynamicSaveObjects() {
    quartz::runHookChain<void>("PlayLayer:scan_dynamic_save_objects",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::scanDynamicSaveObjects(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCScene* PlayLayerModified::scene(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
    return quartz::runStaticHookChain<cocos2d::CCScene*>("PlayLayer.scene",
        &PlayLayer::scene,
        level, useReplay, dontCreateObjects);
}

void PlayLayerModified::screenFlipObject(GameObject* object) {
    quartz::runHookChain<void>("PlayLayer:screen_flip_object",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::screenFlipObject(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayLayerModified::setupHasCompleted() {
    quartz::runHookChain<void>("PlayLayer:setup_has_completed",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::setupHasCompleted(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::showCompleteEffect() {
    quartz::runHookChain<void>("PlayLayer:show_complete_effect",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::showCompleteEffect(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::showCompleteText() {
    quartz::runHookChain<void>("PlayLayer:show_complete_text",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::showCompleteText(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::showEndLayer() {
    quartz::runHookChain<void>("PlayLayer:show_end_layer",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::showEndLayer(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::showHint() {
    quartz::runHookChain<void>("PlayLayer:show_hint",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::showHint(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::showNewBest(bool newReward, int orbs, int diamonds, bool demonKey, bool noRetry, bool noTitle) {
    quartz::runHookChain<void>("PlayLayer:show_new_best",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::showNewBest(std::forward<decltype(args)>(args)...); 
        }, newReward, orbs, diamonds, demonKey, noRetry, noTitle);
}

void PlayLayerModified::showRetryLayer() {
    quartz::runHookChain<void>("PlayLayer:show_retry_layer",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::showRetryLayer(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::showTwoPlayerGuide() {
    quartz::runHookChain<void>("PlayLayer:show_two_player_guide",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::showTwoPlayerGuide(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::spawnCircle() {
    quartz::runHookChain<void>("PlayLayer:spawn_circle",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::spawnCircle(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::spawnFirework() {
    quartz::runHookChain<void>("PlayLayer:spawn_firework",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::spawnFirework(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::startGame() {
    quartz::runHookChain<void>("PlayLayer:start_game",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::startGame(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::startGameDelayed() {
    quartz::runHookChain<void>("PlayLayer:start_game_delayed",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::startGameDelayed(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::startMusic() {
    quartz::runHookChain<void>("PlayLayer:start_music",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::startMusic(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::storeCheckpoint(CheckpointObject* checkpoint) {
    quartz::runHookChain<void>("PlayLayer:store_checkpoint",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::storeCheckpoint(std::forward<decltype(args)>(args)...); 
        }, checkpoint);
}

float PlayLayerModified::timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id) {
    return quartz::runHookChain<float>("PlayLayer:time_for_pos",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::timeForPos(std::forward<decltype(args)>(args)...); 
        }, position, order, channel, songTriggers, id);
}

void PlayLayerModified::toggleDebugDraw() {
    quartz::runHookChain<void>("PlayLayer:toggle_debug_draw",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::toggleDebugDraw(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::toggleGlitter(bool visible) {
    quartz::runHookChain<void>("PlayLayer:toggle_glitter",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::toggleGlitter(std::forward<decltype(args)>(args)...); 
        }, visible);
}

void PlayLayerModified::toggleGroundVisibility(bool visible) {
    quartz::runHookChain<void>("PlayLayer:toggle_ground_visibility",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::toggleGroundVisibility(std::forward<decltype(args)>(args)...); 
        }, visible);
}

void PlayLayerModified::toggleHideAttempts(bool hide) {
    quartz::runHookChain<void>("PlayLayer:toggle_hide_attempts",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::toggleHideAttempts(std::forward<decltype(args)>(args)...); 
        }, hide);
}

void PlayLayerModified::toggleInfoLabel() {
    quartz::runHookChain<void>("PlayLayer:toggle_info_label",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::toggleInfoLabel(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::toggleMGVisibility(bool visible) {
    quartz::runHookChain<void>("PlayLayer:toggle_mgvisibility",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::toggleMGVisibility(std::forward<decltype(args)>(args)...); 
        }, visible);
}

void PlayLayerModified::toggleMusicInPractice() {
    quartz::runHookChain<void>("PlayLayer:toggle_music_in_practice",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::toggleMusicInPractice(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::togglePracticeMode(bool practiceMode) {
    quartz::runHookChain<void>("PlayLayer:toggle_practice_mode",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::togglePracticeMode(std::forward<decltype(args)>(args)...); 
        }, practiceMode);
}

void PlayLayerModified::toggleProgressbar() {
    quartz::runHookChain<void>("PlayLayer:toggle_progressbar",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::toggleProgressbar(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::updateAttemptTime(float attemptTime) {
    quartz::runHookChain<void>("PlayLayer:update_attempt_time",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateAttemptTime(std::forward<decltype(args)>(args)...); 
        }, attemptTime);
}

void PlayLayerModified::updateAttempts() {
    quartz::runHookChain<void>("PlayLayer:update_attempts",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateAttempts(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2) {
    quartz::runHookChain<void>("PlayLayer:update_color",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateColor(std::forward<decltype(args)>(args)...); 
        }, color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2);
}

void PlayLayerModified::updateDebugDrawSettings() {
    quartz::runHookChain<void>("PlayLayer:update_debug_draw_settings",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateDebugDrawSettings(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::updateInfoLabel() {
    quartz::runHookChain<void>("PlayLayer:update_info_label",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateInfoLabel(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::updateInvisibleBlock(GameObject* object, float rightFadeBound, float leftFadeBound, float rightFadeWidth, float leftFadeWidth, cocos2d::ccColor3B const& lbgColor) {
    quartz::runHookChain<void>("PlayLayer:update_invisible_block",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateInvisibleBlock(std::forward<decltype(args)>(args)...); 
        }, object, rightFadeBound, leftFadeBound, rightFadeWidth, leftFadeWidth, lbgColor);
}

void PlayLayerModified::updateProgressbar() {
    quartz::runHookChain<void>("PlayLayer:update_progressbar",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateProgressbar(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::updateTestModeLabel() {
    quartz::runHookChain<void>("PlayLayer:update_test_mode_label",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateTestModeLabel(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::updateTimeLabel(int seconds, int centiseconds, bool decimals) {
    quartz::runHookChain<void>("PlayLayer:update_time_label",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateTimeLabel(std::forward<decltype(args)>(args)...); 
        }, seconds, centiseconds, decimals);
}

void PlayLayerModified::updateTimeWarp(float timeWarp) {
    quartz::runHookChain<void>("PlayLayer:update_time_warp",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateTimeWarp(std::forward<decltype(args)>(args)...); 
        }, timeWarp);
}

void PlayLayerModified::updateVerifyDamage() {
    quartz::runHookChain<void>("PlayLayer:update_verify_damage",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateVerifyDamage(std::forward<decltype(args)>(args)...); 
        });
}

void PlayLayerModified::updateVisibility(float dt) {
    quartz::runHookChain<void>("PlayLayer:update_visibility",
        static_cast<PlayLayer*>(this),
        [](PlayLayer* self, auto&&... args) -> decltype(auto) {
            return self->PlayLayer::updateVisibility(std::forward<decltype(args)>(args)...); 
        }, dt);
}

} // namespace quartz