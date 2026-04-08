#include <pch.hpp>
#include <quartz/modified/PlayerObject.hpp>

$execute {
	auto& bindingsManager = quartz::BindingsManager::get();
	bindingsManager.queue(
	quartz::BindingLevel::Unit,
		[]() {
			sol::usertype<PlayerObject> usertype = quartz::LuaManager::get().luaState()["PlayerObject"];

			usertype["create"] =
				[](int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> PlayerObject* {
				return quartz::modified::PlayerObject::create(player, ship, gameLayer, layer, playLayer);
				};

			usertype["init"] =
				[](PlayerObject* self, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> bool {
				auto modifiedSelf = static_cast<quartz::modified::PlayerObject*>(self);
				return modifiedSelf->init(player, ship, gameLayer, layer, playLayer);
				};

			usertype["update"] =
				[](PlayerObject* self, float dt) {
				auto modifiedSelf = static_cast<quartz::modified::PlayerObject*>(self);
				modifiedSelf->update(dt);
				};
		}
	);
}