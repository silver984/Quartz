#pragma once

#include <Geode/loader/GameEvent.hpp>
#include <Geode/loader/ModEvent.hpp>
#include <Geode/loader/Mod.hpp>
#include <quartz/core/Templates.hpp>

#define ON_QUARTZ_LOADED				$on_mod(Loaded)
#define ON_GD_LOADED					$on_game(Loaded)
#define ON_GD_EXITING					$on_game(Exiting)
#define NON_STATIC_FN(CLASS, FN)		[](CLASS* self, auto... args) { return self->CLASS::FN(args...); }
#define ENABLE_HOOK_PRIORITY(CLASS, FN) quartz::enableHookPriority(self, #CLASS "::" #FN)