#pragma once
#include <Geode/modify/MenuLayer.hpp>
#include <quartz/core/LuaFields.hpp>

namespace quartz {

struct MenuLayerModified : geode::Modify<MenuLayerModified, MenuLayer>, quartz::LuaFields {
    // @lua "MenuLayer:flalert_clicked"
    void FLAlert_Clicked(FLAlertLayer* layer, bool btn2) override;

    // @lua "MenuLayer:end_game"
    void endGame();

    // @lua "MenuLayer:first_network_test"
    void firstNetworkTest();

    // @lua "MenuLayer:google_play_signed_in"
    void googlePlaySignedIn() override;

    // @lua "MenuLayer:init"
    bool init() override;

    // @lua "MenuLayer:key_back_clicked"
    void keyBackClicked() override;

    // @lua "MenuLayer:key_down"
    void keyDown(cocos2d::enumKeyCodes key, double timestamp) override;

    // @lua "MenuLayer:on_achievements"
    void onAchievements(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_creator"
    void onCreator(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_daily"
    void onDaily(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_discord"
    void onDiscord(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_facebook"
    void onFacebook(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_free_levels"
    void onFreeLevels(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_full_version"
    void onFullVersion(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_garage"
    void onGarage(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_more_games"
    void onMoreGames(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_my_profile"
    void onMyProfile(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_newgrounds"
    void onNewgrounds(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_options"
    void onOptions(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_options_instant"
    void onOptionsInstant();

    // @lua "MenuLayer:on_play"
    void onPlay(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_quit"
    void onQuit(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_rob_top"
    void onRobTop(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_stats"
    void onStats(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_twitch"
    void onTwitch(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_twitter"
    void onTwitter(cocos2d::CCObject* sender);

    // @lua "MenuLayer:on_you_tube"
    void onYouTube(cocos2d::CCObject* sender);

    // @lua "MenuLayer:open_options"
    void openOptions(bool videoOptions);

    // @lua "MenuLayer.scene"
    static cocos2d::CCScene* scene(bool isVideoOptionsOpen);

    // @lua "MenuLayer:show_tos"
    void showTOS();

    // @lua "MenuLayer:update_user_profile_button"
    void updateUserProfileButton();

    // @lua "MenuLayer:will_close"
    void willClose();
};

} // namespace quartz