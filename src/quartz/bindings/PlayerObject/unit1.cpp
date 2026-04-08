#include <pch.hpp>
#include <quartz/modified/PlayerObject.hpp>

$execute {
	auto& bindingsManager = quartz::BindingsManager::get();
	bindingsManager.queue(
	quartz::BindingLevel::Unit,
		[]() {
			sol::usertype<PlayerObject> usertype = quartz::LuaManager::get().luaState()["PlayerObject"];

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