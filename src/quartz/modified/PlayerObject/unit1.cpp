#include <qtz/modified/PlayerObject.hpp>
#include <pch.hpp>

namespace qtz::modified {

void PlayerObject::onModify(geode::modifier::ModifyBase<geode::modifier::ModifyDerive<PlayerObject, ::PlayerObject>>& self) {
	for (const auto& [_, hook] : self.m_hooks) {
		HookStorage::get().storeGeodeHook(hook);
	}
}

::PlayerObject* PlayerObject::create(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) {
	return qtz::runStaticHookChain<::PlayerObject*>(
		"PlayerObject.create",
		&::PlayerObject::create,
		player, ship, gameLayer, layer, playLayer
	);
}

} // namespace qtz::modified