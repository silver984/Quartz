#include <quartz/modified/PlayerObject.hpp>
#include <quartz/pch.hpp>

namespace quartz::modified {

void PlayerObject::update(float dt) {
	quartz::runHookChain<void>(
		"PlayerObject:update",
		static_cast<::PlayerObject*>(this),
		[](::PlayerObject* self, auto&&... args) -> decltype(auto) {
			return self->PlayerObject::update(std::forward<decltype(args)>(args)...);
		}, dt);
}

} // namespace quartz::modified