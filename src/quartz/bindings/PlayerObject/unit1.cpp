#include <quartz/pch.hpp>
#include <quartz/modified/PlayerObject.hpp>

$execute {
	auto& luaManager = quartz::LuaManager::get();
	luaManager.addUnitBinding(
		[&luaManager]() {
			sol::usertype<PlayerObject> usertype = luaManager.luaState()["PlayerObject"];

			usertype["y_velocity"] = sol::property(
				[](PlayerObject* self) {
					return self->m_yVelocity;
				},
				[](PlayerObject* self, double val) {
					self->m_yVelocity = val;
				});
		});
}