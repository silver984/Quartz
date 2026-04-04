#include <quartz/bindings/PlayerObject.hpp>
#include <quartz/modified/PlayerObject.hpp>
#include <quartz/core/LuaManager.hpp>
#include <new>

namespace quartz {

PlayerObjectBindings::PlayerObjectBindings() {
    auto& luaManager = LuaManager::get();
    luaManager.queueBinding(
        [&luaManager]() {
            auto& state = luaManager.luaState();
            state.new_usertype<PlayerObject>("PlayerObject",
                sol::constructors<PlayerObject()>(),
                sol::base_classes, sol::bases<AnimatedSpriteDelegate, GameObject>(),
                "acceleration_or_speed", &PlayerObject::m_accelerationOrSpeed,
                "action_manager", &PlayerObject::m_actionManager,
                "affected_by_forces", &PlayerObject::m_affectedByForces,
                "always_show_streak", &PlayerObject::m_alwaysShowStreak,
                "audio_scale", &PlayerObject::m_audioScale,
                "bird_vehicle", &PlayerObject::m_birdVehicle,
                "black_orb_related", &PlayerObject::m_blackOrbRelated,
                "can_place_checkpoint", &PlayerObject::m_canPlaceCheckpoint,
                "changed_directions_time", &PlayerObject::m_changedDirectionsTime,
                "checkpoint_timeout", &PlayerObject::m_checkpointTimeout,
                "collided_bottom_max_y", &PlayerObject::m_collidedBottomMaxY,
                "collided_left_max_x", &PlayerObject::m_collidedLeftMaxX,
                "collided_object", &PlayerObject::m_collidedObject,
                "collided_right_min_x", &PlayerObject::m_collidedRightMinX,
                "collided_top_min_y", &PlayerObject::m_collidedTopMinY,
                "colliding_with_left", &PlayerObject::m_collidingWithLeft,
                "colliding_with_right", &PlayerObject::m_collidingWithRight,
                "colliding_with_slope_id", &PlayerObject::m_collidingWithSlopeId,
                "collision_log_bottom", &PlayerObject::m_collisionLogBottom,
                "collision_log_left", &PlayerObject::m_collisionLogLeft,
                "collision_log_right", &PlayerObject::m_collisionLogRight,
                "collision_log_top", &PlayerObject::m_collisionLogTop,
                "controls_disabled", &PlayerObject::m_controlsDisabled,
                "current_potential_slope", &PlayerObject::m_currentPotentialSlope,
                "current_robot_animation", &PlayerObject::m_currentRobotAnimation,
                "current_slope", &PlayerObject::m_currentSlope,
                "current_slope2", &PlayerObject::m_currentSlope2,
                "current_slope_yvelocity", &PlayerObject::m_currentSlopeYVelocity,
                "dash_angle", &PlayerObject::m_dashAngle,
                "dash_fire_sprite", &PlayerObject::m_dashFireSprite,
                "dash_particles", &PlayerObject::m_dashParticles,
                "dash_ring", &PlayerObject::m_dashRing,
                "dash_sprites_container", &PlayerObject::m_dashSpritesContainer,
                "dash_start_time", &PlayerObject::m_dashStartTime,
                "dash_x", &PlayerObject::m_dashX,
                "dash_y", &PlayerObject::m_dashY,
                "decrease_boost_slide", &PlayerObject::m_decreaseBoostSlide,
                "default_mini_icon", &PlayerObject::m_defaultMiniIcon,
                "disable_player_squeeze", &PlayerObject::m_disablePlayerSqueeze,
                "disable_streak_tint", &PlayerObject::m_disableStreakTint,
                "enable22_changes", &PlayerObject::m_enable22Changes,
                "fade_out_streak", &PlayerObject::m_fadeOutStreak,
                "fall_speed", &PlayerObject::m_fallSpeed,
                "fall_start_y", &PlayerObject::m_fallStartY,
                "fix_gravity_bug", &PlayerObject::m_fixGravityBug,
                "fix_robot_jump", &PlayerObject::m_fixRobotJump,
                "flash_delay", &PlayerObject::m_flashDelay,
                "flash_duration", &PlayerObject::m_flashDuration,
                "flash_main_color", &PlayerObject::m_flashMainColor,
                "flash_second_color", &PlayerObject::m_flashSecondColor,
                "flash_time", &PlayerObject::m_flashTime,
                "follow_related", &PlayerObject::m_followRelated,
                "game_layer", &PlayerObject::m_gameLayer,
                "game_mode_changed_time", &PlayerObject::m_gameModeChangedTime,
                "ghost_trail", &PlayerObject::m_ghostTrail,
                "ghost_type", &PlayerObject::m_ghostType,
                "glow_color", &PlayerObject::m_glowColor,
                "gravity", &PlayerObject::m_gravity,
                "gravity_mod", &PlayerObject::m_gravityMod,
                "ground_object_material", &PlayerObject::m_groundObjectMaterial,
                "ground_yvelocity", &PlayerObject::m_groundYVelocity,
                "gv0123", &PlayerObject::m_gv0123,
                "has_custom_glow_color", &PlayerObject::m_hasCustomGlowColor,
                "has_ever_hit_ring", &PlayerObject::m_hasEverHitRing,
                "has_ever_jumped", &PlayerObject::m_hasEverJumped,
                "has_glow", &PlayerObject::m_hasGlow,
                "has_ground_particles", &PlayerObject::m_hasGroundParticles,
                "has_ship_particles", &PlayerObject::m_hasShipParticles,
                "holding_buttons", &PlayerObject::m_holdingButtons,
                "holding_left", &PlayerObject::m_holdingLeft,
                "holding_right", &PlayerObject::m_holdingRight,
                "icon_glow", &PlayerObject::m_iconGlow,
                "icon_request_id", &PlayerObject::m_iconRequestID,
                "icon_sprite", &PlayerObject::m_iconSprite,
                "icon_sprite_secondary", &PlayerObject::m_iconSpriteSecondary,
                "icon_sprite_whitener", &PlayerObject::m_iconSpriteWhitener,
                "ignore_damage", &PlayerObject::m_ignoreDamage,
                "inputs_locked", &PlayerObject::m_inputsLocked,
                "is_accelerating", &PlayerObject::m_isAccelerating,
                "is_ball", &PlayerObject::m_isBall,
                "is_ball_rotating", &PlayerObject::m_isBallRotating,
                "is_ball_rotating2", &PlayerObject::m_isBallRotating2,
                "is_being_spawned_by_dual_portal", &PlayerObject::m_isBeingSpawnedByDualPortal,
                "is_bird", &PlayerObject::m_isBird,
                "is_colliding_with_slope", &PlayerObject::m_isCollidingWithSlope,
                "is_current_slope_top", &PlayerObject::m_isCurrentSlopeTop,
                "is_dart", &PlayerObject::m_isDart,
                "is_dashing", &PlayerObject::m_isDashing,
                "is_dead", &PlayerObject::m_isDead,
                "is_going_left", &PlayerObject::m_isGoingLeft,
                "is_hidden", &PlayerObject::m_isHidden,
                "is_locked", &PlayerObject::m_isLocked,
                "is_moving", &PlayerObject::m_isMoving,
                "is_on_ground", &PlayerObject::m_isOnGround,
                "is_on_ground2", &PlayerObject::m_isOnGround2,
                "is_on_ground3", &PlayerObject::m_isOnGround3,
                "is_on_ground4", &PlayerObject::m_isOnGround4,
                "is_on_ice", &PlayerObject::m_isOnIce,
                "is_on_slope", &PlayerObject::m_isOnSlope,
                "is_out_of_bounds", &PlayerObject::m_isOutOfBounds,
                "is_platformer", &PlayerObject::m_isPlatformer,
                "is_robot", &PlayerObject::m_isRobot,
                "is_rotating", &PlayerObject::m_isRotating,
                "is_second_player", &PlayerObject::m_isSecondPlayer,
                "is_ship", &PlayerObject::m_isShip,
                "is_sideways", &PlayerObject::m_isSideways,
                "is_sliding", &PlayerObject::m_isSliding,
                "is_sliding_right", &PlayerObject::m_isSlidingRight,
                "is_spider", &PlayerObject::m_isSpider,
                "is_swing", &PlayerObject::m_isSwing,
                "is_upside_down", &PlayerObject::m_isUpsideDown,
                "jump_buffered", &PlayerObject::m_jumpBuffered,
                "jump_pad_related", &PlayerObject::m_jumpPadRelated,
                "jump_related_ac2", &PlayerObject::m_jumpRelatedAC2,
                "just_placed_streak", &PlayerObject::m_justPlacedStreak,
                "land_particle_related_y", &PlayerObject::m_landParticleRelatedY,
                "land_particles0", &PlayerObject::m_landParticles0,
                "land_particles1", &PlayerObject::m_landParticles1,
                "land_particles_angle", &PlayerObject::m_landParticlesAngle,
                "last_activated_portal", &PlayerObject::m_lastActivatedPortal,
                "last_checkpoint_time", &PlayerObject::m_lastCheckpointTime,
                "last_collision_bottom", &PlayerObject::m_lastCollisionBottom,
                "last_collision_left", &PlayerObject::m_lastCollisionLeft,
                "last_collision_right", &PlayerObject::m_lastCollisionRight,
                "last_collision_top", &PlayerObject::m_lastCollisionTop,
                "last_flip_time", &PlayerObject::m_lastFlipTime,
                "last_ground_object", &PlayerObject::m_lastGroundObject,
                "last_grounded_pos", &PlayerObject::m_lastGroundedPos,
                "last_jump_time", &PlayerObject::m_lastJumpTime,
                "last_land_time", &PlayerObject::m_lastLandTime,
                "last_portal_pos", &PlayerObject::m_lastPortalPos,
                "last_spider_flip_time", &PlayerObject::m_lastSpiderFlipTime,
                "left_pressed_first", &PlayerObject::m_leftPressedFirst,
                "main_layer", &PlayerObject::m_mainLayer,
                "maybe_can_run_into_blocks", &PlayerObject::m_maybeCanRunIntoBlocks,
                "maybe_changed_direction_angle", &PlayerObject::m_maybeChangedDirectionAngle,
                "maybe_going_correct_slope_direction", &PlayerObject::m_maybeGoingCorrectSlopeDirection,
                "maybe_has_stopped", &PlayerObject::m_maybeHasStopped,
                "maybe_is_boosted", &PlayerObject::m_maybeIsBoosted,
                "maybe_is_colliding", &PlayerObject::m_maybeIsColliding,
                "maybe_is_falling", &PlayerObject::m_maybeIsFalling,
                "maybe_is_vehicle_glowing", &PlayerObject::m_maybeIsVehicleGlowing,
                "maybe_last_ground_object", &PlayerObject::m_maybeLastGroundObject,
                "maybe_reduced_effects", &PlayerObject::m_maybeReducedEffects,
                "maybe_reverse_acceleration", &PlayerObject::m_maybeReverseAcceleration,
                "maybe_reverse_speed", &PlayerObject::m_maybeReverseSpeed,
                "maybe_saved_player_frame", &PlayerObject::m_maybeSavedPlayerFrame,
                "maybe_sliding_start_time", &PlayerObject::m_maybeSlidingStartTime,
                "maybe_sliding_time", &PlayerObject::m_maybeSlidingTime,
                "maybe_slope_force", &PlayerObject::m_maybeSlopeForce,
                "maybe_sprite_related", &PlayerObject::m_maybeSpriteRelated,
                "maybe_state_force2", &PlayerObject::m_maybeStateForce2,
                "maybe_touched_breakable_block", &PlayerObject::m_maybeTouchedBreakableBlock,
                "maybe_upside_down_slope", &PlayerObject::m_maybeUpsideDownSlope,
                "object_snapped_to", &PlayerObject::m_objectSnappedTo,
                "on_fly_checkpoint_tries", &PlayerObject::m_onFlyCheckpointTries,
                "original_main_color", &PlayerObject::m_originalMainColor,
                "original_second_color", &PlayerObject::m_originalSecondColor,
                "pad_ring_related", &PlayerObject::m_padRingRelated,
                "parent_layer", &PlayerObject::m_parentLayer,
                "particle_systems", &PlayerObject::m_particleSystems,
                "pending_checkpoint", &PlayerObject::m_pendingCheckpoint,
                "phys_delta_related", &PlayerObject::m_physDeltaRelated,
                "platformer_moving_left", &PlayerObject::m_platformerMovingLeft,
                "platformer_moving_right", &PlayerObject::m_platformerMovingRight,
                "platformer_velocity_related", &PlayerObject::m_platformerVelocityRelated,
                "platformer_xvelocity", &PlayerObject::m_platformerXVelocity,
                "play_effects", &PlayerObject::m_playEffects,
                "player_color1", &PlayerObject::m_playerColor1,
                "player_color2", &PlayerObject::m_playerColor2,
                "player_follow_floats", &PlayerObject::m_playerFollowFloats,
                "player_ground_particles", &PlayerObject::m_playerGroundParticles,
                "player_speed", &PlayerObject::m_playerSpeed,
                "player_speed_ac", &PlayerObject::m_playerSpeedAC,
                "player_streak", &PlayerObject::m_playerStreak,
                "position", &PlayerObject::m_position,
                "potential_slope_map", &PlayerObject::m_potentialSlopeMap,
                "practice_death_effect", &PlayerObject::m_practiceDeathEffect,
                "pre_last_ground_object", &PlayerObject::m_preLastGroundObject,
                "quick_checkpoint_mode", &PlayerObject::m_quickCheckpointMode,
                "regular_trail", &PlayerObject::m_regularTrail,
                "reverse_related", &PlayerObject::m_reverseRelated,
                "reverse_sync", &PlayerObject::m_reverseSync,
                "ring_jump_related", &PlayerObject::m_ringJumpRelated,
                "ring_related_set", &PlayerObject::m_ringRelatedSet,
                "robot_animation1_enabled", &PlayerObject::m_robotAnimation1Enabled,
                "robot_animation2_enabled", &PlayerObject::m_robotAnimation2Enabled,
                "robot_batch_node", &PlayerObject::m_robotBatchNode,
                "robot_burst_particles", &PlayerObject::m_robotBurstParticles,
                "robot_fire", &PlayerObject::m_robotFire,
                "robot_sprite", &PlayerObject::m_robotSprite,
                "rotate_objects_related", &PlayerObject::m_rotateObjectsRelated,
                "rotate_speed", &PlayerObject::m_rotateSpeed,
                "rotation_speed", &PlayerObject::m_rotationSpeed,
                "scale_xrelated", &PlayerObject::m_scaleXRelated,
                "scale_xrelated2", &PlayerObject::m_scaleXRelated2,
                "scale_xrelated3", &PlayerObject::m_scaleXRelated3,
                "scale_xrelated4", &PlayerObject::m_scaleXRelated4,
                "scale_xrelated5", &PlayerObject::m_scaleXRelated5,
                "scale_xrelated_time", &PlayerObject::m_scaleXRelatedTime,
                "ship_click_particles", &PlayerObject::m_shipClickParticles,
                "ship_rotation", &PlayerObject::m_shipRotation,
                "ship_streak", &PlayerObject::m_shipStreak,
                "ship_streak_type", &PlayerObject::m_shipStreakType,
                "should_try_placing_checkpoint", &PlayerObject::m_shouldTryPlacingCheckpoint,
                "slope_angle", &PlayerObject::m_slopeAngle,
                "slope_angle_radians", &PlayerObject::m_slopeAngleRadians,
                "slope_end_time", &PlayerObject::m_slopeEndTime,
                "slope_flip_gravity_related", &PlayerObject::m_slopeFlipGravityRelated,
                "slope_rotation", &PlayerObject::m_slopeRotation,
                "slope_sliding_maybe_rotated", &PlayerObject::m_slopeSlidingMaybeRotated,
                "slope_start_time", &PlayerObject::m_slopeStartTime,
                "slope_velocity", &PlayerObject::m_slopeVelocity,
                "snap_distance", &PlayerObject::m_snapDistance,
                "something_player_speed_time", &PlayerObject::m_somethingPlayerSpeedTime,
                "speed_multiplier", &PlayerObject::m_speedMultiplier,
                "spider_animation_enabled", &PlayerObject::m_spiderAnimationEnabled,
                "spider_batch_node", &PlayerObject::m_spiderBatchNode,
                "spider_sprite", &PlayerObject::m_spiderSprite,
                "state_boost_x", &PlayerObject::m_stateBoostX,
                "state_boost_y", &PlayerObject::m_stateBoostY,
                "state_dart_slide", &PlayerObject::m_stateDartSlide,
                "state_flip_gravity", &PlayerObject::m_stateFlipGravity,
                "state_force", &PlayerObject::m_stateForce,
                "state_force_vector", &PlayerObject::m_stateForceVector,
                "state_hit_head", &PlayerObject::m_stateHitHead,
                "state_jump_buffered", &PlayerObject::m_stateJumpBuffered,
                "state_no_auto_jump", &PlayerObject::m_stateNoAutoJump,
                "state_no_stick_x", &PlayerObject::m_stateNoStickX,
                "state_no_stick_y", &PlayerObject::m_stateNoStickY,
                "state_on_ground", &PlayerObject::m_stateOnGround,
                "state_ring_jump", &PlayerObject::m_stateRingJump,
                "state_ring_jump2", &PlayerObject::m_stateRingJump2,
                "state_scale", &PlayerObject::m_stateScale,
                "state_unk", &PlayerObject::m_stateUnk,
                "state_unk2", &PlayerObject::m_stateUnk2,
                "streak_stroke_width", &PlayerObject::m_streakStrokeWidth,
                "swap_colors", &PlayerObject::m_swapColors,
                "swing_burst_particles1", &PlayerObject::m_swingBurstParticles1,
                "swing_burst_particles2", &PlayerObject::m_swingBurstParticles2,
                "swing_fire_bottom", &PlayerObject::m_swingFireBottom,
                "swing_fire_middle", &PlayerObject::m_swingFireMiddle,
                "swing_fire_top", &PlayerObject::m_swingFireTop,
                "switch_dash_fire_color", &PlayerObject::m_switchDashFireColor,
                "switch_wave_trail_color", &PlayerObject::m_switchWaveTrailColor,
                "total_time", &PlayerObject::m_totalTime,
                "touched_custom_ring", &PlayerObject::m_touchedCustomRing,
                "touched_gravity_portal", &PlayerObject::m_touchedGravityPortal,
                "touched_pad", &PlayerObject::m_touchedPad,
                "touched_ring", &PlayerObject::m_touchedRing,
                "touched_rings", &PlayerObject::m_touchedRings,
                "touching_rings", &PlayerObject::m_touchingRings,
                "trailing_particle_life", &PlayerObject::m_trailingParticleLife,
                "trailing_particles", &PlayerObject::m_trailingParticles,
                "ufo_click_particles", &PlayerObject::m_ufoClickParticles,
                "unk3d0", &PlayerObject::m_unk3d0,
                "unk3e0", &PlayerObject::m_unk3e0,
                "unk3e1", &PlayerObject::m_unk3e1,
                "unk50_c", &PlayerObject::m_unk50C,
                "unk510", &PlayerObject::m_unk510,
                "unk648", &PlayerObject::m_unk648,
                "unk669", &PlayerObject::m_unk669,
                "unk838", &PlayerObject::m_unk838,
                "unk958", &PlayerObject::m_unk958,
                "unk9e8", &PlayerObject::m_unk9e8,
                "unk_a29", &PlayerObject::m_unkA29,
                "unk_a99", &PlayerObject::m_unkA99,
                "unk_angle1", &PlayerObject::m_unkAngle1,
                "unk_bool5", &PlayerObject::m_unkBool5,
                "unk_unused", &PlayerObject::m_unkUnused,
                "unk_unused2", &PlayerObject::m_unkUnused2,
                "unk_unused3", &PlayerObject::m_unkUnused3,
                "use_land_particles0", &PlayerObject::m_useLandParticles0,
                "vehicle_glow", &PlayerObject::m_vehicleGlow,
                "vehicle_ground_particles", &PlayerObject::m_vehicleGroundParticles,
                "vehicle_size", &PlayerObject::m_vehicleSize,
                "vehicle_sprite", &PlayerObject::m_vehicleSprite,
                "vehicle_sprite_secondary", &PlayerObject::m_vehicleSpriteSecondary,
                "vehicle_sprite_whitener", &PlayerObject::m_vehicleSpriteWhitener,
                "was_jump_buffered", &PlayerObject::m_wasJumpBuffered,
                "was_on_slope", &PlayerObject::m_wasOnSlope,
                "was_robot_jump", &PlayerObject::m_wasRobotJump,
                "was_teleported", &PlayerObject::m_wasTeleported,
                "wave_trail", &PlayerObject::m_waveTrail,
                "x_velocity_related", &PlayerObject::m_xVelocityRelated,
                "x_velocity_related2", &PlayerObject::m_xVelocityRelated2,
                "y_start", &PlayerObject::m_yStart,
                "y_velocity", &PlayerObject::m_yVelocity,
                "y_velocity_before_slope", &PlayerObject::m_yVelocityBeforeSlope,
                "y_velocity_related", &PlayerObject::m_yVelocityRelated,
                "y_velocity_related3", &PlayerObject::m_yVelocityRelated3,
                "unk584", &PlayerObject::unk_584);

            sol::table usertype = state["PlayerObject"];

            // expose the custom fields to lua
            usertype.set_function("fields",
                [](sol::this_state s, PlayerObject* self) -> sol::table {
                    sol::state_view lua(s);

                    if (!self) {
                        return lua.create_table();
                    }

                    // this cast is required to access lua field storage
                    auto modifiedSelf = static_cast<PlayerObjectModified*>(self);
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
                []() -> PlayerObject* {
                    PlayerObject* ptr = new(std::nothrow) PlayerObject();
                    return ptr;
                });

            // manual deallocation for `alloc()`
            usertype.set_function("free",
                [](PlayerObject* self) {
                    delete self;
                });

            luaManager.addValidHook("PlayerObject:activate_streak");
            usertype.set_function("activate_streak",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->activateStreak();
                });

            luaManager.addValidHook("PlayerObject:add_all_particles");
            usertype.set_function("add_all_particles",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->addAllParticles();
                });

            usertype.set_function("add_to_touched_rings",
                [](PlayerObject* self, RingObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToTouchedRings(object);
                });

            usertype.set_function("add_to_yvelocity",
                [](PlayerObject* self, double yVelocity, int type) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToYVelocity(yVelocity, type);
                });

            luaManager.addValidHook("PlayerObject:animate_platformer_jump");
            usertype.set_function("animate_platformer_jump",
                [](PlayerObject* self, float scale) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->animatePlatformerJump(scale);
                });

            luaManager.addValidHook("PlayerObject:animation_finished");
            usertype.set_function("animation_finished",
                [](PlayerObject* self, char const* key) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->animationFinished(key);
                });

            luaManager.addValidHook("PlayerObject:boost_player");
            usertype.set_function("boost_player",
                [](PlayerObject* self, float yVelocity) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->boostPlayer(yVelocity);
                });

            luaManager.addValidHook("PlayerObject:bump_player");
            usertype.set_function("bump_player",
                [](PlayerObject* self, float bumpMod, int objectType, bool noEffects, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->bumpPlayer(bumpMod, objectType, noEffects, object);
                });

            usertype.set_function("button_down",
                [](PlayerObject* self, PlayerButton button) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->buttonDown(button);
                });

            usertype.set_function("can_stick_to_ground",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canStickToGround();
                });

            luaManager.addValidHook("PlayerObject:check_snap_jump_to_object");
            usertype.set_function("check_snap_jump_to_object",
                [](PlayerObject* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->checkSnapJumpToObject(object);
                });

            luaManager.addValidHook("PlayerObject:collided_with_object@2");
            usertype.set_function("collided_with_object",
                sol::overload(
                    [](PlayerObject* self, float dt, GameObject* object) -> bool {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        return self->collidedWithObject(dt, object);
                    },
                    [](PlayerObject* self, float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) -> bool {
                        auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                        return modifiedSelf->collidedWithObject(dt, object, rect, skipCheck);
                    }));

            luaManager.addValidHook("PlayerObject:collided_with_object_internal");
            usertype.set_function("collided_with_object_internal",
                [](PlayerObject* self, float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) -> bool {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->collidedWithObjectInternal(dt, object, rect, skipCheck);
                });

            usertype.set_function("collided_with_slope",
                [](PlayerObject* self, float dt, GameObject* object, bool skipPre) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->collidedWithSlope(dt, object, skipPre);
                });

            luaManager.addValidHook("PlayerObject:collided_with_slope_internal");
            usertype.set_function("collided_with_slope_internal",
                [](PlayerObject* self, float dt, GameObject* object, bool forced) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->collidedWithSlopeInternal(dt, object, forced);
                });

            luaManager.addValidHook("PlayerObject:convert_to_closest_rotation");
            usertype.set_function("convert_to_closest_rotation",
                [](PlayerObject* self, float rotation) -> float {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->convertToClosestRotation(rotation);
                });

            luaManager.addValidHook("PlayerObject:copy_attributes");
            usertype.set_function("copy_attributes",
                [](PlayerObject* self, PlayerObject* player) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->copyAttributes(player);
                });

            luaManager.addValidHook("PlayerObject.create");
            usertype.set_function("create",
                [](int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> PlayerObject* {
                    return quartz::PlayerObjectModified::create(player, ship, gameLayer, layer, playLayer);
                });

            luaManager.addValidHook("PlayerObject:create_fade_out_dart_streak");
            usertype.set_function("create_fade_out_dart_streak",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->createFadeOutDartStreak();
                });

            luaManager.addValidHook("PlayerObject:create_robot");
            usertype.set_function("create_robot",
                [](PlayerObject* self, int frame) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->createRobot(frame);
                });

            luaManager.addValidHook("PlayerObject:create_spider");
            usertype.set_function("create_spider",
                [](PlayerObject* self, int frame) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->createSpider(frame);
                });

            usertype.set_function("deactivate_particle",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->deactivateParticle();
                });

            usertype.set_function("deactivate_streak",
                [](PlayerObject* self, bool stop) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->deactivateStreak(stop);
                });

            usertype.set_function("destroy_from_hit_head",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->destroyFromHitHead();
                });

            luaManager.addValidHook("PlayerObject:did_hit_head");
            usertype.set_function("did_hit_head",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->didHitHead();
                });

            usertype.set_function("disable_custom_glow_color",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->disableCustomGlowColor();
                });

            luaManager.addValidHook("PlayerObject:disable_player_controls");
            usertype.set_function("disable_player_controls",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->disablePlayerControls();
                });

            luaManager.addValidHook("PlayerObject:disable_swing_fire");
            usertype.set_function("disable_swing_fire",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->disableSwingFire();
                });

            luaManager.addValidHook("PlayerObject:do_reverse_player");
            usertype.set_function("do_reverse_player",
                [](PlayerObject* self, bool reverse) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->doReversePlayer(reverse);
                });

            usertype.set_function("enable_custom_glow_color",
                [](PlayerObject* self, cocos2d::ccColor3B const& color) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->enableCustomGlowColor(color);
                });

            luaManager.addValidHook("PlayerObject:enable_player_controls");
            usertype.set_function("enable_player_controls",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->enablePlayerControls();
                });

            luaManager.addValidHook("PlayerObject:exit_platformer_animate_jump");
            usertype.set_function("exit_platformer_animate_jump",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->exitPlatformerAnimateJump();
                });

            luaManager.addValidHook("PlayerObject:fade_out_streak2");
            usertype.set_function("fade_out_streak2",
                [](PlayerObject* self, float duration) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->fadeOutStreak2(duration);
                });

            usertype.set_function("flash_player",
                [](PlayerObject* self, float flashDuration, float flashDelay, cocos2d::ccColor3B mainColor, cocos2d::ccColor3B secondColor) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->flashPlayer(flashDuration, flashDelay, mainColor, secondColor);
                });

            luaManager.addValidHook("PlayerObject:flip_gravity");
            usertype.set_function("flip_gravity",
                [](PlayerObject* self, bool flip, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->flipGravity(flip, noEffects);
                });

            usertype.set_function("flip_mod",
                [](PlayerObject* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->flipMod();
                });

            usertype.set_function("game_event_triggered",
                [](PlayerObject* self, int gameEvent, int material) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->gameEventTriggered(gameEvent, material);
                });

            usertype.set_function("get_active_mode",
                [](PlayerObject* self) -> GameObjectType {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getActiveMode();
                });

            usertype.set_function("get_current_xvelocity",
                [](PlayerObject* self) -> double {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getCurrentXVelocity();
                });

            usertype.set_function("get_modified_slope_yvel",
                [](PlayerObject* self) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getModifiedSlopeYVel();
                });

            luaManager.addValidHook("PlayerObject:get_object_rotation");
            usertype.set_function("get_object_rotation",
                [](PlayerObject* self) -> float {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->getObjectRotation();
                });

            usertype.set_function("get_old_position",
                [](PlayerObject* self, float dt) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getOldPosition(dt);
                });

            luaManager.addValidHook("PlayerObject:get_oriented_box");
            usertype.set_function("get_oriented_box",
                [](PlayerObject* self) -> OBB2D* {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->getOrientedBox();
                });

            luaManager.addValidHook("PlayerObject:get_real_position");
            usertype.set_function("get_real_position",
                [](PlayerObject* self) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->getRealPosition();
                });

            usertype.set_function("get_second_color",
                [](PlayerObject* self) -> cocos2d::ccColor3B {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getSecondColor();
                });

            usertype.set_function("get_yvelocity",
                [](PlayerObject* self) -> double {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getYVelocity();
                });

            usertype.set_function("gravity_down",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->gravityDown();
                });

            usertype.set_function("gravity_up",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->gravityUp();
                });

            usertype.set_function("handle_player_command",
                [](PlayerObject* self, int command) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->handlePlayerCommand(command);
                });

            luaManager.addValidHook("PlayerObject:handle_rotated_collision_internal");
            usertype.set_function("handle_rotated_collision_internal",
                [](PlayerObject* self, float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck, bool skipPre, bool slope) -> bool {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->handleRotatedCollisionInternal(dt, object, rect, skipCheck, skipPre, slope);
                });

            usertype.set_function("handle_rotated_object_collision",
                [](PlayerObject* self, float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->handleRotatedObjectCollision(dt, object, rect, skipCheck);
                });

            usertype.set_function("handle_rotated_slope_collision",
                [](PlayerObject* self, float dt, GameObject* object, bool skipPre) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->handleRotatedSlopeCollision(dt, object, skipPre);
                });

            usertype.set_function("hard_flip_gravity",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->hardFlipGravity();
                });

            luaManager.addValidHook("PlayerObject:hit_ground");
            usertype.set_function("hit_ground",
                [](PlayerObject* self, GameObject* object, bool notFlipped) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->hitGround(object, notFlipped);
                });

            usertype.set_function("hit_ground_no_jump",
                [](PlayerObject* self, GameObject* object, bool notFlipped) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->hitGroundNoJump(object, notFlipped);
                });

            luaManager.addValidHook("PlayerObject:increment_jumps");
            usertype.set_function("increment_jumps",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->incrementJumps();
                });

            luaManager.addValidHook("PlayerObject:init");
            usertype.set_function("init",
                [](PlayerObject* self, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> bool {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->init(player, ship, gameLayer, layer, playLayer);
                });

            usertype.set_function("is_boost_valid",
                [](PlayerObject* self, float yVelocity) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isBoostValid(yVelocity);
                });

            usertype.set_function("is_flying",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isFlying();
                });

            usertype.set_function("is_in_basic_mode",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isInBasicMode();
                });

            usertype.set_function("is_in_normal_mode",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isInNormalMode();
                });

            usertype.set_function("is_player1",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isPlayer1();
                });

            usertype.set_function("is_player2",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isPlayer2();
                });

            usertype.set_function("is_safe_flip",
                [](PlayerObject* self, float flipTime) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isSafeFlip(flipTime);
                });

            usertype.set_function("is_safe_head_test",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isSafeHeadTest();
                });

            usertype.set_function("is_safe_mode",
                [](PlayerObject* self, float changeTime) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isSafeMode(changeTime);
                });

            usertype.set_function("is_safe_spider_flip",
                [](PlayerObject* self, float flipTime) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isSafeSpiderFlip(flipTime);
                });

            usertype.set_function("is_vanilla_player",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isVanillaPlayer();
                });

            luaManager.addValidHook("PlayerObject:level_flip_finished");
            usertype.set_function("level_flip_finished",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->levelFlipFinished();
                });

            usertype.set_function("level_flipping",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->levelFlipping();
                });

            luaManager.addValidHook("PlayerObject:level_will_flip");
            usertype.set_function("level_will_flip",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->levelWillFlip();
                });

            usertype.set_function("limit_dash_rotation",
                [](PlayerObject* self, float& rotation) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->limitDashRotation(rotation);
                });

            luaManager.addValidHook("PlayerObject:load_from_checkpoint");
            usertype.set_function("load_from_checkpoint",
                [](PlayerObject* self, PlayerCheckpoint* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->loadFromCheckpoint(object);
                });

            luaManager.addValidHook("PlayerObject:lock_player");
            usertype.set_function("lock_player",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->lockPlayer();
                });

            usertype.set_function("log_values",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->logValues();
                });

            usertype.set_function("mode_did_change",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->modeDidChange();
                });

            usertype.set_function("perform_slide_check",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->performSlideCheck();
                });

            luaManager.addValidHook("PlayerObject:place_streak_point");
            usertype.set_function("place_streak_point",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->placeStreakPoint();
                });

            luaManager.addValidHook("PlayerObject:play_bump_effect");
            usertype.set_function("play_bump_effect",
                [](PlayerObject* self, int objectType, GameObject* player) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->playBumpEffect(objectType, player);
                });

            usertype.set_function("play_burst_effect",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playBurstEffect();
                });

            luaManager.addValidHook("PlayerObject:play_complete_effect");
            usertype.set_function("play_complete_effect",
                [](PlayerObject* self, bool noEffects, bool instant) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->playCompleteEffect(noEffects, instant);
                });

            luaManager.addValidHook("PlayerObject:play_death_effect");
            usertype.set_function("play_death_effect",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->playDeathEffect();
                });

            luaManager.addValidHook("PlayerObject:play_dynamic_spider_run");
            usertype.set_function("play_dynamic_spider_run",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->playDynamicSpiderRun();
                });

            luaManager.addValidHook("PlayerObject:play_spawn_effect");
            usertype.set_function("play_spawn_effect",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->playSpawnEffect();
                });

            luaManager.addValidHook("PlayerObject:play_spider_dash_effect");
            usertype.set_function("play_spider_dash_effect",
                [](PlayerObject* self, cocos2d::CCPoint from, cocos2d::CCPoint to) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->playSpiderDashEffect(from, to);
                });

            luaManager.addValidHook("PlayerObject:player_destroyed");
            usertype.set_function("player_destroyed",
                [](PlayerObject* self, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->playerDestroyed(noEffects);
                });

            usertype.set_function("player_is_falling",
                [](PlayerObject* self, float yVelocity) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->playerIsFalling(yVelocity);
                });

            luaManager.addValidHook("PlayerObject:player_is_falling_bugged");
            usertype.set_function("player_is_falling_bugged",
                [](PlayerObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->playerIsFallingBugged();
                });

            usertype.set_function("player_is_moving_up",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->playerIsMovingUp();
                });

            usertype.set_function("player_teleported",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playerTeleported();
                });

            usertype.set_function("playing_end_effect",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->playingEndEffect();
                });

            luaManager.addValidHook("PlayerObject:post_collision");
            usertype.set_function("post_collision",
                [](PlayerObject* self, float dt, bool betweenSteps) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->postCollision(dt, betweenSteps);
                });

            usertype.set_function("pre_collision",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->preCollision();
                });

            luaManager.addValidHook("PlayerObject:pre_slope_collision");
            usertype.set_function("pre_slope_collision",
                [](PlayerObject* self, float dt, GameObject* object) -> bool {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->preSlopeCollision(dt, object);
                });

            luaManager.addValidHook("PlayerObject:propell_player");
            usertype.set_function("propell_player",
                [](PlayerObject* self, float yVelocity, bool noEffects, int objectType) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->propellPlayer(yVelocity, noEffects, objectType);
                });

            luaManager.addValidHook("PlayerObject:push_button");
            usertype.set_function("push_button",
                [](PlayerObject* self, PlayerButton button) -> bool {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->pushButton(button);
                });

            usertype.set_function("push_down",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->pushDown();
                });

            usertype.set_function("push_player",
                [](PlayerObject* self, float yVelocity) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->pushPlayer(yVelocity);
                });

            usertype.set_function("redirect_dash",
                [](PlayerObject* self, float rotation) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->redirectDash(rotation);
                });

            luaManager.addValidHook("PlayerObject:redirect_player_force");
            usertype.set_function("redirect_player_force",
                [](PlayerObject* self, float rotation, float modifier, float minimum, float maximum) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->redirectPlayerForce(rotation, modifier, minimum, maximum);
                });

            luaManager.addValidHook("PlayerObject:release_all_buttons");
            usertype.set_function("release_all_buttons",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->releaseAllButtons();
                });

            luaManager.addValidHook("PlayerObject:release_button");
            usertype.set_function("release_button",
                [](PlayerObject* self, PlayerButton button) -> bool {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->releaseButton(button);
                });

            usertype.set_function("remove_all_particles",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeAllParticles();
                });

            luaManager.addValidHook("PlayerObject:remove_pending_checkpoint");
            usertype.set_function("remove_pending_checkpoint",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->removePendingCheckpoint();
                });

            usertype.set_function("remove_placed_checkpoint",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removePlacedCheckpoint();
                });

            luaManager.addValidHook("PlayerObject:reset_all_particles");
            usertype.set_function("reset_all_particles",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->resetAllParticles();
                });

            usertype.set_function("reset_collision_log",
                [](PlayerObject* self, bool full) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetCollisionLog(full);
                });

            usertype.set_function("reset_collision_values",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetCollisionValues();
                });

            luaManager.addValidHook("PlayerObject:reset_object");
            usertype.set_function("reset_object",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->resetObject();
                });

            luaManager.addValidHook("PlayerObject:reset_player_icon");
            usertype.set_function("reset_player_icon",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->resetPlayerIcon();
                });

            usertype.set_function("reset_state_variables",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetStateVariables();
                });

            luaManager.addValidHook("PlayerObject:reset_streak");
            usertype.set_function("reset_streak",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->resetStreak();
                });

            luaManager.addValidHook("PlayerObject:reset_touched_rings");
            usertype.set_function("reset_touched_rings",
                [](PlayerObject* self, bool removeAll) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->resetTouchedRings(removeAll);
                });

            usertype.set_function("reverse_mod",
                [](PlayerObject* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->reverseMod();
                });

            luaManager.addValidHook("PlayerObject:reverse_player");
            usertype.set_function("reverse_player",
                [](PlayerObject* self, EffectGameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->reversePlayer(object);
                });

            luaManager.addValidHook("PlayerObject:ring_jump");
            usertype.set_function("ring_jump",
                [](PlayerObject* self, RingObject* object, bool skipCheck) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->ringJump(object, skipCheck);
                });

            luaManager.addValidHook("PlayerObject:rotate_gameplay");
            usertype.set_function("rotate_gameplay",
                [](PlayerObject* self, int moveDirection, int groundDirection, bool editVelocity, float velocityModX, float velocityModY, bool overrideVelocity, bool dontSlide) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->rotateGameplay(moveDirection, groundDirection, editVelocity, velocityModX, velocityModY, overrideVelocity, dontSlide);
                });

            luaManager.addValidHook("PlayerObject:rotate_gameplay_object");
            usertype.set_function("rotate_gameplay_object",
                [](PlayerObject* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->rotateGameplayObject(object);
                });

            usertype.set_function("rotate_gameplay_only",
                [](PlayerObject* self, bool sideways) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->rotateGameplayOnly(sideways);
                });

            usertype.set_function("rotate_pre_slope_objects",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->rotatePreSlopeObjects();
                });

            luaManager.addValidHook("PlayerObject:run_ball_rotation");
            usertype.set_function("run_ball_rotation",
                [](PlayerObject* self, float speed) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->runBallRotation(speed);
                });

            luaManager.addValidHook("PlayerObject:run_ball_rotation2");
            usertype.set_function("run_ball_rotation2",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->runBallRotation2();
                });

            luaManager.addValidHook("PlayerObject:run_normal_rotation@2");
            usertype.set_function("run_normal_rotation",
                sol::overload(
                    [](PlayerObject* self) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->runNormalRotation();
                    },
                    [](PlayerObject* self, bool notNormalMode, float speed) {
                        auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                        modifiedSelf->runNormalRotation(notNormalMode, speed);
                    }));

            usertype.set_function("run_rotate_action",
                [](PlayerObject* self, bool ground, int type) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->runRotateAction(ground, type);
                });

            luaManager.addValidHook("PlayerObject:save_to_checkpoint");
            usertype.set_function("save_to_checkpoint",
                [](PlayerObject* self, PlayerCheckpoint* checkpoint) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->saveToCheckpoint(checkpoint);
                });

            luaManager.addValidHook("PlayerObject:set_color");
            usertype.set_function("set_color",
                [](PlayerObject* self, cocos2d::ccColor3B const& color) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setColor(color);
                });

            luaManager.addValidHook("PlayerObject:set_flip_x");
            usertype.set_function("set_flip_x",
                [](PlayerObject* self, bool flipX) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setFlipX(flipX);
                });

            luaManager.addValidHook("PlayerObject:set_flip_y");
            usertype.set_function("set_flip_y",
                [](PlayerObject* self, bool flipY) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setFlipY(flipY);
                });

            luaManager.addValidHook("PlayerObject:set_opacity");
            usertype.set_function("set_opacity",
                [](PlayerObject* self, unsigned char opacity) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setOpacity(opacity);
                });

            luaManager.addValidHook("PlayerObject:set_position");
            usertype.set_function("set_position",
                [](PlayerObject* self, cocos2d::CCPoint const& position) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setPosition(position);
                });

            luaManager.addValidHook("PlayerObject:set_rotation");
            usertype.set_function("set_rotation",
                [](PlayerObject* self, float rotation) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setRotation(rotation);
                });

            luaManager.addValidHook("PlayerObject:set_scale");
            usertype.set_function("set_scale",
                [](PlayerObject* self, float scale) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setScale(scale);
                });

            luaManager.addValidHook("PlayerObject:set_scale_x");
            usertype.set_function("set_scale_x",
                [](PlayerObject* self, float scale) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setScaleX(scale);
                });

            luaManager.addValidHook("PlayerObject:set_scale_y");
            usertype.set_function("set_scale_y",
                [](PlayerObject* self, float scale) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setScaleY(scale);
                });

            luaManager.addValidHook("PlayerObject:set_second_color");
            usertype.set_function("set_second_color",
                [](PlayerObject* self, cocos2d::ccColor3B const& color) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setSecondColor(color);
                });

            luaManager.addValidHook("PlayerObject:set_visible");
            usertype.set_function("set_visible",
                [](PlayerObject* self, bool visible) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setVisible(visible);
                });

            luaManager.addValidHook("PlayerObject:set_yvelocity");
            usertype.set_function("set_yvelocity",
                [](PlayerObject* self, double velocity, int type) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setYVelocity(velocity, type);
                });

            luaManager.addValidHook("PlayerObject:setup_streak");
            usertype.set_function("setup_streak",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->setupStreak();
                });

            luaManager.addValidHook("PlayerObject:spawn_circle");
            usertype.set_function("spawn_circle",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->spawnCircle();
                });

            usertype.set_function("spawn_circle2",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->spawnCircle2();
                });

            luaManager.addValidHook("PlayerObject:spawn_dual_circle");
            usertype.set_function("spawn_dual_circle",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->spawnDualCircle();
                });

            usertype.set_function("spawn_from_player",
                [](PlayerObject* self, PlayerObject* player, bool flip) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->spawnFromPlayer(player, flip);
                });

            luaManager.addValidHook("PlayerObject:spawn_portal_circle");
            usertype.set_function("spawn_portal_circle",
                [](PlayerObject* self, cocos2d::ccColor3B color, float startRadius) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->spawnPortalCircle(color, startRadius);
                });

            luaManager.addValidHook("PlayerObject:spawn_scale_circle");
            usertype.set_function("spawn_scale_circle",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->spawnScaleCircle();
                });

            usertype.set_function("special_ground_hit",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->specialGroundHit();
                });

            usertype.set_function("speed_down",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->speedDown();
                });

            usertype.set_function("speed_up",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->speedUp();
                });

            luaManager.addValidHook("PlayerObject:spider_test_jump");
            usertype.set_function("spider_test_jump",
                [](PlayerObject* self, bool dynamic) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->spiderTestJump(dynamic);
                });

            luaManager.addValidHook("PlayerObject:spider_test_jump_internal");
            usertype.set_function("spider_test_jump_internal",
                [](PlayerObject* self, bool dynamic) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->spiderTestJumpInternal(dynamic);
                });

            luaManager.addValidHook("PlayerObject:spider_test_jump_x");
            usertype.set_function("spider_test_jump_x",
                [](PlayerObject* self, bool dynamic) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->spiderTestJumpX(dynamic);
                });

            luaManager.addValidHook("PlayerObject:spider_test_jump_y");
            usertype.set_function("spider_test_jump_y",
                [](PlayerObject* self, bool dynamic) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->spiderTestJumpY(dynamic);
                });

            luaManager.addValidHook("PlayerObject:start_dashing");
            usertype.set_function("start_dashing",
                [](PlayerObject* self, DashRingObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->startDashing(object);
                });

            luaManager.addValidHook("PlayerObject:stop_burst_effect");
            usertype.set_function("stop_burst_effect",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->stopBurstEffect();
                });

            luaManager.addValidHook("PlayerObject:stop_dashing");
            usertype.set_function("stop_dashing",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->stopDashing();
                });

            luaManager.addValidHook("PlayerObject:stop_particles");
            usertype.set_function("stop_particles",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->stopParticles();
                });

            luaManager.addValidHook("PlayerObject:stop_platformer_jump_animation");
            usertype.set_function("stop_platformer_jump_animation",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->stopPlatformerJumpAnimation();
                });

            usertype.set_function("stop_rotation",
                [](PlayerObject* self, bool ground, int type) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->stopRotation(ground, type);
                });

            usertype.set_function("stop_streak2",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->stopStreak2();
                });

            usertype.set_function("store_collision",
                [](PlayerObject* self, PlayerCollisionDirection direction, int id) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->storeCollision(direction, id);
                });

            luaManager.addValidHook("PlayerObject:switched_dir_to");
            usertype.set_function("switched_dir_to",
                [](PlayerObject* self, PlayerButton button) -> bool {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    return modifiedSelf->switchedDirTo(button);
                });

            luaManager.addValidHook("PlayerObject:switched_to_mode");
            usertype.set_function("switched_to_mode",
                [](PlayerObject* self, GameObjectType type) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->switchedToMode(type);
                });

            usertype.set_function("test_for_moving",
                [](PlayerObject* self, float dt, GameObject* object) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->testForMoving(dt, object);
                });

            luaManager.addValidHook("PlayerObject:toggle_bird_mode");
            usertype.set_function("toggle_bird_mode",
                [](PlayerObject* self, bool enable, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->toggleBirdMode(enable, noEffects);
                });

            luaManager.addValidHook("PlayerObject:toggle_dart_mode");
            usertype.set_function("toggle_dart_mode",
                [](PlayerObject* self, bool enable, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->toggleDartMode(enable, noEffects);
                });

            luaManager.addValidHook("PlayerObject:toggle_fly_mode");
            usertype.set_function("toggle_fly_mode",
                [](PlayerObject* self, bool enable, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->toggleFlyMode(enable, noEffects);
                });

            luaManager.addValidHook("PlayerObject:toggle_ghost_effect");
            usertype.set_function("toggle_ghost_effect",
                [](PlayerObject* self, GhostType type) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->toggleGhostEffect(type);
                });

            usertype.set_function("toggle_platformer_mode",
                [](PlayerObject* self, bool val) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->togglePlatformerMode(val);
                });

            luaManager.addValidHook("PlayerObject:toggle_player_scale");
            usertype.set_function("toggle_player_scale",
                [](PlayerObject* self, bool enable, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->togglePlayerScale(enable, noEffects);
                });

            luaManager.addValidHook("PlayerObject:toggle_robot_mode");
            usertype.set_function("toggle_robot_mode",
                [](PlayerObject* self, bool enable, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->toggleRobotMode(enable, noEffects);
                });

            luaManager.addValidHook("PlayerObject:toggle_roll_mode");
            usertype.set_function("toggle_roll_mode",
                [](PlayerObject* self, bool enable, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->toggleRollMode(enable, noEffects);
                });

            luaManager.addValidHook("PlayerObject:toggle_spider_mode");
            usertype.set_function("toggle_spider_mode",
                [](PlayerObject* self, bool enable, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->toggleSpiderMode(enable, noEffects);
                });

            luaManager.addValidHook("PlayerObject:toggle_swing_mode");
            usertype.set_function("toggle_swing_mode",
                [](PlayerObject* self, bool enable, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->toggleSwingMode(enable, noEffects);
                });

            luaManager.addValidHook("PlayerObject:toggle_visibility");
            usertype.set_function("toggle_visibility",
                [](PlayerObject* self, bool visible) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->toggleVisibility(visible);
                });

            usertype.set_function("touched_object",
                [](PlayerObject* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->touchedObject(object);
                });

            luaManager.addValidHook("PlayerObject:try_place_checkpoint");
            usertype.set_function("try_place_checkpoint",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->tryPlaceCheckpoint();
                });

            luaManager.addValidHook("PlayerObject:unrotate_gameplay_object");
            usertype.set_function("unrotate_gameplay_object",
                [](PlayerObject* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->unrotateGameplayObject(object);
                });

            usertype.set_function("unrotate_pre_slope_objects",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->unrotatePreSlopeObjects();
                });

            luaManager.addValidHook("PlayerObject:update");
            usertype.set_function("update",
                [](PlayerObject* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->update(dt);
                });

            usertype.set_function("update_checkpoint_mode",
                [](PlayerObject* self, bool enable) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateCheckpointMode(enable);
                });

            usertype.set_function("update_checkpoint_test",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateCheckpointTest();
                });

            luaManager.addValidHook("PlayerObject:update_collide");
            usertype.set_function("update_collide",
                [](PlayerObject* self, PlayerCollisionDirection direction, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateCollide(direction, object);
                });

            usertype.set_function("update_collide_bottom",
                [](PlayerObject* self, float y, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateCollideBottom(y, object);
                });

            luaManager.addValidHook("PlayerObject:update_collide_left");
            usertype.set_function("update_collide_left",
                [](PlayerObject* self, float x, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateCollideLeft(x, object);
                });

            luaManager.addValidHook("PlayerObject:update_collide_right");
            usertype.set_function("update_collide_right",
                [](PlayerObject* self, float x, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateCollideRight(x, object);
                });

            usertype.set_function("update_collide_top",
                [](PlayerObject* self, float y, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateCollideTop(y, object);
                });

            luaManager.addValidHook("PlayerObject:update_dash_animation");
            usertype.set_function("update_dash_animation",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateDashAnimation();
                });

            luaManager.addValidHook("PlayerObject:update_dash_art");
            usertype.set_function("update_dash_art",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateDashArt();
                });

            usertype.set_function("update_effects",
                [](PlayerObject* self, float param) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateEffects(param);
                });

            luaManager.addValidHook("PlayerObject:update_glow_color");
            usertype.set_function("update_glow_color",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateGlowColor();
                });

            luaManager.addValidHook("PlayerObject:update_internal_actions");
            usertype.set_function("update_internal_actions",
                [](PlayerObject* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateInternalActions(dt);
                });

            luaManager.addValidHook("PlayerObject:update_jump");
            usertype.set_function("update_jump",
                [](PlayerObject* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateJump(dt);
                });

            usertype.set_function("update_jump_variables",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateJumpVariables();
                });

            usertype.set_function("update_last_ground_object",
                [](PlayerObject* self, GameObject* object) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateLastGroundObject(object);
                });

            luaManager.addValidHook("PlayerObject:update_move");
            usertype.set_function("update_move",
                [](PlayerObject* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateMove(dt);
                });

            luaManager.addValidHook("PlayerObject:update_player_art");
            usertype.set_function("update_player_art",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerArt();
                });

            luaManager.addValidHook("PlayerObject:update_player_bird_frame");
            usertype.set_function("update_player_bird_frame",
                [](PlayerObject* self, int frame) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerBirdFrame(frame);
                });

            luaManager.addValidHook("PlayerObject:update_player_dart_frame");
            usertype.set_function("update_player_dart_frame",
                [](PlayerObject* self, int frame) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerDartFrame(frame);
                });

            usertype.set_function("update_player_force",
                [](PlayerObject* self, cocos2d::CCPoint velocity, bool additive) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updatePlayerForce(velocity, additive);
                });

            luaManager.addValidHook("PlayerObject:update_player_frame");
            usertype.set_function("update_player_frame",
                [](PlayerObject* self, int frame) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerFrame(frame);
                });

            luaManager.addValidHook("PlayerObject:update_player_glow");
            usertype.set_function("update_player_glow",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerGlow();
                });

            luaManager.addValidHook("PlayerObject:update_player_jetpack_frame");
            usertype.set_function("update_player_jetpack_frame",
                [](PlayerObject* self, int frame) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerJetpackFrame(frame);
                });

            usertype.set_function("update_player_robot_frame",
                [](PlayerObject* self, int frame) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updatePlayerRobotFrame(frame);
                });

            luaManager.addValidHook("PlayerObject:update_player_roll_frame");
            usertype.set_function("update_player_roll_frame",
                [](PlayerObject* self, int frame) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerRollFrame(frame);
                });

            usertype.set_function("update_player_scale",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updatePlayerScale();
                });

            luaManager.addValidHook("PlayerObject:update_player_ship_frame");
            usertype.set_function("update_player_ship_frame",
                [](PlayerObject* self, int frame) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerShipFrame(frame);
                });

            usertype.set_function("update_player_spider_frame",
                [](PlayerObject* self, int frame) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updatePlayerSpiderFrame(frame);
                });

            luaManager.addValidHook("PlayerObject:update_player_sprite_extra");
            usertype.set_function("update_player_sprite_extra",
                [](PlayerObject* self, gd::string frameName) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerSpriteExtra(frameName);
                });

            luaManager.addValidHook("PlayerObject:update_player_swing_frame");
            usertype.set_function("update_player_swing_frame",
                [](PlayerObject* self, int frame) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updatePlayerSwingFrame(frame);
                });

            luaManager.addValidHook("PlayerObject:update_robot_animation_speed");
            usertype.set_function("update_robot_animation_speed",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateRobotAnimationSpeed();
                });

            luaManager.addValidHook("PlayerObject:update_rotation");
            luaManager.addValidHook("PlayerObject:update_rotation@2");
            usertype.set_function("update_rotation",
                sol::overload(
                    [](PlayerObject* self, float dt) {
                        auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                        modifiedSelf->updateRotation(dt);
                    },
                    [](PlayerObject* self, float dt, float rotation) {
                        auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                        modifiedSelf->updateRotation(dt, rotation);
                    }));

            luaManager.addValidHook("PlayerObject:update_ship_rotation");
            usertype.set_function("update_ship_rotation",
                [](PlayerObject* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateShipRotation(dt);
                });

            luaManager.addValidHook("PlayerObject:update_ship_sprite_extra");
            usertype.set_function("update_ship_sprite_extra",
                [](PlayerObject* self, gd::string frameName) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateShipSpriteExtra(frameName);
                });

            luaManager.addValidHook("PlayerObject:update_slope_rotation");
            usertype.set_function("update_slope_rotation",
                [](PlayerObject* self, float dt) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateSlopeRotation(dt);
                });

            usertype.set_function("update_slope_yvelocity",
                [](PlayerObject* self, float yVelocity) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateSlopeYVelocity(yVelocity);
                });

            usertype.set_function("update_special",
                [](PlayerObject* self, float dt) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateSpecial(dt);
                });

            usertype.set_function("update_state_variables",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateStateVariables();
                });

            usertype.set_function("update_static_force",
                [](PlayerObject* self, float rotation, float staticForce, bool additive) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateStaticForce(rotation, staticForce, additive);
                });

            luaManager.addValidHook("PlayerObject:update_streak_blend");
            usertype.set_function("update_streak_blend",
                [](PlayerObject* self, bool blend) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateStreakBlend(blend);
                });

            usertype.set_function("update_streaks",
                [](PlayerObject* self, float dt) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateStreaks(dt);
                });

            luaManager.addValidHook("PlayerObject:update_swing_fire");
            usertype.set_function("update_swing_fire",
                [](PlayerObject* self) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateSwingFire();
                });

            luaManager.addValidHook("PlayerObject:update_time_mod");
            usertype.set_function("update_time_mod",
                [](PlayerObject* self, float speed, bool noEffects) {
                    auto modifiedSelf = static_cast<quartz::PlayerObjectModified*>(self);
                    modifiedSelf->updateTimeMod(speed, noEffects);
                });

            usertype.set_function("using_wall_limited_mode",
                [](PlayerObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->usingWallLimitedMode();
                });

            usertype.set_function("y_start_down",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->yStartDown();
                });

            usertype.set_function("y_start_up",
                [](PlayerObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->yStartUp();
                });
        });
}

} // namespace quartz