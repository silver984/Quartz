#include <quartz/pch.hpp>
#include <quartz/modified/PlayerObject.hpp>

$execute {
	auto& luaManager = quartz::LuaManager::get();
	luaManager.addUnitBinding(
		[&luaManager]() {
			sol::table usertype = luaManager.luaState()["PlayerObject"];

			luaManager.addValidHook("PlayerObject.create");
			usertype["create"] =
				[](int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> PlayerObject* {
				return quartz::modified::PlayerObject::create(player, ship, gameLayer, layer, playLayer);
				};

			luaManager.addValidHook("PlayerObject:init");
			usertype["init"] =
				[](PlayerObject* self, int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) -> bool {
				auto modifiedSelf = static_cast<quartz::modified::PlayerObject*>(self);
				return modifiedSelf->init(player, ship, gameLayer, layer, playLayer);
				};

			luaManager.addValidHook("PlayerObject:update");
			usertype["update"] =
				[](PlayerObject* self, float dt) {
				auto modifiedSelf = static_cast<quartz::modified::PlayerObject*>(self);
				modifiedSelf->update(dt);
				};
		});
}