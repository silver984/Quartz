#include <pch.hpp>
#include <string>

$execute {
    auto& bindingsManager = quartz::BindingsManager::get();
    bindingsManager.queue(
        quartz::BindingLevel::Entry,
        []() {
            auto state = quartz::LuaManager::get().luaState();
            sol::table quartzTable = state["quartz"].get_or_create<sol::table>();
            quartzTable["hook"] =
                [](std::string name, sol::function callback) {
                quartz::HookStorage::get().storeLuaCallback(name, std::move(callback));
                };
        }
    );
}