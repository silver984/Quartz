#pragma once
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <quartz/core/LuaFields.hpp>

namespace quartz {

struct GJBaseGameLayerModified : geode::Modify<GJBaseGameLayerModified, GJBaseGameLayer>, quartz::LuaFields {
    // @lua "GJBaseGameLayer:activate_event_trigger"
    void activateEventTrigger(EventLinkTrigger* object, gd::vector<int> const& remapKeys);

    // @lua "GJBaseGameLayer:activate_item_compare_trigger"
    void activateItemCompareTrigger(ItemTriggerGameObject* object, gd::vector<int> const& remapKeys);

    // @lua "GJBaseGameLayer:activate_item_edit_trigger"
    void activateItemEditTrigger(ItemTriggerGameObject* object);

    // @lua "GJBaseGameLayer:activate_persistent_item_trigger"
    void activatePersistentItemTrigger(ItemTriggerGameObject* object);

    // @lua "GJBaseGameLayer:activate_player_control_trigger"
    void activatePlayerControlTrigger(PlayerControlGameObject* object);

    // @lua "GJBaseGameLayer:activate_sfxedit_trigger"
    void activateSFXEditTrigger(SFXTriggerGameObject* object);

    // @lua "GJBaseGameLayer:activate_sfxtrigger"
    void activateSFXTrigger(SFXTriggerGameObject* object);

    // @lua "GJBaseGameLayer:activate_song_edit_trigger"
    void activateSongEditTrigger(SongTriggerGameObject* object);

    // @lua "GJBaseGameLayer:activate_song_trigger"
    void activateSongTrigger(SongTriggerGameObject* object);

    // @lua "GJBaseGameLayer:activate_timer_trigger"
    void activateTimerTrigger(TimerTriggerGameObject* object, gd::vector<int> const& remapKeys);

    // @lua "GJBaseGameLayer:activated_audio_trigger"
    void activatedAudioTrigger(SFXTriggerGameObject* object) override;

    // @lua "GJBaseGameLayer:activated_audio_trigger@2"
    void activatedAudioTrigger(SFXTriggerGameObject* object, float levelTime);

    // @lua "GJBaseGameLayer:add_area_effect"
    void addAreaEffect(EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJAreaActionType type);

    // @lua "GJBaseGameLayer:add_custom_enter_effect"
    void addCustomEnterEffect(EnterEffectObject* object, bool enter);

    // @lua "GJBaseGameLayer:add_guide_art"
    bool addGuideArt(GameObject* object);

    // @lua "GJBaseGameLayer:add_keyframe"
    void addKeyframe(KeyframeGameObject* object) override;

    // @lua "GJBaseGameLayer:add_proximity_volume_effect"
    void addProximityVolumeEffect(int channelID, int targetType, SFXTriggerGameObject* object);

    // @lua "GJBaseGameLayer:add_remap_targets"
    void addRemapTargets(gd::set<int>& targets);

    // @lua "GJBaseGameLayer:add_to_group"
    void addToGroup(GameObject* object, int groupID, bool triggerGroup) override;

    // @lua "GJBaseGameLayer:add_to_groups"
    void addToGroups(GameObject* object, bool duplicateTrigger);

    // @lua "GJBaseGameLayer:add_to_section"
    void addToSection(GameObject* object) override;

    // @lua "GJBaseGameLayer:add_uiobject"
    void addUIObject(GameObject* object);

    // @lua "GJBaseGameLayer:animate_in_dual_ground_new"
    void animateInDualGroundNew(GameObject* object, float height, bool instant, float duration);

    // @lua "GJBaseGameLayer:apply_remap"
    void applyRemap(EffectGameObject* object, gd::vector<int> const& remapKeys, gd::unordered_map<int, int>& remap);

    // @lua "GJBaseGameLayer:apply_sfxedit_trigger"
    void applySFXEditTrigger(int channelID, int targetType, SFXTriggerGameObject* object);

    // @lua "GJBaseGameLayer:apply_time_warp"
    void applyTimeWarp(float timeWarp) override;

    // @lua "GJBaseGameLayer:assign_new_sticky_groups"
    void assignNewStickyGroups(cocos2d::CCArray* objects);

    // @lua "GJBaseGameLayer:bump_player"
    void bumpPlayer(PlayerObject* player, EffectGameObject* object);

    // @lua "GJBaseGameLayer:button_is_relevant"
    bool buttonIsRelevant(PlayerButtonCommand const& button);

    // @lua "GJBaseGameLayer:calculate_color_groups"
    void calculateColorGroups();

    // @lua "GJBaseGameLayer:can_be_activated_by_player"
    bool canBeActivatedByPlayer(PlayerObject* player, EffectGameObject* object);

    // @lua "GJBaseGameLayer:can_process_sfx"
    bool canProcessSFX(SFXTriggerState& state, gd::unordered_map<int, int>& stateIndices, gd::unordered_map<int, float>& times, gd::vector<SFXTriggerState>& states);

    // @lua "GJBaseGameLayer:check_camera_limit_after_teleport"
    void checkCameraLimitAfterTeleport(PlayerObject* player, float yOffset);

    // @lua "GJBaseGameLayer:check_collision"
    bool checkCollision(int blockAID, int blockBID);

    // @lua "GJBaseGameLayer:check_collision_blocks"
    void checkCollisionBlocks(EffectGameObject* object, gd::vector<EffectGameObject *>* blocks, int blockCount);

    // @lua "GJBaseGameLayer:check_collisions"
    int checkCollisions(PlayerObject* object, float dt, bool ignoreDamage);

    // @lua "GJBaseGameLayer:check_repell_player"
    void checkRepellPlayer();

    // @lua "GJBaseGameLayer:check_spawn_objects"
    void checkSpawnObjects();

    // @lua "GJBaseGameLayer:checkpoint_activated"
    void checkpointActivated(CheckpointGameObject* object) override;

    // @lua "GJBaseGameLayer:claim_custom_particle"
    cocos2d::CCParticleSystemQuad* claimCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int zLayer, int zOrder, int uiObject, bool dontAdd) override;

    // @lua "GJBaseGameLayer:claim_move_action"
    cocos2d::CCPoint claimMoveAction(int groupID, bool ignoreStaticGroups);

    // @lua "GJBaseGameLayer:claim_particle"
    cocos2d::CCParticleSystemQuad* claimParticle(gd::string key, int zLayer);

    // @lua "GJBaseGameLayer:claim_rotation_action"
    void claimRotationAction(int targetID, int centerID, float& rotation, float& offset, bool ignoreStaticGroups, bool unused);

    // @lua "GJBaseGameLayer:collision_check_objects"
    void collisionCheckObjects(PlayerObject* object, gd::vector<GameObject *>* objects, int objectCount, float dt);

    // @lua "GJBaseGameLayer:control_area_effect"
    void controlAreaEffect(EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJActionCommand command);

    // @lua "GJBaseGameLayer:control_area_effect_with_id"
    void controlAreaEffectWithID(int uniqueID, int controlID, GJActionCommand command);

    // @lua "GJBaseGameLayer:control_event_link"
    void controlEventLink(int uniqueID, int controlID, GJActionCommand command);

    // @lua "GJBaseGameLayer:control_triggers_in_group"
    void controlTriggersInGroup(int group, GJActionCommand command);

    // @lua "GJBaseGameLayer:control_triggers_with_control_id"
    void controlTriggersWithControlID(int controlID, GJActionCommand command);

    // @lua "GJBaseGameLayer.convert_to_closest_direction"
    static float convertToClosestDirection(float angle, float bound);

    // @lua "GJBaseGameLayer:create_background"
    void createBackground(int background);

    // @lua "GJBaseGameLayer:create_custom_particle"
    cocos2d::CCParticleSystemQuad* createCustomParticle(gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int minimum, bool dontAdd) override;

    // @lua "GJBaseGameLayer:create_ground_layer"
    void createGroundLayer(int ground, int line);

    // @lua "GJBaseGameLayer:create_middleground"
    void createMiddleground(int middleground);

    // @lua "GJBaseGameLayer:create_particle"
    cocos2d::CCParticleSystemQuad* createParticle(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType);

    // @lua "GJBaseGameLayer:create_player"
    void createPlayer();

    // @lua "GJBaseGameLayer:create_player_collision_block"
    void createPlayerCollisionBlock();

    // @lua "GJBaseGameLayer:create_text_layers"
    void createTextLayers();

    // @lua "GJBaseGameLayer:damaging_objects_in_rect"
    cocos2d::CCArray* damagingObjectsInRect(cocos2d::CCRect rect, bool enabledGroups);

    // @lua "GJBaseGameLayer:destroy_object"
    void destroyObject(GameObject* object);

    // @lua "GJBaseGameLayer:exit_static_camera"
    void exitStaticCamera(bool exitX, bool exitY, float time, int easingType, float easingRate, bool smoothVelocity, float smoothVelocityMod, bool exitInstant);

    // @lua "GJBaseGameLayer:flip_gravity"
    void flipGravity(PlayerObject* object, bool flip, bool noEffects);

    // @lua "GJBaseGameLayer:flip_objects"
    void flipObjects();

    // @lua "GJBaseGameLayer.game_event_to_string"
    static gd::string gameEventToString(GJGameEvent event);

    // @lua "GJBaseGameLayer:game_event_triggered"
    void gameEventTriggered(GJGameEvent event, int material, int playerID);

    // @lua "GJBaseGameLayer:generate_enter_easing_buffer"
    int generateEnterEasingBuffer(int easingType, float easingRate);

    // @lua "GJBaseGameLayer:generate_spawn_remap"
    void generateSpawnRemap();

    // @lua "GJBaseGameLayer:generate_target_groups"
    void generateTargetGroups();

    // @lua "GJBaseGameLayer:generate_visibility_groups"
    void generateVisibilityGroups();

    // @lua "GJBaseGameLayer:get_area_object_value"
    float getAreaObjectValue(EnterEffectInstance* instance, GameObject* object, cocos2d::CCPoint& position, bool& show);

    // @lua "GJBaseGameLayer:get_follow_speed_val"
    cocos2d::CCPoint getFollowSpeedVal(GameObject* object, int startSpeedRef, int startDirRef, float startDir, float startSpeed);

    // @lua "GJBaseGameLayer:get_group"
    cocos2d::CCArray* getGroup(int id);

    // @lua "GJBaseGameLayer:get_item_value"
    double getItemValue(int type, int id);

    // @lua "GJBaseGameLayer:get_max_portal_y"
    float getMaxPortalY();

    // @lua "GJBaseGameLayer:get_min_distance"
    float getMinDistance(cocos2d::CCPoint position, cocos2d::CCArray* objects, float minNear, int mode);

    // @lua "GJBaseGameLayer:get_min_portal_y"
    float getMinPortalY();

    // @lua "GJBaseGameLayer:get_modified_delta"
    double getModifiedDelta(float dt);

    // @lua "GJBaseGameLayer:get_particle_key"
    gd::string getParticleKey(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType);

    // @lua "GJBaseGameLayer:get_particle_key2"
    gd::string getParticleKey2(gd::string key);

    // @lua "GJBaseGameLayer:get_record_string"
    gd::string getRecordString(bool compress);

    // @lua "GJBaseGameLayer:get_saved_position"
    cocos2d::CCPoint getSavedPosition(int groupID, float delay);

    // @lua "GJBaseGameLayer:group_sticky_objects"
    void groupStickyObjects(cocos2d::CCArray* objects);

    // @lua "GJBaseGameLayer:handle_button"
    void handleButton(bool down, int button, bool isPlayer1);

    // @lua "GJBaseGameLayer:has_unique_coin"
    bool hasUniqueCoin(EffectGameObject* object);

    // @lua "GJBaseGameLayer:increase_batch_node_capacity"
    void increaseBatchNodeCapacity();

    // @lua "GJBaseGameLayer:init"
    bool init() override;

    // @lua "GJBaseGameLayer:lightning_flash@2"
    void lightningFlash(cocos2d::CCPoint from, cocos2d::CCPoint to, cocos2d::ccColor3B color, float lineWidth, float duration, int displacement, bool flash, float opacity);

    // @lua "GJBaseGameLayer:load_group_parents_from_string"
    void loadGroupParentsFromString(GameObject* object, gd::string groupList);

    // @lua "GJBaseGameLayer:load_level_settings"
    void loadLevelSettings();

    // @lua "GJBaseGameLayer:load_start_pos_object"
    void loadStartPosObject();

    // @lua "GJBaseGameLayer:load_up_to_position"
    void loadUpToPosition(float position, int order, int channel);

    // @lua "GJBaseGameLayer:max_zorder_for_shader_z"
    int maxZOrderForShaderZ(int zLayer);

    // @lua "GJBaseGameLayer:min_zorder_for_shader_z"
    int minZOrderForShaderZ(int zLayer);

    // @lua "GJBaseGameLayer:modify_group_physics"
    void modifyGroupPhysics(AdvancedFollowEditObject* object, cocos2d::CCArray* group);

    // @lua "GJBaseGameLayer:move_object_to_static_group"
    void moveObjectToStaticGroup(GameObject* object);

    // @lua "GJBaseGameLayer:move_objects"
    void moveObjects(cocos2d::CCArray* objects, double dx, double dy, bool lockPlayerY);

    // @lua "GJBaseGameLayer:object_type_to_game_event"
    GJGameEvent objectTypeToGameEvent(int type);

    // @lua "GJBaseGameLayer:objects_collided"
    void objectsCollided(int blockAID, int blockBID) override;

    // @lua "GJBaseGameLayer:opacity_for_object"
    float opacityForObject(GameObject* object) override;

    // @lua "GJBaseGameLayer:optimize_move_groups"
    void optimizeMoveGroups();

    // @lua "GJBaseGameLayer:order_spawn_objects"
    void orderSpawnObjects();

    // @lua "GJBaseGameLayer:parent_for_zlayer"
    cocos2d::CCNode* parentForZLayer(int zLayer, bool blending, int parentMode, int uiObject);

    // @lua "GJBaseGameLayer:pause_audio"
    void pauseAudio();

    // @lua "GJBaseGameLayer:pickup_item"
    void pickupItem(EffectGameObject* object);

    // @lua "GJBaseGameLayer:play_exit_dual_effect"
    void playExitDualEffect(PlayerObject* player);

    // @lua "GJBaseGameLayer:play_keyframe_animation"
    void playKeyframeAnimation(KeyframeAnimTriggerObject* object, gd::vector<int> const& remapKeys);

    // @lua "GJBaseGameLayer:player_circle_collision"
    bool playerCircleCollision(PlayerObject* player, GameObject* object);

    // @lua "GJBaseGameLayer:player_touched_ring"
    void playerTouchedRing(PlayerObject* player, RingObject* object);

    // @lua "GJBaseGameLayer:player_touched_trigger"
    void playerTouchedTrigger(PlayerObject* player, EffectGameObject* object);

    // @lua "GJBaseGameLayer:player_will_switch_mode"
    void playerWillSwitchMode(PlayerObject* player, GameObject* object);

    // @lua "GJBaseGameLayer:position_for_shader_target"
    cocos2d::CCPoint positionForShaderTarget(int groupID);

    // @lua "GJBaseGameLayer:position_uiobjects"
    void positionUIObjects();

    // @lua "GJBaseGameLayer:pre_update_visibility"
    void preUpdateVisibility(float dt);

    // @lua "GJBaseGameLayer:prepare_save_position_objects"
    void prepareSavePositionObjects();

    // @lua "GJBaseGameLayer:process_activated_audio_triggers"
    void processActivatedAudioTriggers(float levelTime);

    // @lua "GJBaseGameLayer:process_advanced_follow_action"
    void processAdvancedFollowAction(AdvancedFollowInstance& instance, bool started, float dt);

    // @lua "GJBaseGameLayer:process_advanced_follow_actions"
    void processAdvancedFollowActions(float dt);

    // @lua "GJBaseGameLayer:process_area_actions"
    void processAreaActions(float dt, bool visibleFrame);

    // @lua "GJBaseGameLayer:process_area_effects"
    void processAreaEffects(gd::vector<EnterEffectInstance>* effects, GJAreaActionType type, float dt, bool visibleFrame);

    // @lua "GJBaseGameLayer:process_area_move_group_action"
    void processAreaMoveGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset);

    // @lua "GJBaseGameLayer:process_area_rotate_group_action"
    void processAreaRotateGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset);

    // @lua "GJBaseGameLayer:process_area_tint_group_action"
    void processAreaTintGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, bool targetGroups);

    // @lua "GJBaseGameLayer:process_area_transform_group_action"
    void processAreaTransformGroupAction(cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset);

    // @lua "GJBaseGameLayer:process_commands"
    void processCommands(float dt, bool isHalfTick, bool isLastTick);

    // @lua "GJBaseGameLayer:process_dynamic_object_actions"
    void processDynamicObjectActions(int type, float dt);

    // @lua "GJBaseGameLayer:process_follow_actions"
    void processFollowActions();

    // @lua "GJBaseGameLayer:process_items"
    void processItems();

    // @lua "GJBaseGameLayer:process_move_actions"
    void processMoveActions();

    // @lua "GJBaseGameLayer:process_move_actions_step"
    void processMoveActionsStep(float dt, bool visibleFrame);

    // @lua "GJBaseGameLayer:process_options_trigger"
    void processOptionsTrigger(GameOptionsTrigger* object);

    // @lua "GJBaseGameLayer:process_player_follow_actions"
    void processPlayerFollowActions(float dt);

    // @lua "GJBaseGameLayer:process_queued_audio_triggers"
    void processQueuedAudioTriggers();

    // @lua "GJBaseGameLayer:process_queued_buttons"
    void processQueuedButtons(float dt, bool clearInputQueue);

    // @lua "GJBaseGameLayer:process_rotation_actions"
    void processRotationActions();

    // @lua "GJBaseGameLayer:process_sfxobjects"
    void processSFXObjects();

    // @lua "GJBaseGameLayer:process_sfxstate"
    void processSFXState(SFXTriggerState* state1, SFXTriggerState* state2, int type, float levelTime);

    // @lua "GJBaseGameLayer:process_song_state"
    bool processSongState(int musicID, float spawnDelay, float levelTime, int songOffset, float volume, float speed, gd::vector<SongTriggerState>* states, SongTriggerGameObject* object);

    // @lua "GJBaseGameLayer:process_transform_actions"
    void processTransformActions(bool visibleFrame);

    // @lua "GJBaseGameLayer:refresh_counter_labels"
    void refreshCounterLabels();

    // @lua "GJBaseGameLayer:refresh_keyframe_anims"
    void refreshKeyframeAnims();

    // @lua "GJBaseGameLayer:remove_from_group"
    void removeFromGroup(GameObject* object, int groupID) override;

    // @lua "GJBaseGameLayer:remove_from_groups"
    void removeFromGroups(GameObject* object);

    // @lua "GJBaseGameLayer:remove_group_parent"
    void removeGroupParent(int groupID);

    // @lua "GJBaseGameLayer:remove_object_from_section"
    void removeObjectFromSection(GameObject* object);

    // @lua "GJBaseGameLayer:remove_released_buttons"
    void removeReleasedButtons();

    // @lua "GJBaseGameLayer:reset_active_enter_effects"
    void resetActiveEnterEffects();

    // @lua "GJBaseGameLayer:reset_area_object_values"
    bool resetAreaObjectValues(GameObject* object, bool update);

    // @lua "GJBaseGameLayer:reset_audio"
    void resetAudio();

    // @lua "GJBaseGameLayer:reset_camera"
    void resetCamera();

    // @lua "GJBaseGameLayer:reset_gradient_layers"
    void resetGradientLayers();

    // @lua "GJBaseGameLayer:reset_level_variables"
    void resetLevelVariables();

    // @lua "GJBaseGameLayer:reset_player"
    void resetPlayer();

    // @lua "GJBaseGameLayer:reset_record"
    void resetRecord(int steps, bool noFullReset);

    // @lua "GJBaseGameLayer:reset_spawn_channel_index"
    void resetSpawnChannelIndex();

    // @lua "GJBaseGameLayer:reset_static_camera"
    void resetStaticCamera(bool resetX, bool resetY);

    // @lua "GJBaseGameLayer:restore_remap"
    void restoreRemap(EffectGameObject* object, gd::unordered_map<int, int>& remap);

    // @lua "GJBaseGameLayer:resume_audio"
    void resumeAudio();

    // @lua "GJBaseGameLayer:reverse_direction"
    void reverseDirection(EffectGameObject* object) override;

    // @lua "GJBaseGameLayer:rotate_area_objects"
    void rotateAreaObjects(GameObject* object, cocos2d::CCArray* objects, float rotation, bool reset);

    // @lua "GJBaseGameLayer:rotate_gameplay"
    void rotateGameplay(RotateGameplayGameObject* object) override;

    // @lua "GJBaseGameLayer:rotate_object"
    void rotateObject(GameObject* object, float rotation);

    // @lua "GJBaseGameLayer:rotate_objects"
    void rotateObjects(cocos2d::CCArray* objects, float rotation, cocos2d::CCPoint position, cocos2d::CCPoint offset, bool finished, bool unused);

    // @lua "GJBaseGameLayer:set_group_parent"
    void setGroupParent(GameObject* object, int groupID);

    // @lua "GJBaseGameLayer:setup_layers"
    void setupLayers();

    // @lua "GJBaseGameLayer:setup_level_start"
    void setupLevelStart(LevelSettingsObject* settings);

    // @lua "GJBaseGameLayer:shake_camera"
    void shakeCamera(float duration, float strength, float interval);

    // @lua "GJBaseGameLayer:should_exit_hacked_level"
    bool shouldExitHackedLevel();

    // @lua "GJBaseGameLayer:sort_groups"
    void sortGroups();

    // @lua "GJBaseGameLayer:sort_section_vector"
    void sortSectionVector();

    // @lua "GJBaseGameLayer:sort_sticky_groups"
    void sortStickyGroups();

    // @lua "GJBaseGameLayer:spawn_group"
    void spawnGroup(int group, bool ordered, double delay, gd::vector<int> const& remapKeys, int triggerID, int controlID) override;

    // @lua "GJBaseGameLayer:spawn_object"
    void spawnObject(GameObject* object, double delay, gd::vector<int> const& remapKeys) override;

    // @lua "GJBaseGameLayer:spawn_objects_in_order"
    void spawnObjectsInOrder(cocos2d::CCArray* objects, double delay, gd::vector<int> const& remapKeys, int uniqueID, int controlID);

    // @lua "GJBaseGameLayer:spawn_particle"
    cocos2d::CCParticleSystemQuad* spawnParticle(char const* plist, int zOrder, cocos2d::tCCPositionType positionType, cocos2d::CCPoint position);

    // @lua "GJBaseGameLayer:spawn_particle_trigger@2"
    void spawnParticleTrigger(int particleID, cocos2d::CCPoint position, float rotation, float scale);

    // @lua "GJBaseGameLayer:speed_for_shader_target"
    cocos2d::CCPoint speedForShaderTarget(int groupID);

    // @lua "GJBaseGameLayer:static_objects_in_rect"
    cocos2d::CCArray* staticObjectsInRect(cocos2d::CCRect rect, bool enabledGroups);

    // @lua "GJBaseGameLayer:stop_custom_enter_effect@2"
    void stopCustomEnterEffect(EnterEffectObject* object, bool enter);

    // @lua "GJBaseGameLayer:switch_to_robot_mode"
    void switchToRobotMode(PlayerObject* player, GameObject* object, bool noPortal);

    // @lua "GJBaseGameLayer:switch_to_roll_mode"
    void switchToRollMode(PlayerObject* player, GameObject* object, bool noPortal);

    // @lua "GJBaseGameLayer:switch_to_spider_mode"
    void switchToSpiderMode(PlayerObject* player, GameObject* object, bool noPortal);

    // @lua "GJBaseGameLayer:sync_bgtextures"
    void syncBGTextures();

    // @lua "GJBaseGameLayer:teleport_player"
    void teleportPlayer(TeleportPortalObject* object, PlayerObject* player);

    // @lua "GJBaseGameLayer:toggle_audio_visualizer"
    void toggleAudioVisualizer(bool visible);

    // @lua "GJBaseGameLayer:toggle_dual_mode"
    void toggleDualMode(GameObject* object, bool dual, PlayerObject* player, bool noEffects);

    // @lua "GJBaseGameLayer:toggle_flipped"
    void toggleFlipped(bool flip, bool noEffects);

    // @lua "GJBaseGameLayer:toggle_group"
    void toggleGroup(int id, bool activate);

    // @lua "GJBaseGameLayer:toggle_group_triggered"
    void toggleGroupTriggered(int group, bool activate, gd::vector<int> const& remapKeys, int triggerID, int controlID) override;

    // @lua "GJBaseGameLayer:transform_area_objects"
    void transformAreaObjects(GameObject* object, cocos2d::CCArray* objects, float scaleX, float scaleY, bool reset);

    // @lua "GJBaseGameLayer:trigger_advanced_follow_edit_command"
    void triggerAdvancedFollowEditCommand(AdvancedFollowEditObject* object);

    // @lua "GJBaseGameLayer:trigger_area_effect"
    void triggerAreaEffect(EnterEffectObject* object);

    // @lua "GJBaseGameLayer:trigger_dynamic_rotate_command"
    void triggerDynamicRotateCommand(EnhancedTriggerObject* object);

    // @lua "GJBaseGameLayer:trigger_gradient_command"
    void triggerGradientCommand(GradientTriggerObject* object);

    // @lua "GJBaseGameLayer:trigger_move_command"
    void triggerMoveCommand(EffectGameObject* object);

    // @lua "GJBaseGameLayer:trigger_shader_command"
    void triggerShaderCommand(ShaderGameObject* object);

    // @lua "GJBaseGameLayer:trigger_transform_command"
    void triggerTransformCommand(TransformTriggerGameObject* object);

    // @lua "GJBaseGameLayer:try_get_main_object"
    GameObject* tryGetMainObject(int groupID);

    // @lua "GJBaseGameLayer:try_get_object"
    GameObject* tryGetObject(int groupID);

    // @lua "GJBaseGameLayer:unclaim_custom_particle"
    void unclaimCustomParticle(gd::string const& key, cocos2d::CCParticleSystemQuad* particle) override;

    // @lua "GJBaseGameLayer:unclaim_particle"
    void unclaimParticle(char const* key, cocos2d::CCParticleSystemQuad* particle);

    // @lua "GJBaseGameLayer:ungroup_sticky_objects"
    void ungroupStickyObjects(cocos2d::CCArray* objects);

    // @lua "GJBaseGameLayer:update"
    void update(float dt) override;

    // @lua "GJBaseGameLayer:update_audio_visualizer"
    void updateAudioVisualizer();

    // @lua "GJBaseGameLayer:update_camera"
    void updateCamera(float dt);

    // @lua "GJBaseGameLayer:update_camera_bgart"
    void updateCameraBGArt(cocos2d::CCPoint position, float zoom);

    // @lua "GJBaseGameLayer:update_camera_offset_x"
    void updateCameraOffsetX(float offsetX, float duration, int easingType, float easingRate, int uniqueID, int controlID);

    // @lua "GJBaseGameLayer:update_camera_offset_y"
    void updateCameraOffsetY(float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID);

    // @lua "GJBaseGameLayer:update_collision_blocks"
    void updateCollisionBlocks();

    // @lua "GJBaseGameLayer:update_color"
    void updateColor(cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2) override;

    // @lua "GJBaseGameLayer:update_counters"
    void updateCounters(int itemId, int value);

    // @lua "GJBaseGameLayer:update_debug_draw"
    void updateDebugDraw() override;

    // @lua "GJBaseGameLayer:update_dual_ground"
    void updateDualGround(PlayerObject* object, int mode, bool instant, float duration);

    // @lua "GJBaseGameLayer:update_enter_effects"
    void updateEnterEffects(float dt);

    // @lua "GJBaseGameLayer:update_extra_game_layers"
    void updateExtraGameLayers();

    // @lua "GJBaseGameLayer:update_gradient_layers"
    void updateGradientLayers();

    // @lua "GJBaseGameLayer:update_ground_shadows"
    void updateGroundShadows();

    // @lua "GJBaseGameLayer:update_guide_art"
    void updateGuideArt();

    // @lua "GJBaseGameLayer:update_keyframe_order"
    void updateKeyframeOrder(int keyframeGroup);

    // @lua "GJBaseGameLayer:update_layer_capacity"
    void updateLayerCapacity(gd::string capacityString);

    // @lua "GJBaseGameLayer:update_level_colors"
    void updateLevelColors();

    // @lua "GJBaseGameLayer:update_mgoffset_y"
    void updateMGOffsetY(float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID);

    // @lua "GJBaseGameLayer:update_max_gameplay_y"
    void updateMaxGameplayY();

    // @lua "GJBaseGameLayer:update_object_section"
    void updateObjectSection(GameObject* object) override;

    // @lua "GJBaseGameLayer:update_particles"
    void updateParticles(float dt);

    // @lua "GJBaseGameLayer:update_platformer_time"
    void updatePlatformerTime();

    // @lua "GJBaseGameLayer:update_player_collision_blocks"
    void updatePlayerCollisionBlocks();

    // @lua "GJBaseGameLayer:update_proximity_volume_effects"
    void updateProximityVolumeEffects();

    // @lua "GJBaseGameLayer:update_screen_rotation"
    void updateScreenRotation(float rotation, bool add, bool convert, float duration, int easingType, float easingRate, int uniqueID, int controlID) override;

    // @lua "GJBaseGameLayer:update_shader_layer"
    void updateShaderLayer(float dt);

    // @lua "GJBaseGameLayer:update_special_group_data"
    void updateSpecialGroupData();

    // @lua "GJBaseGameLayer:update_special_labels"
    void updateSpecialLabels();

    // @lua "GJBaseGameLayer:update_static_camera_pos"
    void updateStaticCameraPos(cocos2d::CCPoint pos, bool staticX, bool staticY, bool followOrSmoothEase, float time, int easingType, float easingRate);

    // @lua "GJBaseGameLayer:update_static_camera_pos_to_group"
    void updateStaticCameraPosToGroup(int centerID, bool updateX, bool updateY, bool followObject, float followEase, float duration, int easingType, float easingRate, bool smoothVelocity, float velocityMod);

    // @lua "GJBaseGameLayer:update_time_warp"
    void updateTimeWarp(float timeWarp) override;

    // @lua "GJBaseGameLayer:update_timer_labels"
    void updateTimerLabels();

    // @lua "GJBaseGameLayer:update_zoom"
    void updateZoom(float zoom, float duration, int easing, float rate, int uniqueID, int controlID);

    // @lua "GJBaseGameLayer:visit"
    void visit() override;

    // @lua "GJBaseGameLayer:visit_with_color_flash"
    void visitWithColorFlash();

    // @lua "GJBaseGameLayer:volume_for_proximity_effect"
    float volumeForProximityEffect(SFXTriggerInstance& instance);
};

} // namespace quartz