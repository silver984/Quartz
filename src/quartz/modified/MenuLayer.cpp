#include <quartz/modified/MenuLayer.hpp>
#include <quartz/core/Templates.hpp>
#include <utility>

namespace quartz {

void MenuLayerModified::FLAlert_Clicked(FLAlertLayer* layer, bool btn2) {
    quartz::runHookChain<void>("MenuLayer:flalert_clicked",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::FLAlert_Clicked(std::forward<decltype(args)>(args)...); 
        }, layer, btn2);
}

void MenuLayerModified::endGame() {
    quartz::runHookChain<void>("MenuLayer:end_game",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::endGame(std::forward<decltype(args)>(args)...); 
        });
}

void MenuLayerModified::firstNetworkTest() {
    quartz::runHookChain<void>("MenuLayer:first_network_test",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::firstNetworkTest(std::forward<decltype(args)>(args)...); 
        });
}

void MenuLayerModified::googlePlaySignedIn() {
    quartz::runHookChain<void>("MenuLayer:google_play_signed_in",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::googlePlaySignedIn(std::forward<decltype(args)>(args)...); 
        });
}

bool MenuLayerModified::init() {
    return quartz::runHookChain<bool>("MenuLayer:init",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::init(std::forward<decltype(args)>(args)...); 
        });
}

void MenuLayerModified::keyBackClicked() {
    quartz::runHookChain<void>("MenuLayer:key_back_clicked",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::keyBackClicked(std::forward<decltype(args)>(args)...); 
        });
}

void MenuLayerModified::keyDown(cocos2d::enumKeyCodes key, double timestamp) {
    quartz::runHookChain<void>("MenuLayer:key_down",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::keyDown(std::forward<decltype(args)>(args)...); 
        }, key, timestamp);
}

void MenuLayerModified::onAchievements(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_achievements",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onAchievements(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onCreator(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_creator",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onCreator(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onDaily(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_daily",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onDaily(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onDiscord(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_discord",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onDiscord(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onFacebook(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_facebook",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onFacebook(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onFreeLevels(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_free_levels",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onFreeLevels(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onFullVersion(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_full_version",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onFullVersion(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onGarage(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_garage",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onGarage(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onMoreGames(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_more_games",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onMoreGames(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onMyProfile(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_my_profile",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onMyProfile(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onNewgrounds(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_newgrounds",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onNewgrounds(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onOptions(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_options",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onOptions(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onOptionsInstant() {
    quartz::runHookChain<void>("MenuLayer:on_options_instant",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onOptionsInstant(std::forward<decltype(args)>(args)...); 
        });
}

void MenuLayerModified::onPlay(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_play",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onPlay(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onQuit(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_quit",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onQuit(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onRobTop(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_rob_top",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onRobTop(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onStats(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_stats",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onStats(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onTwitch(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_twitch",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onTwitch(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onTwitter(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_twitter",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onTwitter(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::onYouTube(cocos2d::CCObject* sender) {
    quartz::runHookChain<void>("MenuLayer:on_you_tube",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::onYouTube(std::forward<decltype(args)>(args)...); 
        }, sender);
}

void MenuLayerModified::openOptions(bool videoOptions) {
    quartz::runHookChain<void>("MenuLayer:open_options",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::openOptions(std::forward<decltype(args)>(args)...); 
        }, videoOptions);
}

cocos2d::CCScene* MenuLayerModified::scene(bool isVideoOptionsOpen) {
    return quartz::runStaticHookChain<cocos2d::CCScene*>("MenuLayer.scene",
        &MenuLayer::scene,
        isVideoOptionsOpen);
}

void MenuLayerModified::showTOS() {
    quartz::runHookChain<void>("MenuLayer:show_tos",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::showTOS(std::forward<decltype(args)>(args)...); 
        });
}

void MenuLayerModified::updateUserProfileButton() {
    quartz::runHookChain<void>("MenuLayer:update_user_profile_button",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::updateUserProfileButton(std::forward<decltype(args)>(args)...); 
        });
}

void MenuLayerModified::willClose() {
    quartz::runHookChain<void>("MenuLayer:will_close",
        static_cast<MenuLayer*>(this),
        [](MenuLayer* self, auto&&... args) -> decltype(auto) {
            return self->MenuLayer::willClose(std::forward<decltype(args)>(args)...); 
        });
}

} // namespace quartz