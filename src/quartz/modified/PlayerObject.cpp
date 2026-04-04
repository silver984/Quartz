#include <quartz/modified/PlayerObject.hpp>
#include <quartz/core/Templates.hpp>
#include <utility>

namespace quartz {

void PlayerObjectModified::activateStreak() {
    quartz::runHookChain<void>("PlayerObject:activate_streak",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::activateStreak(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::addAllParticles() {
    quartz::runHookChain<void>("PlayerObject:add_all_particles",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::addAllParticles(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::animatePlatformerJump(float scale) {
    quartz::runHookChain<void>("PlayerObject:animate_platformer_jump",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::animatePlatformerJump(std::forward<decltype(args)>(args)...); 
        }, scale);
}

void PlayerObjectModified::animationFinished(char const* key) {
    quartz::runHookChain<void>("PlayerObject:animation_finished",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::animationFinished(std::forward<decltype(args)>(args)...); 
        }, key);
}

void PlayerObjectModified::boostPlayer(float yVelocity) {
    quartz::runHookChain<void>("PlayerObject:boost_player",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::boostPlayer(std::forward<decltype(args)>(args)...); 
        }, yVelocity);
}

void PlayerObjectModified::bumpPlayer(float bumpMod, int objectType, bool noEffects, GameObject* object) {
    quartz::runHookChain<void>("PlayerObject:bump_player",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::bumpPlayer(std::forward<decltype(args)>(args)...); 
        }, bumpMod, objectType, noEffects, object);
}

void PlayerObjectModified::checkSnapJumpToObject(GameObject* object) {
    quartz::runHookChain<void>("PlayerObject:check_snap_jump_to_object",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::checkSnapJumpToObject(std::forward<decltype(args)>(args)...); 
        }, object);
}

bool PlayerObjectModified::collidedWithObject(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) {
    return quartz::runHookChain<bool>("PlayerObject:collided_with_object@2",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::collidedWithObject(std::forward<decltype(args)>(args)...); 
        }, dt, object, rect, skipCheck);
}

bool PlayerObjectModified::collidedWithObjectInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck) {
    return quartz::runHookChain<bool>("PlayerObject:collided_with_object_internal",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::collidedWithObjectInternal(std::forward<decltype(args)>(args)...); 
        }, dt, object, rect, skipCheck);
}

void PlayerObjectModified::collidedWithSlopeInternal(float dt, GameObject* object, bool forced) {
    quartz::runHookChain<void>("PlayerObject:collided_with_slope_internal",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::collidedWithSlopeInternal(std::forward<decltype(args)>(args)...); 
        }, dt, object, forced);
}

float PlayerObjectModified::convertToClosestRotation(float rotation) {
    return quartz::runHookChain<float>("PlayerObject:convert_to_closest_rotation",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::convertToClosestRotation(std::forward<decltype(args)>(args)...); 
        }, rotation);
}

void PlayerObjectModified::copyAttributes(PlayerObject* player) {
    quartz::runHookChain<void>("PlayerObject:copy_attributes",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::copyAttributes(std::forward<decltype(args)>(args)...); 
        }, player);
}

PlayerObject* PlayerObjectModified::create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) {
    return quartz::runStaticHookChain<PlayerObject*>("PlayerObject.create",
        &PlayerObject::create,
        player, ship, gameLayer, layer, playLayer);
}

void PlayerObjectModified::createFadeOutDartStreak() {
    quartz::runHookChain<void>("PlayerObject:create_fade_out_dart_streak",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::createFadeOutDartStreak(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::createRobot(int frame) {
    quartz::runHookChain<void>("PlayerObject:create_robot",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::createRobot(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void PlayerObjectModified::createSpider(int frame) {
    quartz::runHookChain<void>("PlayerObject:create_spider",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::createSpider(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void PlayerObjectModified::didHitHead() {
    quartz::runHookChain<void>("PlayerObject:did_hit_head",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::didHitHead(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::disablePlayerControls() {
    quartz::runHookChain<void>("PlayerObject:disable_player_controls",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::disablePlayerControls(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::disableSwingFire() {
    quartz::runHookChain<void>("PlayerObject:disable_swing_fire",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::disableSwingFire(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::doReversePlayer(bool reverse) {
    quartz::runHookChain<void>("PlayerObject:do_reverse_player",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::doReversePlayer(std::forward<decltype(args)>(args)...); 
        }, reverse);
}

void PlayerObjectModified::enablePlayerControls() {
    quartz::runHookChain<void>("PlayerObject:enable_player_controls",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::enablePlayerControls(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::exitPlatformerAnimateJump() {
    quartz::runHookChain<void>("PlayerObject:exit_platformer_animate_jump",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::exitPlatformerAnimateJump(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::fadeOutStreak2(float duration) {
    quartz::runHookChain<void>("PlayerObject:fade_out_streak2",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::fadeOutStreak2(std::forward<decltype(args)>(args)...); 
        }, duration);
}

void PlayerObjectModified::flipGravity(bool flip, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:flip_gravity",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::flipGravity(std::forward<decltype(args)>(args)...); 
        }, flip, noEffects);
}

float PlayerObjectModified::getObjectRotation() {
    return quartz::runHookChain<float>("PlayerObject:get_object_rotation",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::getObjectRotation(std::forward<decltype(args)>(args)...); 
        });
}

OBB2D* PlayerObjectModified::getOrientedBox() {
    return quartz::runHookChain<OBB2D*>("PlayerObject:get_oriented_box",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::getOrientedBox(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCPoint PlayerObjectModified::getRealPosition() {
    return quartz::runHookChain<cocos2d::CCPoint>("PlayerObject:get_real_position",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::getRealPosition(std::forward<decltype(args)>(args)...); 
        });
}

bool PlayerObjectModified::handleRotatedCollisionInternal(float dt, GameObject* object, cocos2d::CCRect rect, bool skipCheck, bool skipPre, bool slope) {
    return quartz::runHookChain<bool>("PlayerObject:handle_rotated_collision_internal",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::handleRotatedCollisionInternal(std::forward<decltype(args)>(args)...); 
        }, dt, object, rect, skipCheck, skipPre, slope);
}

void PlayerObjectModified::hitGround(GameObject* object, bool notFlipped) {
    quartz::runHookChain<void>("PlayerObject:hit_ground",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::hitGround(std::forward<decltype(args)>(args)...); 
        }, object, notFlipped);
}

void PlayerObjectModified::incrementJumps() {
    quartz::runHookChain<void>("PlayerObject:increment_jumps",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::incrementJumps(std::forward<decltype(args)>(args)...); 
        });
}

bool PlayerObjectModified::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) {
    return quartz::runHookChain<bool>("PlayerObject:init",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::init(std::forward<decltype(args)>(args)...); 
        }, player, ship, gameLayer, layer, playLayer);
}

void PlayerObjectModified::levelFlipFinished() {
    quartz::runHookChain<void>("PlayerObject:level_flip_finished",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::levelFlipFinished(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::levelWillFlip() {
    quartz::runHookChain<void>("PlayerObject:level_will_flip",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::levelWillFlip(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::loadFromCheckpoint(PlayerCheckpoint* object) {
    quartz::runHookChain<void>("PlayerObject:load_from_checkpoint",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::loadFromCheckpoint(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayerObjectModified::lockPlayer() {
    quartz::runHookChain<void>("PlayerObject:lock_player",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::lockPlayer(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::placeStreakPoint() {
    quartz::runHookChain<void>("PlayerObject:place_streak_point",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::placeStreakPoint(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::playBumpEffect(int objectType, GameObject* player) {
    quartz::runHookChain<void>("PlayerObject:play_bump_effect",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::playBumpEffect(std::forward<decltype(args)>(args)...); 
        }, objectType, player);
}

void PlayerObjectModified::playCompleteEffect(bool noEffects, bool instant) {
    quartz::runHookChain<void>("PlayerObject:play_complete_effect",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::playCompleteEffect(std::forward<decltype(args)>(args)...); 
        }, noEffects, instant);
}

void PlayerObjectModified::playDeathEffect() {
    quartz::runHookChain<void>("PlayerObject:play_death_effect",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::playDeathEffect(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::playDynamicSpiderRun() {
    quartz::runHookChain<void>("PlayerObject:play_dynamic_spider_run",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::playDynamicSpiderRun(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::playSpawnEffect() {
    quartz::runHookChain<void>("PlayerObject:play_spawn_effect",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::playSpawnEffect(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::playSpiderDashEffect(cocos2d::CCPoint from, cocos2d::CCPoint to) {
    quartz::runHookChain<void>("PlayerObject:play_spider_dash_effect",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::playSpiderDashEffect(std::forward<decltype(args)>(args)...); 
        }, from, to);
}

void PlayerObjectModified::playerDestroyed(bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:player_destroyed",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::playerDestroyed(std::forward<decltype(args)>(args)...); 
        }, noEffects);
}

bool PlayerObjectModified::playerIsFallingBugged() {
    return quartz::runHookChain<bool>("PlayerObject:player_is_falling_bugged",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::playerIsFallingBugged(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::postCollision(float dt, bool betweenSteps) {
    quartz::runHookChain<void>("PlayerObject:post_collision",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::postCollision(std::forward<decltype(args)>(args)...); 
        }, dt, betweenSteps);
}

bool PlayerObjectModified::preSlopeCollision(float dt, GameObject* object) {
    return quartz::runHookChain<bool>("PlayerObject:pre_slope_collision",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::preSlopeCollision(std::forward<decltype(args)>(args)...); 
        }, dt, object);
}

void PlayerObjectModified::propellPlayer(float yVelocity, bool noEffects, int objectType) {
    quartz::runHookChain<void>("PlayerObject:propell_player",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::propellPlayer(std::forward<decltype(args)>(args)...); 
        }, yVelocity, noEffects, objectType);
}

bool PlayerObjectModified::pushButton(PlayerButton button) {
    return quartz::runHookChain<bool>("PlayerObject:push_button",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::pushButton(std::forward<decltype(args)>(args)...); 
        }, button);
}

void PlayerObjectModified::redirectPlayerForce(float rotation, float modifier, float minimum, float maximum) {
    quartz::runHookChain<void>("PlayerObject:redirect_player_force",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::redirectPlayerForce(std::forward<decltype(args)>(args)...); 
        }, rotation, modifier, minimum, maximum);
}

void PlayerObjectModified::releaseAllButtons() {
    quartz::runHookChain<void>("PlayerObject:release_all_buttons",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::releaseAllButtons(std::forward<decltype(args)>(args)...); 
        });
}

bool PlayerObjectModified::releaseButton(PlayerButton button) {
    return quartz::runHookChain<bool>("PlayerObject:release_button",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::releaseButton(std::forward<decltype(args)>(args)...); 
        }, button);
}

void PlayerObjectModified::removePendingCheckpoint() {
    quartz::runHookChain<void>("PlayerObject:remove_pending_checkpoint",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::removePendingCheckpoint(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::resetAllParticles() {
    quartz::runHookChain<void>("PlayerObject:reset_all_particles",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::resetAllParticles(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::resetObject() {
    quartz::runHookChain<void>("PlayerObject:reset_object",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::resetObject(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::resetPlayerIcon() {
    quartz::runHookChain<void>("PlayerObject:reset_player_icon",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::resetPlayerIcon(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::resetStreak() {
    quartz::runHookChain<void>("PlayerObject:reset_streak",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::resetStreak(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::resetTouchedRings(bool removeAll) {
    quartz::runHookChain<void>("PlayerObject:reset_touched_rings",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::resetTouchedRings(std::forward<decltype(args)>(args)...); 
        }, removeAll);
}

void PlayerObjectModified::reversePlayer(EffectGameObject* object) {
    quartz::runHookChain<void>("PlayerObject:reverse_player",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::reversePlayer(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayerObjectModified::ringJump(RingObject* object, bool skipCheck) {
    quartz::runHookChain<void>("PlayerObject:ring_jump",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::ringJump(std::forward<decltype(args)>(args)...); 
        }, object, skipCheck);
}

void PlayerObjectModified::rotateGameplay(int moveDirection, int groundDirection, bool editVelocity, float velocityModX, float velocityModY, bool overrideVelocity, bool dontSlide) {
    quartz::runHookChain<void>("PlayerObject:rotate_gameplay",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::rotateGameplay(std::forward<decltype(args)>(args)...); 
        }, moveDirection, groundDirection, editVelocity, velocityModX, velocityModY, overrideVelocity, dontSlide);
}

void PlayerObjectModified::rotateGameplayObject(GameObject* object) {
    quartz::runHookChain<void>("PlayerObject:rotate_gameplay_object",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::rotateGameplayObject(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayerObjectModified::runBallRotation(float speed) {
    quartz::runHookChain<void>("PlayerObject:run_ball_rotation",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::runBallRotation(std::forward<decltype(args)>(args)...); 
        }, speed);
}

void PlayerObjectModified::runBallRotation2() {
    quartz::runHookChain<void>("PlayerObject:run_ball_rotation2",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::runBallRotation2(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::runNormalRotation(bool notNormalMode, float speed) {
    quartz::runHookChain<void>("PlayerObject:run_normal_rotation@2",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::runNormalRotation(std::forward<decltype(args)>(args)...); 
        }, notNormalMode, speed);
}

void PlayerObjectModified::saveToCheckpoint(PlayerCheckpoint* checkpoint) {
    quartz::runHookChain<void>("PlayerObject:save_to_checkpoint",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::saveToCheckpoint(std::forward<decltype(args)>(args)...); 
        }, checkpoint);
}

void PlayerObjectModified::setColor(cocos2d::ccColor3B const& color) {
    quartz::runHookChain<void>("PlayerObject:set_color",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setColor(std::forward<decltype(args)>(args)...); 
        }, color);
}

void PlayerObjectModified::setFlipX(bool flipX) {
    quartz::runHookChain<void>("PlayerObject:set_flip_x",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setFlipX(std::forward<decltype(args)>(args)...); 
        }, flipX);
}

void PlayerObjectModified::setFlipY(bool flipY) {
    quartz::runHookChain<void>("PlayerObject:set_flip_y",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setFlipY(std::forward<decltype(args)>(args)...); 
        }, flipY);
}

void PlayerObjectModified::setOpacity(unsigned char opacity) {
    quartz::runHookChain<void>("PlayerObject:set_opacity",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setOpacity(std::forward<decltype(args)>(args)...); 
        }, opacity);
}

void PlayerObjectModified::setPosition(cocos2d::CCPoint const& position) {
    quartz::runHookChain<void>("PlayerObject:set_position",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setPosition(std::forward<decltype(args)>(args)...); 
        }, position);
}

void PlayerObjectModified::setRotation(float rotation) {
    quartz::runHookChain<void>("PlayerObject:set_rotation",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setRotation(std::forward<decltype(args)>(args)...); 
        }, rotation);
}

void PlayerObjectModified::setScale(float scale) {
    quartz::runHookChain<void>("PlayerObject:set_scale",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setScale(std::forward<decltype(args)>(args)...); 
        }, scale);
}

void PlayerObjectModified::setScaleX(float scale) {
    quartz::runHookChain<void>("PlayerObject:set_scale_x",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setScaleX(std::forward<decltype(args)>(args)...); 
        }, scale);
}

void PlayerObjectModified::setScaleY(float scale) {
    quartz::runHookChain<void>("PlayerObject:set_scale_y",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setScaleY(std::forward<decltype(args)>(args)...); 
        }, scale);
}

void PlayerObjectModified::setSecondColor(cocos2d::ccColor3B const& color) {
    quartz::runHookChain<void>("PlayerObject:set_second_color",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setSecondColor(std::forward<decltype(args)>(args)...); 
        }, color);
}

void PlayerObjectModified::setVisible(bool visible) {
    quartz::runHookChain<void>("PlayerObject:set_visible",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setVisible(std::forward<decltype(args)>(args)...); 
        }, visible);
}

void PlayerObjectModified::setYVelocity(double velocity, int type) {
    quartz::runHookChain<void>("PlayerObject:set_yvelocity",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setYVelocity(std::forward<decltype(args)>(args)...); 
        }, velocity, type);
}

void PlayerObjectModified::setupStreak() {
    quartz::runHookChain<void>("PlayerObject:setup_streak",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::setupStreak(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::spawnCircle() {
    quartz::runHookChain<void>("PlayerObject:spawn_circle",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::spawnCircle(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::spawnDualCircle() {
    quartz::runHookChain<void>("PlayerObject:spawn_dual_circle",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::spawnDualCircle(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::spawnPortalCircle(cocos2d::ccColor3B color, float startRadius) {
    quartz::runHookChain<void>("PlayerObject:spawn_portal_circle",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::spawnPortalCircle(std::forward<decltype(args)>(args)...); 
        }, color, startRadius);
}

void PlayerObjectModified::spawnScaleCircle() {
    quartz::runHookChain<void>("PlayerObject:spawn_scale_circle",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::spawnScaleCircle(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::spiderTestJump(bool dynamic) {
    quartz::runHookChain<void>("PlayerObject:spider_test_jump",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::spiderTestJump(std::forward<decltype(args)>(args)...); 
        }, dynamic);
}

void PlayerObjectModified::spiderTestJumpInternal(bool dynamic) {
    quartz::runHookChain<void>("PlayerObject:spider_test_jump_internal",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::spiderTestJumpInternal(std::forward<decltype(args)>(args)...); 
        }, dynamic);
}

void PlayerObjectModified::spiderTestJumpX(bool dynamic) {
    quartz::runHookChain<void>("PlayerObject:spider_test_jump_x",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::spiderTestJumpX(std::forward<decltype(args)>(args)...); 
        }, dynamic);
}

void PlayerObjectModified::spiderTestJumpY(bool dynamic) {
    quartz::runHookChain<void>("PlayerObject:spider_test_jump_y",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::spiderTestJumpY(std::forward<decltype(args)>(args)...); 
        }, dynamic);
}

void PlayerObjectModified::startDashing(DashRingObject* object) {
    quartz::runHookChain<void>("PlayerObject:start_dashing",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::startDashing(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayerObjectModified::stopBurstEffect() {
    quartz::runHookChain<void>("PlayerObject:stop_burst_effect",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::stopBurstEffect(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::stopDashing() {
    quartz::runHookChain<void>("PlayerObject:stop_dashing",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::stopDashing(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::stopParticles() {
    quartz::runHookChain<void>("PlayerObject:stop_particles",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::stopParticles(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::stopPlatformerJumpAnimation() {
    quartz::runHookChain<void>("PlayerObject:stop_platformer_jump_animation",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::stopPlatformerJumpAnimation(std::forward<decltype(args)>(args)...); 
        });
}

bool PlayerObjectModified::switchedDirTo(PlayerButton button) {
    return quartz::runHookChain<bool>("PlayerObject:switched_dir_to",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::switchedDirTo(std::forward<decltype(args)>(args)...); 
        }, button);
}

void PlayerObjectModified::switchedToMode(GameObjectType type) {
    quartz::runHookChain<void>("PlayerObject:switched_to_mode",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::switchedToMode(std::forward<decltype(args)>(args)...); 
        }, type);
}

void PlayerObjectModified::toggleBirdMode(bool enable, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:toggle_bird_mode",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::toggleBirdMode(std::forward<decltype(args)>(args)...); 
        }, enable, noEffects);
}

void PlayerObjectModified::toggleDartMode(bool enable, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:toggle_dart_mode",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::toggleDartMode(std::forward<decltype(args)>(args)...); 
        }, enable, noEffects);
}

void PlayerObjectModified::toggleFlyMode(bool enable, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:toggle_fly_mode",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::toggleFlyMode(std::forward<decltype(args)>(args)...); 
        }, enable, noEffects);
}

void PlayerObjectModified::toggleGhostEffect(GhostType type) {
    quartz::runHookChain<void>("PlayerObject:toggle_ghost_effect",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::toggleGhostEffect(std::forward<decltype(args)>(args)...); 
        }, type);
}

void PlayerObjectModified::togglePlayerScale(bool enable, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:toggle_player_scale",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::togglePlayerScale(std::forward<decltype(args)>(args)...); 
        }, enable, noEffects);
}

void PlayerObjectModified::toggleRobotMode(bool enable, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:toggle_robot_mode",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::toggleRobotMode(std::forward<decltype(args)>(args)...); 
        }, enable, noEffects);
}

void PlayerObjectModified::toggleRollMode(bool enable, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:toggle_roll_mode",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::toggleRollMode(std::forward<decltype(args)>(args)...); 
        }, enable, noEffects);
}

void PlayerObjectModified::toggleSpiderMode(bool enable, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:toggle_spider_mode",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::toggleSpiderMode(std::forward<decltype(args)>(args)...); 
        }, enable, noEffects);
}

void PlayerObjectModified::toggleSwingMode(bool enable, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:toggle_swing_mode",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::toggleSwingMode(std::forward<decltype(args)>(args)...); 
        }, enable, noEffects);
}

void PlayerObjectModified::toggleVisibility(bool visible) {
    quartz::runHookChain<void>("PlayerObject:toggle_visibility",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::toggleVisibility(std::forward<decltype(args)>(args)...); 
        }, visible);
}

void PlayerObjectModified::tryPlaceCheckpoint() {
    quartz::runHookChain<void>("PlayerObject:try_place_checkpoint",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::tryPlaceCheckpoint(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::unrotateGameplayObject(GameObject* object) {
    quartz::runHookChain<void>("PlayerObject:unrotate_gameplay_object",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::unrotateGameplayObject(std::forward<decltype(args)>(args)...); 
        }, object);
}

void PlayerObjectModified::update(float dt) {
    quartz::runHookChain<void>("PlayerObject:update",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::update(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void PlayerObjectModified::updateCollide(PlayerCollisionDirection direction, GameObject* object) {
    quartz::runHookChain<void>("PlayerObject:update_collide",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateCollide(std::forward<decltype(args)>(args)...); 
        }, direction, object);
}

void PlayerObjectModified::updateCollideLeft(float x, GameObject* object) {
    quartz::runHookChain<void>("PlayerObject:update_collide_left",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateCollideLeft(std::forward<decltype(args)>(args)...); 
        }, x, object);
}

void PlayerObjectModified::updateCollideRight(float x, GameObject* object) {
    quartz::runHookChain<void>("PlayerObject:update_collide_right",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateCollideRight(std::forward<decltype(args)>(args)...); 
        }, x, object);
}

void PlayerObjectModified::updateDashAnimation() {
    quartz::runHookChain<void>("PlayerObject:update_dash_animation",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateDashAnimation(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::updateDashArt() {
    quartz::runHookChain<void>("PlayerObject:update_dash_art",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateDashArt(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::updateGlowColor() {
    quartz::runHookChain<void>("PlayerObject:update_glow_color",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateGlowColor(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::updateInternalActions(float dt) {
    quartz::runHookChain<void>("PlayerObject:update_internal_actions",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateInternalActions(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void PlayerObjectModified::updateJump(float dt) {
    quartz::runHookChain<void>("PlayerObject:update_jump",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateJump(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void PlayerObjectModified::updateMove(float dt) {
    quartz::runHookChain<void>("PlayerObject:update_move",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateMove(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void PlayerObjectModified::updatePlayerArt() {
    quartz::runHookChain<void>("PlayerObject:update_player_art",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerArt(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::updatePlayerBirdFrame(int frame) {
    quartz::runHookChain<void>("PlayerObject:update_player_bird_frame",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerBirdFrame(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void PlayerObjectModified::updatePlayerDartFrame(int frame) {
    quartz::runHookChain<void>("PlayerObject:update_player_dart_frame",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerDartFrame(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void PlayerObjectModified::updatePlayerFrame(int frame) {
    quartz::runHookChain<void>("PlayerObject:update_player_frame",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerFrame(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void PlayerObjectModified::updatePlayerGlow() {
    quartz::runHookChain<void>("PlayerObject:update_player_glow",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerGlow(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::updatePlayerJetpackFrame(int frame) {
    quartz::runHookChain<void>("PlayerObject:update_player_jetpack_frame",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerJetpackFrame(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void PlayerObjectModified::updatePlayerRollFrame(int frame) {
    quartz::runHookChain<void>("PlayerObject:update_player_roll_frame",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerRollFrame(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void PlayerObjectModified::updatePlayerShipFrame(int frame) {
    quartz::runHookChain<void>("PlayerObject:update_player_ship_frame",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerShipFrame(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void PlayerObjectModified::updatePlayerSpriteExtra(gd::string frameName) {
    quartz::runHookChain<void>("PlayerObject:update_player_sprite_extra",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerSpriteExtra(std::forward<decltype(args)>(args)...); 
        }, frameName);
}

void PlayerObjectModified::updatePlayerSwingFrame(int frame) {
    quartz::runHookChain<void>("PlayerObject:update_player_swing_frame",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updatePlayerSwingFrame(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void PlayerObjectModified::updateRobotAnimationSpeed() {
    quartz::runHookChain<void>("PlayerObject:update_robot_animation_speed",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateRobotAnimationSpeed(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::updateRotation(float dt) {
    quartz::runHookChain<void>("PlayerObject:update_rotation",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateRotation(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void PlayerObjectModified::updateRotation(float dt, float rotation) {
    quartz::runHookChain<void>("PlayerObject:update_rotation@2",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateRotation(std::forward<decltype(args)>(args)...); 
        }, dt, rotation);
}

void PlayerObjectModified::updateShipRotation(float dt) {
    quartz::runHookChain<void>("PlayerObject:update_ship_rotation",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateShipRotation(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void PlayerObjectModified::updateShipSpriteExtra(gd::string frameName) {
    quartz::runHookChain<void>("PlayerObject:update_ship_sprite_extra",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateShipSpriteExtra(std::forward<decltype(args)>(args)...); 
        }, frameName);
}

void PlayerObjectModified::updateSlopeRotation(float dt) {
    quartz::runHookChain<void>("PlayerObject:update_slope_rotation",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateSlopeRotation(std::forward<decltype(args)>(args)...); 
        }, dt);
}

void PlayerObjectModified::updateStreakBlend(bool blend) {
    quartz::runHookChain<void>("PlayerObject:update_streak_blend",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateStreakBlend(std::forward<decltype(args)>(args)...); 
        }, blend);
}

void PlayerObjectModified::updateSwingFire() {
    quartz::runHookChain<void>("PlayerObject:update_swing_fire",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateSwingFire(std::forward<decltype(args)>(args)...); 
        });
}

void PlayerObjectModified::updateTimeMod(float speed, bool noEffects) {
    quartz::runHookChain<void>("PlayerObject:update_time_mod",
        static_cast<PlayerObject*>(this),
        [](PlayerObject* self, auto&&... args) -> decltype(auto) {
            return self->PlayerObject::updateTimeMod(std::forward<decltype(args)>(args)...); 
        }, speed, noEffects);
}

} // namespace quartz