#include <quartz/bindings/MenuLayer.hpp>
#include <quartz/modified/MenuLayer.hpp>
#include <quartz/core/LuaManager.hpp>
#include <new>

namespace quartz {

MenuLayerBindings::MenuLayerBindings() {
    auto& luaManager = LuaManager::get();
    luaManager.queueBinding(
        [&luaManager]() {
            auto& state = luaManager.luaState();
            state.new_usertype<MenuLayer>("MenuLayer",
                sol::no_constructor,
                sol::base_classes, sol::bases<FLAlertLayerProtocol, GooglePlayDelegate, cocos2d::CCLayer>(),
                "gp_sprite", &MenuLayer::m_gpSprite,
                "menu_game_layer", &MenuLayer::m_menuGameLayer,
                "profile_button", &MenuLayer::m_profileButton,
                "profile_label", &MenuLayer::m_profileLabel,
                "showing_tos", &MenuLayer::m_showingTOS,
                "unknown", &MenuLayer::m_unknown,
                "view_profile_sprite", &MenuLayer::m_viewProfileSprite);

            sol::table usertype = state["MenuLayer"];

            // expose the custom fields to lua
            usertype.set_function("fields",
                [](sol::this_state s, MenuLayer* self) -> sol::table {
                    sol::state_view lua(s);

                    if (!self) {
                        return lua.create_table();
                    }

                    // this cast is required to access lua field storage
                    auto modifiedSelf = static_cast<MenuLayerModified*>(self);
                    auto& luaFields = modifiedSelf->m_fields->m_luaFields;

                    if (!luaFields.valid()) {
                        // lazily create lua fields on first accesss
                        luaFields = lua.create_table();
                    }

                    return luaFields;
                });

            luaManager.addValidHook("MenuLayer:flalert_clicked");
            usertype.set_function("flalert_clicked",
                [](MenuLayer* self, FLAlertLayer* layer, bool btn2) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->FLAlert_Clicked(layer, btn2);
                });

            luaManager.addValidHook("MenuLayer:end_game");
            usertype.set_function("end_game",
                [](MenuLayer* self) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->endGame();
                });

            luaManager.addValidHook("MenuLayer:first_network_test");
            usertype.set_function("first_network_test",
                [](MenuLayer* self) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->firstNetworkTest();
                });

            usertype.set_function("get",
                []() -> MenuLayer* {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call the original static function instead
                    return MenuLayer::get();
                });

            luaManager.addValidHook("MenuLayer:google_play_signed_in");
            usertype.set_function("google_play_signed_in",
                [](MenuLayer* self) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->googlePlaySignedIn();
                });

            luaManager.addValidHook("MenuLayer:init");
            usertype.set_function("init",
                [](MenuLayer* self) -> bool {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    return modifiedSelf->init();
                });

            luaManager.addValidHook("MenuLayer:key_back_clicked");
            usertype.set_function("key_back_clicked",
                [](MenuLayer* self) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->keyBackClicked();
                });

            luaManager.addValidHook("MenuLayer:key_down");
            usertype.set_function("key_down",
                [](MenuLayer* self, cocos2d::enumKeyCodes key, double timestamp) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->keyDown(key, timestamp);
                });

            luaManager.addValidHook("MenuLayer:on_achievements");
            usertype.set_function("on_achievements",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onAchievements(sender);
                });

            luaManager.addValidHook("MenuLayer:on_creator");
            usertype.set_function("on_creator",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onCreator(sender);
                });

            luaManager.addValidHook("MenuLayer:on_daily");
            usertype.set_function("on_daily",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onDaily(sender);
                });

            luaManager.addValidHook("MenuLayer:on_discord");
            usertype.set_function("on_discord",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onDiscord(sender);
                });

            usertype.set_function("on_everyplay",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->onEveryplay(sender);
                });

            luaManager.addValidHook("MenuLayer:on_facebook");
            usertype.set_function("on_facebook",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onFacebook(sender);
                });

            luaManager.addValidHook("MenuLayer:on_free_levels");
            usertype.set_function("on_free_levels",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onFreeLevels(sender);
                });

            luaManager.addValidHook("MenuLayer:on_full_version");
            usertype.set_function("on_full_version",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onFullVersion(sender);
                });

            usertype.set_function("on_game_center",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->onGameCenter(sender);
                });

            luaManager.addValidHook("MenuLayer:on_garage");
            usertype.set_function("on_garage",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onGarage(sender);
                });

            usertype.set_function("on_google_play_games",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->onGooglePlayGames(sender);
                });

            luaManager.addValidHook("MenuLayer:on_more_games");
            usertype.set_function("on_more_games",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onMoreGames(sender);
                });

            luaManager.addValidHook("MenuLayer:on_my_profile");
            usertype.set_function("on_my_profile",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onMyProfile(sender);
                });

            luaManager.addValidHook("MenuLayer:on_newgrounds");
            usertype.set_function("on_newgrounds",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onNewgrounds(sender);
                });

            luaManager.addValidHook("MenuLayer:on_options");
            usertype.set_function("on_options",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onOptions(sender);
                });

            luaManager.addValidHook("MenuLayer:on_options_instant");
            usertype.set_function("on_options_instant",
                [](MenuLayer* self) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onOptionsInstant();
                });

            luaManager.addValidHook("MenuLayer:on_play");
            usertype.set_function("on_play",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onPlay(sender);
                });

            luaManager.addValidHook("MenuLayer:on_quit");
            usertype.set_function("on_quit",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onQuit(sender);
                });

            luaManager.addValidHook("MenuLayer:on_rob_top");
            usertype.set_function("on_rob_top",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onRobTop(sender);
                });

            luaManager.addValidHook("MenuLayer:on_stats");
            usertype.set_function("on_stats",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onStats(sender);
                });

            usertype.set_function("on_trailer",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->onTrailer(sender);
                });

            luaManager.addValidHook("MenuLayer:on_twitch");
            usertype.set_function("on_twitch",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onTwitch(sender);
                });

            luaManager.addValidHook("MenuLayer:on_twitter");
            usertype.set_function("on_twitter",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onTwitter(sender);
                });

            luaManager.addValidHook("MenuLayer:on_you_tube");
            usertype.set_function("on_you_tube",
                [](MenuLayer* self, cocos2d::CCObject* sender) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->onYouTube(sender);
                });

            luaManager.addValidHook("MenuLayer:open_options");
            usertype.set_function("open_options",
                [](MenuLayer* self, bool videoOptions) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->openOptions(videoOptions);
                });

            luaManager.addValidHook("MenuLayer.scene");
            usertype.set_function("scene",
                [](bool isVideoOptionsOpen) -> cocos2d::CCScene* {
                    return quartz::MenuLayerModified::scene(isVideoOptionsOpen);
                });

            usertype.set_function("show_gcquestion",
                [](MenuLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->showGCQuestion();
                });

            usertype.set_function("show_meltdown_promo",
                [](MenuLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->showMeltdownPromo();
                });

            luaManager.addValidHook("MenuLayer:show_tos");
            usertype.set_function("show_tos",
                [](MenuLayer* self) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->showTOS();
                });

            usertype.set_function("sync_platform_achievements",
                [](MenuLayer* self, float dt) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->syncPlatformAchievements(dt);
                });

            usertype.set_function("try_show_ad",
                [](MenuLayer* self, float dt) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->tryShowAd(dt);
                });

            luaManager.addValidHook("MenuLayer:update_user_profile_button");
            usertype.set_function("update_user_profile_button",
                [](MenuLayer* self) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->updateUserProfileButton();
                });

            usertype.set_function("video_options_closed",
                [](MenuLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->videoOptionsClosed();
                });

            usertype.set_function("video_options_opened",
                [](MenuLayer* self) {
                    // this function is out of line on at least one platform
                    // it cannot be modified, so we call it using `self` instead
                    self->videoOptionsOpened();
                });

            luaManager.addValidHook("MenuLayer:will_close");
            usertype.set_function("will_close",
                [](MenuLayer* self) {
                    auto modifiedSelf = static_cast<quartz::MenuLayerModified*>(self);
                    modifiedSelf->willClose();
                });
        });
}

} // namespace quartz