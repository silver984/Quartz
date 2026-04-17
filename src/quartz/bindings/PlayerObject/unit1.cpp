#include <pch.hpp>
#include <qtz/modified/PlayerObject.hpp>

$execute {
	auto& bindingsManager = qtz::BindingsManager::get();
	bindingsManager.queue(
	qtz::BindingLevel::Unit,
		[]() {
			sol::usertype<PlayerObject> usertype = qtz::LuaManager::get().luaState()["PlayerObject"];

			usertype["yVlocity"] = sol::property(
				[](PlayerObject* self) {
					return self->m_yVelocity;
				},
				[](PlayerObject* self, double val) {
					self->m_yVelocity = val;
				}
			);
		}
	);
}