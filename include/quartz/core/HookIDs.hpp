#pragma once

namespace quartz
{
enum HookIDs
{
	PlayerObject_init,
	PlayerObject_update,

	_COUNT
};

constexpr bool isValidHookID(HookIDs id)
{
	return id >= 0 && id < HookIDs::_COUNT;
}
} // quartz