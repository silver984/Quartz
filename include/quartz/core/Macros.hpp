#pragma once

#include <Geode/loader/GameEvent.hpp>
#include <Geode/loader/ModEvent.hpp>
#include <Geode/loader/Mod.hpp>
#include <quartz/core/Templates.hpp>

#define ON_QUARTZ_LOADED    $on_mod(Loaded)
#define ON_GD_LOADED        $on_game(Loaded)
#define ON_GD_EXITING       $on_game(Exiting)

#define QUARTZ_ORIGINAL(CLASS, FN)      \
    [](auto* self, auto... args)        \
    {                                   \
        return self->CLASS::FN(args...);\
    }

#define QUARTZ_RUN_HOOK_CHAIN(TYPE, NAMESPACE, CLASS, FN, ...)\
    quartz::runHookChain<TYPE>(#NAMESPACE "." #CLASS "." #FN, this, QUARTZ_ORIGINAL(CLASS, FN), ##__VA_ARGS__)

#define QUARTZ_ENABLE_HOOK_PRIORITY(CLASS, FN)\
    quartz::enableHookPriority(self, #CLASS "::" #FN)