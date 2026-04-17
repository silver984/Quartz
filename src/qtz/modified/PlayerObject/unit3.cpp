#include <qtz/modified/PlayerObject.hpp>

namespace qtz::modified {

bool PlayerObject::init(int player, int ship, GJBaseGameLayer* gameLayer, cocos2d::CCLayer* layer, bool playLayer) {
	return qtz::runHookChain<bool>(
		"PlayerObject::init",
		static_cast<::PlayerObject*>(this),
		[](::PlayerObject* self, auto&&... args) -> decltype(auto) {
			return self->PlayerObject::init(std::forward<decltype(args)>(args)...);
		},
		player, ship, gameLayer, layer, playLayer
	);
}

} // namespace qtz::modified