#include <quartz/modified/PlayerObject.hpp>
#include <quartz/pch.hpp>

namespace quartz::modified {

bool PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) {
	return quartz::runHookChain<bool>(
		"PlayerObject:init",
		static_cast<::PlayerObject*>(this),
		[](::PlayerObject* self, auto&&... args) -> decltype(auto) {
			return self->PlayerObject::init(std::forward<decltype(args)>(args)...);
		}, player, ship, gameLayer, layer, playLayer);
}

} // namespace quartz::modified