#include <quartz/modified/GameObject.hpp>
#include <quartz/core/Templates.hpp>
#include <utility>

namespace quartz {

void GameObjectModified::activateObject() {
    quartz::runHookChain<void>("GameObject:activate_object",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::activateObject(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::addColorSprite(gd::string frame) {
    quartz::runHookChain<void>("GameObject:add_color_sprite",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addColorSprite(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void GameObjectModified::addColorSpriteToParent(bool reorder) {
    quartz::runHookChain<void>("GameObject:add_color_sprite_to_parent",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addColorSpriteToParent(std::forward<decltype(args)>(args)...); 
        }, reorder);
}

void GameObjectModified::addColorSpriteToSelf() {
    quartz::runHookChain<void>("GameObject:add_color_sprite_to_self",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addColorSpriteToSelf(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCSprite* GameObjectModified::addCustomChild(gd::string frame, cocos2d::CCPoint offset, int zOrder) {
    return quartz::runHookChain<cocos2d::CCSprite*>("GameObject:add_custom_child",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addCustomChild(std::forward<decltype(args)>(args)...); 
        }, frame, offset, zOrder);
}

cocos2d::CCSprite* GameObjectModified::addCustomColorChild(gd::string frame) {
    return quartz::runHookChain<cocos2d::CCSprite*>("GameObject:add_custom_color_child",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addCustomColorChild(std::forward<decltype(args)>(args)...); 
        }, frame);
}

void GameObjectModified::addEmptyGlow() {
    quartz::runHookChain<void>("GameObject:add_empty_glow",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addEmptyGlow(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::addGlow(gd::string frame) {
    quartz::runHookChain<void>("GameObject:add_glow",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addGlow(std::forward<decltype(args)>(args)...); 
        }, frame);
}

cocos2d::CCSprite* GameObjectModified::addInternalCustomColorChild(gd::string frame, cocos2d::CCPoint offset, int zOrder) {
    return quartz::runHookChain<cocos2d::CCSprite*>("GameObject:add_internal_custom_color_child",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addInternalCustomColorChild(std::forward<decltype(args)>(args)...); 
        }, frame, offset, zOrder);
}

cocos2d::CCSprite* GameObjectModified::addInternalGlowChild(gd::string frame, cocos2d::CCPoint offset) {
    return quartz::runHookChain<cocos2d::CCSprite*>("GameObject:add_internal_glow_child",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addInternalGlowChild(std::forward<decltype(args)>(args)...); 
        }, frame, offset);
}

void GameObjectModified::addMainSpriteToParent(bool reorder) {
    quartz::runHookChain<void>("GameObject:add_main_sprite_to_parent",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addMainSpriteToParent(std::forward<decltype(args)>(args)...); 
        }, reorder);
}

void GameObjectModified::addRotation(float rotation) {
    quartz::runHookChain<void>("GameObject:add_rotation",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addRotation(std::forward<decltype(args)>(args)...); 
        }, rotation);
}

void GameObjectModified::addToColorGroup(int group) {
    quartz::runHookChain<void>("GameObject:add_to_color_group",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addToColorGroup(std::forward<decltype(args)>(args)...); 
        }, group);
}

int GameObjectModified::addToGroup(int id) {
    return quartz::runHookChain<int>("GameObject:add_to_group",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::addToGroup(std::forward<decltype(args)>(args)...); 
        }, id);
}

void GameObjectModified::claimParticle() {
    quartz::runHookChain<void>("GameObject:claim_particle",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::claimParticle(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::ccColor3B const& GameObjectModified::colorForMode(int id, bool mainColor) {
    return quartz::runHookChain<cocos2d::ccColor3B const&>("GameObject:color_for_mode",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::colorForMode(std::forward<decltype(args)>(args)...); 
        }, id, mainColor);
}

void GameObjectModified::commonInteractiveSetup() {
    quartz::runHookChain<void>("GameObject:common_interactive_setup",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::commonInteractiveSetup(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::commonSetup() {
    quartz::runHookChain<void>("GameObject:common_setup",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::commonSetup(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::copyGroups(GameObject* object) {
    quartz::runHookChain<void>("GameObject:copy_groups",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::copyGroups(std::forward<decltype(args)>(args)...); 
        }, object);
}

cocos2d::CCParticleSystemQuad* GameObjectModified::createAndAddParticle(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType) {
    return quartz::runHookChain<cocos2d::CCParticleSystemQuad*>("GameObject:create_and_add_particle",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::createAndAddParticle(std::forward<decltype(args)>(args)...); 
        }, objectType, plistName, tag, positionType);
}

void GameObjectModified::createGlow(gd::string frame) {
    quartz::runHookChain<void>("GameObject:create_glow",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::createGlow(std::forward<decltype(args)>(args)...); 
        }, frame);
}

GameObject* GameObjectModified::createWithFrame(char const* name) {
    return quartz::runStaticHookChain<GameObject*>("GameObject.create_with_frame",
        &GameObject::createWithFrame,
        name);
}

GameObject* GameObjectModified::createWithKey(int key) {
    return quartz::runStaticHookChain<GameObject*>("GameObject.create_with_key",
        &GameObject::createWithKey,
        key);
}

void GameObjectModified::customSetup() {
    quartz::runHookChain<void>("GameObject:custom_setup",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::customSetup(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::deactivateObject(bool deactivate) {
    quartz::runHookChain<void>("GameObject:deactivate_object",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::deactivateObject(std::forward<decltype(args)>(args)...); 
        }, deactivate);
}

void GameObjectModified::determineSlopeDirection() {
    quartz::runHookChain<void>("GameObject:determine_slope_direction",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::determineSlopeDirection(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::duplicateAttributes(GameObject* object) {
    quartz::runHookChain<void>("GameObject:duplicate_attributes",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::duplicateAttributes(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GameObjectModified::duplicateColorMode(GameObject* object) {
    quartz::runHookChain<void>("GameObject:duplicate_color_mode",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::duplicateColorMode(std::forward<decltype(args)>(args)...); 
        }, object);
}

void GameObjectModified::duplicateValues(GameObject* object) {
    quartz::runHookChain<void>("GameObject:duplicate_values",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::duplicateValues(std::forward<decltype(args)>(args)...); 
        }, object);
}

cocos2d::ccColor3B GameObjectModified::editorColorForMode(int id) {
    return quartz::runHookChain<cocos2d::ccColor3B>("GameObject:editor_color_for_mode",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::editorColorForMode(std::forward<decltype(args)>(args)...); 
        }, id);
}

cocos2d::ccColor3B const& GameObjectModified::getActiveColorForMode(int id, bool mainColor) {
    return quartz::runHookChain<cocos2d::ccColor3B const&>("GameObject:get_active_color_for_mode",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getActiveColorForMode(std::forward<decltype(args)>(args)...); 
        }, id, mainColor);
}

cocos2d::CCPoint const& GameObjectModified::getBoxOffset() {
    return quartz::runHookChain<cocos2d::CCPoint const&>("GameObject:get_box_offset",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getBoxOffset(std::forward<decltype(args)>(args)...); 
        });
}

gd::string GameObjectModified::getColorFrame(gd::string frame) {
    return quartz::runHookChain<gd::string>("GameObject:get_color_frame",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getColorFrame(std::forward<decltype(args)>(args)...); 
        }, frame);
}

gd::string GameObjectModified::getColorKey(bool isMainColor, bool colorGroups) {
    return quartz::runHookChain<gd::string>("GameObject:get_color_key",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getColorKey(std::forward<decltype(args)>(args)...); 
        }, isMainColor, colorGroups);
}

gd::string GameObjectModified::getGlowFrame(gd::string frame) {
    return quartz::runHookChain<gd::string>("GameObject:get_glow_frame",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getGlowFrame(std::forward<decltype(args)>(args)...); 
        }, frame);
}

int GameObjectModified::getObjectDirection() {
    return quartz::runHookChain<int>("GameObject:get_object_direction",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getObjectDirection(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCRect const& GameObjectModified::getObjectRect() {
    return quartz::runHookChain<cocos2d::CCRect const&>("GameObject:get_object_rect",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getObjectRect(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCRect GameObjectModified::getObjectRect(float width, float height) {
    return quartz::runHookChain<cocos2d::CCRect>("GameObject:get_object_rect@2",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getObjectRect(std::forward<decltype(args)>(args)...); 
        }, width, height);
}

cocos2d::CCRect const& GameObjectModified::getObjectRect2(float width, float height) {
    return quartz::runHookChain<cocos2d::CCRect const&>("GameObject:get_object_rect2",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getObjectRect2(std::forward<decltype(args)>(args)...); 
        }, width, height);
}

bool GameObjectModified::getObjectRectDirty() const {
    return quartz::runHookChain<bool>("GameObject:get_object_rect_dirty",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getObjectRectDirty(std::forward<decltype(args)>(args)...); 
        });
}

float GameObjectModified::getObjectRotation() {
    return quartz::runHookChain<float>("GameObject:get_object_rotation",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getObjectRotation(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCRect const& GameObjectModified::getObjectTextureRect() {
    return quartz::runHookChain<cocos2d::CCRect const&>("GameObject:get_object_texture_rect",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getObjectTextureRect(std::forward<decltype(args)>(args)...); 
        });
}

OBB2D* GameObjectModified::getOrientedBox() {
    return quartz::runHookChain<OBB2D*>("GameObject:get_oriented_box",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getOrientedBox(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::getOrientedRectDirty() const {
    return quartz::runHookChain<bool>("GameObject:get_oriented_rect_dirty",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getOrientedRectDirty(std::forward<decltype(args)>(args)...); 
        });
}

int GameObjectModified::getParentMode() {
    return quartz::runHookChain<int>("GameObject:get_parent_mode",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getParentMode(std::forward<decltype(args)>(args)...); 
        });
}

float GameObjectModified::getRScaleX() {
    return quartz::runHookChain<float>("GameObject:get_rscale_x",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getRScaleX(std::forward<decltype(args)>(args)...); 
        });
}

float GameObjectModified::getRScaleY() {
    return quartz::runHookChain<float>("GameObject:get_rscale_y",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getRScaleY(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCPoint GameObjectModified::getRealPosition() {
    return quartz::runHookChain<cocos2d::CCPoint>("GameObject:get_real_position",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getRealPosition(std::forward<decltype(args)>(args)...); 
        });
}

GJSpriteColor* GameObjectModified::getRelativeSpriteColor(int type) {
    return quartz::runHookChain<GJSpriteColor*>("GameObject:get_relative_sprite_color",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getRelativeSpriteColor(std::forward<decltype(args)>(args)...); 
        }, type);
}

gd::string GameObjectModified::getSaveString(GJBaseGameLayer* layer) {
    return quartz::runHookChain<gd::string>("GameObject:get_save_string",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getSaveString(std::forward<decltype(args)>(args)...); 
        }, layer);
}

cocos2d::CCPoint GameObjectModified::getScalePosDelta() {
    return quartz::runHookChain<cocos2d::CCPoint>("GameObject:get_scale_pos_delta",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getScalePosDelta(std::forward<decltype(args)>(args)...); 
        });
}

cocos2d::CCPoint GameObjectModified::getStartPos() const {
    return quartz::runHookChain<cocos2d::CCPoint>("GameObject:get_start_pos",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getStartPos(std::forward<decltype(args)>(args)...); 
        });
}

GameObjectType GameObjectModified::getType() const {
    return quartz::runHookChain<GameObjectType>("GameObject:get_type",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::getType(std::forward<decltype(args)>(args)...); 
        });
}

float GameObjectModified::groupOpacityMod() {
    return quartz::runHookChain<float>("GameObject:group_opacity_mod",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::groupOpacityMod(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::ignoreEditorDuration() {
    return quartz::runHookChain<bool>("GameObject:ignore_editor_duration",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::ignoreEditorDuration(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::initWithTexture(cocos2d::CCTexture2D* texture) {
    return quartz::runHookChain<bool>("GameObject:init_with_texture",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::initWithTexture(std::forward<decltype(args)>(args)...); 
        }, texture);
}

bool GameObjectModified::isBasicTrigger() {
    return quartz::runHookChain<bool>("GameObject:is_basic_trigger",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::isBasicTrigger(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::isFacingDown() {
    return quartz::runHookChain<bool>("GameObject:is_facing_down",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::isFacingDown(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::isFacingLeft() {
    return quartz::runHookChain<bool>("GameObject:is_facing_left",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::isFacingLeft(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::isFlipX() {
    return quartz::runHookChain<bool>("GameObject:is_flip_x",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::isFlipX(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::isFlipY() {
    return quartz::runHookChain<bool>("GameObject:is_flip_y",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::isFlipY(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::isSpawnableTrigger() {
    return quartz::runHookChain<bool>("GameObject:is_spawnable_trigger",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::isSpawnableTrigger(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::isSpecialObject() {
    return quartz::runHookChain<bool>("GameObject:is_special_object",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::isSpecialObject(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::isTrigger() {
    return quartz::runHookChain<bool>("GameObject:is_trigger",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::isTrigger(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::loadGroupsFromString(gd::string groupList) {
    quartz::runHookChain<void>("GameObject:load_groups_from_string",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::loadGroupsFromString(std::forward<decltype(args)>(args)...); 
        }, groupList);
}

GameObject* GameObjectModified::objectFromVector(gd::vector<gd::string>& propValues, gd::vector<void *>& propIsPresent, GJBaseGameLayer* gameLayer, bool lowDetail) {
    return quartz::runStaticHookChain<GameObject*>("GameObject.object_from_vector",
        &GameObject::objectFromVector,
        propValues, propIsPresent, gameLayer, lowDetail);
}

cocos2d::CCNode* GameObjectModified::parentForZLayer(int zLayer, bool blending, int parentMode) {
    return quartz::runHookChain<cocos2d::CCNode*>("GameObject:parent_for_zlayer",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::parentForZLayer(std::forward<decltype(args)>(args)...); 
        }, zLayer, blending, parentMode);
}

gd::string GameObjectModified::perspectiveColorFrame(char const* prefix, int index) {
    return quartz::runHookChain<gd::string>("GameObject:perspective_color_frame",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::perspectiveColorFrame(std::forward<decltype(args)>(args)...); 
        }, prefix, index);
}

gd::string GameObjectModified::perspectiveFrame(char const* prefix, int index) {
    return quartz::runHookChain<gd::string>("GameObject:perspective_frame",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::perspectiveFrame(std::forward<decltype(args)>(args)...); 
        }, prefix, index);
}

void GameObjectModified::playDestroyObjectAnim(GJBaseGameLayer* layer) {
    quartz::runHookChain<void>("GameObject:play_destroy_object_anim",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::playDestroyObjectAnim(std::forward<decltype(args)>(args)...); 
        }, layer);
}

void GameObjectModified::playPickupAnimation(cocos2d::CCSprite* target, float xOffset, float yOffset, float controlYOffset1, float controlYOffset2, float endYOffset, float duration, float fadeDelay, float fadeDuration, bool rotate, float randomValue1, float randomValue2) {
    quartz::runHookChain<void>("GameObject:play_pickup_animation@2",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::playPickupAnimation(std::forward<decltype(args)>(args)...); 
        }, target, xOffset, yOffset, controlYOffset1, controlYOffset2, endYOffset, duration, fadeDelay, fadeDuration, rotate, randomValue1, randomValue2);
}

void GameObjectModified::playShineEffect() {
    quartz::runHookChain<void>("GameObject:play_shine_effect",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::playShineEffect(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::removeFromGroup(int id) {
    quartz::runHookChain<void>("GameObject:remove_from_group",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::removeFromGroup(std::forward<decltype(args)>(args)...); 
        }, id);
}

void GameObjectModified::resetObject() {
    quartz::runHookChain<void>("GameObject:reset_object",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::resetObject(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::restoreObject() {
    quartz::runHookChain<void>("GameObject:restore_object",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::restoreObject(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::saveActiveColors() {
    quartz::runHookChain<void>("GameObject:save_active_colors",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::saveActiveColors(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::selectObject(cocos2d::ccColor3B color) {
    quartz::runHookChain<void>("GameObject:select_object",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::selectObject(std::forward<decltype(args)>(args)...); 
        }, color);
}

void GameObjectModified::setAreaOpacity(float step, float value, int index) {
    quartz::runHookChain<void>("GameObject:set_area_opacity",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setAreaOpacity(std::forward<decltype(args)>(args)...); 
        }, step, value, index);
}

void GameObjectModified::setChildColor(cocos2d::ccColor3B const& color) {
    quartz::runHookChain<void>("GameObject:set_child_color",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setChildColor(std::forward<decltype(args)>(args)...); 
        }, color);
}

void GameObjectModified::setFlipX(bool flipX) {
    quartz::runHookChain<void>("GameObject:set_flip_x",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setFlipX(std::forward<decltype(args)>(args)...); 
        }, flipX);
}

void GameObjectModified::setFlipY(bool flipY) {
    quartz::runHookChain<void>("GameObject:set_flip_y",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setFlipY(std::forward<decltype(args)>(args)...); 
        }, flipY);
}

void GameObjectModified::setGlowColor(cocos2d::ccColor3B const& color) {
    quartz::runHookChain<void>("GameObject:set_glow_color",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setGlowColor(std::forward<decltype(args)>(args)...); 
        }, color);
}

void GameObjectModified::setObjectColor(cocos2d::ccColor3B const& color) {
    quartz::runHookChain<void>("GameObject:set_object_color",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setObjectColor(std::forward<decltype(args)>(args)...); 
        }, color);
}

void GameObjectModified::setObjectRectDirty(bool dirty) {
    quartz::runHookChain<void>("GameObject:set_object_rect_dirty",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setObjectRectDirty(std::forward<decltype(args)>(args)...); 
        }, dirty);
}

void GameObjectModified::setOpacity(unsigned char opacity) {
    quartz::runHookChain<void>("GameObject:set_opacity",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setOpacity(std::forward<decltype(args)>(args)...); 
        }, opacity);
}

void GameObjectModified::setOrientedRectDirty(bool dirty) {
    quartz::runHookChain<void>("GameObject:set_oriented_rect_dirty",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setOrientedRectDirty(std::forward<decltype(args)>(args)...); 
        }, dirty);
}

void GameObjectModified::setPosition(cocos2d::CCPoint const& position) {
    quartz::runHookChain<void>("GameObject:set_position",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setPosition(std::forward<decltype(args)>(args)...); 
        }, position);
}

void GameObjectModified::setRRotation(float rotation) {
    quartz::runHookChain<void>("GameObject:set_rrotation",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setRRotation(std::forward<decltype(args)>(args)...); 
        }, rotation);
}

void GameObjectModified::setRScale(float scale) {
    quartz::runHookChain<void>("GameObject:set_rscale",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setRScale(std::forward<decltype(args)>(args)...); 
        }, scale);
}

void GameObjectModified::setRScaleX(float scaleX) {
    quartz::runHookChain<void>("GameObject:set_rscale_x",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setRScaleX(std::forward<decltype(args)>(args)...); 
        }, scaleX);
}

void GameObjectModified::setRScaleY(float scaleY) {
    quartz::runHookChain<void>("GameObject:set_rscale_y",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setRScaleY(std::forward<decltype(args)>(args)...); 
        }, scaleY);
}

void GameObjectModified::setRotation(float rotation) {
    quartz::runHookChain<void>("GameObject:set_rotation",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setRotation(std::forward<decltype(args)>(args)...); 
        }, rotation);
}

void GameObjectModified::setRotationX(float rotationX) {
    quartz::runHookChain<void>("GameObject:set_rotation_x",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setRotationX(std::forward<decltype(args)>(args)...); 
        }, rotationX);
}

void GameObjectModified::setRotationY(float rotationY) {
    quartz::runHookChain<void>("GameObject:set_rotation_y",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setRotationY(std::forward<decltype(args)>(args)...); 
        }, rotationY);
}

void GameObjectModified::setScale(float scale) {
    quartz::runHookChain<void>("GameObject:set_scale",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setScale(std::forward<decltype(args)>(args)...); 
        }, scale);
}

void GameObjectModified::setScaleX(float scaleX) {
    quartz::runHookChain<void>("GameObject:set_scale_x",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setScaleX(std::forward<decltype(args)>(args)...); 
        }, scaleX);
}

void GameObjectModified::setScaleY(float scaleY) {
    quartz::runHookChain<void>("GameObject:set_scale_y",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setScaleY(std::forward<decltype(args)>(args)...); 
        }, scaleY);
}

void GameObjectModified::setStartPos(cocos2d::CCPoint position) {
    quartz::runHookChain<void>("GameObject:set_start_pos",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setStartPos(std::forward<decltype(args)>(args)...); 
        }, position);
}

void GameObjectModified::setType(GameObjectType type) {
    quartz::runHookChain<void>("GameObject:set_type",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setType(std::forward<decltype(args)>(args)...); 
        }, type);
}

void GameObjectModified::setVisible(bool visible) {
    quartz::runHookChain<void>("GameObject:set_visible",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setVisible(std::forward<decltype(args)>(args)...); 
        }, visible);
}

void GameObjectModified::setupCustomSprites(gd::string frameName) {
    quartz::runHookChain<void>("GameObject:setup_custom_sprites",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setupCustomSprites(std::forward<decltype(args)>(args)...); 
        }, frameName);
}

void GameObjectModified::setupPixelScale() {
    quartz::runHookChain<void>("GameObject:setup_pixel_scale",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setupPixelScale(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::setupSpriteSize() {
    quartz::runHookChain<void>("GameObject:setup_sprite_size",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::setupSpriteSize(std::forward<decltype(args)>(args)...); 
        });
}

bool GameObjectModified::shouldBlendColor(GJSpriteColor* color, bool mainColor) {
    return quartz::runHookChain<bool>("GameObject:should_blend_color",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::shouldBlendColor(std::forward<decltype(args)>(args)...); 
        }, color, mainColor);
}

bool GameObjectModified::shouldLockX() {
    return quartz::runHookChain<bool>("GameObject:should_lock_x",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::shouldLockX(std::forward<decltype(args)>(args)...); 
        });
}

double GameObjectModified::slopeYPos(float x) {
    return quartz::runHookChain<double>("GameObject:slope_ypos@3",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::slopeYPos(std::forward<decltype(args)>(args)...); 
        }, x);
}

void GameObjectModified::spawnDefaultPickupParticle(GJBaseGameLayer* layer) {
    quartz::runHookChain<void>("GameObject:spawn_default_pickup_particle",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::spawnDefaultPickupParticle(std::forward<decltype(args)>(args)...); 
        }, layer);
}

float GameObjectModified::spawnXPosition() {
    return quartz::runHookChain<float>("GameObject:spawn_xposition",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::spawnXPosition(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::transferObjectRect(cocos2d::CCRect& rect) {
    quartz::runHookChain<void>("GameObject:transfer_object_rect",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::transferObjectRect(std::forward<decltype(args)>(args)...); 
        }, rect);
}

void GameObjectModified::unclaimParticle() {
    quartz::runHookChain<void>("GameObject:unclaim_particle",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::unclaimParticle(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::updateCustomScaleX(float scaleX) {
    quartz::runHookChain<void>("GameObject:update_custom_scale_x",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateCustomScaleX(std::forward<decltype(args)>(args)...); 
        }, scaleX);
}

void GameObjectModified::updateCustomScaleY(float scaleY) {
    quartz::runHookChain<void>("GameObject:update_custom_scale_y",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateCustomScaleY(std::forward<decltype(args)>(args)...); 
        }, scaleY);
}

void GameObjectModified::updateIsOriented() {
    quartz::runHookChain<void>("GameObject:update_is_oriented",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateIsOriented(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::updateMainColor(cocos2d::ccColor3B const& color) {
    quartz::runHookChain<void>("GameObject:update_main_color",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateMainColor(std::forward<decltype(args)>(args)...); 
        }, color);
}

void GameObjectModified::updateObjectEditorColor() {
    quartz::runHookChain<void>("GameObject:update_object_editor_color",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateObjectEditorColor(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::updateOrientedBox() {
    quartz::runHookChain<void>("GameObject:update_oriented_box",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateOrientedBox(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::updateParticleColor(cocos2d::ccColor3B const& color) {
    quartz::runHookChain<void>("GameObject:update_particle_color",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateParticleColor(std::forward<decltype(args)>(args)...); 
        }, color);
}

void GameObjectModified::updateParticleOpacity(unsigned char opacity) {
    quartz::runHookChain<void>("GameObject:update_particle_opacity",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateParticleOpacity(std::forward<decltype(args)>(args)...); 
        }, opacity);
}

void GameObjectModified::updateSecondaryColor(cocos2d::ccColor3B const& color) {
    quartz::runHookChain<void>("GameObject:update_secondary_color",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateSecondaryColor(std::forward<decltype(args)>(args)...); 
        }, color);
}

void GameObjectModified::updateStartPos() {
    quartz::runHookChain<void>("GameObject:update_start_pos",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateStartPos(std::forward<decltype(args)>(args)...); 
        });
}

void GameObjectModified::updateStartValues() {
    quartz::runHookChain<void>("GameObject:update_start_values",
        static_cast<GameObject*>(this),
        [](GameObject* self, auto&&... args) -> decltype(auto) {
            return self->GameObject::updateStartValues(std::forward<decltype(args)>(args)...); 
        });
}

} // namespace quartz