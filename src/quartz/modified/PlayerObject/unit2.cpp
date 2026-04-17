#include <qtz/modified/PlayerObject.hpp>

namespace qtz::modified {

void PlayerObject::update(float dt) {
	qtz::runHookChain<void>(
		"PlayerObject::update",
		static_cast<::PlayerObject*>(this),
		[](::PlayerObject* self, auto&&... args) -> decltype(auto) {
			return self->PlayerObject::update(std::forward<decltype(args)>(args)...);
		},
		dt
	);
}

} // namespace qtz::modified