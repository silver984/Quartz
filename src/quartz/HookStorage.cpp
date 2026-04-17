#include <qtz/HookStorage.hpp>
#include <Geode/loader/Log.hpp>
#include <string>
#include <fmt/format.h>

#define DISCARD(call) static_cast<void>(call)

namespace qtz {

HookStorage& HookStorage::get() {
	static HookStorage instance;
	return instance;
}

std::vector<sol::function>* HookStorage::getLuaCallbacks(std::string_view hookName) {
	auto it = m_hooks.find(hookName);
	if (it == m_hooks.end()) {
		return nullptr;
	}

	return &it->second.luaCallbacks;
}

void HookStorage::storeLuaCallback(std::string_view hookName, sol::function callback) {
	if (!callback.valid()) {
		geode::log::error("Invalid Lua callback for \"{}\" hook", hookName);
		return;
	}

	auto it = m_hooks.find(hookName);
	if (it == m_hooks.end()) {
		geode::log::error("\"{}\" is not hookable", hookName);
		return;
	}

	it->second.luaCallbacks.emplace_back(std::move(callback));
}

void HookStorage::storeGeodeHook(std::shared_ptr<geode::Hook> hook) {
	if (!hook) {
		return;
	}

	// handle overloaded hooks
	size_t i = 1;
	std::string resolvedHookName = std::string(hook->getDisplayName());
	while (
		m_hooks.contains(
			i == 1
			? resolvedHookName
			: fmt::format("{}@{}", resolvedHookName, i)
		)
	) {
		++i;
	}

	auto [it, _] = m_hooks.emplace(resolvedHookName, Hook());
	it->second.geodeHook = hook;
	geode::log::trace("Stored hook: \"{}\"", it->first);
}

void HookStorage::resetState() {
	for (auto& [_, hook] : m_hooks) {
		hook.luaCallbacks.clear();

		if (auto geodeHook = hook.geodeHook.lock()) {
			DISCARD(geodeHook->disable());
		}
	}
}

void HookStorage::autoEnableGeodeHooks() {
	for (auto& [_, hook] : m_hooks) {
		if (auto geodeHook = hook.geodeHook.lock()) {
			if (hook.luaCallbacks.empty()) {
				DISCARD(geodeHook->disable());
			}
			else {
				DISCARD(geodeHook->enable());
			}
		}
	}
}

void HookStorage::setGeodeHooksPriority(int32_t priority) {
	for (auto& [_, hook] : m_hooks) {
		if (auto geodeHook = hook.geodeHook.lock()) {
			geodeHook->setPriority(priority);
		}
	}
}

} // namespace qtz