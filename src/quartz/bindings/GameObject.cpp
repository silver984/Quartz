#include <quartz/bindings/GameObject.hpp>
#include <quartz/modified/GameObject.hpp>
#include <quartz/core/LuaManager.hpp>
#include <new>

namespace quartz {

GameObjectBindings::GameObjectBindings() {
    auto& luaManager = LuaManager::get();
    luaManager.queueBinding(
        [&luaManager]() {
            auto& state = luaManager.luaState();
            state.new_usertype<GameObject>("GameObject",
                sol::constructors<GameObject()>(),
                sol::base_classes, sol::bases<CCSpritePlus>(),
                "activate_trigger_in_editor", &GameObject::m_activateTriggerInEditor,
                "active_detail_color_id", &GameObject::m_activeDetailColorID,
                "active_main_color_id", &GameObject::m_activeMainColorID,
                "add_to_node_container", &GameObject::m_addToNodeContainer,
                "area_opacity_index", &GameObject::m_areaOpacityIndex,
                "area_opacity_related", &GameObject::m_areaOpacityRelated,
                "area_opacity_value", &GameObject::m_areaOpacityValue,
                "base_color", &GameObject::m_baseColor,
                "base_or_detail_blending", &GameObject::m_baseOrDetailBlending,
                "base_uses_hsv", &GameObject::m_baseUsesHSV,
                "black_child_opacity", &GameObject::m_blackChildOpacity,
                "black_child_opacity_locked", &GameObject::m_blackChildOpacityLocked,
                "box_offset", &GameObject::m_boxOffset,
                "box_offset_calculated", &GameObject::m_boxOffsetCalculated,
                "can_be_controlled", &GameObject::m_canBeControlled,
                "can_rotate_free", &GameObject::m_canRotateFree,
                "cant_color_glow", &GameObject::m_cantColorGlow,
                "child_color_type", &GameObject::m_childColorType,
                "class_type", &GameObject::m_classType,
                "color_group_count", &GameObject::m_colorGroupCount,
                "color_groups", &GameObject::m_colorGroups,
                "color_sprite", &GameObject::m_colorSprite,
                "color_sprite_locked", &GameObject::m_colorSpriteLocked,
                "color_type", &GameObject::m_colorType,
                "color_zlayer_related", &GameObject::m_colorZLayerRelated,
                "custom_audio_scale", &GameObject::m_customAudioScale,
                "custom_box_offset", &GameObject::m_customBoxOffset,
                "custom_color_type", &GameObject::m_customColorType,
                "custom_glow_color", &GameObject::m_customGlowColor,
                "custom_scale_x", &GameObject::m_customScaleX,
                "custom_scale_y", &GameObject::m_customScaleY,
                "custom_sprite_color", &GameObject::m_customSpriteColor,
                "default_zlayer", &GameObject::m_defaultZLayer,
                "default_zorder", &GameObject::m_defaultZOrder,
                "detail_action_sprite", &GameObject::m_detailActionSprite,
                "detail_color", &GameObject::m_detailColor,
                "detail_color_key_index", &GameObject::m_detailColorKeyIndex,
                "detail_uses_hsv", &GameObject::m_detailUsesHSV,
                "dont_ignore_duration", &GameObject::m_dontIgnoreDuration,
                "editor_enabled", &GameObject::m_editorEnabled,
                "editor_layer", &GameObject::m_editorLayer,
                "editor_layer2", &GameObject::m_editorLayer2,
                "enabled_groups_counter", &GameObject::m_enabledGroupsCounter,
                "enter_channel", &GameObject::m_enterChannel,
                "enter_type", &GameObject::m_enterType,
                "exit_type", &GameObject::m_exitType,
                "fade_margin", &GameObject::m_fadeMargin,
                "glow_color_is_lbg", &GameObject::m_glowColorIsLBG,
                "glow_sprite", &GameObject::m_glowSprite,
                "go_effect_manager", &GameObject::m_goEffectManager,
                "green_debug_draw", &GameObject::m_greenDebugDraw,
                "group_color", &GameObject::m_groupColor,
                "group_count", &GameObject::m_groupCount,
                "groups", &GameObject::m_groups,
                "has_area_parent", &GameObject::m_hasAreaParent,
                "has_color_sprite", &GameObject::m_hasColorSprite,
                "has_content_size", &GameObject::m_hasContentSize,
                "has_custom_child", &GameObject::m_hasCustomChild,
                "has_extended_collision", &GameObject::m_hasExtendedCollision,
                "has_group_parent", &GameObject::m_hasGroupParent,
                "has_group_parents_string", &GameObject::m_hasGroupParentsString,
                "has_no_audio_scale", &GameObject::m_hasNoAudioScale,
                "has_no_effects", &GameObject::m_hasNoEffects,
                "has_no_glow", &GameObject::m_hasNoGlow,
                "has_no_particles", &GameObject::m_hasNoParticles,
                "has_particles", &GameObject::m_hasParticles,
                "height", &GameObject::m_height,
                "ignore_enter", &GameObject::m_ignoreEnter,
                "ignore_fade", &GameObject::m_ignoreFade,
                "inner_section_index", &GameObject::m_innerSectionIndex,
                "intrinsic_dont_fade", &GameObject::m_intrinsicDontFade,
                "is_activated", &GameObject::m_isActivated,
                "is_color_sprite_black", &GameObject::m_isColorSpriteBlack,
                "is_color_trigger", &GameObject::m_isColorTrigger,
                "is_decoration", &GameObject::m_isDecoration,
                "is_decoration2", &GameObject::m_isDecoration2,
                "is_dirty", &GameObject::m_isDirty,
                "is_disabled", &GameObject::m_isDisabled,
                "is_disabled2", &GameObject::m_isDisabled2,
                "is_dont_boost_x", &GameObject::m_isDontBoostX,
                "is_dont_boost_y", &GameObject::m_isDontBoostY,
                "is_dont_enter", &GameObject::m_isDontEnter,
                "is_dont_fade", &GameObject::m_isDontFade,
                "is_extra_sticky", &GameObject::m_isExtraSticky,
                "is_flip_x", &GameObject::m_isFlipX,
                "is_flip_y", &GameObject::m_isFlipY,
                "is_grip_slope", &GameObject::m_isGripSlope,
                "is_group_disabled", &GameObject::m_isGroupDisabled,
                "is_group_disabled_temp", &GameObject::m_isGroupDisabledTemp,
                "is_hide", &GameObject::m_isHide,
                "is_high_detail", &GameObject::m_isHighDetail,
                "is_ice_block", &GameObject::m_isIceBlock,
                "is_invisible", &GameObject::m_isInvisible,
                "is_invisible_block", &GameObject::m_isInvisibleBlock,
                "is_mirrored_by_scale", &GameObject::m_isMirroredByScale,
                "is_no_touch", &GameObject::m_isNoTouch,
                "is_non_stick_x", &GameObject::m_isNonStickX,
                "is_non_stick_y", &GameObject::m_isNonStickY,
                "is_object_black", &GameObject::m_isObjectBlack,
                "is_object_pos_dirty", &GameObject::m_isObjectPosDirty,
                "is_object_rect_dirty", &GameObject::m_isObjectRectDirty,
                "is_oriented_box_dirty", &GameObject::m_isOrientedBoxDirty,
                "is_particle_sprite_locked", &GameObject::m_isParticleSpriteLocked,
                "is_passable", &GameObject::m_isPassable,
                "is_ring_powered_on", &GameObject::m_isRingPoweredOn,
                "is_rotation_aligned", &GameObject::m_isRotationAligned,
                "is_scale_stick", &GameObject::m_isScaleStick,
                "is_selected", &GameObject::m_isSelected,
                "is_solid_color_block", &GameObject::m_isSolidColorBlock,
                "is_spawn_order_trigger", &GameObject::m_isSpawnOrderTrigger,
                "is_start_pos", &GameObject::m_isStartPos,
                "is_trigger", &GameObject::m_isTrigger,
                "is_uiobject", &GameObject::m_isUIObject,
                "is_unmodified_pos_dirty", &GameObject::m_isUnmodifiedPosDirty,
                "last_position", &GameObject::m_lastPosition,
                "last_size", &GameObject::m_lastSize,
                "linked_group", &GameObject::m_linkedGroup,
                "main_action_sprite", &GameObject::m_mainActionSprite,
                "main_color_key_index", &GameObject::m_mainColorKeyIndex,
                "max_audio_scale", &GameObject::m_maxAudioScale,
                "maybe_not_colorable", &GameObject::m_maybeNotColorable,
                "middle_section_index", &GameObject::m_middleSectionIndex,
                "min_audio_scale", &GameObject::m_minAudioScale,
                "object_id", &GameObject::m_objectID,
                "object_material", &GameObject::m_objectMaterial,
                "object_radius", &GameObject::m_objectRadius,
                "object_rect", &GameObject::m_objectRect,
                "object_type", &GameObject::m_objectType,
                "opacity_group_count", &GameObject::m_opacityGroupCount,
                "opacity_groups", &GameObject::m_opacityGroups,
                "opacity_mod", &GameObject::m_opacityMod,
                "opacity_mod2", &GameObject::m_opacityMod2,
                "oriented_box", &GameObject::m_orientedBox,
                "outer_section_index", &GameObject::m_outerSectionIndex,
                "parent_mode", &GameObject::m_parentMode,
                "particle", &GameObject::m_particle,
                "particle_locked", &GameObject::m_particleLocked,
                "particle_offset", &GameObject::m_particleOffset,
                "particle_string", &GameObject::m_particleString,
                "particle_use_object_color", &GameObject::m_particleUseObjectColor,
                "pixel_scale_x", &GameObject::m_pixelScaleX,
                "pixel_scale_y", &GameObject::m_pixelScaleY,
                "position_x", &GameObject::m_positionX,
                "position_xoffset", &GameObject::m_positionXOffset,
                "position_y", &GameObject::m_positionY,
                "position_yoffset", &GameObject::m_positionYOffset,
                "property53", &GameObject::m_property53,
                "rotation_xoffset", &GameObject::m_rotationXOffset,
                "rotation_yoffset", &GameObject::m_rotationYOffset,
                "saved_object_type", &GameObject::m_savedObjectType,
                "scale_x", &GameObject::m_scaleX,
                "scale_xoffset", &GameObject::m_scaleXOffset,
                "scale_y", &GameObject::m_scaleY,
                "scale_yoffset", &GameObject::m_scaleYOffset,
                "should_blend_base", &GameObject::m_shouldBlendBase,
                "should_blend_detail", &GameObject::m_shouldBlendDetail,
                "should_use_outer_ob", &GameObject::m_shouldUseOuterOb,
                "slope_direction", &GameObject::m_slopeDirection,
                "slope_is_hazard", &GameObject::m_slopeIsHazard,
                "slope_uphill", &GameObject::m_slopeUphill,
                "some_other_index", &GameObject::m_someOtherIndex,
                "sprite_height_scale", &GameObject::m_spriteHeightScale,
                "sprite_width_scale", &GameObject::m_spriteWidthScale,
                "start_flip_x", &GameObject::m_startFlipX,
                "start_flip_y", &GameObject::m_startFlipY,
                "start_position", &GameObject::m_startPosition,
                "start_rotation_x", &GameObject::m_startRotationX,
                "start_rotation_y", &GameObject::m_startRotationY,
                "start_scale_x", &GameObject::m_startScaleX,
                "start_scale_y", &GameObject::m_startScaleY,
                "target_color", &GameObject::m_targetColor,
                "temp_offset_xrelated", &GameObject::m_tempOffsetXRelated,
                "texture_rect", &GameObject::m_textureRect,
                "unique_id", &GameObject::m_uniqueID,
                "unk28c", &GameObject::m_unk28c,
                "unk2_a8", &GameObject::m_unk2A8,
                "unk2_b0", &GameObject::m_unk2B0,
                "unk2_bc", &GameObject::m_unk2BC,
                "unk2_c0", &GameObject::m_unk2C0,
                "unk353", &GameObject::m_unk353,
                "unk35_c", &GameObject::m_unk35C,
                "unk367", &GameObject::m_unk367,
                "unk370", &GameObject::m_unk370,
                "unk390", &GameObject::m_unk390,
                "unk3_d8", &GameObject::m_unk3D8,
                "unk3_de", &GameObject::m_unk3DE,
                "unk3_e8", &GameObject::m_unk3E8,
                "unk3_f8", &GameObject::m_unk3F8,
                "unk3_fd", &GameObject::m_unk3FD,
                "unk3ee", &GameObject::m_unk3ee,
                "unk40_c", &GameObject::m_unk40C,
                "unk460", &GameObject::m_unk460,
                "unk464", &GameObject::m_unk464,
                "unk4_c0", &GameObject::m_unk4C0,
                "unk4_c4", &GameObject::m_unk4C4,
                "unk4_c8", &GameObject::m_unk4C8,
                "unk4_cc", &GameObject::m_unk4CC,
                "unk4_f8", &GameObject::m_unk4F8,
                "unk4fb", &GameObject::m_unk4fb,
                "unk507", &GameObject::m_unk507,
                "unk508", &GameObject::m_unk508,
                "unk50_c", &GameObject::m_unk50C,
                "unk52_c", &GameObject::m_unk52C,
                "unk530", &GameObject::m_unk530,
                "unmodified_position_x", &GameObject::m_unmodifiedPositionX,
                "unmodified_position_y", &GameObject::m_unmodifiedPositionY,
                "update_custom_content_size", &GameObject::m_updateCustomContentSize,
                "update_editor_color", &GameObject::m_updateEditorColor,
                "update_parents", &GameObject::m_updateParents,
                "uses_audio_scale", &GameObject::m_usesAudioScale,
                "variance_index", &GameObject::m_varianceIndex,
                "was_selected", &GameObject::m_wasSelected,
                "width", &GameObject::m_width,
                "z_fixed_zlayer", &GameObject::m_zFixedZLayer,
                "z_layer", &GameObject::m_zLayer,
                "z_order", &GameObject::m_zOrder);

            sol::table usertype = state["GameObject"];

            // expose the custom fields to lua
            usertype.set_function("fields",
                [](sol::this_state s, GameObject* self) -> sol::table {
                    sol::state_view lua(s);

                    if (!self) {
                        return lua.create_table();
                    }

                    // this cast is required to access lua field storage
                    auto modifiedSelf = static_cast<GameObjectModified*>(self);
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
                []() -> GameObject* {
                    GameObject* ptr = new(std::nothrow) GameObject();
                    return ptr;
                });

            // manual deallocation for `alloc()`
            usertype.set_function("free",
                [](GameObject* self) {
                    delete self;
                });

            luaManager.addValidHook("GameObject:activate_object");
            usertype.set_function("activate_object",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->activateObject();
                });

            usertype.set_function("activated_by_player",
                [](GameObject* self, PlayerObject* player) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->activatedByPlayer(player);
                });

            luaManager.addValidHook("GameObject:add_color_sprite");
            usertype.set_function("add_color_sprite",
                [](GameObject* self, gd::string frame) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->addColorSprite(frame);
                });

            luaManager.addValidHook("GameObject:add_color_sprite_to_parent");
            usertype.set_function("add_color_sprite_to_parent",
                [](GameObject* self, bool reorder) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->addColorSpriteToParent(reorder);
                });

            luaManager.addValidHook("GameObject:add_color_sprite_to_self");
            usertype.set_function("add_color_sprite_to_self",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->addColorSpriteToSelf();
                });

            usertype.set_function("add_custom_black_child",
                [](GameObject* self, gd::string frame, float opacity, bool color) -> cocos2d::CCSprite* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->addCustomBlackChild(frame, opacity, color);
                });

            luaManager.addValidHook("GameObject:add_custom_child");
            usertype.set_function("add_custom_child",
                [](GameObject* self, gd::string frame, cocos2d::CCPoint offset, int zOrder) -> cocos2d::CCSprite* {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->addCustomChild(frame, offset, zOrder);
                });

            luaManager.addValidHook("GameObject:add_custom_color_child");
            usertype.set_function("add_custom_color_child",
                [](GameObject* self, gd::string frame) -> cocos2d::CCSprite* {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->addCustomColorChild(frame);
                });

            luaManager.addValidHook("GameObject:add_empty_glow");
            usertype.set_function("add_empty_glow",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->addEmptyGlow();
                });

            luaManager.addValidHook("GameObject:add_glow");
            usertype.set_function("add_glow",
                [](GameObject* self, gd::string frame) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->addGlow(frame);
                });

            usertype.set_function("add_internal_child",
                [](GameObject* self, cocos2d::CCSprite* parent, gd::string frame, cocos2d::CCPoint offset, int zOrder) -> cocos2d::CCSprite* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->addInternalChild(parent, frame, offset, zOrder);
                });

            luaManager.addValidHook("GameObject:add_internal_custom_color_child");
            usertype.set_function("add_internal_custom_color_child",
                [](GameObject* self, gd::string frame, cocos2d::CCPoint offset, int zOrder) -> cocos2d::CCSprite* {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->addInternalCustomColorChild(frame, offset, zOrder);
                });

            luaManager.addValidHook("GameObject:add_internal_glow_child");
            usertype.set_function("add_internal_glow_child",
                [](GameObject* self, gd::string frame, cocos2d::CCPoint offset) -> cocos2d::CCSprite* {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->addInternalGlowChild(frame, offset);
                });

            luaManager.addValidHook("GameObject:add_main_sprite_to_parent");
            usertype.set_function("add_main_sprite_to_parent",
                [](GameObject* self, bool reorder) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->addMainSpriteToParent(reorder);
                });

            usertype.set_function("add_new_slope01",
                [](GameObject* self, bool dontDraw) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addNewSlope01(dontDraw);
                });

            usertype.set_function("add_new_slope01_glow",
                [](GameObject* self, bool dontDraw) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addNewSlope01Glow(dontDraw);
                });

            usertype.set_function("add_new_slope02",
                [](GameObject* self, bool dontDraw) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addNewSlope02(dontDraw);
                });

            usertype.set_function("add_new_slope02_glow",
                [](GameObject* self, bool dontDraw) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addNewSlope02Glow(dontDraw);
                });

            luaManager.addValidHook("GameObject:add_rotation");
            usertype.set_function("add_rotation",
                sol::overload(
                    [](GameObject* self, float rotation) {
                        auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                        modifiedSelf->addRotation(rotation);
                    },
                    [](GameObject* self, float rotationX, float rotationY) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->addRotation(rotationX, rotationY);
                    }));

            luaManager.addValidHook("GameObject:add_to_color_group");
            usertype.set_function("add_to_color_group",
                [](GameObject* self, int group) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->addToColorGroup(group);
                });

            usertype.set_function("add_to_custom_scale_x",
                [](GameObject* self, float scale) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToCustomScaleX(scale);
                });

            usertype.set_function("add_to_custom_scale_y",
                [](GameObject* self, float scale) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToCustomScaleY(scale);
                });

            luaManager.addValidHook("GameObject:add_to_group");
            usertype.set_function("add_to_group",
                [](GameObject* self, int id) -> int {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->addToGroup(id);
                });

            usertype.set_function("add_to_opacity_group",
                [](GameObject* self, int group) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToOpacityGroup(group);
                });

            usertype.set_function("add_to_temp_offset",
                [](GameObject* self, double offsetX, double offsetY) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->addToTempOffset(offsetX, offsetY);
                });

            usertype.set_function("animation_triggered",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->animationTriggered();
                });

            usertype.set_function("assign_unique_id",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->assignUniqueID();
                });

            usertype.set_function("belongs_to_group",
                [](GameObject* self, int group) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->belongsToGroup(group);
                });

            usertype.set_function("blend_mode_changed",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->blendModeChanged();
                });

            usertype.set_function("calculate_oriented_box",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->calculateOrientedBox();
                });

            usertype.set_function("can_allow_multi_activate",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canAllowMultiActivate();
                });

            usertype.set_function("can_be_ordered",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canBeOrdered();
                });

            usertype.set_function("can_change_custom_color",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canChangeCustomColor();
                });

            usertype.set_function("can_change_main_color",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canChangeMainColor();
                });

            usertype.set_function("can_change_secondary_color",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canChangeSecondaryColor();
                });

            usertype.set_function("can_multi_activate",
                [](GameObject* self, bool multiActivate) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canMultiActivate(multiActivate);
                });

            usertype.set_function("can_reverse",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canReverse();
                });

            usertype.set_function("can_rotate_free",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->canRotateFree();
                });

            luaManager.addValidHook("GameObject:claim_particle");
            usertype.set_function("claim_particle",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->claimParticle();
                });

            luaManager.addValidHook("GameObject:color_for_mode");
            usertype.set_function("color_for_mode",
                [](GameObject* self, int id, bool mainColor) -> cocos2d::ccColor3B const& {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->colorForMode(id, mainColor);
                });

            luaManager.addValidHook("GameObject:common_interactive_setup");
            usertype.set_function("common_interactive_setup",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->commonInteractiveSetup();
                });

            luaManager.addValidHook("GameObject:common_setup");
            usertype.set_function("common_setup",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->commonSetup();
                });

            luaManager.addValidHook("GameObject:copy_groups");
            usertype.set_function("copy_groups",
                [](GameObject* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->copyGroups(object);
                });

            luaManager.addValidHook("GameObject:create_and_add_particle");
            usertype.set_function("create_and_add_particle",
                [](GameObject* self, int objectType, char const* plistName, int tag, cocos2d::tCCPositionType positionType) -> cocos2d::CCParticleSystemQuad* {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->createAndAddParticle(objectType, plistName, tag, positionType);
                });

            usertype.set_function("create_color_group_container",
                [](GameObject* self, int size) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->createColorGroupContainer(size);
                });

            luaManager.addValidHook("GameObject:create_glow");
            usertype.set_function("create_glow",
                [](GameObject* self, gd::string frame) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->createGlow(frame);
                });

            usertype.set_function("create_group_container",
                [](GameObject* self, int size) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->createGroupContainer(size);
                });

            usertype.set_function("create_opacity_group_container",
                [](GameObject* self, int size) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->createOpacityGroupContainer(size);
                });

            usertype.set_function("create_sprite_color",
                [](GameObject* self, int type) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->createSpriteColor(type);
                });

            luaManager.addValidHook("GameObject.create_with_frame");
            usertype.set_function("create_with_frame",
                [](char const* name) -> GameObject* {
                    return quartz::GameObjectModified::createWithFrame(name);
                });

            luaManager.addValidHook("GameObject.create_with_key");
            usertype.set_function("create_with_key",
                [](int key) -> GameObject* {
                    return quartz::GameObjectModified::createWithKey(key);
                });

            usertype.set_function("custom_object_setup",
                [](GameObject* self, gd::vector<gd::string>& values, gd::vector<void *>& exists) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->customObjectSetup(values, exists);
                });

            luaManager.addValidHook("GameObject:custom_setup");
            usertype.set_function("custom_setup",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->customSetup();
                });

            luaManager.addValidHook("GameObject:deactivate_object");
            usertype.set_function("deactivate_object",
                [](GameObject* self, bool deactivate) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->deactivateObject(deactivate);
                });

            usertype.set_function("deselect_object",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->deselectObject();
                });

            usertype.set_function("destroy_object",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->destroyObject();
                });

            luaManager.addValidHook("GameObject:determine_slope_direction");
            usertype.set_function("determine_slope_direction",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->determineSlopeDirection();
                });

            usertype.set_function("did_scale_xchange",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->didScaleXChange();
                });

            usertype.set_function("did_scale_ychange",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->didScaleYChange();
                });

            usertype.set_function("dirtify_object_pos",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->dirtifyObjectPos();
                });

            usertype.set_function("dirtify_object_rect",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->dirtifyObjectRect();
                });

            usertype.set_function("disable_object",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->disableObject();
                });

            usertype.set_function("dont_count_towards_limit",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->dontCountTowardsLimit();
                });

            luaManager.addValidHook("GameObject:duplicate_attributes");
            usertype.set_function("duplicate_attributes",
                [](GameObject* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->duplicateAttributes(object);
                });

            luaManager.addValidHook("GameObject:duplicate_color_mode");
            usertype.set_function("duplicate_color_mode",
                [](GameObject* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->duplicateColorMode(object);
                });

            luaManager.addValidHook("GameObject:duplicate_values");
            usertype.set_function("duplicate_values",
                [](GameObject* self, GameObject* object) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->duplicateValues(object);
                });

            usertype.set_function("editor_color_for_custom_mode",
                [](GameObject* self, int id) -> cocos2d::ccColor3B {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->editorColorForCustomMode(id);
                });

            luaManager.addValidHook("GameObject:editor_color_for_mode");
            usertype.set_function("editor_color_for_mode",
                [](GameObject* self, int id) -> cocos2d::ccColor3B {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->editorColorForMode(id);
                });

            usertype.set_function("fast_rotate_object",
                [](GameObject* self, float rotation) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->fastRotateObject(rotation);
                });

            usertype.set_function("first_setup",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->firstSetup();
                });

            luaManager.addValidHook("GameObject:get_active_color_for_mode");
            usertype.set_function("get_active_color_for_mode",
                [](GameObject* self, int id, bool mainColor) -> cocos2d::ccColor3B const& {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getActiveColorForMode(id, mainColor);
                });

            usertype.set_function("get_ball_frame",
                [](GameObject* self, int index) -> char const* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getBallFrame(index);
                });

            usertype.set_function("get_bounding_rect",
                [](GameObject* self) -> cocos2d::CCRect {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getBoundingRect();
                });

            luaManager.addValidHook("GameObject:get_box_offset");
            usertype.set_function("get_box_offset",
                [](GameObject* self) -> cocos2d::CCPoint const& {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getBoxOffset();
                });

            luaManager.addValidHook("GameObject:get_color_frame");
            usertype.set_function("get_color_frame",
                [](GameObject* self, gd::string frame) -> gd::string {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getColorFrame(frame);
                });

            usertype.set_function("get_color_index",
                [](GameObject* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getColorIndex();
                });

            luaManager.addValidHook("GameObject:get_color_key");
            usertype.set_function("get_color_key",
                [](GameObject* self, bool isMainColor, bool colorGroups) -> gd::string {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getColorKey(isMainColor, colorGroups);
                });

            usertype.set_function("get_custom_zlayer",
                [](GameObject* self) -> ZLayer {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getCustomZLayer();
                });

            luaManager.addValidHook("GameObject:get_glow_frame");
            usertype.set_function("get_glow_frame",
                [](GameObject* self, gd::string frame) -> gd::string {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getGlowFrame(frame);
                });

            usertype.set_function("get_group_disabled",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getGroupDisabled();
                });

            usertype.set_function("get_group_id",
                [](GameObject* self, int index) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getGroupID(index);
                });

            usertype.set_function("get_group_string",
                [](GameObject* self) -> gd::string {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getGroupString();
                });

            usertype.set_function("get_has_rotate_action",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getHasRotateAction();
                });

            usertype.set_function("get_has_synced_animation",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getHasSyncedAnimation();
                });

            usertype.set_function("get_last_position",
                [](GameObject* self) -> cocos2d::CCPoint const& {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getLastPosition();
                });

            usertype.set_function("get_main_color",
                [](GameObject* self) -> GJSpriteColor* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getMainColor();
                });

            usertype.set_function("get_main_color_mode",
                [](GameObject* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getMainColorMode();
                });

            luaManager.addValidHook("GameObject:get_object_direction");
            usertype.set_function("get_object_direction",
                [](GameObject* self) -> int {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getObjectDirection();
                });

            usertype.set_function("get_object_label",
                [](GameObject* self) -> cocos2d::CCLabelBMFont* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getObjectLabel();
                });

            usertype.set_function("get_object_radius",
                [](GameObject* self) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getObjectRadius();
                });

            luaManager.addValidHook("GameObject:get_object_rect");
            luaManager.addValidHook("GameObject:get_object_rect@2");
            usertype.set_function("get_object_rect",
                sol::overload(
                    [](GameObject* self) -> cocos2d::CCRect const& {
                        auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                        return modifiedSelf->getObjectRect();
                    },
                    [](GameObject* self, float width, float height) -> cocos2d::CCRect {
                        auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                        return modifiedSelf->getObjectRect(width, height);
                    }));

            luaManager.addValidHook("GameObject:get_object_rect2");
            usertype.set_function("get_object_rect2",
                [](GameObject* self, float width, float height) -> cocos2d::CCRect const& {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getObjectRect2(width, height);
                });

            luaManager.addValidHook("GameObject:get_object_rect_dirty");
            usertype.set_function("get_object_rect_dirty",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getObjectRectDirty();
                });

            usertype.set_function("get_object_rect_pointer",
                [](GameObject* self) -> cocos2d::CCRect* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getObjectRectPointer();
                });

            luaManager.addValidHook("GameObject:get_object_rotation");
            usertype.set_function("get_object_rotation",
                [](GameObject* self) -> float {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getObjectRotation();
                });

            luaManager.addValidHook("GameObject:get_object_texture_rect");
            usertype.set_function("get_object_texture_rect",
                [](GameObject* self) -> cocos2d::CCRect const& {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getObjectTextureRect();
                });

            usertype.set_function("get_object_zlayer",
                [](GameObject* self) -> ZLayer {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getObjectZLayer();
                });

            usertype.set_function("get_object_zorder",
                [](GameObject* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getObjectZOrder();
                });

            luaManager.addValidHook("GameObject:get_oriented_box");
            usertype.set_function("get_oriented_box",
                [](GameObject* self) -> OBB2D* {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getOrientedBox();
                });

            luaManager.addValidHook("GameObject:get_oriented_rect_dirty");
            usertype.set_function("get_oriented_rect_dirty",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getOrientedRectDirty();
                });

            usertype.set_function("get_outer_object_rect",
                [](GameObject* self) -> cocos2d::CCRect {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getOuterObjectRect();
                });

            luaManager.addValidHook("GameObject:get_parent_mode");
            usertype.set_function("get_parent_mode",
                [](GameObject* self) -> int {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getParentMode();
                });

            luaManager.addValidHook("GameObject:get_rscale_x");
            usertype.set_function("get_rscale_x",
                [](GameObject* self) -> float {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getRScaleX();
                });

            luaManager.addValidHook("GameObject:get_rscale_y");
            usertype.set_function("get_rscale_y",
                [](GameObject* self) -> float {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getRScaleY();
                });

            luaManager.addValidHook("GameObject:get_real_position");
            usertype.set_function("get_real_position",
                [](GameObject* self) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getRealPosition();
                });

            luaManager.addValidHook("GameObject:get_relative_sprite_color");
            usertype.set_function("get_relative_sprite_color",
                [](GameObject* self, int type) -> GJSpriteColor* {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getRelativeSpriteColor(type);
                });

            luaManager.addValidHook("GameObject:get_save_string");
            usertype.set_function("get_save_string",
                [](GameObject* self, GJBaseGameLayer* layer) -> gd::string {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getSaveString(layer);
                });

            luaManager.addValidHook("GameObject:get_scale_pos_delta");
            usertype.set_function("get_scale_pos_delta",
                [](GameObject* self) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getScalePosDelta();
                });

            usertype.set_function("get_secondary_color",
                [](GameObject* self) -> GJSpriteColor* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getSecondaryColor();
                });

            usertype.set_function("get_secondary_color_mode",
                [](GameObject* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getSecondaryColorMode();
                });

            usertype.set_function("get_slope_angle",
                [](GameObject* self) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getSlopeAngle();
                });

            luaManager.addValidHook("GameObject:get_start_pos");
            usertype.set_function("get_start_pos",
                [](GameObject* self) -> cocos2d::CCPoint {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getStartPos();
                });

            usertype.set_function("get_text_kerning",
                [](GameObject* self) -> int {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getTextKerning();
                });

            luaManager.addValidHook("GameObject:get_type");
            usertype.set_function("get_type",
                [](GameObject* self) -> GameObjectType {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->getType();
                });

            usertype.set_function("get_unmodified_position",
                [](GameObject* self) -> cocos2d::CCPoint {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->getUnmodifiedPosition();
                });

            usertype.set_function("group_color",
                [](GameObject* self, cocos2d::ccColor3B const& color, bool mainColor) -> cocos2d::ccColor3B const& {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->groupColor(color, mainColor);
                });

            luaManager.addValidHook("GameObject:group_opacity_mod");
            usertype.set_function("group_opacity_mod",
                [](GameObject* self) -> float {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->groupOpacityMod();
                });

            usertype.set_function("group_was_disabled",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->groupWasDisabled();
                });

            usertype.set_function("group_was_enabled",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->groupWasEnabled();
                });

            usertype.set_function("has_been_activated",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->hasBeenActivated();
                });

            usertype.set_function("has_been_activated_by_player",
                [](GameObject* self, PlayerObject* player) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->hasBeenActivatedByPlayer(player);
                });

            usertype.set_function("has_secondary_color",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->hasSecondaryColor();
                });

            luaManager.addValidHook("GameObject:ignore_editor_duration");
            usertype.set_function("ignore_editor_duration",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->ignoreEditorDuration();
                });

            usertype.set_function("ignore_enter",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->ignoreEnter();
                });

            usertype.set_function("ignore_fade",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->ignoreFade();
                });

            usertype.set_function("init",
                [](GameObject* self, char const* frame) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->init(frame);
                });

            luaManager.addValidHook("GameObject:init_with_texture");
            usertype.set_function("init_with_texture",
                [](GameObject* self, cocos2d::CCTexture2D* texture) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->initWithTexture(texture);
                });

            usertype.set_function("is_basic_enter_effect",
                [](int id) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call the original static function instead
                    return GameObject::isBasicEnterEffect(id);
                });

            luaManager.addValidHook("GameObject:is_basic_trigger");
            usertype.set_function("is_basic_trigger",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->isBasicTrigger();
                });

            usertype.set_function("is_color_object",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isColorObject();
                });

            usertype.set_function("is_color_trigger",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isColorTrigger();
                });

            usertype.set_function("is_configurable_portal",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isConfigurablePortal();
                });

            usertype.set_function("is_editor_spawnable_trigger",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isEditorSpawnableTrigger();
                });

            luaManager.addValidHook("GameObject:is_facing_down");
            usertype.set_function("is_facing_down",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->isFacingDown();
                });

            luaManager.addValidHook("GameObject:is_facing_left");
            usertype.set_function("is_facing_left",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->isFacingLeft();
                });

            luaManager.addValidHook("GameObject:is_flip_x");
            usertype.set_function("is_flip_x",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->isFlipX();
                });

            luaManager.addValidHook("GameObject:is_flip_y");
            usertype.set_function("is_flip_y",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->isFlipY();
                });

            usertype.set_function("is_settings_object",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isSettingsObject();
                });

            luaManager.addValidHook("GameObject:is_spawnable_trigger");
            usertype.set_function("is_spawnable_trigger",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->isSpawnableTrigger();
                });

            luaManager.addValidHook("GameObject:is_special_object");
            usertype.set_function("is_special_object",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->isSpecialObject();
                });

            usertype.set_function("is_special_spawn_object",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isSpecialSpawnObject();
                });

            usertype.set_function("is_speed_object",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isSpeedObject();
                });

            usertype.set_function("is_stoppable_trigger",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->isStoppableTrigger();
                });

            luaManager.addValidHook("GameObject:is_trigger");
            usertype.set_function("is_trigger",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->isTrigger();
                });

            luaManager.addValidHook("GameObject:load_groups_from_string");
            usertype.set_function("load_groups_from_string",
                [](GameObject* self, gd::string groupList) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->loadGroupsFromString(groupList);
                });

            usertype.set_function("make_invisible",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->makeInvisible();
                });

            usertype.set_function("make_visible",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->makeVisible();
                });

            luaManager.addValidHook("GameObject.object_from_vector");
            usertype.set_function("object_from_vector",
                [](gd::vector<gd::string>& propValues, gd::vector<void *>& propIsPresent, GJBaseGameLayer* gameLayer, bool lowDetail) -> GameObject* {
                    return quartz::GameObjectModified::objectFromVector(propValues, propIsPresent, gameLayer, lowDetail);
                });

            usertype.set_function("opacity_mod_for_mode",
                [](GameObject* self, int id, bool mainColor) -> float {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->opacityModForMode(id, mainColor);
                });

            luaManager.addValidHook("GameObject:parent_for_zlayer");
            usertype.set_function("parent_for_zlayer",
                [](GameObject* self, int zLayer, bool blending, int parentMode) -> cocos2d::CCNode* {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->parentForZLayer(zLayer, blending, parentMode);
                });

            usertype.set_function("particle_was_activated",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->particleWasActivated();
                });

            luaManager.addValidHook("GameObject:perspective_color_frame");
            usertype.set_function("perspective_color_frame",
                [](GameObject* self, char const* prefix, int index) -> gd::string {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->perspectiveColorFrame(prefix, index);
                });

            luaManager.addValidHook("GameObject:perspective_frame");
            usertype.set_function("perspective_frame",
                [](GameObject* self, char const* prefix, int index) -> gd::string {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->perspectiveFrame(prefix, index);
                });

            luaManager.addValidHook("GameObject:play_destroy_object_anim");
            usertype.set_function("play_destroy_object_anim",
                [](GameObject* self, GJBaseGameLayer* layer) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->playDestroyObjectAnim(layer);
                });

            luaManager.addValidHook("GameObject:play_pickup_animation@2");
            usertype.set_function("play_pickup_animation",
                sol::overload(
                    [](GameObject* self, cocos2d::CCSprite* target, float offset, float duration, float randomValue1, float randomValue2) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->playPickupAnimation(target, offset, duration, randomValue1, randomValue2);
                    },
                    [](GameObject* self, cocos2d::CCSprite* target, float xOffset, float yOffset, float controlYOffset1, float controlYOffset2, float endYOffset, float duration, float fadeDelay, float fadeDuration, bool rotate, float randomValue1, float randomValue2) {
                        auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                        modifiedSelf->playPickupAnimation(target, xOffset, yOffset, controlYOffset1, controlYOffset2, endYOffset, duration, fadeDelay, fadeDuration, rotate, randomValue1, randomValue2);
                    }));

            luaManager.addValidHook("GameObject:play_shine_effect");
            usertype.set_function("play_shine_effect",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->playShineEffect();
                });

            usertype.set_function("quick_update_position",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->quickUpdatePosition();
                });

            usertype.set_function("quick_update_position2",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->quickUpdatePosition2();
                });

            usertype.set_function("remove_color_sprite",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeColorSprite();
                });

            luaManager.addValidHook("GameObject:remove_from_group");
            usertype.set_function("remove_from_group",
                [](GameObject* self, int id) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->removeFromGroup(id);
                });

            usertype.set_function("remove_glow",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->removeGlow();
                });

            usertype.set_function("reorder_color_sprite",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->reorderColorSprite();
                });

            usertype.set_function("reset_color_groups",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetColorGroups();
                });

            usertype.set_function("reset_group_disabled",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetGroupDisabled();
                });

            usertype.set_function("reset_groups",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetGroups();
                });

            usertype.set_function("reset_mid",
                []() {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call the original static function instead
                    GameObject::resetMID();
                });

            usertype.set_function("reset_main_color_mode",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetMainColorMode();
                });

            usertype.set_function("reset_move_offset",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetMoveOffset();
                });

            luaManager.addValidHook("GameObject:reset_object");
            usertype.set_function("reset_object",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->resetObject();
                });

            usertype.set_function("reset_rscale_forced",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetRScaleForced();
                });

            usertype.set_function("reset_secondary_color_mode",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->resetSecondaryColorMode();
                });

            luaManager.addValidHook("GameObject:restore_object");
            usertype.set_function("restore_object",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->restoreObject();
                });

            luaManager.addValidHook("GameObject:save_active_colors");
            usertype.set_function("save_active_colors",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->saveActiveColors();
                });

            luaManager.addValidHook("GameObject:select_object");
            usertype.set_function("select_object",
                [](GameObject* self, cocos2d::ccColor3B color) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->selectObject(color);
                });

            luaManager.addValidHook("GameObject:set_area_opacity");
            usertype.set_function("set_area_opacity",
                [](GameObject* self, float step, float value, int index) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setAreaOpacity(step, value, index);
                });

            luaManager.addValidHook("GameObject:set_child_color");
            usertype.set_function("set_child_color",
                [](GameObject* self, cocos2d::ccColor3B const& color) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setChildColor(color);
                });

            usertype.set_function("set_custom_zlayer",
                [](GameObject* self, int zLayer) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setCustomZLayer(zLayer);
                });

            usertype.set_function("set_default_main_color_mode",
                [](GameObject* self, int id) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setDefaultMainColorMode(id);
                });

            usertype.set_function("set_default_secondary_color_mode",
                [](GameObject* self, int id) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setDefaultSecondaryColorMode(id);
                });

            luaManager.addValidHook("GameObject:set_flip_x");
            usertype.set_function("set_flip_x",
                [](GameObject* self, bool flipX) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setFlipX(flipX);
                });

            luaManager.addValidHook("GameObject:set_flip_y");
            usertype.set_function("set_flip_y",
                [](GameObject* self, bool flipY) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setFlipY(flipY);
                });

            luaManager.addValidHook("GameObject:set_glow_color");
            usertype.set_function("set_glow_color",
                [](GameObject* self, cocos2d::ccColor3B const& color) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setGlowColor(color);
                });

            usertype.set_function("set_glow_opacity",
                [](GameObject* self, unsigned char opacity) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setGlowOpacity(opacity);
                });

            usertype.set_function("set_last_position",
                [](GameObject* self, cocos2d::CCPoint const& position) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setLastPosition(position);
                });

            usertype.set_function("set_main_color_mode",
                [](GameObject* self, int id) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setMainColorMode(id);
                });

            luaManager.addValidHook("GameObject:set_object_color");
            usertype.set_function("set_object_color",
                [](GameObject* self, cocos2d::ccColor3B const& color) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setObjectColor(color);
                });

            usertype.set_function("set_object_label",
                [](GameObject* self, cocos2d::CCLabelBMFont* label) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setObjectLabel(label);
                });

            luaManager.addValidHook("GameObject:set_object_rect_dirty");
            usertype.set_function("set_object_rect_dirty",
                [](GameObject* self, bool dirty) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setObjectRectDirty(dirty);
                });

            luaManager.addValidHook("GameObject:set_opacity");
            usertype.set_function("set_opacity",
                [](GameObject* self, unsigned char opacity) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setOpacity(opacity);
                });

            luaManager.addValidHook("GameObject:set_oriented_rect_dirty");
            usertype.set_function("set_oriented_rect_dirty",
                [](GameObject* self, bool dirty) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setOrientedRectDirty(dirty);
                });

            luaManager.addValidHook("GameObject:set_position");
            usertype.set_function("set_position",
                [](GameObject* self, cocos2d::CCPoint const& position) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setPosition(position);
                });

            luaManager.addValidHook("GameObject:set_rrotation");
            usertype.set_function("set_rrotation",
                [](GameObject* self, float rotation) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setRRotation(rotation);
                });

            luaManager.addValidHook("GameObject:set_rscale");
            usertype.set_function("set_rscale",
                [](GameObject* self, float scale) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setRScale(scale);
                });

            luaManager.addValidHook("GameObject:set_rscale_x");
            usertype.set_function("set_rscale_x",
                [](GameObject* self, float scaleX) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setRScaleX(scaleX);
                });

            luaManager.addValidHook("GameObject:set_rscale_y");
            usertype.set_function("set_rscale_y",
                [](GameObject* self, float scaleY) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setRScaleY(scaleY);
                });

            luaManager.addValidHook("GameObject:set_rotation");
            usertype.set_function("set_rotation",
                [](GameObject* self, float rotation) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setRotation(rotation);
                });

            luaManager.addValidHook("GameObject:set_rotation_x");
            usertype.set_function("set_rotation_x",
                [](GameObject* self, float rotationX) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setRotationX(rotationX);
                });

            luaManager.addValidHook("GameObject:set_rotation_y");
            usertype.set_function("set_rotation_y",
                [](GameObject* self, float rotationY) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setRotationY(rotationY);
                });

            luaManager.addValidHook("GameObject:set_scale");
            usertype.set_function("set_scale",
                [](GameObject* self, float scale) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setScale(scale);
                });

            luaManager.addValidHook("GameObject:set_scale_x");
            usertype.set_function("set_scale_x",
                [](GameObject* self, float scaleX) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setScaleX(scaleX);
                });

            luaManager.addValidHook("GameObject:set_scale_y");
            usertype.set_function("set_scale_y",
                [](GameObject* self, float scaleY) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setScaleY(scaleY);
                });

            usertype.set_function("set_secondary_color_mode",
                [](GameObject* self, int id) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setSecondaryColorMode(id);
                });

            luaManager.addValidHook("GameObject:set_start_pos");
            usertype.set_function("set_start_pos",
                [](GameObject* self, cocos2d::CCPoint position) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setStartPos(position);
                });

            luaManager.addValidHook("GameObject:set_type");
            usertype.set_function("set_type",
                [](GameObject* self, GameObjectType type) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setType(type);
                });

            luaManager.addValidHook("GameObject:set_visible");
            usertype.set_function("set_visible",
                [](GameObject* self, bool visible) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setVisible(visible);
                });

            usertype.set_function("setup_color_sprite",
                [](GameObject* self, int id, bool mainColor) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->setupColorSprite(id, mainColor);
                });

            luaManager.addValidHook("GameObject:setup_custom_sprites");
            usertype.set_function("setup_custom_sprites",
                [](GameObject* self, gd::string frameName) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setupCustomSprites(frameName);
                });

            luaManager.addValidHook("GameObject:setup_pixel_scale");
            usertype.set_function("setup_pixel_scale",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setupPixelScale();
                });

            luaManager.addValidHook("GameObject:setup_sprite_size");
            usertype.set_function("setup_sprite_size",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->setupSpriteSize();
                });

            luaManager.addValidHook("GameObject:should_blend_color");
            usertype.set_function("should_blend_color",
                [](GameObject* self, GJSpriteColor* color, bool mainColor) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->shouldBlendColor(color, mainColor);
                });

            usertype.set_function("should_draw_editor_hitbox",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->shouldDrawEditorHitbox();
                });

            luaManager.addValidHook("GameObject:should_lock_x");
            usertype.set_function("should_lock_x",
                [](GameObject* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->shouldLockX();
                });

            usertype.set_function("should_not_hide_anim_freeze",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->shouldNotHideAnimFreeze();
                });

            usertype.set_function("should_show_pickup_effects",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->shouldShowPickupEffects();
                });

            usertype.set_function("slope_floor_top",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->slopeFloorTop();
                });

            usertype.set_function("slope_wall_left",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->slopeWallLeft();
                });

            luaManager.addValidHook("GameObject:slope_ypos@3");
            usertype.set_function("slope_ypos",
                sol::overload(
                    [](GameObject* self, GameObject* object) -> double {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        return self->slopeYPos(object);
                    },
                    [](GameObject* self, cocos2d::CCRect rect) -> double {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        return self->slopeYPos(rect);
                    },
                    [](GameObject* self, float x) -> double {
                        auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                        return modifiedSelf->slopeYPos(x);
                    }));

            luaManager.addValidHook("GameObject:spawn_default_pickup_particle");
            usertype.set_function("spawn_default_pickup_particle",
                [](GameObject* self, GJBaseGameLayer* layer) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->spawnDefaultPickupParticle(layer);
                });

            luaManager.addValidHook("GameObject:spawn_xposition");
            usertype.set_function("spawn_xposition",
                [](GameObject* self) -> float {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    return modifiedSelf->spawnXPosition();
                });

            luaManager.addValidHook("GameObject:transfer_object_rect");
            usertype.set_function("transfer_object_rect",
                [](GameObject* self, cocos2d::CCRect& rect) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->transferObjectRect(rect);
                });

            usertype.set_function("trigger_activated",
                [](GameObject* self, float xPosition) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->triggerActivated(xPosition);
                });

            usertype.set_function("trigger_object",
                [](GameObject* self, GJBaseGameLayer* layer, int uniqueID, gd::vector<int> const* remapKeys) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->triggerObject(layer, uniqueID, remapKeys);
                });

            luaManager.addValidHook("GameObject:unclaim_particle");
            usertype.set_function("unclaim_particle",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->unclaimParticle();
                });

            usertype.set_function("update",
                [](GameObject* self, float dt) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->update(dt);
                });

            usertype.set_function("update_blend_mode",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateBlendMode();
                });

            usertype.set_function("update_custom_color_type",
                [](GameObject* self, short type) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateCustomColorType(type);
                });

            luaManager.addValidHook("GameObject:update_custom_scale_x");
            usertype.set_function("update_custom_scale_x",
                [](GameObject* self, float scaleX) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->updateCustomScaleX(scaleX);
                });

            luaManager.addValidHook("GameObject:update_custom_scale_y");
            usertype.set_function("update_custom_scale_y",
                [](GameObject* self, float scaleY) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->updateCustomScaleY(scaleY);
                });

            usertype.set_function("update_hsvstate",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateHSVState();
                });

            luaManager.addValidHook("GameObject:update_is_oriented");
            usertype.set_function("update_is_oriented",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->updateIsOriented();
                });

            luaManager.addValidHook("GameObject:update_main_color");
            usertype.set_function("update_main_color",
                sol::overload(
                    [](GameObject* self, cocos2d::ccColor3B const& color) {
                        auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                        modifiedSelf->updateMainColor(color);
                    },
                    [](GameObject* self) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->updateMainColor();
                    }));

            usertype.set_function("update_main_color_only",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateMainColorOnly();
                });

            usertype.set_function("update_main_opacity",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateMainOpacity();
                });

            usertype.set_function("update_main_particle_opacity",
                [](GameObject* self, unsigned char opacity) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateMainParticleOpacity(opacity);
                });

            luaManager.addValidHook("GameObject:update_object_editor_color");
            usertype.set_function("update_object_editor_color",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->updateObjectEditorColor();
                });

            luaManager.addValidHook("GameObject:update_oriented_box");
            usertype.set_function("update_oriented_box",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->updateOrientedBox();
                });

            luaManager.addValidHook("GameObject:update_particle_color");
            usertype.set_function("update_particle_color",
                [](GameObject* self, cocos2d::ccColor3B const& color) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->updateParticleColor(color);
                });

            luaManager.addValidHook("GameObject:update_particle_opacity");
            usertype.set_function("update_particle_opacity",
                [](GameObject* self, unsigned char opacity) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->updateParticleOpacity(opacity);
                });

            luaManager.addValidHook("GameObject:update_secondary_color");
            usertype.set_function("update_secondary_color",
                sol::overload(
                    [](GameObject* self, cocos2d::ccColor3B const& color) {
                        auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                        modifiedSelf->updateSecondaryColor(color);
                    },
                    [](GameObject* self) {
                        // this function is out of line on at least one platform
                        // it cannot be modified, so we call it using `self` instead
                        self->updateSecondaryColor();
                    }));

            usertype.set_function("update_secondary_color_only",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateSecondaryColorOnly();
                });

            usertype.set_function("update_secondary_opacity",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateSecondaryOpacity();
                });

            usertype.set_function("update_secondary_particle_opacity",
                [](GameObject* self, unsigned char opacity) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateSecondaryParticleOpacity(opacity);
                });

            luaManager.addValidHook("GameObject:update_start_pos");
            usertype.set_function("update_start_pos",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->updateStartPos();
                });

            luaManager.addValidHook("GameObject:update_start_values");
            usertype.set_function("update_start_values",
                [](GameObject* self) {
                    auto modifiedSelf = static_cast<quartz::GameObjectModified*>(self);
                    modifiedSelf->updateStartValues();
                });

            usertype.set_function("update_text_kerning",
                [](GameObject* self, int kerning) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateTextKerning(kerning);
                });

            usertype.set_function("update_unmodified_positions",
                [](GameObject* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->updateUnmodifiedPositions();
                });

            usertype.set_function("uses_freeze_animation",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->usesFreezeAnimation();
                });

            usertype.set_function("uses_special_animation",
                [](GameObject* self) -> bool {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    return self->usesSpecialAnimation();
                });
        });
}

} // namespace quartz