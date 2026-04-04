#pragma once
#include <Geode/modify/PlayLayer.hpp>
#include <quartz/core/LuaFields.hpp>

namespace quartz {

struct PlayLayerModified : geode::Modify<PlayLayerModified, PlayLayer>, quartz::LuaFields {
    // @lua "PlayLayer:activate_platformer_end_trigger"
    void activatePlatformerEndTrigger(EndTriggerGameObject* object, gd::vector<int> const& remapKeys) override;

    // @lua "PlayLayer:add_object"
    void addObject(GameObject* object);

    // @lua "PlayLayer:apply_custom_enter_effect"
    void applyCustomEnterEffect(GameObject* object, bool isRight);

    // @lua "PlayLayer:apply_enter_effect"
    void applyEnterEffect(GameObject* object, int enterType, bool isRight);

    // @lua "PlayLayer:check_for_end"
    void checkForEnd() override;

    // @lua "PlayLayer:checkpoint_activated"
    void checkpointActivated(CheckpointGameObject* object) override;

    // @lua "PlayLayer:circle_wave_will_be_removed"
    void circleWaveWillBeRemoved(CCCircleWave* circleWave) override;

    // @lua "PlayLayer:create_checkpoint"
    CheckpointObject* createCheckpoint();

    // @lua "PlayLayer:create_objects_from_setup_finished"
    void createObjectsFromSetupFinished();

    // @lua "PlayLayer:currency_will_exit"
    void currencyWillExit(CurrencyRewardLayer* layer) override;

    // @lua "PlayLayer:delayed_reset_level"
    void delayedResetLevel();

    // @lua "PlayLayer:destroy_player"
    void destroyPlayer(PlayerObject* player, GameObject* object) override;

    // @lua "PlayLayer:dialog_closed"
    void dialogClosed(DialogLayer* layer) override;

    // @lua "PlayLayer:flip_art"
    void flipArt(bool flip) override;

    // @lua "PlayLayer:full_reset"
    void fullReset();

    // @lua "PlayLayer:get_current_percent"
    float getCurrentPercent();

    // @lua "PlayLayer:gravity_effect_finished"
    void gravityEffectFinished();

    // @lua "PlayLayer:init"
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects);

    // @lua "PlayLayer:level_complete"
    void levelComplete();

    // @lua "PlayLayer:load_default_colors"
    void loadDefaultColors();

    // @lua "PlayLayer:load_from_checkpoint"
    void loadFromCheckpoint(CheckpointObject* object);

    // @lua "PlayLayer:manual_update_object_colors"
    void manualUpdateObjectColors(GameObject* object) override;

    // @lua "PlayLayer:mark_checkpoint"
    CheckpointObject* markCheckpoint();

    // @lua "PlayLayer:on_enter_transition_did_finish"
    void onEnterTransitionDidFinish() override;

    // @lua "PlayLayer:on_exit"
    void onExit() override;

    // @lua "PlayLayer:on_quit"
    void onQuit();

    // @lua "PlayLayer:opacity_for_object"
    float opacityForObject(GameObject* object) override;

    // @lua "PlayLayer:optimize_color_groups"
    void optimizeColorGroups();

    // @lua "PlayLayer:optimize_opacity_groups"
    void optimizeOpacityGroups();

    // @lua "PlayLayer:pause_game"
    void pauseGame(bool unfocused);

    // @lua "PlayLayer:play_end_animation_to_pos"
    void playEndAnimationToPos(cocos2d::CCPoint position);

    // @lua "PlayLayer:play_gravity_effect"
    void playGravityEffect(bool flip) override;

    // @lua "PlayLayer:play_platformer_end_animation_to_pos"
    void playPlatformerEndAnimationToPos(cocos2d::CCPoint position, bool instant);

    // @lua "PlayLayer:pos_for_time"
    cocos2d::CCPoint posForTime(float time) override;

    // @lua "PlayLayer:post_update"
    void postUpdate(float dt) override;

    // @lua "PlayLayer:prepare_create_objects_from_setup"
    void prepareCreateObjectsFromSetup(gd::string& levelString);

    // @lua "PlayLayer:prepare_music"
    void prepareMusic(bool dontWait);

    // @lua "PlayLayer:process_checkpoints"
    void processCheckpoints() override;

    // @lua "PlayLayer:process_create_objects_from_setup"
    void processCreateObjectsFromSetup();

    // @lua "PlayLayer:process_loaded_move_actions"
    void processLoadedMoveActions();

    // @lua "PlayLayer:remove_all_checkpoints"
    void removeAllCheckpoints() override;

    // @lua "PlayLayer:remove_all_objects"
    void removeAllObjects();

    // @lua "PlayLayer:remove_checkpoint"
    void removeCheckpoint(bool first);

    // @lua "PlayLayer:reset_level"
    void resetLevel() override;

    // @lua "PlayLayer:reset_level_from_start"
    void resetLevelFromStart();

    // @lua "PlayLayer:reset_sptriggered"
    void resetSPTriggered() override;

    // @lua "PlayLayer:resume"
    void resume();

    // @lua "PlayLayer:resume_and_restart"
    void resumeAndRestart(bool fromStart);

    // @lua "PlayLayer:save_active_save_objects"
    void saveActiveSaveObjects(gd::vector<SavedActiveObjectState>& activeObjects, gd::vector<SavedSpecialObjectState>& specialObjects);

    // @lua "PlayLayer:save_dynamic_save_objects"
    void saveDynamicSaveObjects(gd::vector<SavedObjectStateRef>& dynamicObjects);

    // @lua "PlayLayer:scan_dynamic_save_objects"
    void scanDynamicSaveObjects();

    // @lua "PlayLayer.scene"
    static cocos2d::CCScene* scene(GJGameLevel* level, bool useReplay, bool dontCreateObjects);

    // @lua "PlayLayer:screen_flip_object"
    void screenFlipObject(GameObject* object);

    // @lua "PlayLayer:setup_has_completed"
    void setupHasCompleted();

    // @lua "PlayLayer:show_complete_effect"
    void showCompleteEffect();

    // @lua "PlayLayer:show_complete_text"
    void showCompleteText();

    // @lua "PlayLayer:show_end_layer"
    void showEndLayer();

    // @lua "PlayLayer:show_hint"
    void showHint();

    // @lua "PlayLayer:show_new_best"
    void showNewBest(bool newReward, int orbs, int diamonds, bool demonKey, bool noRetry, bool noTitle);

    // @lua "PlayLayer:show_retry_layer"
    void showRetryLayer();

    // @lua "PlayLayer:show_two_player_guide"
    void showTwoPlayerGuide();

    // @lua "PlayLayer:spawn_circle"
    void spawnCircle();

    // @lua "PlayLayer:spawn_firework"
    void spawnFirework();

    // @lua "PlayLayer:start_game"
    void startGame();

    // @lua "PlayLayer:start_game_delayed"
    void startGameDelayed();

    // @lua "PlayLayer:start_music"
    void startMusic();

    // @lua "PlayLayer:store_checkpoint"
    void storeCheckpoint(CheckpointObject* checkpoint);

    // @lua "PlayLayer:time_for_pos"
    float timeForPos(cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id) override;

    // @lua "PlayLayer:toggle_debug_draw"
    void toggleDebugDraw();

    // @lua "PlayLayer:toggle_glitter"
    void toggleGlitter(bool visible) override;

    // @lua "PlayLayer:toggle_ground_visibility"
    void toggleGroundVisibility(bool visible) override;

    // @lua "PlayLayer:toggle_hide_attempts"
    void toggleHideAttempts(bool hide) override;

    // @lua "PlayLayer:toggle_info_label"
    void toggleInfoLabel() override;

    // @lua "PlayLayer:toggle_mgvisibility"
    void toggleMGVisibility(bool visible) override;

    // @lua "PlayLayer:toggle_music_in_practice"
    void toggleMusicInPractice() override;

    // @lua "PlayLayer:toggle_practice_mode"
    void togglePracticeMode(bool practiceMode);

    // @lua "PlayLayer:toggle_progressbar"
    void toggleProgressbar() override;

    // @lua "PlayLayer:update_attempt_time"
    void updateAttemptTime(float attemptTime) override;

    // @lua "PlayLayer:update_attempts"
    void updateAttempts();

    // @lua "PlayLayer:update_color"
    void updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2) override;

    // @lua "PlayLayer:update_debug_draw_settings"
    void updateDebugDrawSettings();

    // @lua "PlayLayer:update_info_label"
    void updateInfoLabel();

    // @lua "PlayLayer:update_invisible_block"
    void updateInvisibleBlock(GameObject* object, float rightFadeBound, float leftFadeBound, float rightFadeWidth, float leftFadeWidth, cocos2d::ccColor3B const& lbgColor);

    // @lua "PlayLayer:update_progressbar"
    void updateProgressbar();

    // @lua "PlayLayer:update_test_mode_label"
    void updateTestModeLabel();

    // @lua "PlayLayer:update_time_label"
    void updateTimeLabel(int seconds, int centiseconds, bool decimals) override;

    // @lua "PlayLayer:update_time_warp"
    void updateTimeWarp(float timeWarp) override;

    // @lua "PlayLayer:update_verify_damage"
    void updateVerifyDamage() override;

    // @lua "PlayLayer:update_visibility"
    void updateVisibility(float dt) override;
};

} // namespace quartz