#include <pch.hpp>
#include <string>

$execute {
    auto& bindingsManager = qtz::BindingsManager::get();
    bindingsManager.queue(
        qtz::BindingLevel::Entry,
        []() {
            auto state = qtz::LuaManager::get().luaState();
            sol::table quartzTable = state["quartz"].get_or_create<sol::table>();
            quartzTable["hook"] =
                [](std::string name, sol::function callback) {
                qtz::HookStorage::get().storeLuaCallback(name, std::move(callback));
                };
        }
    );
}