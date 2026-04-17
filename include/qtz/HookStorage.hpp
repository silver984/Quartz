#pragma once
#include <Geode/loader/Hook.hpp>
#include <qtz/core/StringMap.hpp>
#include <sol/sol.hpp>
#include <vector>
#include <string_view>
#include <memory>
#include <cstdint>

namespace qtz {

class HookStorage final {
public:
	HookStorage(const HookStorage&) = delete;
	HookStorage(HookStorage&&) = delete;
	HookStorage& operator=(const HookStorage&) = delete;
	HookStorage& operator=(HookStorage&&) = delete;

	[[nodiscard]] static HookStorage& get();
	[[nodiscard]] std::vector<sol::function>* getLuaCallbacks(std::string_view hookName);
	void storeLuaCallback(std::string_view hookName, sol::function callback);
	void storeGeodeHook(std::shared_ptr<geode::Hook> hook);
	void resetState();
	void autoEnableGeodeHooks();
	void setGeodeHooksPriority(int32_t priority);

private:	
	HookStorage() = default;
	~HookStorage() = default;

	struct Hook final {
		std::vector<sol::function> luaCallbacks;
		std::weak_ptr<geode::Hook> geodeHook;
	};

	StringMap<Hook> m_hooks;
};

} // namespace qtz