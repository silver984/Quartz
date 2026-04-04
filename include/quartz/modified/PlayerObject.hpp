#pragma once
#include <Geode/modify/PlayerObject.hpp>
#include <quartz/core/LuaFields.hpp>

namespace quartz {

struct PlayerObjectModified : geode::Modify<PlayerObjectModified, PlayerObject>, quartz::LuaFields {
    // @lua "PlayerObject:activate_streak"
    void activateStreak();

    // @lua "PlayerObject:add_all_particles"
    void addAllParticles();

    // @lua "PlayerObject:animate_platformer_jump"
    void animatePlatformerJump(float scale);

    // @lua "PlayerObject:animation_finished"
    void animationFinished(char const* key) override;

    // @lua "PlayerObject:boost_player"
    void boostPlayer(float yVelocity);

    // @lua "PlayerObject:bump_player"
    void bumpPlayer(float bumpMod, int objectType, bool noEffects, GameObject* object);

    // @lua "PlayerObject:check_snap_jump_to_object"
    void checkSnapJumpToObject(GameObject* object);

    // @lua "PlayerObject:collided_with_object@2"
    bool collidedWithObject(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck);

    // @lua "PlayerObject:collided_with_object_internal"
    bool collidedWithObjectInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck);

    // @lua "PlayerObject:collided_with_slope_internal"
    void collidedWithSlopeInternal(float dt, GameObject* object, bool forced);

    // @lua "PlayerObject:convert_to_closest_rotation"
    float convertToClosestRotation(float rotation);

    // @lua "PlayerObject:copy_attributes"
    void copyAttributes(PlayerObject* player);

    // @lua "PlayerObject.create"
    static PlayerObject* create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);

    // @lua "PlayerObject:create_fade_out_dart_streak"
    void createFadeOutDartStreak();

    // @lua "PlayerObject:create_robot"
    void createRobot(int frame);

    // @lua "PlayerObject:create_spider"
    void createSpider(int frame);

    // @lua "PlayerObject:did_hit_head"
    void didHitHead();

    // @lua "PlayerObject:disable_player_controls"
    void disablePlayerControls();

    // @lua "PlayerObject:disable_swing_fire"
    void disableSwingFire();

    // @lua "PlayerObject:do_reverse_player"
    void doReversePlayer(bool reverse);

    // @lua "PlayerObject:enable_player_controls"
    void enablePlayerControls();

    // @lua "PlayerObject:exit_platformer_animate_jump"
    void exitPlatformerAnimateJump();

    // @lua "PlayerObject:fade_out_streak2"
    void fadeOutStreak2(float duration);

    // @lua "PlayerObject:flip_gravity"
    void flipGravity(bool flip, bool noEffects);

    // @lua "PlayerObject:get_object_rotation"
    float getObjectRotation() override;

    // @lua "PlayerObject:get_oriented_box"
    OBB2D* getOrientedBox() override;

    // @lua "PlayerObject:get_real_position"
    cocos2d::CCPoint getRealPosition() override;

    // @lua "PlayerObject:handle_rotated_collision_internal"
    bool handleRotatedCollisionInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck, bool skipPre, bool slope);

    // @lua "PlayerObject:hit_ground"
    void hitGround(GameObject* object, bool notFlipped);

    // @lua "PlayerObject:increment_jumps"
    void incrementJumps();

    // @lua "PlayerObject:init"
    bool init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer);

    // @lua "PlayerObject:level_flip_finished"
    void levelFlipFinished();

    // @lua "PlayerObject:level_will_flip"
    void levelWillFlip();

    // @lua "PlayerObject:load_from_checkpoint"
    void loadFromCheckpoint(PlayerCheckpoint* object);

    // @lua "PlayerObject:lock_player"
    void lockPlayer();

    // @lua "PlayerObject:place_streak_point"
    void placeStreakPoint();

    // @lua "PlayerObject:play_bump_effect"
    void playBumpEffect(int objectType, GameObject* player);

    // @lua "PlayerObject:play_complete_effect"
    void playCompleteEffect(bool noEffects, bool instant);

    // @lua "PlayerObject:play_death_effect"
    void playDeathEffect();

    // @lua "PlayerObject:play_dynamic_spider_run"
    void playDynamicSpiderRun();

    // @lua "PlayerObject:play_spawn_effect"
    void playSpawnEffect();

    // @lua "PlayerObject:play_spider_dash_effect"
    void playSpiderDashEffect(cocos2d::CCPoint from, cocos2d::CCPoint to);

    // @lua "PlayerObject:player_destroyed"
    void playerDestroyed(bool noEffects);

    // @lua "PlayerObject:player_is_falling_bugged"
    bool playerIsFallingBugged();

    // @lua "PlayerObject:post_collision"
    void postCollision(float dt, bool betweenSteps);

    // @lua "PlayerObject:pre_slope_collision"
    bool preSlopeCollision(float dt, GameObject* object);

    // @lua "PlayerObject:propell_player"
    void propellPlayer(float yVelocity, bool noEffects, int objectType);

    // @lua "PlayerObject:push_button"
    bool pushButton(PlayerButton button);

    // @lua "PlayerObject:redirect_player_force"
    void redirectPlayerForce(float rotation, float modifier, float minimum, float maximum);

    // @lua "PlayerObject:release_all_buttons"
    void releaseAllButtons();

    // @lua "PlayerObject:release_button"
    bool releaseButton(PlayerButton button);

    // @lua "PlayerObject:remove_pending_checkpoint"
    void removePendingCheckpoint();

    // @lua "PlayerObject:reset_all_particles"
    void resetAllParticles();

    // @lua "PlayerObject:reset_object"
    void resetObject() override;

    // @lua "PlayerObject:reset_player_icon"
    void resetPlayerIcon();

    // @lua "PlayerObject:reset_streak"
    void resetStreak();

    // @lua "PlayerObject:reset_touched_rings"
    void resetTouchedRings(bool removeAll);

    // @lua "PlayerObject:reverse_player"
    void reversePlayer(EffectGameObject* object);

    // @lua "PlayerObject:ring_jump"
    void ringJump(RingObject* object, bool skipCheck);

    // @lua "PlayerObject:rotate_gameplay"
    void rotateGameplay(int moveDirection, int groundDirection, bool editVelocity, float velocityModX, float velocityModY, bool overrideVelocity, bool dontSlide);

    // @lua "PlayerObject:rotate_gameplay_object"
    void rotateGameplayObject(GameObject* object);

    // @lua "PlayerObject:run_ball_rotation"
    void runBallRotation(float speed);

    // @lua "PlayerObject:run_ball_rotation2"
    void runBallRotation2();

    // @lua "PlayerObject:run_normal_rotation@2"
    void runNormalRotation(bool notNormalMode, float speed);

    // @lua "PlayerObject:save_to_checkpoint"
    void saveToCheckpoint(PlayerCheckpoint* checkpoint);

    // @lua "PlayerObject:set_color"
    void setColor(cocos2d::ccColor3B const& color) override;

    // @lua "PlayerObject:set_flip_x"
    void setFlipX(bool flipX) override;

    // @lua "PlayerObject:set_flip_y"
    void setFlipY(bool flipY) override;

    // @lua "PlayerObject:set_opacity"
    void setOpacity(unsigned char opacity) override;

    // @lua "PlayerObject:set_position"
    void setPosition(cocos2d::CCPoint const& position) override;

    // @lua "PlayerObject:set_rotation"
    void setRotation(float rotation) override;

    // @lua "PlayerObject:set_scale"
    void setScale(float scale) override;

    // @lua "PlayerObject:set_scale_x"
    void setScaleX(float scale) override;

    // @lua "PlayerObject:set_scale_y"
    void setScaleY(float scale) override;

    // @lua "PlayerObject:set_second_color"
    void setSecondColor(cocos2d::ccColor3B const& color);

    // @lua "PlayerObject:set_visible"
    void setVisible(bool visible) override;

    // @lua "PlayerObject:set_yvelocity"
    void setYVelocity(double velocity, int type);

    // @lua "PlayerObject:setup_streak"
    void setupStreak();

    // @lua "PlayerObject:spawn_circle"
    void spawnCircle();

    // @lua "PlayerObject:spawn_dual_circle"
    void spawnDualCircle();

    // @lua "PlayerObject:spawn_portal_circle"
    void spawnPortalCircle(cocos2d::ccColor3B color, float startRadius);

    // @lua "PlayerObject:spawn_scale_circle"
    void spawnScaleCircle();

    // @lua "PlayerObject:spider_test_jump"
    void spiderTestJump(bool dynamic);

    // @lua "PlayerObject:spider_test_jump_internal"
    void spiderTestJumpInternal(bool dynamic);

    // @lua "PlayerObject:spider_test_jump_x"
    void spiderTestJumpX(bool dynamic);

    // @lua "PlayerObject:spider_test_jump_y"
    void spiderTestJumpY(bool dynamic);

    // @lua "PlayerObject:start_dashing"
    void startDashing(DashRingObject* object);

    // @lua "PlayerObject:stop_burst_effect"
    void stopBurstEffect();

    // @lua "PlayerObject:stop_dashing"
    void stopDashing();

    // @lua "PlayerObject:stop_particles"
    void stopParticles();

    // @lua "PlayerObject:stop_platformer_jump_animation"
    void stopPlatformerJumpAnimation();

    // @lua "PlayerObject:switched_dir_to"
    bool switchedDirTo(PlayerButton button);

    // @lua "PlayerObject:switched_to_mode"
    void switchedToMode(GameObjectType type);

    // @lua "PlayerObject:toggle_bird_mode"
    void toggleBirdMode(bool enable, bool noEffects);

    // @lua "PlayerObject:toggle_dart_mode"
    void toggleDartMode(bool enable, bool noEffects);

    // @lua "PlayerObject:toggle_fly_mode"
    void toggleFlyMode(bool enable, bool noEffects);

    // @lua "PlayerObject:toggle_ghost_effect"
    void toggleGhostEffect(GhostType type);

    // @lua "PlayerObject:toggle_player_scale"
    void togglePlayerScale(bool enable, bool noEffects);

    // @lua "PlayerObject:toggle_robot_mode"
    void toggleRobotMode(bool enable, bool noEffects);

    // @lua "PlayerObject:toggle_roll_mode"
    void toggleRollMode(bool enable, bool noEffects);

    // @lua "PlayerObject:toggle_spider_mode"
    void toggleSpiderMode(bool enable, bool noEffects);

    // @lua "PlayerObject:toggle_swing_mode"
    void toggleSwingMode(bool enable, bool noEffects);

    // @lua "PlayerObject:toggle_visibility"
    void toggleVisibility(bool visible);

    // @lua "PlayerObject:try_place_checkpoint"
    void tryPlaceCheckpoint();

    // @lua "PlayerObject:unrotate_gameplay_object"
    void unrotateGameplayObject(GameObject* object);

    // @lua "PlayerObject:update"
    void update(float dt) override;

    // @lua "PlayerObject:update_collide"
    void updateCollide(PlayerCollisionDirection direction, GameObject* object);

    // @lua "PlayerObject:update_collide_left"
    void updateCollideLeft(float x, GameObject* object);

    // @lua "PlayerObject:update_collide_right"
    void updateCollideRight(float x, GameObject* object);

    // @lua "PlayerObject:update_dash_animation"
    void updateDashAnimation();

    // @lua "PlayerObject:update_dash_art"
    void updateDashArt();

    // @lua "PlayerObject:update_glow_color"
    void updateGlowColor();

    // @lua "PlayerObject:update_internal_actions"
    void updateInternalActions(float dt);

    // @lua "PlayerObject:update_jump"
    void updateJump(float dt);

    // @lua "PlayerObject:update_move"
    void updateMove(float dt);

    // @lua "PlayerObject:update_player_art"
    void updatePlayerArt();

    // @lua "PlayerObject:update_player_bird_frame"
    void updatePlayerBirdFrame(int frame);

    // @lua "PlayerObject:update_player_dart_frame"
    void updatePlayerDartFrame(int frame);

    // @lua "PlayerObject:update_player_frame"
    void updatePlayerFrame(int frame);

    // @lua "PlayerObject:update_player_glow"
    void updatePlayerGlow();

    // @lua "PlayerObject:update_player_jetpack_frame"
    void updatePlayerJetpackFrame(int frame);

    // @lua "PlayerObject:update_player_roll_frame"
    void updatePlayerRollFrame(int frame);

    // @lua "PlayerObject:update_player_ship_frame"
    void updatePlayerShipFrame(int frame);

    // @lua "PlayerObject:update_player_sprite_extra"
    void updatePlayerSpriteExtra(gd::string frameName);

    // @lua "PlayerObject:update_player_swing_frame"
    void updatePlayerSwingFrame(int frame);

    // @lua "PlayerObject:update_robot_animation_speed"
    void updateRobotAnimationSpeed();

    // @lua "PlayerObject:update_rotation"
    void updateRotation(float dt);

    // @lua "PlayerObject:update_rotation@2"
    void updateRotation(float dt, float rotation);

    // @lua "PlayerObject:update_ship_rotation"
    void updateShipRotation(float dt);

    // @lua "PlayerObject:update_ship_sprite_extra"
    void updateShipSpriteExtra(gd::string frameName);

    // @lua "PlayerObject:update_slope_rotation"
    void updateSlopeRotation(float dt);

    // @lua "PlayerObject:update_streak_blend"
    void updateStreakBlend(bool blend);

    // @lua "PlayerObject:update_swing_fire"
    void updateSwingFire();

    // @lua "PlayerObject:update_time_mod"
    void updateTimeMod(float speed, bool noEffects);
};

} // namespace quartz