#include <quartz/core/LuaManager.hpp>
#include <quartz/core/TypeRef.hpp>
#include <Geode/loader/Log.hpp>
#include <Geode/loader/Mod.hpp>
#include <Geode/ui/Notification.hpp>
#include <algorithm>
#include <exception>
#include <string>

namespace
{
constexpr std::string sanitizeStringSpaces(const std::string& str)
{
	std::string sanitized;

	for (size_t i = 0; i < str.size(); ++i)
	{
		char c = str[i];

		if (c == ' ')
		{
			sanitized += '_';
		}
		else
		{
			sanitized += c;
		}
	}

	return sanitized;
}
}

#define CREATE_TYPE_REF(BASE, TYPE)														\
	BASE.new_usertype<quartz::TypeRef<TYPE>>(                                           \
		(sanitizeStringSpaces(#TYPE) + std::string("_ref")),							\
		sol::no_constructor,                                                            \
		"value", sol::property(&quartz::TypeRef<TYPE>::get, &quartz::TypeRef<TYPE>::set)\
	)

namespace quartz
{

void LuaManager::createScriptsDir()
{
	m_scriptsDir = geode::Mod::get()->getSettingValue<std::filesystem::path>("scripts-dir");

	if (!std::filesystem::exists(m_scriptsDir))
	{
		try
		{
			std::filesystem::create_directories(m_scriptsDir);
			geode::log::debug("Created missing scripts directory | location: \"{}\"", m_scriptsDir);
		}
		catch (const std::exception& e)
		{
			geode::log::error("Failed to create missing scripts directory | what: {}", e.what());
		}
	}
}

void LuaManager::openLibs()
{
	if (m_openedLibs)
	{
		return;
	}

	using enum sol::lib;
	m_luaState.open_libraries(base, string, table, math, utf8);

	m_openedLibs = true;
}

void LuaManager::createGlobals()
{
	if (!m_openedLibs)
	{
		return;
	}

	sol::table quartz = m_luaState.create_table();
	sol::table quartz_hook_ids = m_luaState.create_table();
	sol::table cocos2d = m_luaState.create_table();
	m_luaState["quartz"] = quartz;
	m_luaState["quartz"]["hook_ids"] = quartz_hook_ids;
	m_luaState["cocos2d"] = cocos2d;

	quartz.set_function(
		"add_hook_callback",
		[this](quartz::HookIDs id, sol::protected_function&& callback)
		{
			auto& hookCallbacks = getHookCallbacks(id);
			hookCallbacks.emplace_back(std::move(callback));
			geode::log::debug("	Added callback for hook id #{} | registry_index: {} | current total: {}",
							  static_cast<int>(id), hookCallbacks.back().registry_index(), hookCallbacks.size());
		}
	);

	CREATE_TYPE_REF(quartz, bool);
	CREATE_TYPE_REF(quartz, char);
	CREATE_TYPE_REF(quartz, signed char);
	CREATE_TYPE_REF(quartz, unsigned char);
	CREATE_TYPE_REF(quartz, wchar_t);
	CREATE_TYPE_REF(quartz, char16_t);
	CREATE_TYPE_REF(quartz, char32_t);
	CREATE_TYPE_REF(quartz, short);
	CREATE_TYPE_REF(quartz, unsigned short);
	CREATE_TYPE_REF(quartz, int);
	CREATE_TYPE_REF(quartz, unsigned int);
	CREATE_TYPE_REF(quartz, long);
	CREATE_TYPE_REF(quartz, unsigned long);
	CREATE_TYPE_REF(quartz, long long);
	CREATE_TYPE_REF(quartz, unsigned long long);
	CREATE_TYPE_REF(quartz, float);
	CREATE_TYPE_REF(quartz, double);
	CREATE_TYPE_REF(quartz, long double);
}

void LuaManager::cleanup()
{
	if (!m_openedLibs)
	{
		return;
	}

	for (auto& callbacks : m_hookCallbacks)
	{
		callbacks.clear();
	}

	m_luaState.collect_garbage();
	m_luaState = sol::state();

	m_openedLibs = false;
}

void LuaManager::loadScripts()
{
	auto errorNotif = geode::Notification::create("Failed to load scripts", geode::NotificationIcon::Error);

	if (!m_openedLibs)
	{
		if (errorNotif)
		{
			errorNotif->show();
		}

		return;
	}

	for (auto& callbacks : m_hookCallbacks)
	{
		callbacks.clear();
	}

	geode::log::debug("Populating script dictionary...");

	try
	{
		auto start = startTimer();

		for (const auto& entry : std::filesystem::directory_iterator(m_scriptsDir))
		{
			if (entry.path().extension() == ".lua")
			{
				m_scriptDict.push_back(entry.path());
				geode::log::debug("	Added script \"{}\" | current total: {}",
								  entry.path().filename().string(), m_scriptDict.size());
			}
		}

		endTimer(start);
	}
	catch (const std::filesystem::filesystem_error& error)
	{
		geode::log::error("	Failed to add scripts due to filesystem error | what: {}",
						  error.what());
		
		m_scriptDict.clear();
		
		if (errorNotif)
		{
			errorNotif->show();
		}

		return;
	}

	std::ranges::sort(m_scriptDict);

	geode::log::debug("Attempting to run {}...",
					  (m_scriptDict.size() > 1) ? "scripts" : "script");
	
	auto start = startTimer();

	for (auto it = m_scriptDict.begin(); it != m_scriptDict.end();)
	{
		sol::protected_function_result scriptResult;

		try
		{
			sol::table env = m_luaState.create_table();
			scriptResult = m_luaState.load_file((*it).string())(env);
		}
		catch (const std::exception& e)
		{
			geode::log::error("	Script \"{}\" caused an exception | what: {}",
							  (*it).filename().string(), e.what());
			it = m_scriptDict.erase(it);
			continue;
		}

		if (!scriptResult.valid())
		{
			sol::error err = scriptResult;
			geode::log::error("	Script \"{}\" invalid | what: {}",
							  (*it).filename().string(), err.what());
			it = m_scriptDict.erase(it);
			continue;
		}

		++it;
	}

	endTimer(start);
	
	std::string statusLog;
	geode::NotificationIcon statusIcon;
	size_t dictSize = m_scriptDict.size();

	if (dictSize > 0)
	{
		statusLog = fmt::format("{} {} {}",
								m_scriptsLoadedOnce ? "Reloaded" : "Loaded", dictSize, (dictSize > 1) ? "scripts" : "script");
		statusIcon = geode::NotificationIcon::Success;
	}
	else
	{
		statusLog = "No valid scripts";
		statusIcon = geode::NotificationIcon::Warning;
	}

	geode::Notification::create(statusLog, statusIcon, 3.f)->show();
	
	m_scriptDict.clear();

	if (!m_scriptsLoadedOnce)
	{
		m_scriptsLoadedOnce = true;
	}
}

// private
void LuaManager::endTimer(const std::chrono::steady_clock::time_point& start)
{
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	geode::log::debug("Took {}s", elapsed.count());
}

} // quartz