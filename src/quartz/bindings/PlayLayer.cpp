#include <quartz/bindings/PlayLayer.hpp>
#include <quartz/modified/PlayLayer.hpp>
#include <quartz/core/LuaManager.hpp>
#include <new>

namespace quartz {

PlayLayerBindings::PlayLayerBindings() {
    auto& luaManager = LuaManager::get();
    luaManager.queueBinding(
        [&luaManager]() {
            auto& state = luaManager.luaState();
            state.new_usertype<PlayLayer>("PlayLayer",
                sol::constructors<PlayLayer()>(),
                sol::base_classes, sol::bases<CCCircleWaveDelegate, CurrencyRewardDelegate, DialogDelegate, GJBaseGameLayer>(),
                "activated_checkpoint", &PlayLayer::m_activatedCheckpoint,
                "active_gravity_effects", &PlayLayer::m_activeGravityEffects,
                "active_save_objects1", &PlayLayer::m_activeSaveObjects1,
                "active_save_objects2", &PlayLayer::m_activeSaveObjects2,
                "attempt_label", &PlayLayer::m_attemptLabel,
                "attempt_time", &PlayLayer::m_attemptTime,
                "best_attempt_time", &PlayLayer::m_bestAttemptTime,
                "bg_effect_disabled", &PlayLayer::m_bgEffectDisabled,
                "blending_colors", &PlayLayer::m_blendingColors,
                "checkpoint_array", &PlayLayer::m_checkpointArray,
                "circle_wave_array", &PlayLayer::m_circleWaveArray,
                "coin_array", &PlayLayer::m_coinArray,
                "collectibles", &PlayLayer::m_collectibles,
                "color_key_dict", &PlayLayer::m_colorKeyDict,
                "current_checkpoint", &PlayLayer::m_currentCheckpoint,
                "current_time", &PlayLayer::m_currentTime,
                "damage_verified", &PlayLayer::m_damageVerified,
                "decimal_percentage", &PlayLayer::m_decimalPercentage,
                "diamonds", &PlayLayer::m_diamonds,
                "disable_gravity_effect", &PlayLayer::m_disableGravityEffect,
                "do_not", &PlayLayer::m_doNot,
                "dynamic_save_objects", &PlayLayer::m_dynamicSaveObjects,
                "dynamic_save_objects2", &PlayLayer::m_dynamicSaveObjects2,
                "end_checked", &PlayLayer::m_endChecked,
                "end_layer_stars", &PlayLayer::m_endLayerStars,
                "end_position", &PlayLayer::m_endPosition,
                "end_xposition", &PlayLayer::m_endXPosition,
                "enter_effect_position", &PlayLayer::m_enterEffectPosition,
                "glitter_enabled", &PlayLayer::m_glitterEnabled,
                "gravity_effect_index", &PlayLayer::m_gravityEffectIndex,
                "gravity_effects", &PlayLayer::m_gravityEffects,
                "has_completed_level", &PlayLayer::m_hasCompletedLevel,
                "has_jumped", &PlayLayer::m_hasJumped,
                "hint_shown", &PlayLayer::m_hintShown,
                "in_reset_delay", &PlayLayer::m_inResetDelay,
                "info_label", &PlayLayer::m_infoLabel,
                "is_ignore_damage_enabled", &PlayLayer::m_isIgnoreDamageEnabled,
                "is_paused", &PlayLayer::m_isPaused,
                "is_silent", &PlayLayer::m_isSilent,
                "jumps", &PlayLayer::m_jumps,
                "key_colors", &PlayLayer::m_keyColors,
                "key_opacities", &PlayLayer::m_keyOpacities,
                "key_pulses", &PlayLayer::m_keyPulses,
                "last_attempt_percent", &PlayLayer::m_lastAttemptPercent,
                "max_object_x", &PlayLayer::m_maxObjectX,
                "music_prepared", &PlayLayer::m_musicPrepared,
                "next_color_key", &PlayLayer::m_nextColorKey,
                "object_strings", &PlayLayer::m_objectStrings,
                "objects_created", &PlayLayer::m_objectsCreated,
                "orbs", &PlayLayer::m_orbs,
                "passed_integrity", &PlayLayer::m_passedIntegrity,
                "pause_delta", &PlayLayer::m_pauseDelta,
                "pause_time", &PlayLayer::m_pauseTime,
                "percentage_label", &PlayLayer::m_percentageLabel,
                "platformer_end_trigger", &PlayLayer::m_platformerEndTrigger,
                "platformer_restart", &PlayLayer::m_platformerRestart,
                "progress_bar", &PlayLayer::m_progressBar,
                "progress_fill", &PlayLayer::m_progressFill,
                "progress_height", &PlayLayer::m_progressHeight,
                "progress_width", &PlayLayer::m_progressWidth,
                "pulse_rod_index", &PlayLayer::m_pulseRodIndex,
                "recording_stopped", &PlayLayer::m_recordingStopped,
                "secret_key", &PlayLayer::m_secretKey,
                "show_leaderboard_percentage", &PlayLayer::m_showLeaderboardPercentage,
                "skip_audio_step", &PlayLayer::m_skipAudioStep,
                "speed_objects", &PlayLayer::m_speedObjects,
                "status_label", &PlayLayer::m_statusLabel,
                "total_gravity_effects", &PlayLayer::m_totalGravityEffects,
                "try_place_checkpoint", &PlayLayer::m_tryPlaceCheckpoint,
                "uncommitted_jumps", &PlayLayer::m_uncommittedJumps,
                "unk36c8", &PlayLayer::m_unk36c8,
                "unk36cc", &PlayLayer::m_unk36cc,
                "unk36cd", &PlayLayer::m_unk36cd,
                "unk36ce", &PlayLayer::m_unk36ce,
                "unk36cf", &PlayLayer::m_unk36cf,
                "unk3768", &PlayLayer::m_unk3768,
                "unk376d", &PlayLayer::m_unk376d,
                "unk3778", &PlayLayer::m_unk3778,
                "unk377c", &PlayLayer::m_unk377c,
                "unk3780", &PlayLayer::m_unk3780,
                "unk3784", &PlayLayer::m_unk3784,
                "unk3788", &PlayLayer::m_unk3788,
                "unk378c", &PlayLayer::m_unk378c,
                "unk37b0", &PlayLayer::m_unk37b0,
                "unk37b1", &PlayLayer::m_unk37b1,
                "unk37c0", &PlayLayer::m_unk37c0,
                "unk37cc", &PlayLayer::m_unk37cc,
                "unk37e0", &PlayLayer::m_unk37e0,
                "unk383c", &PlayLayer::m_unk383c,
                "unk38b0", &PlayLayer::m_unk38b0,
                "unk38b8", &PlayLayer::m_unk38b8,
                "unk38c0", &PlayLayer::m_unk38c0,
                "unk38c8", &PlayLayer::m_unk38c8,
                "unk38cc", &PlayLayer::m_unk38cc,
                "unk38d0", &PlayLayer::m_unk38d0,
                "unk3900", &PlayLayer::m_unk3900,
                "unk3906", &PlayLayer::m_unk3906,
                "unk3918", &PlayLayer::m_unk3918,
                "unk3920", &PlayLayer::m_unk3920);

            sol::table usertype = state["PlayLayer"];

            // expose the custom fields to lua
            usertype.set_function("fields",
                [](sol::this_state s, PlayLayer* self) -> sol::table {
                    sol::state_view lua(s);

                    if (!self) {
                        return lua.create_table();
                    }

                    // this cast is required to access lua field storage
                    auto modifiedSelf = static_cast<PlayLayerModified*>(self);
                    auto& luaFields = modifiedSelf->m_fields->m_luaFields;

                    if (!luaFields.valid()) {
                        // lazily create lua fields on first accesss
                        luaFields = lua.create_table();
                    }

                    return luaFields;
                });

            // manual allocation exposed to lua
            // returns raw pointer
            // lua must `free()` and `obj = nil` after use
            usertype.set_function("alloc",
                []() -> PlayLayer* {
                    PlayLayer* ptr = new(std::nothrow) PlayLayer();
                    return ptr;
                });

            // manual deallocation for `alloc()`
            usertype.set_function("free",
                [](PlayLayer* self) {
                    delete self;
                });

            usertype.set_function("activate_end_trigger",
                [](PlayLayer* self, int targetID, bool reverse, bool lockPlayerY) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->activateEndTrigger(targetID, reverse, lockPlayerY);
                });

            luaManager.addValidHook("PlayLayer:activate_platformer_end_trigger");
            usertype.set_function("activate_platformer_end_trigger",
                [](PlayLayer* self, EndTriggerGameObject* object, gd::vector<int> const& remapKeys) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->activatePlatformerEndTrigger(object, remapKeys);
                });

            usertype.set_function("add_circle",
                [](PlayLayer* self, CCCircleWave* cw) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addCircle(cw);
                });

            luaManager.addValidHook("PlayLayer:add_object");
            usertype.set_function("add_object",
                [](PlayLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->addObject(object);
                });

            usertype.set_function("add_to_group_old",
                [](PlayLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToGroupOld(object);
                });

            luaManager.addValidHook("PlayLayer:apply_custom_enter_effect");
            usertype.set_function("apply_custom_enter_effect",
                [](PlayLayer* self, GameObject* object, bool isRight) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->applyCustomEnterEffect(object, isRight);
                });

            luaManager.addValidHook("PlayLayer:apply_enter_effect");
            usertype.set_function("apply_enter_effect",
                [](PlayLayer* self, GameObject* object, int enterType, bool isRight) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->applyEnterEffect(object, enterType, isRight);
                });

            usertype.set_function("can_pause_game",
                [](PlayLayer* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canPauseGame();
                });

            luaManager.addValidHook("PlayLayer:check_for_end");
            usertype.set_function("check_for_end",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->checkForEnd();
                });

            usertype.set_function("check_snapshot",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->checkSnapshot();
                });

            luaManager.addValidHook("PlayLayer:checkpoint_activated");
            usertype.set_function("checkpoint_activated",
                [](PlayLayer* self, CheckpointGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->checkpointActivated(object);
                });

            usertype.set_function("checkpoint_with_id",
                [](PlayLayer* self, int id) -> CheckpointObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->checkpointWithID(id);
                });

            luaManager.addValidHook("PlayLayer:circle_wave_will_be_removed");
            usertype.set_function("circle_wave_will_be_removed",
                [](PlayLayer* self, CCCircleWave* circleWave) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->circleWaveWillBeRemoved(circleWave);
                });

            usertype.set_function("color_object",
                [](PlayLayer* self, int id, cocos2d::ccColor3B color) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->colorObject(id, color);
                });

            usertype.set_function("commit_jumps",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->commitJumps();
                });

            usertype.set_function("compare_state_snapshot",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->compareStateSnapshot();
                });

            usertype.set_function("create",
                [](GJGameLevel* level, bool useReplay, bool dontCreateObjects) -> PlayLayer* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call the original static function instead
                    return PlayLayer::create(level, useReplay, dontCreateObjects);
                });

            luaManager.addValidHook("PlayLayer:create_checkpoint");
            usertype.set_function("create_checkpoint",
                [](PlayLayer* self) -> CheckpointObject* {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    return modifiedSelf->createCheckpoint();
                });

            luaManager.addValidHook("PlayLayer:create_objects_from_setup_finished");
            usertype.set_function("create_objects_from_setup_finished",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->createObjectsFromSetupFinished();
                });

            luaManager.addValidHook("PlayLayer:currency_will_exit");
            usertype.set_function("currency_will_exit",
                [](PlayLayer* self, CurrencyRewardLayer* layer) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->currencyWillExit(layer);
                });

            usertype.set_function("delayed_full_reset",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->delayedFullReset();
                });

            luaManager.addValidHook("PlayLayer:delayed_reset_level");
            usertype.set_function("delayed_reset_level",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->delayedResetLevel();
                });

            luaManager.addValidHook("PlayLayer:destroy_player");
            usertype.set_function("destroy_player",
                [](PlayLayer* self, PlayerObject* player, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->destroyPlayer(player, object);
                });

            luaManager.addValidHook("PlayLayer:dialog_closed");
            usertype.set_function("dialog_closed",
                [](PlayLayer* self, DialogLayer* layer) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->dialogClosed(layer);
                });

            luaManager.addValidHook("PlayLayer:flip_art");
            usertype.set_function("flip_art",
                [](PlayLayer* self, bool flip) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->flipArt(flip);
                });

            luaManager.addValidHook("PlayLayer:full_reset");
            usertype.set_function("full_reset",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->fullReset();
                });

            usertype.set_function("get",
                []() -> PlayLayer* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call the original static function instead
                    return PlayLayer::get();
                });

            luaManager.addValidHook("PlayLayer:get_current_percent");
            usertype.set_function("get_current_percent",
                [](PlayLayer* self) -> float {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    return modifiedSelf->getCurrentPercent();
                });

            usertype.set_function("get_current_percent_int",
                [](PlayLayer* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getCurrentPercentInt();
                });

            usertype.set_function("get_end_position",
                [](PlayLayer* self) -> cocos2d::CCPoint {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getEndPosition();
                });

            usertype.set_function("get_last_checkpoint",
                [](PlayLayer* self) -> CheckpointObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getLastCheckpoint();
                });

            usertype.set_function("get_relative_mod",
                [](PlayLayer* self, cocos2d::CCPoint position, float right, float left, float offset) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getRelativeMod(position, right, left, offset);
                });

            usertype.set_function("get_relative_mod_new",
                [](PlayLayer* self, cocos2d::CCPoint position, float mod, float offset, bool unused, bool isRight) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getRelativeModNew(position, mod, offset, unused, isRight);
                });

            usertype.set_function("get_temp_milli_time",
                [](PlayLayer* self) -> double {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getTempMilliTime();
                });

            luaManager.addValidHook("PlayLayer:gravity_effect_finished");
            usertype.set_function("gravity_effect_finished",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->gravityEffectFinished();
                });

            usertype.set_function("increment_jumps",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->incrementJumps();
                });

            luaManager.addValidHook("PlayLayer:init");
            usertype.set_function("init",
                [](PlayLayer* self, GJGameLevel* level, bool useReplay, bool dontCreateObjects) -> bool {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    return modifiedSelf->init(level, useReplay, dontCreateObjects);
                });

            usertype.set_function("is_gameplay_active",
                [](PlayLayer* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isGameplayActive();
                });

            luaManager.addValidHook("PlayLayer:level_complete");
            usertype.set_function("level_complete",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->levelComplete();
                });

            usertype.set_function("load_active_save_objects",
                [](PlayLayer* self, gd::vector<SavedActiveObjectState>& activeObjects, gd::vector<SavedSpecialObjectState>& specialObjects) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->loadActiveSaveObjects(activeObjects, specialObjects);
                });

            luaManager.addValidHook("PlayLayer:load_default_colors");
            usertype.set_function("load_default_colors",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->loadDefaultColors();
                });

            usertype.set_function("load_dynamic_save_objects",
                [](PlayLayer* self, gd::vector<SavedObjectStateRef>& dynamicObjects) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->loadDynamicSaveObjects(dynamicObjects);
                });

            luaManager.addValidHook("PlayLayer:load_from_checkpoint");
            usertype.set_function("load_from_checkpoint",
                [](PlayLayer* self, CheckpointObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->loadFromCheckpoint(object);
                });

            usertype.set_function("load_last_checkpoint",
                [](PlayLayer* self) -> CheckpointObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->loadLastCheckpoint();
                });

            luaManager.addValidHook("PlayLayer:manual_update_object_colors");
            usertype.set_function("manual_update_object_colors",
                [](PlayLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->manualUpdateObjectColors(object);
                });

            luaManager.addValidHook("PlayLayer:mark_checkpoint");
            usertype.set_function("mark_checkpoint",
                [](PlayLayer* self) -> CheckpointObject* {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    return modifiedSelf->markCheckpoint();
                });

            luaManager.addValidHook("PlayLayer:on_enter_transition_did_finish");
            usertype.set_function("on_enter_transition_did_finish",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->onEnterTransitionDidFinish();
                });

            luaManager.addValidHook("PlayLayer:on_exit");
            usertype.set_function("on_exit",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->onExit();
                });

            luaManager.addValidHook("PlayLayer:on_quit");
            usertype.set_function("on_quit",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->onQuit();
                });

            luaManager.addValidHook("PlayLayer:opacity_for_object");
            usertype.set_function("opacity_for_object",
                [](PlayLayer* self, GameObject* object) -> float {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    return modifiedSelf->opacityForObject(object);
                });

            luaManager.addValidHook("PlayLayer:optimize_color_groups");
            usertype.set_function("optimize_color_groups",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->optimizeColorGroups();
                });

            luaManager.addValidHook("PlayLayer:optimize_opacity_groups");
            usertype.set_function("optimize_opacity_groups",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->optimizeOpacityGroups();
                });

            luaManager.addValidHook("PlayLayer:pause_game");
            usertype.set_function("pause_game",
                [](PlayLayer* self, bool unfocused) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->pauseGame(unfocused);
                });

            luaManager.addValidHook("PlayLayer:play_end_animation_to_pos");
            usertype.set_function("play_end_animation_to_pos",
                [](PlayLayer* self, cocos2d::CCPoint position) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->playEndAnimationToPos(position);
                });

            luaManager.addValidHook("PlayLayer:play_gravity_effect");
            usertype.set_function("play_gravity_effect",
                [](PlayLayer* self, bool flip) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->playGravityEffect(flip);
                });

            luaManager.addValidHook("PlayLayer:play_platformer_end_animation_to_pos");
            usertype.set_function("play_platformer_end_animation_to_pos",
                [](PlayLayer* self, cocos2d::CCPoint position, bool instant) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->playPlatformerEndAnimationToPos(position, instant);
                });

            usertype.set_function("play_replay",
                [](PlayLayer* self, gd::string inputs) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playReplay(inputs);
                });

            luaManager.addValidHook("PlayLayer:pos_for_time");
            usertype.set_function("pos_for_time",
                [](PlayLayer* self, float time) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    return modifiedSelf->posForTime(time);
                });

            luaManager.addValidHook("PlayLayer:post_update");
            usertype.set_function("post_update",
                [](PlayLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->postUpdate(dt);
                });

            luaManager.addValidHook("PlayLayer:prepare_create_objects_from_setup");
            usertype.set_function("prepare_create_objects_from_setup",
                [](PlayLayer* self, gd::string& levelString) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->prepareCreateObjectsFromSetup(levelString);
                });

            luaManager.addValidHook("PlayLayer:prepare_music");
            usertype.set_function("prepare_music",
                [](PlayLayer* self, bool dontWait) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->prepareMusic(dontWait);
                });

            luaManager.addValidHook("PlayLayer:process_checkpoints");
            usertype.set_function("process_checkpoints",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->processCheckpoints();
                });

            luaManager.addValidHook("PlayLayer:process_create_objects_from_setup");
            usertype.set_function("process_create_objects_from_setup",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->processCreateObjectsFromSetup();
                });

            luaManager.addValidHook("PlayLayer:process_loaded_move_actions");
            usertype.set_function("process_loaded_move_actions",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->processLoadedMoveActions();
                });

            usertype.set_function("queue_checkpoint",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->queueCheckpoint();
                });

            luaManager.addValidHook("PlayLayer:remove_all_checkpoints");
            usertype.set_function("remove_all_checkpoints",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->removeAllCheckpoints();
                });

            luaManager.addValidHook("PlayLayer:remove_all_objects");
            usertype.set_function("remove_all_objects",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->removeAllObjects();
                });

            luaManager.addValidHook("PlayLayer:remove_checkpoint");
            usertype.set_function("remove_checkpoint",
                [](PlayLayer* self, bool first) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->removeCheckpoint(first);
                });

            usertype.set_function("remove_from_group_old",
                [](PlayLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeFromGroupOld(object);
                });

            luaManager.addValidHook("PlayLayer:reset_level");
            usertype.set_function("reset_level",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->resetLevel();
                });

            luaManager.addValidHook("PlayLayer:reset_level_from_start");
            usertype.set_function("reset_level_from_start",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->resetLevelFromStart();
                });

            luaManager.addValidHook("PlayLayer:reset_sptriggered");
            usertype.set_function("reset_sptriggered",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->resetSPTriggered();
                });

            luaManager.addValidHook("PlayLayer:resume");
            usertype.set_function("resume",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->resume();
                });

            luaManager.addValidHook("PlayLayer:resume_and_restart");
            usertype.set_function("resume_and_restart",
                [](PlayLayer* self, bool fromStart) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->resumeAndRestart(fromStart);
                });

            luaManager.addValidHook("PlayLayer:save_active_save_objects");
            usertype.set_function("save_active_save_objects",
                [](PlayLayer* self, gd::vector<SavedActiveObjectState>& activeObjects, gd::vector<SavedSpecialObjectState>& specialObjects) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->saveActiveSaveObjects(activeObjects, specialObjects);
                });

            luaManager.addValidHook("PlayLayer:save_dynamic_save_objects");
            usertype.set_function("save_dynamic_save_objects",
                [](PlayLayer* self, gd::vector<SavedObjectStateRef>& dynamicObjects) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->saveDynamicSaveObjects(dynamicObjects);
                });

            usertype.set_function("scan_active_save_objects",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->scanActiveSaveObjects();
                });

            luaManager.addValidHook("PlayLayer:scan_dynamic_save_objects");
            usertype.set_function("scan_dynamic_save_objects",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->scanDynamicSaveObjects();
                });

            luaManager.addValidHook("PlayLayer.scene");
            usertype.set_function("scene",
                [](GJGameLevel* level, bool useReplay, bool dontCreateObjects) -> cocos2d::CCScene* {
                    return quartz::PlayLayerModified::scene(level, useReplay, dontCreateObjects);
                });

            luaManager.addValidHook("PlayLayer:screen_flip_object");
            usertype.set_function("screen_flip_object",
                [](PlayLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->screenFlipObject(object);
                });

            luaManager.addValidHook("PlayLayer:setup_has_completed");
            usertype.set_function("setup_has_completed",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->setupHasCompleted();
                });

            usertype.set_function("should_blend",
                [](PlayLayer* self, int colorID) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->shouldBlend(colorID);
                });

            usertype.set_function("should_debug_draw",
                [](PlayLayer* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->shouldDebugDraw();
                });

            luaManager.addValidHook("PlayLayer:show_complete_effect");
            usertype.set_function("show_complete_effect",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->showCompleteEffect();
                });

            luaManager.addValidHook("PlayLayer:show_complete_text");
            usertype.set_function("show_complete_text",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->showCompleteText();
                });

            luaManager.addValidHook("PlayLayer:show_end_layer");
            usertype.set_function("show_end_layer",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->showEndLayer();
                });

            luaManager.addValidHook("PlayLayer:show_hint");
            usertype.set_function("show_hint",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->showHint();
                });

            luaManager.addValidHook("PlayLayer:show_new_best");
            usertype.set_function("show_new_best",
                [](PlayLayer* self, bool newReward, int orbs, int diamonds, bool demonKey, bool noRetry, bool noTitle) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->showNewBest(newReward, orbs, diamonds, demonKey, noRetry, noTitle);
                });

            luaManager.addValidHook("PlayLayer:show_retry_layer");
            usertype.set_function("show_retry_layer",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->showRetryLayer();
                });

            luaManager.addValidHook("PlayLayer:show_two_player_guide");
            usertype.set_function("show_two_player_guide",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->showTwoPlayerGuide();
                });

            luaManager.addValidHook("PlayLayer:spawn_circle");
            usertype.set_function("spawn_circle",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->spawnCircle();
                });

            luaManager.addValidHook("PlayLayer:spawn_firework");
            usertype.set_function("spawn_firework",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->spawnFirework();
                });

            luaManager.addValidHook("PlayLayer:start_game");
            usertype.set_function("start_game",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->startGame();
                });

            luaManager.addValidHook("PlayLayer:start_game_delayed");
            usertype.set_function("start_game_delayed",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->startGameDelayed();
                });

            luaManager.addValidHook("PlayLayer:start_music");
            usertype.set_function("start_music",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->startMusic();
                });

            usertype.set_function("start_recording",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->startRecording();
                });

            usertype.set_function("start_recording_delayed",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->startRecordingDelayed();
                });

            usertype.set_function("stop_recording",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->stopRecording();
                });

            luaManager.addValidHook("PlayLayer:store_checkpoint");
            usertype.set_function("store_checkpoint",
                [](PlayLayer* self, CheckpointObject* checkpoint) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->storeCheckpoint(checkpoint);
                });

            usertype.set_function("take_state_snapshot",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->takeStateSnapshot();
                });

            usertype.set_function("test_time",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->testTime();
                });

            luaManager.addValidHook("PlayLayer:time_for_pos");
            usertype.set_function("time_for_pos",
                [](PlayLayer* self, cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id) -> float {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    return modifiedSelf->timeForPos(position, order, channel, songTriggers, id);
                });

            usertype.set_function("toggle_bgeffect_visibility",
                [](PlayLayer* self, bool enabled) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleBGEffectVisibility(enabled);
                });

            luaManager.addValidHook("PlayLayer:toggle_debug_draw");
            usertype.set_function("toggle_debug_draw",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->toggleDebugDraw();
                });

            usertype.set_function("toggle_ghost_effect",
                [](PlayLayer* self, int type) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleGhostEffect(type);
                });

            luaManager.addValidHook("PlayLayer:toggle_glitter");
            usertype.set_function("toggle_glitter",
                [](PlayLayer* self, bool visible) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->toggleGlitter(visible);
                });

            luaManager.addValidHook("PlayLayer:toggle_ground_visibility");
            usertype.set_function("toggle_ground_visibility",
                [](PlayLayer* self, bool visible) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->toggleGroundVisibility(visible);
                });

            luaManager.addValidHook("PlayLayer:toggle_hide_attempts");
            usertype.set_function("toggle_hide_attempts",
                [](PlayLayer* self, bool hide) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->toggleHideAttempts(hide);
                });

            usertype.set_function("toggle_ignore_damage",
                [](PlayLayer* self, bool value) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleIgnoreDamage(value);
                });

            luaManager.addValidHook("PlayLayer:toggle_info_label");
            usertype.set_function("toggle_info_label",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->toggleInfoLabel();
                });

            luaManager.addValidHook("PlayLayer:toggle_mgvisibility");
            usertype.set_function("toggle_mgvisibility",
                [](PlayLayer* self, bool visible) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->toggleMGVisibility(visible);
                });

            luaManager.addValidHook("PlayLayer:toggle_music_in_practice");
            usertype.set_function("toggle_music_in_practice",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->toggleMusicInPractice();
                });

            luaManager.addValidHook("PlayLayer:toggle_practice_mode");
            usertype.set_function("toggle_practice_mode",
                [](PlayLayer* self, bool practiceMode) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->togglePracticeMode(practiceMode);
                });

            luaManager.addValidHook("PlayLayer:toggle_progressbar");
            usertype.set_function("toggle_progressbar",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->toggleProgressbar();
                });

            usertype.set_function("try_start_record",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->tryStartRecord();
                });

            luaManager.addValidHook("PlayLayer:update_attempt_time");
            usertype.set_function("update_attempt_time",
                [](PlayLayer* self, float attemptTime) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateAttemptTime(attemptTime);
                });

            luaManager.addValidHook("PlayLayer:update_attempts");
            usertype.set_function("update_attempts",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateAttempts();
                });

            luaManager.addValidHook("PlayLayer:update_color");
            usertype.set_function("update_color",
                [](PlayLayer* self, cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateColor(color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2);
                });

            luaManager.addValidHook("PlayLayer:update_debug_draw_settings");
            usertype.set_function("update_debug_draw_settings",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateDebugDrawSettings();
                });

            usertype.set_function("update_effect_positions",
                [](PlayLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateEffectPositions();
                });

            luaManager.addValidHook("PlayLayer:update_info_label");
            usertype.set_function("update_info_label",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateInfoLabel();
                });

            luaManager.addValidHook("PlayLayer:update_invisible_block");
            usertype.set_function("update_invisible_block",
                [](PlayLayer* self, GameObject* object, float rightFadeBound, float leftFadeBound, float rightFadeWidth, float leftFadeWidth, cocos2d::ccColor3B const& lbgColor) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateInvisibleBlock(object, rightFadeBound, leftFadeBound, rightFadeWidth, leftFadeWidth, lbgColor);
                });

            luaManager.addValidHook("PlayLayer:update_progressbar");
            usertype.set_function("update_progressbar",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateProgressbar();
                });

            usertype.set_function("update_screen_rotation",
                [](PlayLayer* self, int rotation, bool add, bool convert, float duration, int easingType, float easingRate, int uniqueID, int controlID) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateScreenRotation(rotation, add, convert, duration, easingType, easingRate, uniqueID, controlID);
                });

            luaManager.addValidHook("PlayLayer:update_test_mode_label");
            usertype.set_function("update_test_mode_label",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateTestModeLabel();
                });

            luaManager.addValidHook("PlayLayer:update_time_label");
            usertype.set_function("update_time_label",
                [](PlayLayer* self, int seconds, int centiseconds, bool decimals) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateTimeLabel(seconds, centiseconds, decimals);
                });

            luaManager.addValidHook("PlayLayer:update_time_warp");
            usertype.set_function("update_time_warp",
                [](PlayLayer* self, float timeWarp) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateTimeWarp(timeWarp);
                });

            luaManager.addValidHook("PlayLayer:update_verify_damage");
            usertype.set_function("update_verify_damage",
                [](PlayLayer* self) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateVerifyDamage();
                });

            luaManager.addValidHook("PlayLayer:update_visibility");
            usertype.set_function("update_visibility",
                [](PlayLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::PlayLayerModified*>(self);
                    modifiedSelf->updateVisibility(dt);
                });
        });
}

} // namespace quartz