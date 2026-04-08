#include <pch.hpp>
#include <quartz/modified/PlayerObject.hpp>

$execute {
	auto& bindingsManager = quartz::BindingsManager::get();
    bindingsManager.queue(
        quartz::BindingLevel::Entry,
        []() {
            auto state = quartz::LuaManager::get().luaState();

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