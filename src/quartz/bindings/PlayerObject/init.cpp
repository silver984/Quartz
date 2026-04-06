#include <quartz/pch.hpp>
#include <quartz/modified/PlayerObject.hpp>

$execute {
	auto& luaManager = quartz::LuaManager::get();
	luaManager.addInitBinding(
		[&luaManager]() {
			auto& state = luaManager.luaState();
			state.new_usertype<PlayerObject>(
				"PlayerObject",
				sol::constructors<PlayerObject()>(),
				sol::base_classes, sol::bases<AnimatedSpriteDelegate, GameObject>());

            sol::usertype<PlayerObject> usertype = state["PlayerObject"];

            // expose the custom fields to lua
            usertype["fields"] = sol::readonly_property(
                [](PlayerObject* self, sol::this_state s) -> sol::table {
                    sol::state_view state(s);
                    auto modifiedSelf = static_cast<quartz::modified::PlayerObject*>(self);
                    auto& luaFields = modifiedSelf->m_fields->m_luaFields;

                    if (!luaFields.valid()) {
                        // lazily create lua fields on first accesss
                        luaFields = state.create_table();
                    }

                    return luaFields;
                });

            // manual allocation exposed to lua
            // returns raw pointer
            // lua must `free()` and `obj = nil` after use
            usertype["alloc"] =
                []() -> PlayerObject* {
                PlayerObject* ptr = new(std::nothrow) PlayerObject();
                return ptr;
                };

            // manual deallocation for `alloc()`
            usertype["free"] =
                [](PlayerObject* self) {
                delete self;
                };
		});
}