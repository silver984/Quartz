#include <pch.hpp>
#include <qtz/modified/PlayerObject.hpp>

$execute {
	auto& bindingsManager = qtz::BindingsManager::get();
	bindingsManager.queue(
	qtz::BindingLevel::Unit,
		[]() {
			sol::usertype<PlayerObject> usertype = qtz::LuaManager::get().luaState()["PlayerObject"];

			usertype["create"] =
				[](int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> PlayerObject* {
				return qtz::modified::PlayerObject::create(player, ship, gameLayer, layer, playLayer);
				};

			usertype["init"] =
				[](PlayerObject* self, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> bool {
				auto modifiedSelf = static_cast<qtz::modified::PlayerObject*>(self);
				return modifiedSelf->init(player, ship, gameLayer, layer, playLayer);
				};

			usertype["update"] =
				[](PlayerObject* self, float dt) {
				auto modifiedSelf = static_cast<qtz::modified::PlayerObject*>(self);
				modifiedSelf->update(dt);
				};
		}
	);
}