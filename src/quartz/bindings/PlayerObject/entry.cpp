#include <pch.hpp>
#include <qtz/modified/PlayerObject.hpp>

$execute {
	auto& bindingsManager = qtz::BindingsManager::get();
    bindingsManager.queue(
        qtz::BindingLevel::Entry,
        []() {
            auto state = qtz::LuaManager::get().luaState();

            state.new_usertype<PlayerObject>(
                "PlayerObject",
                sol::constructors<PlayerObject()>(),
                sol::base_classes, sol::bases<AnimatedSpriteDelegate, GameObject>()
            );

            sol::usertype<PlayerObject> usertype = state["PlayerObject"];

            // TODO: custom fields

            usertype["alloc"] =
                []() -> PlayerObject* {
                PlayerObject* ptr = new(std::nothrow) PlayerObject();
                return ptr;
                };

            usertype["free"] =
                [](PlayerObject* self) {
                delete self;
                };
        }
    );
}