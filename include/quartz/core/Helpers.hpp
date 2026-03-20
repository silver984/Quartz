#pragma once

#include <Geode/modify/Modify.hpp>

namespace quartz
{
    void enableHookPriority(auto& self, const char* hook)
    {
        if (self.setHookPriority(hook, geode::Priority::Last))
        {
            geode::log::debug("Enabled hook priority for {}", hook);
        }
        else
        {
            geode::log::warn("Failed to enable hook priority for {}", hook);
        }
    }
}