#pragma once
#include <Geode/modify/GameObject.hpp>
#include <quartz/core/LuaFields.hpp>

namespace quartz {

struct GameObjectModified : geode::Modify<GameObjectModified, GameObject>, quartz::LuaFields {
    // @lua "GameObject:activate_object"
    void activateObject() override;

    // @lua "GameObject:add_color_sprite"
    void addColorSprite(gd::string frame);

    // @lua "GameObject:add_color_sprite_to_parent"
    void addColorSpriteToParent(bool reorder);

    // @lua "GameObject:add_color_sprite_to_self"
    void addColorSpriteToSelf();

    // @lua "GameObject:add_custom_child"
    cocos2d::CCSprite* addCustomChild(gd::string frame, cocos2d::CCPoint offset, int zOrder);

    // @lua "GameObject:add_custom_color_child"
    cocos2d::CCSprite* addCustomColorChild(gd::string frame);

    // @lua "GameObject:add_empty_glow"
    void addEmptyGlow();

    // @lua "GameObject:add_glow"
    void addGlow(gd::string frame);

    // @lua "GameObject:add_internal_custom_color_child"
    cocos2d::CCSprite* addInternalCustomColorChild(gd::string frame, cocos2d::CCPoint offset, int zOrder);

    // @lua "GameObject:add_internal_glow_child"
    cocos2d::CCSprite* addInternalGlowChild(gd::string frame, cocos2d::CCPoint offset);

    // @lua "GameObject:add_main_sprite_to_parent"
    void addMainSpriteToParent(bool reorder) override;

    // @lua "GameObject:add_rotation"
    void addRotation(float rotation);

    // @lua "GameObject:add_to_color_group"
    void addToColorGroup(int group);

    // @lua "GameObject:add_to_group"
    int addToGroup(int id) override;

    // @lua "GameObject:claim_particle"
    void claimParticle() override;

    // @lua "GameObject:color_for_mode"
    cocos2d::ccColor3B const& colorForMode(int id, bool mainColor);

    // @lua "GameObject:common_interactive_setup"
    void commonInteractiveSetup();

    // @lua "GameObject:common_setup"
    void commonSetup();

    // @lua "GameObject:copy_groups"
    void copyGroups(GameObject* object);

    // @lua "GameObject:create_and_add_particle"
    cocos2d::CCParticleSystemQuad* createAndAddParticle(int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType);

    // @lua "GameObject:create_glow"
    void createGlow(gd::string frame);

    // @lua "GameObject.create_with_frame"
    static GameObject* createWithFrame(char const* name);

    // @lua "GameObject.create_with_key"
    static GameObject* createWithKey(int key);

    // @lua "GameObject:custom_setup"
    void customSetup() override;

    // @lua "GameObject:deactivate_object"
    void deactivateObject(bool deactivate) override;

    // @lua "GameObject:determine_slope_direction"
    void determineSlopeDirection();

    // @lua "GameObject:duplicate_attributes"
    void duplicateAttributes(GameObject* object);

    // @lua "GameObject:duplicate_color_mode"
    void duplicateColorMode(GameObject* object);

    // @lua "GameObject:duplicate_values"
    void duplicateValues(GameObject* object);

    // @lua "GameObject:editor_color_for_mode"
    cocos2d::ccColor3B editorColorForMode(int id);

    // @lua "GameObject:get_active_color_for_mode"
    cocos2d::ccColor3B const& getActiveColorForMode(int id, bool mainColor);

    // @lua "GameObject:get_box_offset"
    cocos2d::CCPoint const& getBoxOffset();

    // @lua "GameObject:get_color_frame"
    gd::string getColorFrame(gd::string frame);

    // @lua "GameObject:get_color_key"
    gd::string getColorKey(bool isMainColor, bool colorGroups);

    // @lua "GameObject:get_glow_frame"
    gd::string getGlowFrame(gd::string frame);

    // @lua "GameObject:get_object_direction"
    int getObjectDirection();

    // @lua "GameObject:get_object_rect"
    cocos2d::CCRect const& getObjectRect() override;

    // @lua "GameObject:get_object_rect@2"
    cocos2d::CCRect getObjectRect(float width, float height) override;

    // @lua "GameObject:get_object_rect2"
    cocos2d::CCRect const& getObjectRect2(float width, float height) override;

    // @lua "GameObject:get_object_rect_dirty"
    bool getObjectRectDirty() const override;

    // @lua "GameObject:get_object_rotation"
    float getObjectRotation() override;

    // @lua "GameObject:get_object_texture_rect"
    cocos2d::CCRect const& getObjectTextureRect() override;

    // @lua "GameObject:get_oriented_box"
    OBB2D* getOrientedBox() override;

    // @lua "GameObject:get_oriented_rect_dirty"
    bool getOrientedRectDirty() const override;

    // @lua "GameObject:get_parent_mode"
    int getParentMode();

    // @lua "GameObject:get_rscale_x"
    float getRScaleX() override;

    // @lua "GameObject:get_rscale_y"
    float getRScaleY() override;

    // @lua "GameObject:get_real_position"
    cocos2d::CCPoint getRealPosition() override;

    // @lua "GameObject:get_relative_sprite_color"
    GJSpriteColor* getRelativeSpriteColor(int type);

    // @lua "GameObject:get_save_string"
    gd::string getSaveString(GJBaseGameLayer* layer) override;

    // @lua "GameObject:get_scale_pos_delta"
    cocos2d::CCPoint getScalePosDelta();

    // @lua "GameObject:get_start_pos"
    cocos2d::CCPoint getStartPos() const override;

    // @lua "GameObject:get_type"
    GameObjectType getType() const override;

    // @lua "GameObject:group_opacity_mod"
    float groupOpacityMod();

    // @lua "GameObject:ignore_editor_duration"
    bool ignoreEditorDuration();

    // @lua "GameObject:init_with_texture"
    bool initWithTexture(cocos2d::CCTexture2D* texture) override;

    // @lua "GameObject:is_basic_trigger"
    bool isBasicTrigger();

    // @lua "GameObject:is_facing_down"
    bool isFacingDown();

    // @lua "GameObject:is_facing_left"
    bool isFacingLeft();

    // @lua "GameObject:is_flip_x"
    bool isFlipX() override;

    // @lua "GameObject:is_flip_y"
    bool isFlipY() override;

    // @lua "GameObject:is_spawnable_trigger"
    bool isSpawnableTrigger();

    // @lua "GameObject:is_special_object"
    bool isSpecialObject();

    // @lua "GameObject:is_trigger"
    bool isTrigger();

    // @lua "GameObject:load_groups_from_string"
    void loadGroupsFromString(gd::string groupList);

    // @lua "GameObject.object_from_vector"
    static GameObject* objectFromVector(gd::vector<gd::string>& propValues, gd::vector<void *>& propIsPresent, GJBaseGameLayer* gameLayer, bool lowDetail);

    // @lua "GameObject:parent_for_zlayer"
    cocos2d::CCNode* parentForZLayer(int zLayer, bool blending, int parentMode);

    // @lua "GameObject:perspective_color_frame"
    gd::string perspectiveColorFrame(char const* prefix, int index);

    // @lua "GameObject:perspective_frame"
    gd::string perspectiveFrame(char const* prefix, int index);

    // @lua "GameObject:play_destroy_object_anim"
    void playDestroyObjectAnim(GJBaseGameLayer* layer);

    // @lua "GameObject:play_pickup_animation@2"
    void playPickupAnimation(cocos2d::CCSprite* target, float xOffset, float yOffset, float controlYOffset1, float controlYOffset2, float endYOffset, float duration, float fadeDelay, float fadeDuration, bool rotate, float randomValue1, float randomValue2);

    // @lua "GameObject:play_shine_effect"
    void playShineEffect();

    // @lua "GameObject:remove_from_group"
    void removeFromGroup(int id) override;

    // @lua "GameObject:reset_object"
    void resetObject() override;

    // @lua "GameObject:restore_object"
    void restoreObject() override;

    // @lua "GameObject:save_active_colors"
    void saveActiveColors() override;

    // @lua "GameObject:select_object"
    void selectObject(cocos2d::ccColor3B color) override;

    // @lua "GameObject:set_area_opacity"
    void setAreaOpacity(float step, float value, int index);

    // @lua "GameObject:set_child_color"
    void setChildColor(cocos2d::ccColor3B const& color) override;

    // @lua "GameObject:set_flip_x"
    void setFlipX(bool flipX) override;

    // @lua "GameObject:set_flip_y"
    void setFlipY(bool flipY) override;

    // @lua "GameObject:set_glow_color"
    void setGlowColor(cocos2d::ccColor3B const& color) override;

    // @lua "GameObject:set_object_color"
    void setObjectColor(cocos2d::ccColor3B const& color) override;

    // @lua "GameObject:set_object_rect_dirty"
    void setObjectRectDirty(bool dirty) override;

    // @lua "GameObject:set_opacity"
    void setOpacity(unsigned char opacity) override;

    // @lua "GameObject:set_oriented_rect_dirty"
    void setOrientedRectDirty(bool dirty) override;

    // @lua "GameObject:set_position"
    void setPosition(cocos2d::CCPoint const& position) override;

    // @lua "GameObject:set_rrotation"
    void setRRotation(float rotation) override;

    // @lua "GameObject:set_rscale"
    void setRScale(float scale) override;

    // @lua "GameObject:set_rscale_x"
    void setRScaleX(float scaleX) override;

    // @lua "GameObject:set_rscale_y"
    void setRScaleY(float scaleY) override;

    // @lua "GameObject:set_rotation"
    void setRotation(float rotation) override;

    // @lua "GameObject:set_rotation_x"
    void setRotationX(float rotationX) override;

    // @lua "GameObject:set_rotation_y"
    void setRotationY(float rotationY) override;

    // @lua "GameObject:set_scale"
    void setScale(float scale) override;

    // @lua "GameObject:set_scale_x"
    void setScaleX(float scaleX) override;

    // @lua "GameObject:set_scale_y"
    void setScaleY(float scaleY) override;

    // @lua "GameObject:set_start_pos"
    void setStartPos(cocos2d::CCPoint position) override;

    // @lua "GameObject:set_type"
    void setType(GameObjectType type) override;

    // @lua "GameObject:set_visible"
    void setVisible(bool visible) override;

    // @lua "GameObject:setup_custom_sprites"
    void setupCustomSprites(gd::string frameName) override;

    // @lua "GameObject:setup_pixel_scale"
    void setupPixelScale();

    // @lua "GameObject:setup_sprite_size"
    void setupSpriteSize();

    // @lua "GameObject:should_blend_color"
    bool shouldBlendColor(GJSpriteColor* color, bool mainColor);

    // @lua "GameObject:should_lock_x"
    bool shouldLockX();

    // @lua "GameObject:slope_ypos@3"
    double slopeYPos(float x);

    // @lua "GameObject:spawn_default_pickup_particle"
    void spawnDefaultPickupParticle(GJBaseGameLayer* layer);

    // @lua "GameObject:spawn_xposition"
    float spawnXPosition() override;

    // @lua "GameObject:transfer_object_rect"
    void transferObjectRect(cocos2d::CCRect& rect) override;

    // @lua "GameObject:unclaim_particle"
    void unclaimParticle() override;

    // @lua "GameObject:update_custom_scale_x"
    void updateCustomScaleX(float scaleX);

    // @lua "GameObject:update_custom_scale_y"
    void updateCustomScaleY(float scaleY);

    // @lua "GameObject:update_is_oriented"
    void updateIsOriented();

    // @lua "GameObject:update_main_color"
    void updateMainColor(cocos2d::ccColor3B const& color) override;

    // @lua "GameObject:update_object_editor_color"
    void updateObjectEditorColor();

    // @lua "GameObject:update_oriented_box"
    void updateOrientedBox() override;

    // @lua "GameObject:update_particle_color"
    void updateParticleColor(cocos2d::ccColor3B const& color) override;

    // @lua "GameObject:update_particle_opacity"
    void updateParticleOpacity(unsigned char opacity) override;

    // @lua "GameObject:update_secondary_color"
    void updateSecondaryColor(cocos2d::ccColor3B const& color) override;

    // @lua "GameObject:update_start_pos"
    void updateStartPos();

    // @lua "GameObject:update_start_values"
    void updateStartValues() override;
};

} // namespace quartz