#include <quartz/bindings/GJBaseGameLayer.hpp>
#include <quartz/modified/GJBaseGameLayer.hpp>
#include <quartz/core/LuaManager.hpp>
#include <new>

namespace quartz {

GJBaseGameLayerBindings::GJBaseGameLayerBindings() {
    auto& luaManager = LuaManager::get();
    luaManager.queueBinding(
        [&luaManager]() {
            auto& state = luaManager.luaState();
            state.new_usertype<GJBaseGameLayer>("GJBaseGameLayer",
                sol::constructors<GJBaseGameLayer()>(),
                sol::base_classes, sol::bases<TriggerEffectDelegate, cocos2d::CCLayer>(),
                "above_shader_object_layer", &GJBaseGameLayer::m_aboveShaderObjectLayer,
                "above_shader_parent", &GJBaseGameLayer::m_aboveShaderParent,
                "active_gradients", &GJBaseGameLayer::m_activeGradients,
                "active_objects", &GJBaseGameLayer::m_activeObjects,
                "active_objects_count", &GJBaseGameLayer::m_activeObjectsCount,
                "active_objects_index", &GJBaseGameLayer::m_activeObjectsIndex,
                "active_sfx_triggers", &GJBaseGameLayer::m_activeSfxTriggers,
                "allow_static_rotate", &GJBaseGameLayer::m_allowStaticRotate,
                "anticheat_spike", &GJBaseGameLayer::m_anticheatSpike,
                "area_color_count", &GJBaseGameLayer::m_areaColorCount,
                "area_color_count_display", &GJBaseGameLayer::m_areaColorCountDisplay,
                "area_color_count_total", &GJBaseGameLayer::m_areaColorCountTotal,
                "area_color_count_total_display", &GJBaseGameLayer::m_areaColorCountTotalDisplay,
                "area_moved_count", &GJBaseGameLayer::m_areaMovedCount,
                "area_moved_count_display", &GJBaseGameLayer::m_areaMovedCountDisplay,
                "area_moved_count_total", &GJBaseGameLayer::m_areaMovedCountTotal,
                "area_moved_count_total_display", &GJBaseGameLayer::m_areaMovedCountTotalDisplay,
                "area_objects", &GJBaseGameLayer::m_areaObjects,
                "area_objects_count", &GJBaseGameLayer::m_areaObjectsCount,
                "area_objects_index", &GJBaseGameLayer::m_areaObjectsIndex,
                "area_objects_updated", &GJBaseGameLayer::m_areaObjectsUpdated,
                "area_rotate_node", &GJBaseGameLayer::m_areaRotateNode,
                "area_rotated_count", &GJBaseGameLayer::m_areaRotatedCount,
                "area_rotated_count_display", &GJBaseGameLayer::m_areaRotatedCountDisplay,
                "area_rotated_count_total", &GJBaseGameLayer::m_areaRotatedCountTotal,
                "area_rotated_count_total_display", &GJBaseGameLayer::m_areaRotatedCountTotalDisplay,
                "area_scale_node", &GJBaseGameLayer::m_areaScaleNode,
                "area_scaled_count", &GJBaseGameLayer::m_areaScaledCount,
                "area_scaled_count_display", &GJBaseGameLayer::m_areaScaledCountDisplay,
                "area_scaled_count_total", &GJBaseGameLayer::m_areaScaledCountTotal,
                "area_scaled_count_total_display", &GJBaseGameLayer::m_areaScaledCountTotalDisplay,
                "area_skew_node", &GJBaseGameLayer::m_areaSkewNode,
                "area_transform_node", &GJBaseGameLayer::m_areaTransformNode,
                "area_transform_node2", &GJBaseGameLayer::m_areaTransformNode2,
                "attempts", &GJBaseGameLayer::m_attempts,
                "audio_effects_layer", &GJBaseGameLayer::m_audioEffectsLayer,
                "audio_paused", &GJBaseGameLayer::m_audioPaused,
                "audio_visualizer_bg", &GJBaseGameLayer::m_audioVisualizerBG,
                "audio_visualizer_sfx", &GJBaseGameLayer::m_audioVisualizerSFX,
                "background", &GJBaseGameLayer::m_background,
                "batch_nodes", &GJBaseGameLayer::m_batchNodes,
                "blending", &GJBaseGameLayer::m_blending,
                "bottom_section_index", &GJBaseGameLayer::m_bottomSectionIndex,
                "calc_collision_block_objects", &GJBaseGameLayer::m_calcCollisionBlockObjects,
                "calc_collision_block_objects2", &GJBaseGameLayer::m_calcCollisionBlockObjects2,
                "calc_collision_block_objects2_size", &GJBaseGameLayer::m_calcCollisionBlockObjects2Size,
                "calc_collision_block_objects_size", &GJBaseGameLayer::m_calcCollisionBlockObjectsSize,
                "calc_non_effect_objects", &GJBaseGameLayer::m_calcNonEffectObjects,
                "calc_non_effect_objects_size", &GJBaseGameLayer::m_calcNonEffectObjectsSize,
                "calculate_target_height_offset", &GJBaseGameLayer::m_calculateTargetHeightOffset,
                "camera_flip", &GJBaseGameLayer::m_cameraFlip,
                "camera_height", &GJBaseGameLayer::m_cameraHeight,
                "camera_height_offset", &GJBaseGameLayer::m_cameraHeightOffset,
                "camera_obb2", &GJBaseGameLayer::m_cameraObb2,
                "camera_unzoomed_height_offset", &GJBaseGameLayer::m_cameraUnzoomedHeightOffset,
                "camera_unzoomed_x", &GJBaseGameLayer::m_cameraUnzoomedX,
                "camera_width", &GJBaseGameLayer::m_cameraWidth,
                "camera_width_offset", &GJBaseGameLayer::m_cameraWidthOffset,
                "claimed_particles", &GJBaseGameLayer::m_claimedParticles,
                "click_between_steps", &GJBaseGameLayer::m_clickBetweenSteps,
                "click_index", &GJBaseGameLayer::m_clickIndex,
                "click_on_steps", &GJBaseGameLayer::m_clickOnSteps,
                "clicks", &GJBaseGameLayer::m_clicks,
                "collected_items", &GJBaseGameLayer::m_collectedItems,
                "collision_block_section_sizes", &GJBaseGameLayer::m_collisionBlockSectionSizes,
                "collision_block_sections", &GJBaseGameLayer::m_collisionBlockSections,
                "collision_blocks", &GJBaseGameLayer::m_collisionBlocks,
                "current_step", &GJBaseGameLayer::m_currentStep,
                "custom_particle_count", &GJBaseGameLayer::m_customParticleCount,
                "custom_particles", &GJBaseGameLayer::m_customParticles,
                "custom_particles_uids", &GJBaseGameLayer::m_customParticlesUIDs,
                "debug_draw_node", &GJBaseGameLayer::m_debugDrawNode,
                "debug_draw_points", &GJBaseGameLayer::m_debugDrawPoints,
                "destroy_object_values", &GJBaseGameLayer::m_destroyObjectValues,
                "disable_player_hitbox", &GJBaseGameLayer::m_disablePlayerHitbox,
                "disabled_objects", &GJBaseGameLayer::m_disabledObjects,
                "disabled_objects_count", &GJBaseGameLayer::m_disabledObjectsCount,
                "disabled_objects_index", &GJBaseGameLayer::m_disabledObjectsIndex,
                "dual_touch_trigger", &GJBaseGameLayer::m_dualTouchTrigger,
                "effect_manager", &GJBaseGameLayer::m_effectManager,
                "enable22_changes", &GJBaseGameLayer::m_enable22Changes,
                "end_portal", &GJBaseGameLayer::m_endPortal,
                "enter_easing_indices", &GJBaseGameLayer::m_enterEasingIndices,
                "enter_easing_values", &GJBaseGameLayer::m_enterEasingValues,
                "enter_easing_values_index", &GJBaseGameLayer::m_enterEasingValuesIndex,
                "extra_delta", &GJBaseGameLayer::m_extraDelta,
                "extra_ldm", &GJBaseGameLayer::m_extraLDM,
                "fire_blending_layer_b0", &GJBaseGameLayer::m_fireBlendingLayerB0,
                "fire_blending_layer_b1", &GJBaseGameLayer::m_fireBlendingLayerB1,
                "fire_blending_layer_b2", &GJBaseGameLayer::m_fireBlendingLayerB2,
                "fire_blending_layer_b3", &GJBaseGameLayer::m_fireBlendingLayerB3,
                "fire_blending_layer_b4", &GJBaseGameLayer::m_fireBlendingLayerB4,
                "fire_blending_layer_b5", &GJBaseGameLayer::m_fireBlendingLayerB5,
                "fire_blending_layer_t1", &GJBaseGameLayer::m_fireBlendingLayerT1,
                "fire_blending_layer_t2", &GJBaseGameLayer::m_fireBlendingLayerT2,
                "fire_blending_layer_t3", &GJBaseGameLayer::m_fireBlendingLayerT3,
                "fire_blending_layer_t4", &GJBaseGameLayer::m_fireBlendingLayerT4,
                "fire_blending_layer_t5", &GJBaseGameLayer::m_fireBlendingLayerT5,
                "fire_layer_b1", &GJBaseGameLayer::m_fireLayerB1,
                "fire_layer_b2", &GJBaseGameLayer::m_fireLayerB2,
                "fire_layer_b3", &GJBaseGameLayer::m_fireLayerB3,
                "fire_layer_b4", &GJBaseGameLayer::m_fireLayerB4,
                "fire_layer_b5", &GJBaseGameLayer::m_fireLayerB5,
                "fire_layer_t1", &GJBaseGameLayer::m_fireLayerT1,
                "fire_layer_t2", &GJBaseGameLayer::m_fireLayerT2,
                "fire_layer_t3", &GJBaseGameLayer::m_fireLayerT3,
                "fire_layer_t4", &GJBaseGameLayer::m_fireLayerT4,
                "fix_negative_scale", &GJBaseGameLayer::m_fixNegativeScale,
                "flash_node", &GJBaseGameLayer::m_flashNode,
                "followed_count", &GJBaseGameLayer::m_followedCount,
                "followed_count_display", &GJBaseGameLayer::m_followedCountDisplay,
                "freeze_start_camera", &GJBaseGameLayer::m_freezeStartCamera,
                "game2_blending_layer_b0", &GJBaseGameLayer::m_game2BlendingLayerB0,
                "game2_blending_layer_b1", &GJBaseGameLayer::m_game2BlendingLayerB1,
                "game2_blending_layer_b2", &GJBaseGameLayer::m_game2BlendingLayerB2,
                "game2_blending_layer_b3", &GJBaseGameLayer::m_game2BlendingLayerB3,
                "game2_blending_layer_b4", &GJBaseGameLayer::m_game2BlendingLayerB4,
                "game2_blending_layer_b5", &GJBaseGameLayer::m_game2BlendingLayerB5,
                "game2_blending_layer_t1", &GJBaseGameLayer::m_game2BlendingLayerT1,
                "game2_blending_layer_t2", &GJBaseGameLayer::m_game2BlendingLayerT2,
                "game2_blending_layer_t3", &GJBaseGameLayer::m_game2BlendingLayerT3,
                "game2_blending_layer_t4", &GJBaseGameLayer::m_game2BlendingLayerT4,
                "game2_blending_layer_t5", &GJBaseGameLayer::m_game2BlendingLayerT5,
                "game2_layer_b0", &GJBaseGameLayer::m_game2LayerB0,
                "game2_layer_b1", &GJBaseGameLayer::m_game2LayerB1,
                "game2_layer_b2", &GJBaseGameLayer::m_game2LayerB2,
                "game2_layer_b3", &GJBaseGameLayer::m_game2LayerB3,
                "game2_layer_b4", &GJBaseGameLayer::m_game2LayerB4,
                "game2_layer_b5", &GJBaseGameLayer::m_game2LayerB5,
                "game2_layer_t1", &GJBaseGameLayer::m_game2LayerT1,
                "game2_layer_t2", &GJBaseGameLayer::m_game2LayerT2,
                "game2_layer_t3", &GJBaseGameLayer::m_game2LayerT3,
                "game2_layer_t4", &GJBaseGameLayer::m_game2LayerT4,
                "game_blending_layer_b0", &GJBaseGameLayer::m_gameBlendingLayerB0,
                "game_blending_layer_b1", &GJBaseGameLayer::m_gameBlendingLayerB1,
                "game_blending_layer_b2", &GJBaseGameLayer::m_gameBlendingLayerB2,
                "game_blending_layer_b3", &GJBaseGameLayer::m_gameBlendingLayerB3,
                "game_blending_layer_b4", &GJBaseGameLayer::m_gameBlendingLayerB4,
                "game_blending_layer_b5", &GJBaseGameLayer::m_gameBlendingLayerB5,
                "game_blending_layer_t1", &GJBaseGameLayer::m_gameBlendingLayerT1,
                "game_blending_layer_t2", &GJBaseGameLayer::m_gameBlendingLayerT2,
                "game_blending_layer_t3", &GJBaseGameLayer::m_gameBlendingLayerT3,
                "game_blending_layer_t4", &GJBaseGameLayer::m_gameBlendingLayerT4,
                "game_blending_layer_t5", &GJBaseGameLayer::m_gameBlendingLayerT5,
                "game_layer_b1", &GJBaseGameLayer::m_gameLayerB1,
                "game_layer_b2", &GJBaseGameLayer::m_gameLayerB2,
                "game_layer_b3", &GJBaseGameLayer::m_gameLayerB3,
                "game_layer_b4", &GJBaseGameLayer::m_gameLayerB4,
                "game_layer_b5", &GJBaseGameLayer::m_gameLayerB5,
                "game_layer_t1", &GJBaseGameLayer::m_gameLayerT1,
                "game_layer_t2", &GJBaseGameLayer::m_gameLayerT2,
                "game_layer_t3", &GJBaseGameLayer::m_gameLayerT3,
                "game_layer_t4", &GJBaseGameLayer::m_gameLayerT4,
                "game_state", &GJBaseGameLayer::m_gameState,
                "glitter_particles", &GJBaseGameLayer::m_glitterParticles,
                "glow_layer_b1", &GJBaseGameLayer::m_glowLayerB1,
                "glow_layer_b2", &GJBaseGameLayer::m_glowLayerB2,
                "glow_layer_b3", &GJBaseGameLayer::m_glowLayerB3,
                "glow_layer_b4", &GJBaseGameLayer::m_glowLayerB4,
                "glow_layer_b5", &GJBaseGameLayer::m_glowLayerB5,
                "glow_layer_t1", &GJBaseGameLayer::m_glowLayerT1,
                "glow_layer_t2", &GJBaseGameLayer::m_glowLayerT2,
                "glow_layer_t3", &GJBaseGameLayer::m_glowLayerT3,
                "glow_layer_t4", &GJBaseGameLayer::m_glowLayerT4,
                "gradient_layers", &GJBaseGameLayer::m_gradientLayers,
                "ground_layer", &GJBaseGameLayer::m_groundLayer,
                "ground_layer2", &GJBaseGameLayer::m_groundLayer2,
                "group_dict", &GJBaseGameLayer::m_groupDict,
                "groups", &GJBaseGameLayer::m_groups,
                "half_camera_width", &GJBaseGameLayer::m_halfCameraWidth,
                "hazard_collision_objects", &GJBaseGameLayer::m_hazardCollisionObjects,
                "hazard_collision_objects_count", &GJBaseGameLayer::m_hazardCollisionObjectsCount,
                "hazard_collision_objects_index", &GJBaseGameLayer::m_hazardCollisionObjectsIndex,
                "hide_ground", &GJBaseGameLayer::m_hideGround,
                "hitboxes_on_death", &GJBaseGameLayer::m_hitboxesOnDeath,
                "hover_node", &GJBaseGameLayer::m_hoverNode,
                "ignore_damage", &GJBaseGameLayer::m_ignoreDamage,
                "in_shader_object_layer", &GJBaseGameLayer::m_inShaderObjectLayer,
                "in_shader_parent", &GJBaseGameLayer::m_inShaderParent,
                "increased_layer_capacity", &GJBaseGameLayer::m_increasedLayerCapacity,
                "indicator_sprites", &GJBaseGameLayer::m_indicatorSprites,
                "is_between_steps", &GJBaseGameLayer::m_isBetweenSteps,
                "is_debug_draw_enabled", &GJBaseGameLayer::m_isDebugDrawEnabled,
                "is_editor", &GJBaseGameLayer::m_isEditor,
                "is_platformer", &GJBaseGameLayer::m_isPlatformer,
                "is_practice_mode", &GJBaseGameLayer::m_isPracticeMode,
                "is_test_mode", &GJBaseGameLayer::m_isTestMode,
                "jumping", &GJBaseGameLayer::m_jumping,
                "keep_group_parents", &GJBaseGameLayer::m_keepGroupParents,
                "keyframe_group", &GJBaseGameLayer::m_keyframeGroup,
                "keyframe_groups", &GJBaseGameLayer::m_keyframeGroups,
                "label_objects", &GJBaseGameLayer::m_labelObjects,
                "last_used_linked_id", &GJBaseGameLayer::m_lastUsedLinkedID,
                "left_section_index", &GJBaseGameLayer::m_leftSectionIndex,
                "level", &GJBaseGameLayer::m_level,
                "level_end_animation_started", &GJBaseGameLayer::m_levelEndAnimationStarted,
                "level_length", &GJBaseGameLayer::m_levelLength,
                "level_settings", &GJBaseGameLayer::m_levelSettings,
                "light_bgcolor", &GJBaseGameLayer::m_lightBGColor,
                "linked_group_dict", &GJBaseGameLayer::m_linkedGroupDict,
                "loading_layer", &GJBaseGameLayer::m_loadingLayer,
                "loading_progress", &GJBaseGameLayer::m_loadingProgress,
                "loading_start_position", &GJBaseGameLayer::m_loadingStartPosition,
                "low_detail_mode", &GJBaseGameLayer::m_lowDetailMode,
                "max_gameplay_y", &GJBaseGameLayer::m_maxGameplayY,
                "middleground", &GJBaseGameLayer::m_middleground,
                "moved_count", &GJBaseGameLayer::m_movedCount,
                "moved_count_display", &GJBaseGameLayer::m_movedCountDisplay,
                "non_effect_objects", &GJBaseGameLayer::m_nonEffectObjects,
                "non_effect_objects_flags", &GJBaseGameLayer::m_nonEffectObjectsFlags,
                "non_effect_objects_sizes", &GJBaseGameLayer::m_nonEffectObjectsSizes,
                "obb2", &GJBaseGameLayer::m_obb2,
                "object_layer", &GJBaseGameLayer::m_objectLayer,
                "object_parent", &GJBaseGameLayer::m_objectParent,
                "objects", &GJBaseGameLayer::m_objects,
                "objects_deactivated", &GJBaseGameLayer::m_objectsDeactivated,
                "objects_to_deactivate", &GJBaseGameLayer::m_objectsToDeactivate,
                "objects_to_move", &GJBaseGameLayer::m_objectsToMove,
                "optimized_group_dict", &GJBaseGameLayer::m_optimizedGroupDict,
                "optimized_groups", &GJBaseGameLayer::m_optimizedGroups,
                "orb_indicators", &GJBaseGameLayer::m_orbIndicators,
                "parent_group_ids", &GJBaseGameLayer::m_parentGroupIDs,
                "parent_groups_dict", &GJBaseGameLayer::m_parentGroupsDict,
                "particle_blending_layer_b0", &GJBaseGameLayer::m_particleBlendingLayerB0,
                "particle_blending_layer_b1", &GJBaseGameLayer::m_particleBlendingLayerB1,
                "particle_blending_layer_b2", &GJBaseGameLayer::m_particleBlendingLayerB2,
                "particle_blending_layer_b3", &GJBaseGameLayer::m_particleBlendingLayerB3,
                "particle_blending_layer_b4", &GJBaseGameLayer::m_particleBlendingLayerB4,
                "particle_blending_layer_b5", &GJBaseGameLayer::m_particleBlendingLayerB5,
                "particle_blending_layer_t1", &GJBaseGameLayer::m_particleBlendingLayerT1,
                "particle_blending_layer_t2", &GJBaseGameLayer::m_particleBlendingLayerT2,
                "particle_blending_layer_t3", &GJBaseGameLayer::m_particleBlendingLayerT3,
                "particle_blending_layer_t4", &GJBaseGameLayer::m_particleBlendingLayerT4,
                "particle_blending_layer_t5", &GJBaseGameLayer::m_particleBlendingLayerT5,
                "particle_count", &GJBaseGameLayer::m_particleCount,
                "particle_count_to_particle_string", &GJBaseGameLayer::m_particleCountToParticleString,
                "particle_layer_b1", &GJBaseGameLayer::m_particleLayerB1,
                "particle_layer_b2", &GJBaseGameLayer::m_particleLayerB2,
                "particle_layer_b3", &GJBaseGameLayer::m_particleLayerB3,
                "particle_layer_b4", &GJBaseGameLayer::m_particleLayerB4,
                "particle_layer_b5", &GJBaseGameLayer::m_particleLayerB5,
                "particle_layer_t1", &GJBaseGameLayer::m_particleLayerT1,
                "particle_layer_t2", &GJBaseGameLayer::m_particleLayerT2,
                "particle_layer_t3", &GJBaseGameLayer::m_particleLayerT3,
                "particle_layer_t4", &GJBaseGameLayer::m_particleLayerT4,
                "particle_system_limit", &GJBaseGameLayer::m_particleSystemLimit,
                "particles_dict", &GJBaseGameLayer::m_particlesDict,
                "persistent_state_string", &GJBaseGameLayer::m_persistentStateString,
                "pixel_blending_layer_b0", &GJBaseGameLayer::m_pixelBlendingLayerB0,
                "pixel_blending_layer_b1", &GJBaseGameLayer::m_pixelBlendingLayerB1,
                "pixel_blending_layer_b2", &GJBaseGameLayer::m_pixelBlendingLayerB2,
                "pixel_blending_layer_b3", &GJBaseGameLayer::m_pixelBlendingLayerB3,
                "pixel_blending_layer_b4", &GJBaseGameLayer::m_pixelBlendingLayerB4,
                "pixel_blending_layer_b5", &GJBaseGameLayer::m_pixelBlendingLayerB5,
                "pixel_blending_layer_t1", &GJBaseGameLayer::m_pixelBlendingLayerT1,
                "pixel_blending_layer_t2", &GJBaseGameLayer::m_pixelBlendingLayerT2,
                "pixel_blending_layer_t3", &GJBaseGameLayer::m_pixelBlendingLayerT3,
                "pixel_blending_layer_t4", &GJBaseGameLayer::m_pixelBlendingLayerT4,
                "pixel_blending_layer_t5", &GJBaseGameLayer::m_pixelBlendingLayerT5,
                "pixel_layer_b1", &GJBaseGameLayer::m_pixelLayerB1,
                "pixel_layer_b2", &GJBaseGameLayer::m_pixelLayerB2,
                "pixel_layer_b3", &GJBaseGameLayer::m_pixelLayerB3,
                "pixel_layer_b4", &GJBaseGameLayer::m_pixelLayerB4,
                "pixel_layer_b5", &GJBaseGameLayer::m_pixelLayerB5,
                "pixel_layer_t1", &GJBaseGameLayer::m_pixelLayerT1,
                "pixel_layer_t2", &GJBaseGameLayer::m_pixelLayerT2,
                "pixel_layer_t3", &GJBaseGameLayer::m_pixelLayerT3,
                "pixel_layer_t4", &GJBaseGameLayer::m_pixelLayerT4,
                "playback_mode", &GJBaseGameLayer::m_playbackMode,
                "player1", &GJBaseGameLayer::m_player1,
                "player1_collision_block", &GJBaseGameLayer::m_player1CollisionBlock,
                "player2", &GJBaseGameLayer::m_player2,
                "player2_collision_block", &GJBaseGameLayer::m_player2CollisionBlock,
                "player_died", &GJBaseGameLayer::m_playerDied,
                "points", &GJBaseGameLayer::m_points,
                "points_string", &GJBaseGameLayer::m_pointsString,
                "portal_indicators", &GJBaseGameLayer::m_portalIndicators,
                "practice_music_sync", &GJBaseGameLayer::m_practiceMusicSync,
                "processed_area_objects", &GJBaseGameLayer::m_processedAreaObjects,
                "processed_area_objects_count", &GJBaseGameLayer::m_processedAreaObjectsCount,
                "processed_area_objects_index", &GJBaseGameLayer::m_processedAreaObjectsIndex,
                "processing_audio_triggers", &GJBaseGameLayer::m_processingAudioTriggers,
                "queued_buttons", &GJBaseGameLayer::m_queuedButtons,
                "queued_recorded_buttons", &GJBaseGameLayer::m_queuedRecordedButtons,
                "queued_recorded_buttons_size", &GJBaseGameLayer::m_queuedRecordedButtonsSize,
                "queued_replay_buttons", &GJBaseGameLayer::m_queuedReplayButtons,
                "random_seed", &GJBaseGameLayer::m_randomSeed,
                "record_inputs", &GJBaseGameLayer::m_recordInputs,
                "record_string", &GJBaseGameLayer::m_recordString,
                "removed_parent_group_ids", &GJBaseGameLayer::m_removedParentGroupIDs,
                "replay_rand_seed", &GJBaseGameLayer::m_replayRandSeed,
                "reset_active_objects", &GJBaseGameLayer::m_resetActiveObjects,
                "resume_timer", &GJBaseGameLayer::m_resumeTimer,
                "right_section_index", &GJBaseGameLayer::m_rightSectionIndex,
                "rotated_count", &GJBaseGameLayer::m_rotatedCount,
                "rotated_count_display", &GJBaseGameLayer::m_rotatedCountDisplay,
                "save_position_objects", &GJBaseGameLayer::m_savePositionObjects,
                "save_position_values", &GJBaseGameLayer::m_savePositionValues,
                "saved_attempts", &GJBaseGameLayer::m_savedAttempts,
                "saved_persistent_state_string", &GJBaseGameLayer::m_savedPersistentStateString,
                "scaled_count", &GJBaseGameLayer::m_scaledCount,
                "scaled_count_display", &GJBaseGameLayer::m_scaledCountDisplay,
                "section_sizes", &GJBaseGameLayer::m_sectionSizes,
                "section_xfactor", &GJBaseGameLayer::m_sectionXFactor,
                "section_yfactor", &GJBaseGameLayer::m_sectionYFactor,
                "sections", &GJBaseGameLayer::m_sections,
                "sequence_triggers", &GJBaseGameLayer::m_sequenceTriggers,
                "shader_layer", &GJBaseGameLayer::m_shaderLayer,
                "show_audio_visualizer", &GJBaseGameLayer::m_showAudioVisualizer,
                "skip_art_reload", &GJBaseGameLayer::m_skipArtReload,
                "skip_camera_shake", &GJBaseGameLayer::m_skipCameraShake,
                "solid_collision_objects", &GJBaseGameLayer::m_solidCollisionObjects,
                "solid_collision_objects_count", &GJBaseGameLayer::m_solidCollisionObjectsCount,
                "solid_collision_objects_index", &GJBaseGameLayer::m_solidCollisionObjectsIndex,
                "song_trigger_interval", &GJBaseGameLayer::m_songTriggerInterval,
                "spawn_objects", &GJBaseGameLayer::m_spawnObjects,
                "spawn_objects_array", &GJBaseGameLayer::m_spawnObjectsArray,
                "spawn_remap_triggers", &GJBaseGameLayer::m_spawnRemapTriggers,
                "spawn_tuples", &GJBaseGameLayer::m_spawnTuples,
                "special_layer_b1", &GJBaseGameLayer::m_specialLayerB1,
                "special_layer_b2", &GJBaseGameLayer::m_specialLayerB2,
                "special_layer_b3", &GJBaseGameLayer::m_specialLayerB3,
                "special_layer_b4", &GJBaseGameLayer::m_specialLayerB4,
                "special_layer_b5", &GJBaseGameLayer::m_specialLayerB5,
                "special_layer_t1", &GJBaseGameLayer::m_specialLayerT1,
                "special_layer_t2", &GJBaseGameLayer::m_specialLayerT2,
                "special_layer_t3", &GJBaseGameLayer::m_specialLayerT3,
                "special_layer_t4", &GJBaseGameLayer::m_specialLayerT4,
                "start_optimization", &GJBaseGameLayer::m_startOptimization,
                "start_pos_object", &GJBaseGameLayer::m_startPosObject,
                "started", &GJBaseGameLayer::m_started,
                "starting_from_beginning", &GJBaseGameLayer::m_startingFromBeginning,
                "static_camera_shake", &GJBaseGameLayer::m_staticCameraShake,
                "static_group_dict", &GJBaseGameLayer::m_staticGroupDict,
                "static_groups", &GJBaseGameLayer::m_staticGroups,
                "sticky_groups", &GJBaseGameLayer::m_stickyGroups,
                "target_camera_height_offset", &GJBaseGameLayer::m_targetCameraHeightOffset,
                "target_groups", &GJBaseGameLayer::m_targetGroups,
                "target_groups_array", &GJBaseGameLayer::m_targetGroupsArray,
                "temporary_particles", &GJBaseGameLayer::m_temporaryParticles,
                "text_blending_layer_b1", &GJBaseGameLayer::m_textBlendingLayerB1,
                "text_blending_layer_b2", &GJBaseGameLayer::m_textBlendingLayerB2,
                "text_blending_layer_b3", &GJBaseGameLayer::m_textBlendingLayerB3,
                "text_blending_layer_b4", &GJBaseGameLayer::m_textBlendingLayerB4,
                "text_blending_layer_b5", &GJBaseGameLayer::m_textBlendingLayerB5,
                "text_blending_layer_t1", &GJBaseGameLayer::m_textBlendingLayerT1,
                "text_blending_layer_t2", &GJBaseGameLayer::m_textBlendingLayerT2,
                "text_blending_layer_t3", &GJBaseGameLayer::m_textBlendingLayerT3,
                "text_blending_layer_t4", &GJBaseGameLayer::m_textBlendingLayerT4,
                "text_layer_b1", &GJBaseGameLayer::m_textLayerB1,
                "text_layer_b2", &GJBaseGameLayer::m_textLayerB2,
                "text_layer_b3", &GJBaseGameLayer::m_textLayerB3,
                "text_layer_b4", &GJBaseGameLayer::m_textLayerB4,
                "text_layer_b5", &GJBaseGameLayer::m_textLayerB5,
                "text_layer_t1", &GJBaseGameLayer::m_textLayerT1,
                "text_layer_t2", &GJBaseGameLayer::m_textLayerT2,
                "text_layer_t3", &GJBaseGameLayer::m_textLayerT3,
                "text_layer_t4", &GJBaseGameLayer::m_textLayerT4,
                "tick_index", &GJBaseGameLayer::m_tickIndex,
                "time_label_objects", &GJBaseGameLayer::m_timeLabelObjects,
                "time_played", &GJBaseGameLayer::m_timePlayed,
                "timestamp", &GJBaseGameLayer::m_timestamp,
                "top_section_index", &GJBaseGameLayer::m_topSectionIndex,
                "ui_layer", &GJBaseGameLayer::m_uiLayer,
                "ui_object_layers", &GJBaseGameLayer::m_uiObjectLayers,
                "ui_object_positions", &GJBaseGameLayer::m_uiObjectPositions,
                "ui_objects", &GJBaseGameLayer::m_uiObjects,
                "ui_trigger_ui", &GJBaseGameLayer::m_uiTriggerUI,
                "unclaimed_particles", &GJBaseGameLayer::m_unclaimedParticles,
                "unk1000", &GJBaseGameLayer::m_unk1000,
                "unk3189", &GJBaseGameLayer::m_unk3189,
                "unk31f8", &GJBaseGameLayer::m_unk31f8,
                "unk322a", &GJBaseGameLayer::m_unk322a,
                "unk3251", &GJBaseGameLayer::m_unk3251,
                "unk32a1", &GJBaseGameLayer::m_unk32a1,
                "unk32a2", &GJBaseGameLayer::m_unk32a2,
                "unk32a3", &GJBaseGameLayer::m_unk32a3,
                "unk32a4", &GJBaseGameLayer::m_unk32a4,
                "unk32c8", &GJBaseGameLayer::m_unk32c8,
                "unk32d0", &GJBaseGameLayer::m_unk32d0,
                "unk32d4", &GJBaseGameLayer::m_unk32d4,
                "unk32e0", &GJBaseGameLayer::m_unk32e0,
                "unk32ec", &GJBaseGameLayer::m_unk32ec,
                "unk3330", &GJBaseGameLayer::m_unk3330,
                "unk3340", &GJBaseGameLayer::m_unk3340,
                "unk3358", &GJBaseGameLayer::m_unk3358,
                "unk3370", &GJBaseGameLayer::m_unk3370,
                "unk3380", &GJBaseGameLayer::m_unk3380,
                "unk3388", &GJBaseGameLayer::m_unk3388,
                "unk3390", &GJBaseGameLayer::m_unk3390,
                "unk33a0", &GJBaseGameLayer::m_unk33a0,
                "unk33c0", &GJBaseGameLayer::m_unk33c0,
                "unk8a0", &GJBaseGameLayer::m_unk8a0,
                "unkdd0", &GJBaseGameLayer::m_unkdd0,
                "unkdd8", &GJBaseGameLayer::m_unkdd8,
                "unke08", &GJBaseGameLayer::m_unke08,
                "unked0", &GJBaseGameLayer::m_unked0,
                "unked8", &GJBaseGameLayer::m_unked8,
                "unkee4", &GJBaseGameLayer::m_unkee4,
                "unkeec", &GJBaseGameLayer::m_unkeec,
                "update_ground_shadows", &GJBaseGameLayer::m_updateGroundShadows,
                "use_replay", &GJBaseGameLayer::m_useReplay,
                "variance_values", &GJBaseGameLayer::m_varianceValues,
                "visibility_groups", &GJBaseGameLayer::m_visibilityGroups,
                "visible_objects", &GJBaseGameLayer::m_visibleObjects,
                "visible_objects2", &GJBaseGameLayer::m_visibleObjects2,
                "visible_objects2_count", &GJBaseGameLayer::m_visibleObjects2Count,
                "visible_objects2_index", &GJBaseGameLayer::m_visibleObjects2Index,
                "visible_objects_count", &GJBaseGameLayer::m_visibleObjectsCount,
                "visible_objects_index", &GJBaseGameLayer::m_visibleObjectsIndex);

            sol::table usertype = state["GJBaseGameLayer"];

            // expose the custom fields to lua
            usertype.set_function("fields",
                [](sol::this_state s, GJBaseGameLayer* self) -> sol::table {
                    sol::state_view lua(s);

                    if (!self) {
                        return lua.create_table();
                    }

                    // this cast is required to access lua field storage
                    auto modifiedSelf = static_cast<GJBaseGameLayerModified*>(self);
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
                []() -> GJBaseGameLayer* {
                    GJBaseGameLayer* ptr = new(std::nothrow) GJBaseGameLayer();
                    return ptr;
                });

            // manual deallocation for `alloc()`
            usertype.set_function("free",
                [](GJBaseGameLayer* self) {
                    delete self;
                });

            usertype.set_function("activate_custom_ring",
                [](GJBaseGameLayer* self, RingObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->activateCustomRing(object);
                });

            usertype.set_function("activate_end_trigger",
                [](GJBaseGameLayer* self, int targetID, bool reverse, bool lockPlayerY) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->activateEndTrigger(targetID, reverse, lockPlayerY);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_event_trigger");
            usertype.set_function("activate_event_trigger",
                [](GJBaseGameLayer* self, EventLinkTrigger* object, gd::vector<int> const& remapKeys) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activateEventTrigger(object, remapKeys);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_item_compare_trigger");
            usertype.set_function("activate_item_compare_trigger",
                [](GJBaseGameLayer* self, ItemTriggerGameObject* object, gd::vector<int> const& remapKeys) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activateItemCompareTrigger(object, remapKeys);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_item_edit_trigger");
            usertype.set_function("activate_item_edit_trigger",
                [](GJBaseGameLayer* self, ItemTriggerGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activateItemEditTrigger(object);
                });

            usertype.set_function("activate_object_control_trigger",
                [](GJBaseGameLayer* self, ObjectControlGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->activateObjectControlTrigger(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_persistent_item_trigger");
            usertype.set_function("activate_persistent_item_trigger",
                [](GJBaseGameLayer* self, ItemTriggerGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activatePersistentItemTrigger(object);
                });

            usertype.set_function("activate_platformer_end_trigger",
                [](GJBaseGameLayer* self, EndTriggerGameObject* object, gd::vector<int> const& remapKeys) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->activatePlatformerEndTrigger(object, remapKeys);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_player_control_trigger");
            usertype.set_function("activate_player_control_trigger",
                [](GJBaseGameLayer* self, PlayerControlGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activatePlayerControlTrigger(object);
                });

            usertype.set_function("activate_reset_trigger",
                [](GJBaseGameLayer* self, EffectGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->activateResetTrigger(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_sfxedit_trigger");
            usertype.set_function("activate_sfxedit_trigger",
                [](GJBaseGameLayer* self, SFXTriggerGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activateSFXEditTrigger(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_sfxtrigger");
            usertype.set_function("activate_sfxtrigger",
                [](GJBaseGameLayer* self, SFXTriggerGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activateSFXTrigger(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_song_edit_trigger");
            usertype.set_function("activate_song_edit_trigger",
                [](GJBaseGameLayer* self, SongTriggerGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activateSongEditTrigger(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_song_trigger");
            usertype.set_function("activate_song_trigger",
                [](GJBaseGameLayer* self, SongTriggerGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activateSongTrigger(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:activate_timer_trigger");
            usertype.set_function("activate_timer_trigger",
                [](GJBaseGameLayer* self, TimerTriggerGameObject* object, gd::vector<int> const& remapKeys) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->activateTimerTrigger(object, remapKeys);
                });

            luaManager.addValidHook("GJBaseGameLayer:activated_audio_trigger");
            luaManager.addValidHook("GJBaseGameLayer:activated_audio_trigger@2");
            usertype.set_function("activated_audio_trigger",
                sol::overload(
                    [](GJBaseGameLayer* self, SFXTriggerGameObject* object) {
                        auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                        modifiedSelf->activatedAudioTrigger(object);
                    },
                    [](GJBaseGameLayer* self, SFXTriggerGameObject* object, float levelTime) {
                        auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                        modifiedSelf->activatedAudioTrigger(object, levelTime);
                    }));

            luaManager.addValidHook("GJBaseGameLayer:add_area_effect");
            usertype.set_function("add_area_effect",
                [](GJBaseGameLayer* self, EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJAreaActionType type) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->addAreaEffect(object, instances, type);
                });

            luaManager.addValidHook("GJBaseGameLayer:add_custom_enter_effect");
            usertype.set_function("add_custom_enter_effect",
                [](GJBaseGameLayer* self, EnterEffectObject* object, bool enter) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->addCustomEnterEffect(object, enter);
                });

            luaManager.addValidHook("GJBaseGameLayer:add_guide_art");
            usertype.set_function("add_guide_art",
                [](GJBaseGameLayer* self, GameObject* object) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->addGuideArt(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:add_keyframe");
            usertype.set_function("add_keyframe",
                [](GJBaseGameLayer* self, KeyframeGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->addKeyframe(object);
                });

            usertype.set_function("add_object_counter",
                [](GJBaseGameLayer* self, LabelGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addObjectCounter(object);
                });

            usertype.set_function("add_pickup_trigger",
                [](GJBaseGameLayer* self, CountTriggerGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addPickupTrigger(object);
                });

            usertype.set_function("add_points",
                [](GJBaseGameLayer* self, int points) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addPoints(points);
                });

            luaManager.addValidHook("GJBaseGameLayer:add_proximity_volume_effect");
            usertype.set_function("add_proximity_volume_effect",
                [](GJBaseGameLayer* self, int channelID, int targetType, SFXTriggerGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->addProximityVolumeEffect(channelID, targetType, object);
                });

            luaManager.addValidHook("GJBaseGameLayer:add_remap_targets");
            usertype.set_function("add_remap_targets",
                [](GJBaseGameLayer* self, gd::set<int>& targets) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->addRemapTargets(targets);
                });

            luaManager.addValidHook("GJBaseGameLayer:add_to_group");
            usertype.set_function("add_to_group",
                [](GJBaseGameLayer* self, GameObject* object, int groupID, bool triggerGroup) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->addToGroup(object, groupID, triggerGroup);
                });

            usertype.set_function("add_to_group_parents",
                [](GJBaseGameLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToGroupParents(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:add_to_groups");
            usertype.set_function("add_to_groups",
                [](GJBaseGameLayer* self, GameObject* object, bool duplicateTrigger) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->addToGroups(object, duplicateTrigger);
                });

            usertype.set_function("add_to_objects_to_show",
                [](GJBaseGameLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToObjectsToShow(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:add_to_section");
            usertype.set_function("add_to_section",
                [](GJBaseGameLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->addToSection(object);
                });

            usertype.set_function("add_to_speed_objects",
                [](GJBaseGameLayer* self, EffectGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToSpeedObjects(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:add_uiobject");
            usertype.set_function("add_uiobject",
                [](GJBaseGameLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->addUIObject(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:animate_in_dual_ground_new");
            usertype.set_function("animate_in_dual_ground_new",
                [](GJBaseGameLayer* self, GameObject* object, float height, bool instant, float duration) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->animateInDualGroundNew(object, height, instant, duration);
                });

            usertype.set_function("animate_in_ground_new",
                [](GJBaseGameLayer* self, bool unk1, float unk2, bool unk3) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->animateInGroundNew(unk1, unk2, unk3);
                });

            usertype.set_function("animate_out_ground_new",
                [](GJBaseGameLayer* self, bool instant) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->animateOutGroundNew(instant);
                });

            usertype.set_function("animate_portal_y",
                [](GJBaseGameLayer* self, float fromY, float toY, float duration, float easingRate) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->animatePortalY(fromY, toY, duration, easingRate);
                });

            usertype.set_function("apply_level_settings",
                [](GJBaseGameLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->applyLevelSettings(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:apply_remap");
            usertype.set_function("apply_remap",
                [](GJBaseGameLayer* self, EffectGameObject* object, gd::vector<int> const& remapKeys, gd::unordered_map<int, int>& remap) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->applyRemap(object, remapKeys, remap);
                });

            luaManager.addValidHook("GJBaseGameLayer:apply_sfxedit_trigger");
            usertype.set_function("apply_sfxedit_trigger",
                [](GJBaseGameLayer* self, int channelID, int targetType, SFXTriggerGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->applySFXEditTrigger(channelID, targetType, object);
                });

            usertype.set_function("apply_shake",
                [](GJBaseGameLayer* self, cocos2d::CCPoint& point) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->applyShake(point);
                });

            luaManager.addValidHook("GJBaseGameLayer:apply_time_warp");
            usertype.set_function("apply_time_warp",
                [](GJBaseGameLayer* self, float timeWarp) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->applyTimeWarp(timeWarp);
                });

            luaManager.addValidHook("GJBaseGameLayer:assign_new_sticky_groups");
            usertype.set_function("assign_new_sticky_groups",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->assignNewStickyGroups(objects);
                });

            usertype.set_function("async_bgloaded",
                [](GJBaseGameLayer* self, int background) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->asyncBGLoaded(background);
                });

            usertype.set_function("async_gloaded",
                [](GJBaseGameLayer* self, int ground) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->asyncGLoaded(ground);
                });

            usertype.set_function("async_mgloaded",
                [](GJBaseGameLayer* self, int middleground) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->asyncMGLoaded(middleground);
                });

            usertype.set_function("atlas_value",
                [](GJBaseGameLayer* self, int atlas) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->atlasValue(atlas);
                });

            luaManager.addValidHook("GJBaseGameLayer:bump_player");
            usertype.set_function("bump_player",
                [](GJBaseGameLayer* self, PlayerObject* player, EffectGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->bumpPlayer(player, object);
                });

            usertype.set_function("button_idto_button",
                [](GJBaseGameLayer* self, int id) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->buttonIDToButton(id);
                });

            luaManager.addValidHook("GJBaseGameLayer:button_is_relevant");
            usertype.set_function("button_is_relevant",
                [](GJBaseGameLayer* self, PlayerButtonCommand const& button) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->buttonIsRelevant(button);
                });

            luaManager.addValidHook("GJBaseGameLayer:calculate_color_groups");
            usertype.set_function("calculate_color_groups",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->calculateColorGroups();
                });

            usertype.set_function("camera_move_x",
                [](GJBaseGameLayer* self, float value, float duration, float rate, bool unused) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->cameraMoveX(value, duration, rate, unused);
                });

            usertype.set_function("camera_move_y",
                [](GJBaseGameLayer* self, float value, float duration, float rate, bool force) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->cameraMoveY(value, duration, rate, force);
                });

            luaManager.addValidHook("GJBaseGameLayer:can_be_activated_by_player");
            usertype.set_function("can_be_activated_by_player",
                [](GJBaseGameLayer* self, PlayerObject* player, EffectGameObject* object) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->canBeActivatedByPlayer(player, object);
                });

            luaManager.addValidHook("GJBaseGameLayer:can_process_sfx");
            usertype.set_function("can_process_sfx",
                [](GJBaseGameLayer* self, SFXTriggerState& state, gd::unordered_map<int, int>& stateIndices, gd::unordered_map<int, float>& times, gd::vector<SFXTriggerState>& states) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->canProcessSFX(state, stateIndices, times, states);
                });

            usertype.set_function("can_touch_object",
                [](GJBaseGameLayer* self, GameObject* object) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canTouchObject(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:check_camera_limit_after_teleport");
            usertype.set_function("check_camera_limit_after_teleport",
                [](GJBaseGameLayer* self, PlayerObject* player, float yOffset) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->checkCameraLimitAfterTeleport(player, yOffset);
                });

            luaManager.addValidHook("GJBaseGameLayer:check_collision");
            usertype.set_function("check_collision",
                [](GJBaseGameLayer* self, int blockAID, int blockBID) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->checkCollision(blockAID, blockBID);
                });

            luaManager.addValidHook("GJBaseGameLayer:check_collision_blocks");
            usertype.set_function("check_collision_blocks",
                [](GJBaseGameLayer* self, EffectGameObject* object, gd::vector<EffectGameObject *>* blocks, int blockCount) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->checkCollisionBlocks(object, blocks, blockCount);
                });

            luaManager.addValidHook("GJBaseGameLayer:check_collisions");
            usertype.set_function("check_collisions",
                [](GJBaseGameLayer* self, PlayerObject* object, float dt, bool ignoreDamage) -> int {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->checkCollisions(object, dt, ignoreDamage);
                });

            usertype.set_function("check_for_end",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->checkForEnd();
                });

            luaManager.addValidHook("GJBaseGameLayer:check_repell_player");
            usertype.set_function("check_repell_player",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->checkRepellPlayer();
                });

            usertype.set_function("check_snapshot",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->checkSnapshot();
                });

            luaManager.addValidHook("GJBaseGameLayer:check_spawn_objects");
            usertype.set_function("check_spawn_objects",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->checkSpawnObjects();
                });

            luaManager.addValidHook("GJBaseGameLayer:checkpoint_activated");
            usertype.set_function("checkpoint_activated",
                [](GJBaseGameLayer* self, CheckpointGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->checkpointActivated(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:claim_custom_particle");
            usertype.set_function("claim_custom_particle",
                [](GJBaseGameLayer* self, gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int zLayer, int zOrder, int uiObject, bool dontAdd) -> cocos2d::CCParticleSystemQuad* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->claimCustomParticle(key, particleStruct, zLayer, zOrder, uiObject, dontAdd);
                });

            luaManager.addValidHook("GJBaseGameLayer:claim_move_action");
            usertype.set_function("claim_move_action",
                [](GJBaseGameLayer* self, int groupID, bool ignoreStaticGroups) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->claimMoveAction(groupID, ignoreStaticGroups);
                });

            luaManager.addValidHook("GJBaseGameLayer:claim_particle");
            usertype.set_function("claim_particle",
                [](GJBaseGameLayer* self, gd::string key, int zLayer) -> cocos2d::CCParticleSystemQuad* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->claimParticle(key, zLayer);
                });

            luaManager.addValidHook("GJBaseGameLayer:claim_rotation_action");
            usertype.set_function("claim_rotation_action",
                [](GJBaseGameLayer* self, int targetID, int centerID, float& rotation, float& offset, bool ignoreStaticGroups, bool unused) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->claimRotationAction(targetID, centerID, rotation, offset, ignoreStaticGroups, unused);
                });

            usertype.set_function("clear_activated_audio_triggers",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->clearActivatedAudioTriggers();
                });

            usertype.set_function("clear_picked_up_items",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->clearPickedUpItems();
                });

            usertype.set_function("collected_object",
                [](GJBaseGameLayer* self, EffectGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->collectedObject(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:collision_check_objects");
            usertype.set_function("collision_check_objects",
                [](GJBaseGameLayer* self, PlayerObject* object, gd::vector<GameObject *>* objects, int objectCount, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->collisionCheckObjects(object, objects, objectCount, dt);
                });

            usertype.set_function("control_advanced_follow_command",
                [](GJBaseGameLayer* self, AdvancedFollowTriggerObject* object, int controlID, GJActionCommand command) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->controlAdvancedFollowCommand(object, controlID, command);
                });

            luaManager.addValidHook("GJBaseGameLayer:control_area_effect");
            usertype.set_function("control_area_effect",
                [](GJBaseGameLayer* self, EnterEffectObject* object, gd::vector<EnterEffectInstance>* instances, GJActionCommand command) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->controlAreaEffect(object, instances, command);
                });

            luaManager.addValidHook("GJBaseGameLayer:control_area_effect_with_id");
            usertype.set_function("control_area_effect_with_id",
                [](GJBaseGameLayer* self, int uniqueID, int controlID, GJActionCommand command) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->controlAreaEffectWithID(uniqueID, controlID, command);
                });

            usertype.set_function("control_dynamic_command",
                [](GJBaseGameLayer* self, EffectGameObject* object, int controlID, gd::vector<DynamicObjectAction>& actions, GJActionCommand command) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->controlDynamicCommand(object, controlID, actions, command);
                });

            usertype.set_function("control_dynamic_move_command",
                [](GJBaseGameLayer* self, EffectGameObject* object, int controlID, GJActionCommand command) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->controlDynamicMoveCommand(object, controlID, command);
                });

            usertype.set_function("control_dynamic_rotate_command",
                [](GJBaseGameLayer* self, EffectGameObject* object, int controlID, GJActionCommand command) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->controlDynamicRotateCommand(object, controlID, command);
                });

            luaManager.addValidHook("GJBaseGameLayer:control_event_link");
            usertype.set_function("control_event_link",
                [](GJBaseGameLayer* self, int uniqueID, int controlID, GJActionCommand command) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->controlEventLink(uniqueID, controlID, command);
                });

            usertype.set_function("control_gradient_trigger",
                [](GJBaseGameLayer* self, GradientTriggerObject* object, GJActionCommand command) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->controlGradientTrigger(object, command);
                });

            luaManager.addValidHook("GJBaseGameLayer:control_triggers_in_group");
            usertype.set_function("control_triggers_in_group",
                [](GJBaseGameLayer* self, int group, GJActionCommand command) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->controlTriggersInGroup(group, command);
                });

            luaManager.addValidHook("GJBaseGameLayer:control_triggers_with_control_id");
            usertype.set_function("control_triggers_with_control_id",
                [](GJBaseGameLayer* self, int controlID, GJActionCommand command) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->controlTriggersWithControlID(controlID, command);
                });

            luaManager.addValidHook("GJBaseGameLayer.convert_to_closest_direction");
            usertype.set_function("convert_to_closest_direction",
                [](float angle, float bound) -> float {
                    return quartz::GJBaseGameLayerModified::convertToClosestDirection(angle, bound);
                });

            usertype.set_function("count_collected_user_coins",
                [](GJBaseGameLayer* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->countCollectedUserCoins();
                });

            luaManager.addValidHook("GJBaseGameLayer:create_background");
            usertype.set_function("create_background",
                [](GJBaseGameLayer* self, int background) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->createBackground(background);
                });

            luaManager.addValidHook("GJBaseGameLayer:create_custom_particle");
            usertype.set_function("create_custom_particle",
                [](GJBaseGameLayer* self, gd::string const& key, cocos2d::ParticleStruct const& particleStruct, int minimum, bool dontAdd) -> cocos2d::CCParticleSystemQuad* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->createCustomParticle(key, particleStruct, minimum, dontAdd);
                });

            luaManager.addValidHook("GJBaseGameLayer:create_ground_layer");
            usertype.set_function("create_ground_layer",
                [](GJBaseGameLayer* self, int ground, int line) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->createGroundLayer(ground, line);
                });

            luaManager.addValidHook("GJBaseGameLayer:create_middleground");
            usertype.set_function("create_middleground",
                [](GJBaseGameLayer* self, int middleground) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->createMiddleground(middleground);
                });

            usertype.set_function("create_new_keyframe_anim",
                [](GJBaseGameLayer* self) -> cocos2d::CCArray* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->createNewKeyframeAnim();
                });

            luaManager.addValidHook("GJBaseGameLayer:create_particle");
            usertype.set_function("create_particle",
                [](GJBaseGameLayer* self, int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType) -> cocos2d::CCParticleSystemQuad* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->createParticle(objectType, plistName, tag, positionType);
                });

            luaManager.addValidHook("GJBaseGameLayer:create_player");
            usertype.set_function("create_player",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->createPlayer();
                });

            luaManager.addValidHook("GJBaseGameLayer:create_player_collision_block");
            usertype.set_function("create_player_collision_block",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->createPlayerCollisionBlock();
                });

            luaManager.addValidHook("GJBaseGameLayer:create_text_layers");
            usertype.set_function("create_text_layers",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->createTextLayers();
                });

            luaManager.addValidHook("GJBaseGameLayer:damaging_objects_in_rect");
            usertype.set_function("damaging_objects_in_rect",
                [](GJBaseGameLayer* self, cocos2d::CCRect rect, bool enabledGroups) -> cocos2d::CCArray* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->damagingObjectsInRect(rect, enabledGroups);
                });

            luaManager.addValidHook("GJBaseGameLayer:destroy_object");
            usertype.set_function("destroy_object",
                [](GJBaseGameLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->destroyObject(object);
                });

            usertype.set_function("destroy_player",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->destroyPlayer(player, object);
                });

            usertype.set_function("did_rotate_gameplay",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->didRotateGameplay();
                });

            usertype.set_function("enter_dual_mode",
                [](GJBaseGameLayer* self, GameObject* object, bool unused) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->enterDualMode(object, unused);
                });

            luaManager.addValidHook("GJBaseGameLayer:exit_static_camera");
            usertype.set_function("exit_static_camera",
                [](GJBaseGameLayer* self, bool exitX, bool exitY, float time, int easingType, float easingRate, bool smoothVelocity, float smoothVelocityMod, bool exitInstant) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->exitStaticCamera(exitX, exitY, time, easingType, easingRate, smoothVelocity, smoothVelocityMod, exitInstant);
                });

            usertype.set_function("flip_art",
                [](GJBaseGameLayer* self, bool flip) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->flipArt(flip);
                });

            usertype.set_function("flip_finished",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->flipFinished();
                });

            luaManager.addValidHook("GJBaseGameLayer:flip_gravity");
            usertype.set_function("flip_gravity",
                [](GJBaseGameLayer* self, PlayerObject* object, bool flip, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->flipGravity(object, flip, noEffects);
                });

            luaManager.addValidHook("GJBaseGameLayer:flip_objects");
            usertype.set_function("flip_objects",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->flipObjects();
                });

            luaManager.addValidHook("GJBaseGameLayer.game_event_to_string");
            usertype.set_function("game_event_to_string",
                [](GJGameEvent event) -> gd::string {
                    return quartz::GJBaseGameLayerModified::gameEventToString(event);
                });

            luaManager.addValidHook("GJBaseGameLayer:game_event_triggered");
            usertype.set_function("game_event_triggered",
                [](GJBaseGameLayer* self, GJGameEvent event, int material, int playerID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->gameEventTriggered(event, material, playerID);
                });

            luaManager.addValidHook("GJBaseGameLayer:generate_enter_easing_buffer");
            usertype.set_function("generate_enter_easing_buffer",
                [](GJBaseGameLayer* self, int easingType, float easingRate) -> int {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->generateEnterEasingBuffer(easingType, easingRate);
                });

            usertype.set_function("generate_enter_easing_buffers",
                [](GJBaseGameLayer* self, EnterEffectObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->generateEnterEasingBuffers(object);
                });

            usertype.set_function("generate_pickup_anim_rand_val",
                [](GJBaseGameLayer* self, GameObject* object, float& randomValue1, float& randomValue2) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->generatePickupAnimRandVal(object, randomValue1, randomValue2);
                });

            luaManager.addValidHook("GJBaseGameLayer:generate_spawn_remap");
            usertype.set_function("generate_spawn_remap",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->generateSpawnRemap();
                });

            luaManager.addValidHook("GJBaseGameLayer:generate_target_groups");
            usertype.set_function("generate_target_groups",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->generateTargetGroups();
                });

            luaManager.addValidHook("GJBaseGameLayer:generate_visibility_groups");
            usertype.set_function("generate_visibility_groups",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->generateVisibilityGroups();
                });

            usertype.set_function("get",
                []() -> GJBaseGameLayer* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call the original static function instead
                    return GJBaseGameLayer::get();
                });

            usertype.set_function("get_active_order_spawn_objects",
                [](GJBaseGameLayer* self) -> cocos2d::CCArray* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getActiveOrderSpawnObjects();
                });

            luaManager.addValidHook("GJBaseGameLayer:get_area_object_value");
            usertype.set_function("get_area_object_value",
                [](GJBaseGameLayer* self, EnterEffectInstance* instance, GameObject* object, cocos2d::CCPoint& position, bool& show) -> float {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getAreaObjectValue(instance, object, position, show);
                });

            usertype.set_function("get_bump_mod",
                [](GJBaseGameLayer* self, PlayerObject* player, int type) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getBumpMod(player, type);
                });

            usertype.set_function("get_camera_edge_value",
                [](GJBaseGameLayer* self, int type) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getCameraEdgeValue(type);
                });

            usertype.set_function("get_capacity_string",
                [](GJBaseGameLayer* self) -> gd::string {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getCapacityString();
                });

            usertype.set_function("get_center_group_object",
                [](GJBaseGameLayer* self, int groupID, int defaultID) -> GameObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getCenterGroupObject(groupID, defaultID);
                });

            usertype.set_function("get_custom_enter_effects",
                [](GJBaseGameLayer* self, int id, bool enter) -> gd::vector<EnterEffectInstance>* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getCustomEnterEffects(id, enter);
                });

            usertype.set_function("get_eased_area_value",
                [](GJBaseGameLayer* self, GameObject* object, EnterEffectInstance* instance, float value, bool show, int index) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getEasedAreaValue(object, instance, value, show, index);
                });

            usertype.set_function("get_enter_easing_key",
                [](GJBaseGameLayer* self, int easingType, float easingRate) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getEnterEasingKey(easingType, easingRate);
                });

            usertype.set_function("get_enter_easing_value",
                [](GJBaseGameLayer* self, float value, int easingType, float easingRate, int easingBuffer) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getEnterEasingValue(value, easingType, easingRate, easingBuffer);
                });

            luaManager.addValidHook("GJBaseGameLayer:get_follow_speed_val");
            usertype.set_function("get_follow_speed_val",
                [](GJBaseGameLayer* self, GameObject* object, int startSpeedRef, int startDirRef, float startDir, float startSpeed) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getFollowSpeedVal(object, startSpeedRef, startDirRef, startDir, startSpeed);
                });

            usertype.set_function("get_ground_height",
                [](GJBaseGameLayer* self, PlayerObject* player, int type) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getGroundHeight(player, type);
                });

            usertype.set_function("get_ground_height_for_mode",
                [](GJBaseGameLayer* self, int type) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getGroundHeightForMode(type);
                });

            luaManager.addValidHook("GJBaseGameLayer:get_group");
            usertype.set_function("get_group",
                [](GJBaseGameLayer* self, int id) -> cocos2d::CCArray* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getGroup(id);
                });

            usertype.set_function("get_group_parent",
                [](GJBaseGameLayer* self, int groupId) -> GameObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getGroupParent(groupId);
                });

            usertype.set_function("get_group_parents_string",
                [](GJBaseGameLayer* self, GameObject* object) -> gd::string {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getGroupParentsString(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:get_item_value");
            usertype.set_function("get_item_value",
                [](GJBaseGameLayer* self, int type, int id) -> double {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getItemValue(type, id);
                });

            luaManager.addValidHook("GJBaseGameLayer:get_max_portal_y");
            usertype.set_function("get_max_portal_y",
                [](GJBaseGameLayer* self) -> float {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getMaxPortalY();
                });

            luaManager.addValidHook("GJBaseGameLayer:get_min_distance");
            usertype.set_function("get_min_distance",
                [](GJBaseGameLayer* self, cocos2d::CCPoint position, cocos2d::CCArray* objects, float minNear, int mode) -> float {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getMinDistance(position, objects, minNear, mode);
                });

            luaManager.addValidHook("GJBaseGameLayer:get_min_portal_y");
            usertype.set_function("get_min_portal_y",
                [](GJBaseGameLayer* self) -> float {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getMinPortalY();
                });

            luaManager.addValidHook("GJBaseGameLayer:get_modified_delta");
            usertype.set_function("get_modified_delta",
                [](GJBaseGameLayer* self, float dt) -> double {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getModifiedDelta(dt);
                });

            usertype.set_function("get_move_target_delta",
                [](GJBaseGameLayer* self, EffectGameObject* object, bool mainObject) -> cocos2d::CCPoint {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getMoveTargetDelta(object, mainObject);
                });

            usertype.set_function("get_optimized_group",
                [](GJBaseGameLayer* self, int groupID) -> cocos2d::CCArray* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getOptimizedGroup(groupID);
                });

            usertype.set_function("get_other_player",
                [](GJBaseGameLayer* self, PlayerObject* player) -> PlayerObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getOtherPlayer(player);
                });

            luaManager.addValidHook("GJBaseGameLayer:get_particle_key");
            usertype.set_function("get_particle_key",
                [](GJBaseGameLayer* self, int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType) -> gd::string {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getParticleKey(objectType, plistName, tag, positionType);
                });

            luaManager.addValidHook("GJBaseGameLayer:get_particle_key2");
            usertype.set_function("get_particle_key2",
                [](GJBaseGameLayer* self, gd::string key) -> gd::string {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getParticleKey2(key);
                });

            usertype.set_function("get_play_timer_full_seconds",
                [](GJBaseGameLayer* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getPlayTimerFullSeconds();
                });

            usertype.set_function("get_play_timer_milli",
                [](GJBaseGameLayer* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getPlayTimerMilli();
                });

            usertype.set_function("get_player_button_id",
                [](GJBaseGameLayer* self, int button, bool player2) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getPlayerButtonID(button, player2);
                });

            usertype.set_function("get_portal_target",
                [](GJBaseGameLayer* self, TeleportPortalObject* object) -> TeleportPortalObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getPortalTarget(object);
                });

            usertype.set_function("get_portal_target_pos",
                [](GJBaseGameLayer* self, TeleportPortalObject* object, GameObject* target, PlayerObject* player) -> cocos2d::CCPoint {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getPortalTargetPos(object, target, player);
                });

            usertype.set_function("get_record_extra",
                [](GJBaseGameLayer* self) -> gd::string {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getRecordExtra();
                });

            luaManager.addValidHook("GJBaseGameLayer:get_record_string");
            usertype.set_function("get_record_string",
                [](GJBaseGameLayer* self, bool compress) -> gd::string {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getRecordString(compress);
                });

            usertype.set_function("get_rotate_command_targets",
                [](GJBaseGameLayer* self, EnhancedTriggerObject* object, GameObject*& centerObject, GameObject*& targetObject, GameObject*& rotateObject) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->getRotateCommandTargets(object, centerObject, targetObject, rotateObject);
                });

            luaManager.addValidHook("GJBaseGameLayer:get_saved_position");
            usertype.set_function("get_saved_position",
                [](GJBaseGameLayer* self, int groupID, float delay) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->getSavedPosition(groupID, delay);
                });

            usertype.set_function("get_scaled_ground_height",
                [](GJBaseGameLayer* self, float height) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getScaledGroundHeight(height);
                });

            usertype.set_function("get_single_group_object",
                [](GJBaseGameLayer* self, int groupID) -> GameObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getSingleGroupObject(groupID);
                });

            usertype.set_function("get_special_key",
                [](GJBaseGameLayer* self, int groupID, bool ignoreGroupParent, bool ignoreLinkedObjects) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getSpecialKey(groupID, ignoreGroupParent, ignoreLinkedObjects);
                });

            usertype.set_function("get_static_group",
                [](GJBaseGameLayer* self, int groupID) -> cocos2d::CCArray* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getStaticGroup(groupID);
                });

            usertype.set_function("get_sticky_group",
                [](GJBaseGameLayer* self, int group) -> cocos2d::CCArray* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getStickyGroup(group);
                });

            usertype.set_function("get_target_fly_camera_y",
                [](GJBaseGameLayer* self, GameObject* object) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getTargetFlyCameraY(object);
                });

            usertype.set_function("get_target_group",
                [](GJBaseGameLayer* self, int index, int uniqueID) -> cocos2d::CCArray* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getTargetGroup(index, uniqueID);
                });

            usertype.set_function("get_target_group_origin",
                [](GJBaseGameLayer* self, int index, int uniqueID) -> cocos2d::CCArray* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getTargetGroupOrigin(index, uniqueID);
                });

            usertype.set_function("grav_bump_player",
                [](GJBaseGameLayer* self, PlayerObject* player, EffectGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->gravBumpPlayer(player, object);
                });

            luaManager.addValidHook("GJBaseGameLayer:group_sticky_objects");
            usertype.set_function("group_sticky_objects",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->groupStickyObjects(objects);
                });

            luaManager.addValidHook("GJBaseGameLayer:handle_button");
            usertype.set_function("handle_button",
                [](GJBaseGameLayer* self, bool down, int button, bool isPlayer1) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->handleButton(down, button, isPlayer1);
                });

            usertype.set_function("has_item",
                [](GJBaseGameLayer* self, int id) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->hasItem(id);
                });

            luaManager.addValidHook("GJBaseGameLayer:has_unique_coin");
            usertype.set_function("has_unique_coin",
                [](GJBaseGameLayer* self, EffectGameObject* object) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->hasUniqueCoin(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:increase_batch_node_capacity");
            usertype.set_function("increase_batch_node_capacity",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->increaseBatchNodeCapacity();
                });

            luaManager.addValidHook("GJBaseGameLayer:init");
            usertype.set_function("init",
                [](GJBaseGameLayer* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->init();
                });

            usertype.set_function("is_flipping",
                [](GJBaseGameLayer* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isFlipping();
                });

            usertype.set_function("is_player2_button",
                [](GJBaseGameLayer* self, int button) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isPlayer2Button(button);
                });

            luaManager.addValidHook("GJBaseGameLayer:lightning_flash@2");
            usertype.set_function("lightning_flash",
                sol::overload(
                    [](GJBaseGameLayer* self, cocos2d::CCPoint to, cocos2d::ccColor3B color) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->lightningFlash(to, color);
                    },
                    [](GJBaseGameLayer* self, cocos2d::CCPoint from, cocos2d::CCPoint to, cocos2d::ccColor3B color, float lineWidth, float duration, int displacement, bool flash, float opacity) {
                        auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                        modifiedSelf->lightningFlash(from, to, color, lineWidth, duration, displacement, flash, opacity);
                    }));

            luaManager.addValidHook("GJBaseGameLayer:load_group_parents_from_string");
            usertype.set_function("load_group_parents_from_string",
                [](GJBaseGameLayer* self, GameObject* object, gd::string groupList) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->loadGroupParentsFromString(object, groupList);
                });

            luaManager.addValidHook("GJBaseGameLayer:load_level_settings");
            usertype.set_function("load_level_settings",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->loadLevelSettings();
                });

            luaManager.addValidHook("GJBaseGameLayer:load_start_pos_object");
            usertype.set_function("load_start_pos_object",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->loadStartPosObject();
                });

            luaManager.addValidHook("GJBaseGameLayer:load_up_to_position");
            usertype.set_function("load_up_to_position",
                [](GJBaseGameLayer* self, float position, int order, int channel) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->loadUpToPosition(position, order, channel);
                });

            usertype.set_function("manual_update_object_colors",
                [](GJBaseGameLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->manualUpdateObjectColors(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:max_zorder_for_shader_z");
            usertype.set_function("max_zorder_for_shader_z",
                [](GJBaseGameLayer* self, int zLayer) -> int {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->maxZOrderForShaderZ(zLayer);
                });

            luaManager.addValidHook("GJBaseGameLayer:min_zorder_for_shader_z");
            usertype.set_function("min_zorder_for_shader_z",
                [](GJBaseGameLayer* self, int zLayer) -> int {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->minZOrderForShaderZ(zLayer);
                });

            luaManager.addValidHook("GJBaseGameLayer:modify_group_physics");
            usertype.set_function("modify_group_physics",
                [](GJBaseGameLayer* self, AdvancedFollowEditObject* object, cocos2d::CCArray* group) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->modifyGroupPhysics(object, group);
                });

            usertype.set_function("modify_object_physics",
                [](GJBaseGameLayer* self, AdvancedFollowEditObject* object, GameObjectPhysics& physics) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->modifyObjectPhysics(object, physics);
                });

            usertype.set_function("move_area_object",
                [](GJBaseGameLayer* self, GameObject* object, float dx, float dy) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->moveAreaObject(object, dx, dy);
                });

            usertype.set_function("move_camera_to_pos",
                [](GJBaseGameLayer* self, cocos2d::CCPoint pos) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->moveCameraToPos(pos);
                });

            usertype.set_function("move_object",
                [](GJBaseGameLayer* self, GameObject* object, double dx, double dy, bool lockPlayerY) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->moveObject(object, dx, dy, lockPlayerY);
                });

            luaManager.addValidHook("GJBaseGameLayer:move_object_to_static_group");
            usertype.set_function("move_object_to_static_group",
                [](GJBaseGameLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->moveObjectToStaticGroup(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:move_objects");
            usertype.set_function("move_objects",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects, double dx, double dy, bool lockPlayerY) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->moveObjects(objects, dx, dy, lockPlayerY);
                });

            usertype.set_function("move_objects_silent",
                [](GJBaseGameLayer* self, int groupId, double dx, double dy) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->moveObjectsSilent(groupId, dx, dy);
                });

            usertype.set_function("object_intersects_circle",
                [](GJBaseGameLayer* self, GameObject* object, GameObject* circle) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->objectIntersectsCircle(object, circle);
                });

            luaManager.addValidHook("GJBaseGameLayer:object_type_to_game_event");
            usertype.set_function("object_type_to_game_event",
                [](GJBaseGameLayer* self, int type) -> GJGameEvent {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->objectTypeToGameEvent(type);
                });

            luaManager.addValidHook("GJBaseGameLayer:objects_collided");
            usertype.set_function("objects_collided",
                [](GJBaseGameLayer* self, int blockAID, int blockBID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->objectsCollided(blockAID, blockBID);
                });

            luaManager.addValidHook("GJBaseGameLayer:opacity_for_object");
            usertype.set_function("opacity_for_object",
                [](GJBaseGameLayer* self, GameObject* object) -> float {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->opacityForObject(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:optimize_move_groups");
            usertype.set_function("optimize_move_groups",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->optimizeMoveGroups();
                });

            luaManager.addValidHook("GJBaseGameLayer:order_spawn_objects");
            usertype.set_function("order_spawn_objects",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->orderSpawnObjects();
                });

            luaManager.addValidHook("GJBaseGameLayer:parent_for_zlayer");
            usertype.set_function("parent_for_zlayer",
                [](GJBaseGameLayer* self, int zLayer, bool blending, int parentMode, int uiObject) -> cocos2d::CCNode* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->parentForZLayer(zLayer, blending, parentMode, uiObject);
                });

            luaManager.addValidHook("GJBaseGameLayer:pause_audio");
            usertype.set_function("pause_audio",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->pauseAudio();
                });

            usertype.set_function("perform_math_operation",
                [](GJBaseGameLayer* self, double operand1, double operand2, int operation) -> double {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->performMathOperation(operand1, operand2, operation);
                });

            usertype.set_function("perform_math_rounding",
                [](GJBaseGameLayer* self, double value, int type) -> double {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->performMathRounding(value, type);
                });

            luaManager.addValidHook("GJBaseGameLayer:pickup_item");
            usertype.set_function("pickup_item",
                [](GJBaseGameLayer* self, EffectGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->pickupItem(object);
                });

            usertype.set_function("play_animation_command",
                [](GJBaseGameLayer* self, int id, int groupID) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playAnimationCommand(id, groupID);
                });

            luaManager.addValidHook("GJBaseGameLayer:play_exit_dual_effect");
            usertype.set_function("play_exit_dual_effect",
                [](GJBaseGameLayer* self, PlayerObject* player) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->playExitDualEffect(player);
                });

            usertype.set_function("play_flash_effect",
                [](GJBaseGameLayer* self, float duration, int flashes, float unknown) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playFlashEffect(duration, flashes, unknown);
                });

            usertype.set_function("play_gravity_effect",
                [](GJBaseGameLayer* self, bool flip) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playGravityEffect(flip);
                });

            luaManager.addValidHook("GJBaseGameLayer:play_keyframe_animation");
            usertype.set_function("play_keyframe_animation",
                [](GJBaseGameLayer* self, KeyframeAnimTriggerObject* object, gd::vector<int> const& remapKeys) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->playKeyframeAnimation(object, remapKeys);
                });

            usertype.set_function("play_speed_particle",
                [](GJBaseGameLayer* self, float timeMod) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playSpeedParticle(timeMod);
                });

            luaManager.addValidHook("GJBaseGameLayer:player_circle_collision");
            usertype.set_function("player_circle_collision",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->playerCircleCollision(player, object);
                });

            usertype.set_function("player_intersects_circle",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->playerIntersectsCircle(player, object);
                });

            usertype.set_function("player_took_damage",
                [](GJBaseGameLayer* self, PlayerObject* player) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playerTookDamage(player);
                });

            usertype.set_function("player_touched_object",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playerTouchedObject(player, object);
                });

            luaManager.addValidHook("GJBaseGameLayer:player_touched_ring");
            usertype.set_function("player_touched_ring",
                [](GJBaseGameLayer* self, PlayerObject* player, RingObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->playerTouchedRing(player, object);
                });

            luaManager.addValidHook("GJBaseGameLayer:player_touched_trigger");
            usertype.set_function("player_touched_trigger",
                [](GJBaseGameLayer* self, PlayerObject* player, EffectGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->playerTouchedTrigger(player, object);
                });

            usertype.set_function("player_was_touching_object",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->playerWasTouchingObject(player, object);
                });

            luaManager.addValidHook("GJBaseGameLayer:player_will_switch_mode");
            usertype.set_function("player_will_switch_mode",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->playerWillSwitchMode(player, object);
                });

            usertype.set_function("pos_for_time",
                [](GJBaseGameLayer* self, float time) -> cocos2d::CCPoint {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->posForTime(time);
                });

            luaManager.addValidHook("GJBaseGameLayer:position_for_shader_target");
            usertype.set_function("position_for_shader_target",
                [](GJBaseGameLayer* self, int groupID) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->positionForShaderTarget(groupID);
                });

            luaManager.addValidHook("GJBaseGameLayer:position_uiobjects");
            usertype.set_function("position_uiobjects",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->positionUIObjects();
                });

            usertype.set_function("post_update",
                [](GJBaseGameLayer* self, float dt) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->postUpdate(dt);
                });

            usertype.set_function("pre_resume_game",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->preResumeGame();
                });

            luaManager.addValidHook("GJBaseGameLayer:pre_update_visibility");
            usertype.set_function("pre_update_visibility",
                [](GJBaseGameLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->preUpdateVisibility(dt);
                });

            luaManager.addValidHook("GJBaseGameLayer:prepare_save_position_objects");
            usertype.set_function("prepare_save_position_objects",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->prepareSavePositionObjects();
                });

            usertype.set_function("prepare_transform_parent",
                [](GJBaseGameLayer* self, bool rotateNode) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->prepareTransformParent(rotateNode);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_activated_audio_triggers");
            usertype.set_function("process_activated_audio_triggers",
                [](GJBaseGameLayer* self, float levelTime) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processActivatedAudioTriggers(levelTime);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_advanced_follow_action");
            usertype.set_function("process_advanced_follow_action",
                [](GJBaseGameLayer* self, AdvancedFollowInstance& instance, bool started, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processAdvancedFollowAction(instance, started, dt);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_advanced_follow_actions");
            usertype.set_function("process_advanced_follow_actions",
                [](GJBaseGameLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processAdvancedFollowActions(dt);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_area_actions");
            usertype.set_function("process_area_actions",
                [](GJBaseGameLayer* self, float dt, bool visibleFrame) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processAreaActions(dt, visibleFrame);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_area_effects");
            usertype.set_function("process_area_effects",
                [](GJBaseGameLayer* self, gd::vector<EnterEffectInstance>* effects, GJAreaActionType type, float dt, bool visibleFrame) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processAreaEffects(effects, type, dt, visibleFrame);
                });

            usertype.set_function("process_area_fade_group_action",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, bool targetGroups) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->processAreaFadeGroupAction(objects, instance, position, targetGroups);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_area_move_group_action");
            usertype.set_function("process_area_move_group_action",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processAreaMoveGroupAction(objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_area_rotate_group_action");
            usertype.set_function("process_area_rotate_group_action",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processAreaRotateGroupAction(objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_area_tint_group_action");
            usertype.set_function("process_area_tint_group_action",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, bool targetGroups) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processAreaTintGroupAction(objects, instance, position, targetGroups);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_area_transform_group_action");
            usertype.set_function("process_area_transform_group_action",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects, EnterEffectInstance* instance, cocos2d::CCPoint position, int outerMin, int outerMax, int middleMin, int middleMax, int startIndex, bool targetGroups, bool reset) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processAreaTransformGroupAction(objects, instance, position, outerMin, outerMax, middleMin, middleMax, startIndex, targetGroups, reset);
                });

            usertype.set_function("process_area_visual_actions",
                [](GJBaseGameLayer* self, float dt) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->processAreaVisualActions(dt);
                });

            usertype.set_function("process_camera_object",
                [](GJBaseGameLayer* self, GameObject* object, PlayerObject* player) -> GameObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->processCameraObject(object, player);
                });

            usertype.set_function("process_checkpoints",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->processCheckpoints();
                });

            luaManager.addValidHook("GJBaseGameLayer:process_commands");
            usertype.set_function("process_commands",
                [](GJBaseGameLayer* self, float dt, bool isHalfTick, bool isLastTick) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processCommands(dt, isHalfTick, isLastTick);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_dynamic_object_actions");
            usertype.set_function("process_dynamic_object_actions",
                [](GJBaseGameLayer* self, int type, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processDynamicObjectActions(type, dt);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_follow_actions");
            usertype.set_function("process_follow_actions",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processFollowActions();
                });

            luaManager.addValidHook("GJBaseGameLayer:process_items");
            usertype.set_function("process_items",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processItems();
                });

            luaManager.addValidHook("GJBaseGameLayer:process_move_actions");
            usertype.set_function("process_move_actions",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processMoveActions();
                });

            luaManager.addValidHook("GJBaseGameLayer:process_move_actions_step");
            usertype.set_function("process_move_actions_step",
                [](GJBaseGameLayer* self, float dt, bool visibleFrame) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processMoveActionsStep(dt, visibleFrame);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_options_trigger");
            usertype.set_function("process_options_trigger",
                [](GJBaseGameLayer* self, GameOptionsTrigger* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processOptionsTrigger(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_player_follow_actions");
            usertype.set_function("process_player_follow_actions",
                [](GJBaseGameLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processPlayerFollowActions(dt);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_queued_audio_triggers");
            usertype.set_function("process_queued_audio_triggers",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processQueuedAudioTriggers();
                });

            luaManager.addValidHook("GJBaseGameLayer:process_queued_buttons");
            usertype.set_function("process_queued_buttons",
                [](GJBaseGameLayer* self, float dt, bool clearInputQueue) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processQueuedButtons(dt, clearInputQueue);
                });

            usertype.set_function("process_replay_checkpoint",
                [](GJBaseGameLayer* self, int id) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->processReplayCheckpoint(id);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_rotation_actions");
            usertype.set_function("process_rotation_actions",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processRotationActions();
                });

            luaManager.addValidHook("GJBaseGameLayer:process_sfxobjects");
            usertype.set_function("process_sfxobjects",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processSFXObjects();
                });

            luaManager.addValidHook("GJBaseGameLayer:process_sfxstate");
            usertype.set_function("process_sfxstate",
                [](GJBaseGameLayer* self, SFXTriggerState* state1, SFXTriggerState* state2, int type, float levelTime) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processSFXState(state1, state2, type, levelTime);
                });

            luaManager.addValidHook("GJBaseGameLayer:process_song_state");
            usertype.set_function("process_song_state",
                [](GJBaseGameLayer* self, int musicID, float spawnDelay, float levelTime, int songOffset, float volume, float speed, gd::vector<SongTriggerState>* states, SongTriggerGameObject* object) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->processSongState(musicID, spawnDelay, levelTime, songOffset, volume, speed, states, object);
                });

            usertype.set_function("process_state_objects",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->processStateObjects();
                });

            luaManager.addValidHook("GJBaseGameLayer:process_transform_actions");
            usertype.set_function("process_transform_actions",
                [](GJBaseGameLayer* self, bool visibleFrame) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->processTransformActions(visibleFrame);
                });

            usertype.set_function("queue_button",
                [](GJBaseGameLayer* self, int button, bool push, bool isPlayer2, double timestamp) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->queueButton(button, push, isPlayer2, timestamp);
                });

            usertype.set_function("queue_time_warp",
                [](GJBaseGameLayer* self, float timeWarp) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->queueTimeWarp(timeWarp);
                });

            usertype.set_function("re_add_to_sticky_group",
                [](GJBaseGameLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->reAddToStickyGroup(object);
                });

            usertype.set_function("record_action",
                [](GJBaseGameLayer* self, int button, bool down, bool player2) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->recordAction(button, down, player2);
                });

            usertype.set_function("rect_intersects_circle",
                [](GJBaseGameLayer* self, cocos2d::CCRect rect, cocos2d::CCPoint center, float radius) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->rectIntersectsCircle(rect, center, radius);
                });

            luaManager.addValidHook("GJBaseGameLayer:refresh_counter_labels");
            usertype.set_function("refresh_counter_labels",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->refreshCounterLabels();
                });

            luaManager.addValidHook("GJBaseGameLayer:refresh_keyframe_anims");
            usertype.set_function("refresh_keyframe_anims",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->refreshKeyframeAnims();
                });

            usertype.set_function("regenerate_enter_easing_buffers",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->regenerateEnterEasingBuffers();
                });

            usertype.set_function("register_spawn_remap",
                [](GJBaseGameLayer* self, gd::vector<ChanceObject>& spawnRemap) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->registerSpawnRemap(spawnRemap);
                });

            usertype.set_function("register_state_object",
                [](GJBaseGameLayer* self, EffectGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->registerStateObject(object);
                });

            usertype.set_function("remove_all_checkpoints",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeAllCheckpoints();
                });

            usertype.set_function("remove_background",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeBackground();
                });

            usertype.set_function("remove_custom_enter_effects",
                [](GJBaseGameLayer* self, int id, bool enter) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeCustomEnterEffects(id, enter);
                });

            luaManager.addValidHook("GJBaseGameLayer:remove_from_group");
            usertype.set_function("remove_from_group",
                [](GJBaseGameLayer* self, GameObject* object, int groupID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->removeFromGroup(object, groupID);
                });

            usertype.set_function("remove_from_group_parents",
                [](GJBaseGameLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeFromGroupParents(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:remove_from_groups");
            usertype.set_function("remove_from_groups",
                [](GJBaseGameLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->removeFromGroups(object);
                });

            usertype.set_function("remove_from_sticky_group",
                [](GJBaseGameLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeFromStickyGroup(object);
                });

            usertype.set_function("remove_ground_layer",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeGroundLayer();
                });

            luaManager.addValidHook("GJBaseGameLayer:remove_group_parent");
            usertype.set_function("remove_group_parent",
                [](GJBaseGameLayer* self, int groupID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->removeGroupParent(groupID);
                });

            usertype.set_function("remove_keyframe",
                [](GJBaseGameLayer* self, KeyframeGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeKeyframe(object);
                });

            usertype.set_function("remove_middleground",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeMiddleground();
                });

            luaManager.addValidHook("GJBaseGameLayer:remove_object_from_section");
            usertype.set_function("remove_object_from_section",
                [](GJBaseGameLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->removeObjectFromSection(object);
                });

            usertype.set_function("remove_player2",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removePlayer2();
                });

            luaManager.addValidHook("GJBaseGameLayer:remove_released_buttons");
            usertype.set_function("remove_released_buttons",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->removeReleasedButtons();
                });

            usertype.set_function("remove_temporary_particles",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeTemporaryParticles();
                });

            usertype.set_function("reorder_object_section",
                [](GJBaseGameLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->reorderObjectSection(object);
                });

            usertype.set_function("reparent_object",
                [](GJBaseGameLayer* self, cocos2d::CCNode* node, cocos2d::CCNode* parent) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->reparentObject(node, parent);
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_active_enter_effects");
            usertype.set_function("reset_active_enter_effects",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resetActiveEnterEffects();
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_area_object_values");
            usertype.set_function("reset_area_object_values",
                [](GJBaseGameLayer* self, GameObject* object, bool update) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->resetAreaObjectValues(object, update);
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_audio");
            usertype.set_function("reset_audio",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resetAudio();
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_camera");
            usertype.set_function("reset_camera",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resetCamera();
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_gradient_layers");
            usertype.set_function("reset_gradient_layers",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resetGradientLayers();
                });

            usertype.set_function("reset_group_counters",
                [](GJBaseGameLayer* self, bool reset) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetGroupCounters(reset);
                });

            usertype.set_function("reset_level",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetLevel();
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_level_variables");
            usertype.set_function("reset_level_variables",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resetLevelVariables();
                });

            usertype.set_function("reset_move_optimized_value",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetMoveOptimizedValue();
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_player");
            usertype.set_function("reset_player",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resetPlayer();
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_record");
            usertype.set_function("reset_record",
                [](GJBaseGameLayer* self, int steps, bool noFullReset) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resetRecord(steps, noFullReset);
                });

            usertype.set_function("reset_record_full",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetRecordFull();
                });

            usertype.set_function("reset_sptriggered",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetSPTriggered();
                });

            usertype.set_function("reset_song_trigger_values",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetSongTriggerValues();
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_spawn_channel_index");
            usertype.set_function("reset_spawn_channel_index",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resetSpawnChannelIndex();
                });

            luaManager.addValidHook("GJBaseGameLayer:reset_static_camera");
            usertype.set_function("reset_static_camera",
                [](GJBaseGameLayer* self, bool resetX, bool resetY) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resetStaticCamera(resetX, resetY);
                });

            usertype.set_function("reset_stopped_area_objects",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetStoppedAreaObjects();
                });

            usertype.set_function("restore_all_uiobjects",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->restoreAllUIObjects();
                });

            usertype.set_function("restore_default_gameplay_offset_x",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->restoreDefaultGameplayOffsetX();
                });

            usertype.set_function("restore_default_gameplay_offset_y",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->restoreDefaultGameplayOffsetY();
                });

            luaManager.addValidHook("GJBaseGameLayer:restore_remap");
            usertype.set_function("restore_remap",
                [](GJBaseGameLayer* self, EffectGameObject* object, gd::unordered_map<int, int>& remap) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->restoreRemap(object, remap);
                });

            luaManager.addValidHook("GJBaseGameLayer:resume_audio");
            usertype.set_function("resume_audio",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->resumeAudio();
                });

            luaManager.addValidHook("GJBaseGameLayer:reverse_direction");
            usertype.set_function("reverse_direction",
                [](GJBaseGameLayer* self, EffectGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->reverseDirection(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:rotate_area_objects");
            usertype.set_function("rotate_area_objects",
                [](GJBaseGameLayer* self, GameObject* object, cocos2d::CCArray* objects, float rotation, bool reset) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->rotateAreaObjects(object, objects, rotation, reset);
                });

            luaManager.addValidHook("GJBaseGameLayer:rotate_gameplay");
            usertype.set_function("rotate_gameplay",
                [](GJBaseGameLayer* self, RotateGameplayGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->rotateGameplay(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:rotate_object");
            usertype.set_function("rotate_object",
                [](GJBaseGameLayer* self, GameObject* object, float rotation) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->rotateObject(object, rotation);
                });

            luaManager.addValidHook("GJBaseGameLayer:rotate_objects");
            usertype.set_function("rotate_objects",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects, float rotation, cocos2d::CCPoint position, cocos2d::CCPoint offset, bool finished, bool unused) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->rotateObjects(objects, rotation, position, offset, finished, unused);
                });

            luaManager.addValidHook("GJBaseGameLayer:set_group_parent");
            usertype.set_function("set_group_parent",
                [](GJBaseGameLayer* self, GameObject* object, int groupID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->setGroupParent(object, groupID);
                });

            usertype.set_function("set_start_pos_object",
                [](GJBaseGameLayer* self, StartPosObject* startPos) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setStartPosObject(startPos);
                });

            luaManager.addValidHook("GJBaseGameLayer:setup_layers");
            usertype.set_function("setup_layers",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->setupLayers();
                });

            luaManager.addValidHook("GJBaseGameLayer:setup_level_start");
            usertype.set_function("setup_level_start",
                [](GJBaseGameLayer* self, LevelSettingsObject* settings) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->setupLevelStart(settings);
                });

            usertype.set_function("setup_replay",
                [](GJBaseGameLayer* self, gd::string inputs) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setupReplay(inputs);
                });

            luaManager.addValidHook("GJBaseGameLayer:shake_camera");
            usertype.set_function("shake_camera",
                [](GJBaseGameLayer* self, float duration, float strength, float interval) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->shakeCamera(duration, strength, interval);
                });

            luaManager.addValidHook("GJBaseGameLayer:should_exit_hacked_level");
            usertype.set_function("should_exit_hacked_level",
                [](GJBaseGameLayer* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->shouldExitHackedLevel();
                });

            usertype.set_function("should_use_substep_for_button",
                [](GJBaseGameLayer* self, float dt) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->shouldUseSubstepForButton(dt);
                });

            usertype.set_function("sort_all_groups_x",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->sortAllGroupsX();
                });

            luaManager.addValidHook("GJBaseGameLayer:sort_groups");
            usertype.set_function("sort_groups",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->sortGroups();
                });

            luaManager.addValidHook("GJBaseGameLayer:sort_section_vector");
            usertype.set_function("sort_section_vector",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->sortSectionVector();
                });

            luaManager.addValidHook("GJBaseGameLayer:sort_sticky_groups");
            usertype.set_function("sort_sticky_groups",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->sortStickyGroups();
                });

            luaManager.addValidHook("GJBaseGameLayer:spawn_group");
            usertype.set_function("spawn_group",
                [](GJBaseGameLayer* self, int group, bool ordered, double delay, gd::vector<int> const& remapKeys, int triggerID, int controlID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->spawnGroup(group, ordered, delay, remapKeys, triggerID, controlID);
                });

            usertype.set_function("spawn_group_triggered",
                [](GJBaseGameLayer* self, int targetID, float delay, bool spawnOrdered, gd::vector<int> const& remapKeys, int uniqueID, int controlID) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->spawnGroupTriggered(targetID, delay, spawnOrdered, remapKeys, uniqueID, controlID);
                });

            luaManager.addValidHook("GJBaseGameLayer:spawn_object");
            usertype.set_function("spawn_object",
                [](GJBaseGameLayer* self, GameObject* object, double delay, gd::vector<int> const& remapKeys) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->spawnObject(object, delay, remapKeys);
                });

            luaManager.addValidHook("GJBaseGameLayer:spawn_objects_in_order");
            usertype.set_function("spawn_objects_in_order",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects, double delay, gd::vector<int> const& remapKeys, int uniqueID, int controlID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->spawnObjectsInOrder(objects, delay, remapKeys, uniqueID, controlID);
                });

            luaManager.addValidHook("GJBaseGameLayer:spawn_particle");
            usertype.set_function("spawn_particle",
                [](GJBaseGameLayer* self, char const* plist, int zOrder, cocos2d::tCCPositionType positionType, cocos2d::CCPoint position) -> cocos2d::CCParticleSystemQuad* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->spawnParticle(plist, zOrder, positionType, position);
                });

            luaManager.addValidHook("GJBaseGameLayer:spawn_particle_trigger@2");
            usertype.set_function("spawn_particle_trigger",
                sol::overload(
                    [](GJBaseGameLayer* self, SpawnParticleGameObject* object) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->spawnParticleTrigger(object);
                    },
                    [](GJBaseGameLayer* self, int particleID, cocos2d::CCPoint position, float rotation, float scale) {
                        auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                        modifiedSelf->spawnParticleTrigger(particleID, position, rotation, scale);
                    }));

            usertype.set_function("spawn_player2",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->spawnPlayer2();
                });

            luaManager.addValidHook("GJBaseGameLayer:speed_for_shader_target");
            usertype.set_function("speed_for_shader_target",
                [](GJBaseGameLayer* self, int groupID) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->speedForShaderTarget(groupID);
                });

            luaManager.addValidHook("GJBaseGameLayer:static_objects_in_rect");
            usertype.set_function("static_objects_in_rect",
                [](GJBaseGameLayer* self, cocos2d::CCRect rect, bool enabledGroups) -> cocos2d::CCArray* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->staticObjectsInRect(rect, enabledGroups);
                });

            usertype.set_function("stop_all_ground_actions",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->stopAllGroundActions();
                });

            usertype.set_function("stop_camera_shake",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->stopCameraShake();
                });

            luaManager.addValidHook("GJBaseGameLayer:stop_custom_enter_effect@2");
            usertype.set_function("stop_custom_enter_effect",
                sol::overload(
                    [](GJBaseGameLayer* self, EnterEffectObject* object) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->stopCustomEnterEffect(object);
                    },
                    [](GJBaseGameLayer* self, EnterEffectObject* object, bool enter) {
                        auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                        modifiedSelf->stopCustomEnterEffect(object, enter);
                    }));

            usertype.set_function("stop_sfxtrigger",
                [](GJBaseGameLayer* self, SFXTriggerGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->stopSFXTrigger(object);
                });

            usertype.set_function("swap_background",
                [](GJBaseGameLayer* self, int background) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->swapBackground(background);
                });

            usertype.set_function("swap_ground",
                [](GJBaseGameLayer* self, int ground) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->swapGround(ground);
                });

            usertype.set_function("swap_middleground",
                [](GJBaseGameLayer* self, int middleground) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->swapMiddleground(middleground);
                });

            usertype.set_function("switch_to_fly_mode",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object, bool noPortal, int type) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->switchToFlyMode(player, object, noPortal, type);
                });

            luaManager.addValidHook("GJBaseGameLayer:switch_to_robot_mode");
            usertype.set_function("switch_to_robot_mode",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object, bool noPortal) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->switchToRobotMode(player, object, noPortal);
                });

            luaManager.addValidHook("GJBaseGameLayer:switch_to_roll_mode");
            usertype.set_function("switch_to_roll_mode",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object, bool noPortal) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->switchToRollMode(player, object, noPortal);
                });

            luaManager.addValidHook("GJBaseGameLayer:switch_to_spider_mode");
            usertype.set_function("switch_to_spider_mode",
                [](GJBaseGameLayer* self, PlayerObject* player, GameObject* object, bool noPortal) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->switchToSpiderMode(player, object, noPortal);
                });

            luaManager.addValidHook("GJBaseGameLayer:sync_bgtextures");
            usertype.set_function("sync_bgtextures",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->syncBGTextures();
                });

            luaManager.addValidHook("GJBaseGameLayer:teleport_player");
            usertype.set_function("teleport_player",
                [](GJBaseGameLayer* self, TeleportPortalObject* object, PlayerObject* player) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->teleportPlayer(object, player);
                });

            usertype.set_function("test_instant_count_trigger",
                [](GJBaseGameLayer* self, int itemID, int compareCount, int groupID, bool activateGroup, int triggerMode, gd::vector<int> const& remapKeys, int uniqueID, int controlID) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->testInstantCountTrigger(itemID, compareCount, groupID, activateGroup, triggerMode, remapKeys, uniqueID, controlID);
                });

            usertype.set_function("test_time",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->testTime();
                });

            usertype.set_function("time_for_pos",
                [](GJBaseGameLayer* self, cocos2d::CCPoint position, int order, int channel, bool songTriggers, int id) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->timeForPos(position, order, channel, songTriggers, id);
                });

            luaManager.addValidHook("GJBaseGameLayer:toggle_audio_visualizer");
            usertype.set_function("toggle_audio_visualizer",
                [](GJBaseGameLayer* self, bool visible) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->toggleAudioVisualizer(visible);
                });

            luaManager.addValidHook("GJBaseGameLayer:toggle_dual_mode");
            usertype.set_function("toggle_dual_mode",
                [](GJBaseGameLayer* self, GameObject* object, bool dual, PlayerObject* player, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->toggleDualMode(object, dual, player, noEffects);
                });

            luaManager.addValidHook("GJBaseGameLayer:toggle_flipped");
            usertype.set_function("toggle_flipped",
                [](GJBaseGameLayer* self, bool flip, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->toggleFlipped(flip, noEffects);
                });

            usertype.set_function("toggle_glitter",
                [](GJBaseGameLayer* self, bool visible) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleGlitter(visible);
                });

            usertype.set_function("toggle_ground_visibility",
                [](GJBaseGameLayer* self, bool visible) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleGroundVisibility(visible);
                });

            luaManager.addValidHook("GJBaseGameLayer:toggle_group");
            usertype.set_function("toggle_group",
                [](GJBaseGameLayer* self, int id, bool activate) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->toggleGroup(id, activate);
                });

            luaManager.addValidHook("GJBaseGameLayer:toggle_group_triggered");
            usertype.set_function("toggle_group_triggered",
                [](GJBaseGameLayer* self, int group, bool activate, gd::vector<int> const& remapKeys, int triggerID, int controlID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->toggleGroupTriggered(group, activate, remapKeys, triggerID, controlID);
                });

            usertype.set_function("toggle_hide_attempts",
                [](GJBaseGameLayer* self, bool hide) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleHideAttempts(hide);
                });

            usertype.set_function("toggle_info_label",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleInfoLabel();
                });

            usertype.set_function("toggle_lock_player",
                [](GJBaseGameLayer* self, bool disable, bool player2) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleLockPlayer(disable, player2);
                });

            usertype.set_function("toggle_mgvisibility",
                [](GJBaseGameLayer* self, bool visible) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleMGVisibility(visible);
                });

            usertype.set_function("toggle_music_in_practice",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleMusicInPractice();
                });

            usertype.set_function("toggle_player_streak_blend",
                [](GJBaseGameLayer* self, bool blend, bool force) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->togglePlayerStreakBlend(blend, force);
                });

            usertype.set_function("toggle_player_visibility",
                sol::overload(
                    [](GJBaseGameLayer* self, bool visible) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->togglePlayerVisibility(visible);
                    },
                    [](GJBaseGameLayer* self, bool visible, bool player1) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->togglePlayerVisibility(visible, player1);
                    }));

            usertype.set_function("toggle_progressbar",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->toggleProgressbar();
                });

            luaManager.addValidHook("GJBaseGameLayer:transform_area_objects");
            usertype.set_function("transform_area_objects",
                [](GJBaseGameLayer* self, GameObject* object, cocos2d::CCArray* objects, float scaleX, float scaleY, bool reset) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->transformAreaObjects(object, objects, scaleX, scaleY, reset);
                });

            usertype.set_function("trigger_advanced_follow_command",
                [](GJBaseGameLayer* self, AdvancedFollowTriggerObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->triggerAdvancedFollowCommand(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:trigger_advanced_follow_edit_command");
            usertype.set_function("trigger_advanced_follow_edit_command",
                [](GJBaseGameLayer* self, AdvancedFollowEditObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->triggerAdvancedFollowEditCommand(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:trigger_area_effect");
            usertype.set_function("trigger_area_effect",
                [](GJBaseGameLayer* self, EnterEffectObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->triggerAreaEffect(object);
                });

            usertype.set_function("trigger_area_effect_animation",
                [](GJBaseGameLayer* self, EnterEffectObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->triggerAreaEffectAnimation(object);
                });

            usertype.set_function("trigger_dynamic_move_command",
                [](GJBaseGameLayer* self, EffectGameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->triggerDynamicMoveCommand(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:trigger_dynamic_rotate_command");
            usertype.set_function("trigger_dynamic_rotate_command",
                [](GJBaseGameLayer* self, EnhancedTriggerObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->triggerDynamicRotateCommand(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:trigger_gradient_command");
            usertype.set_function("trigger_gradient_command",
                [](GJBaseGameLayer* self, GradientTriggerObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->triggerGradientCommand(object);
                });

            usertype.set_function("trigger_gravity_change",
                [](GJBaseGameLayer* self, EffectGameObject* object, int playerID) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->triggerGravityChange(object, playerID);
                });

            luaManager.addValidHook("GJBaseGameLayer:trigger_move_command");
            usertype.set_function("trigger_move_command",
                [](GJBaseGameLayer* self, EffectGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->triggerMoveCommand(object);
                });

            usertype.set_function("trigger_rotate_command",
                [](GJBaseGameLayer* self, EnhancedTriggerObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->triggerRotateCommand(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:trigger_shader_command");
            usertype.set_function("trigger_shader_command",
                [](GJBaseGameLayer* self, ShaderGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->triggerShaderCommand(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:trigger_transform_command");
            usertype.set_function("trigger_transform_command",
                [](GJBaseGameLayer* self, TransformTriggerGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->triggerTransformCommand(object);
                });

            usertype.set_function("try_get_group_parent",
                [](GJBaseGameLayer* self, int groupID) -> GameObject* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->tryGetGroupParent(groupID);
                });

            luaManager.addValidHook("GJBaseGameLayer:try_get_main_object");
            usertype.set_function("try_get_main_object",
                [](GJBaseGameLayer* self, int groupID) -> GameObject* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->tryGetMainObject(groupID);
                });

            luaManager.addValidHook("GJBaseGameLayer:try_get_object");
            usertype.set_function("try_get_object",
                [](GJBaseGameLayer* self, int groupID) -> GameObject* {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->tryGetObject(groupID);
                });

            usertype.set_function("try_resume_audio",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->tryResumeAudio();
                });

            luaManager.addValidHook("GJBaseGameLayer:unclaim_custom_particle");
            usertype.set_function("unclaim_custom_particle",
                [](GJBaseGameLayer* self, gd::string const& key, cocos2d::CCParticleSystemQuad* particle) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->unclaimCustomParticle(key, particle);
                });

            luaManager.addValidHook("GJBaseGameLayer:unclaim_particle");
            usertype.set_function("unclaim_particle",
                [](GJBaseGameLayer* self, char const* key, cocos2d::CCParticleSystemQuad* particle) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->unclaimParticle(key, particle);
                });

            luaManager.addValidHook("GJBaseGameLayer:ungroup_sticky_objects");
            usertype.set_function("ungroup_sticky_objects",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->ungroupStickyObjects(objects);
                });

            usertype.set_function("unlink_all_events",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->unlinkAllEvents();
                });

            luaManager.addValidHook("GJBaseGameLayer:update");
            usertype.set_function("update",
                [](GJBaseGameLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->update(dt);
                });

            usertype.set_function("update_active_enter_effect",
                [](GJBaseGameLayer* self, EnterEffectObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateActiveEnterEffect(object);
                });

            usertype.set_function("update_all_object_section",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateAllObjectSection();
                });

            usertype.set_function("update_area_object_last_values",
                [](GJBaseGameLayer* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateAreaObjectLastValues(object);
                });

            usertype.set_function("update_attempt_time",
                [](GJBaseGameLayer* self, float attemptTime) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateAttemptTime(attemptTime);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_audio_visualizer");
            usertype.set_function("update_audio_visualizer",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateAudioVisualizer();
                });

            usertype.set_function("update_bgart_speed",
                [](GJBaseGameLayer* self, float modX, float modY) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateBGArtSpeed(modX, modY);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_camera");
            usertype.set_function("update_camera",
                [](GJBaseGameLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateCamera(dt);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_camera_bgart");
            usertype.set_function("update_camera_bgart",
                [](GJBaseGameLayer* self, cocos2d::CCPoint position, float zoom) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateCameraBGArt(position, zoom);
                });

            usertype.set_function("update_camera_edge",
                [](GJBaseGameLayer* self, int direction, int value) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateCameraEdge(direction, value);
                });

            usertype.set_function("update_camera_mode",
                [](GJBaseGameLayer* self, EffectGameObject* obj, bool updateDual) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateCameraMode(obj, updateDual);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_camera_offset_x");
            usertype.set_function("update_camera_offset_x",
                [](GJBaseGameLayer* self, float offsetX, float duration, int easingType, float easingRate, int uniqueID, int controlID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateCameraOffsetX(offsetX, duration, easingType, easingRate, uniqueID, controlID);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_camera_offset_y");
            usertype.set_function("update_camera_offset_y",
                [](GJBaseGameLayer* self, float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateCameraOffsetY(offsetY, duration, easingType, easingRate, uniqueID, controlID);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_collision_blocks");
            usertype.set_function("update_collision_blocks",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateCollisionBlocks();
                });

            luaManager.addValidHook("GJBaseGameLayer:update_color");
            usertype.set_function("update_color",
                [](GJBaseGameLayer* self, cocos2d::ccColor3B& color, float fadeTime, int colorID, bool blending, float opacity, cocos2d::ccHSVValue& copyHSV, int colorIDToCopy, bool copyOpacity, EffectGameObject* callerObject, int unk1, int unk2) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateColor(color, fadeTime, colorID, blending, opacity, copyHSV, colorIDToCopy, copyOpacity, callerObject, unk1, unk2);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_counters");
            usertype.set_function("update_counters",
                [](GJBaseGameLayer* self, int itemId, int value) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateCounters(itemId, value);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_debug_draw");
            usertype.set_function("update_debug_draw",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateDebugDraw();
                });

            usertype.set_function("update_disabled_objects_last_pos",
                [](GJBaseGameLayer* self, cocos2d::CCArray* objects) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateDisabledObjectsLastPos(objects);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_dual_ground");
            usertype.set_function("update_dual_ground",
                [](GJBaseGameLayer* self, PlayerObject* object, int mode, bool instant, float duration) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateDualGround(object, mode, instant, duration);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_enter_effects");
            usertype.set_function("update_enter_effects",
                [](GJBaseGameLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateEnterEffects(dt);
                });

            usertype.set_function("update_extended_collision",
                [](GJBaseGameLayer* self, GameObject* object, bool extendedCollision) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateExtendedCollision(object, extendedCollision);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_extra_game_layers");
            usertype.set_function("update_extra_game_layers",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateExtraGameLayers();
                });

            usertype.set_function("update_gameplay_offset_x",
                [](GJBaseGameLayer* self, int offsetX, bool staticOffset) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateGameplayOffsetX(offsetX, staticOffset);
                });

            usertype.set_function("update_gameplay_offset_y",
                [](GJBaseGameLayer* self, int offsetY, bool staticOffset) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateGameplayOffsetY(offsetY, staticOffset);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_gradient_layers");
            usertype.set_function("update_gradient_layers",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateGradientLayers();
                });

            luaManager.addValidHook("GJBaseGameLayer:update_ground_shadows");
            usertype.set_function("update_ground_shadows",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateGroundShadows();
                });

            luaManager.addValidHook("GJBaseGameLayer:update_guide_art");
            usertype.set_function("update_guide_art",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateGuideArt();
                });

            usertype.set_function("update_internal_cam_offset_x",
                [](GJBaseGameLayer* self, float offsetX, float duration, float easingRate) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateInternalCamOffsetX(offsetX, duration, easingRate);
                });

            usertype.set_function("update_internal_cam_offset_y",
                [](GJBaseGameLayer* self, float offsetY, float duration, float easingRate) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateInternalCamOffsetY(offsetY, duration, easingRate);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_keyframe_order");
            usertype.set_function("update_keyframe_order",
                [](GJBaseGameLayer* self, int keyframeGroup) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateKeyframeOrder(keyframeGroup);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_layer_capacity");
            usertype.set_function("update_layer_capacity",
                [](GJBaseGameLayer* self, gd::string capacityString) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateLayerCapacity(capacityString);
                });

            usertype.set_function("update_legacy_layer_capacity",
                [](GJBaseGameLayer* self, int front, int frontBlend, int back, int backBlend) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateLegacyLayerCapacity(front, frontBlend, back, backBlend);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_level_colors");
            usertype.set_function("update_level_colors",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateLevelColors();
                });

            usertype.set_function("update_mgart_speed",
                [](GJBaseGameLayer* self, float modX, float modY) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateMGArtSpeed(modX, modY);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_mgoffset_y");
            usertype.set_function("update_mgoffset_y",
                [](GJBaseGameLayer* self, float offsetY, float duration, int easingType, float easingRate, int uniqueID, int controlID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateMGOffsetY(offsetY, duration, easingType, easingRate, uniqueID, controlID);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_max_gameplay_y");
            usertype.set_function("update_max_gameplay_y",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateMaxGameplayY();
                });

            usertype.set_function("update_obb2",
                [](GJBaseGameLayer* self, cocos2d::CCRect rect) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateOBB2(rect);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_object_section");
            usertype.set_function("update_object_section",
                [](GJBaseGameLayer* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateObjectSection(object);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_particles");
            usertype.set_function("update_particles",
                [](GJBaseGameLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateParticles(dt);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_platformer_time");
            usertype.set_function("update_platformer_time",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updatePlatformerTime();
                });

            luaManager.addValidHook("GJBaseGameLayer:update_player_collision_blocks");
            usertype.set_function("update_player_collision_blocks",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updatePlayerCollisionBlocks();
                });

            luaManager.addValidHook("GJBaseGameLayer:update_proximity_volume_effects");
            usertype.set_function("update_proximity_volume_effects",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateProximityVolumeEffects();
                });

            usertype.set_function("update_queued_labels",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateQueuedLabels();
                });

            usertype.set_function("update_replay",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateReplay();
                });

            usertype.set_function("update_save_position_objects",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateSavePositionObjects();
                });

            luaManager.addValidHook("GJBaseGameLayer:update_screen_rotation");
            usertype.set_function("update_screen_rotation",
                [](GJBaseGameLayer* self, float rotation, bool add, bool convert, float duration, int easingType, float easingRate, int uniqueID, int controlID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateScreenRotation(rotation, add, convert, duration, easingType, easingRate, uniqueID, controlID);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_shader_layer");
            usertype.set_function("update_shader_layer",
                [](GJBaseGameLayer* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateShaderLayer(dt);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_special_group_data");
            usertype.set_function("update_special_group_data",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateSpecialGroupData();
                });

            luaManager.addValidHook("GJBaseGameLayer:update_special_labels");
            usertype.set_function("update_special_labels",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateSpecialLabels();
                });

            luaManager.addValidHook("GJBaseGameLayer:update_static_camera_pos");
            usertype.set_function("update_static_camera_pos",
                [](GJBaseGameLayer* self, cocos2d::CCPoint pos, bool staticX, bool staticY, bool followOrSmoothEase, float time, int easingType, float easingRate) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateStaticCameraPos(pos, staticX, staticY, followOrSmoothEase, time, easingType, easingRate);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_static_camera_pos_to_group");
            usertype.set_function("update_static_camera_pos_to_group",
                [](GJBaseGameLayer* self, int centerID, bool updateX, bool updateY, bool followObject, float followEase, float duration, int easingType, float easingRate, bool smoothVelocity, float velocityMod) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateStaticCameraPosToGroup(centerID, updateX, updateY, followObject, followEase, duration, easingType, easingRate, smoothVelocity, velocityMod);
                });

            usertype.set_function("update_time_label",
                [](GJBaseGameLayer* self, int seconds, int centiseconds, bool decimals) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateTimeLabel(seconds, centiseconds, decimals);
                });

            usertype.set_function("update_time_mod",
                [](GJBaseGameLayer* self, float speed, bool players, bool noEffects) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateTimeMod(speed, players, noEffects);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_time_warp");
            usertype.set_function("update_time_warp",
                [](GJBaseGameLayer* self, float timeWarp) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateTimeWarp(timeWarp);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_timer_labels");
            usertype.set_function("update_timer_labels",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateTimerLabels();
                });

            usertype.set_function("update_verify_damage",
                [](GJBaseGameLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateVerifyDamage();
                });

            usertype.set_function("update_visibility",
                [](GJBaseGameLayer* self, float dt) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateVisibility(dt);
                });

            luaManager.addValidHook("GJBaseGameLayer:update_zoom");
            usertype.set_function("update_zoom",
                [](GJBaseGameLayer* self, float zoom, float duration, int easing, float rate, int uniqueID, int controlID) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->updateZoom(zoom, duration, easing, rate, uniqueID, controlID);
                });

            luaManager.addValidHook("GJBaseGameLayer:visit");
            usertype.set_function("visit",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->visit();
                });

            luaManager.addValidHook("GJBaseGameLayer:visit_with_color_flash");
            usertype.set_function("visit_with_color_flash",
                [](GJBaseGameLayer* self) {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    modifiedSelf->visitWithColorFlash();
                });

            luaManager.addValidHook("GJBaseGameLayer:volume_for_proximity_effect");
            usertype.set_function("volume_for_proximity_effect",
                [](GJBaseGameLayer* self, SFXTriggerInstance& instance) -> float {
                    auto modifiedSelf = static_cast<quartz::GJBaseGameLayerModified*>(self);
                    return modifiedSelf->volumeForProximityEffect(instance);
                });
        });
}

} // namespace quartz