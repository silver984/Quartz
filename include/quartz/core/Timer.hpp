#pragma once
#include <chrono>

namespace quartz {

std::chrono::steady_clock::time_point startTimer();
double endTimer(const std::chrono::steady_clock::time_point& start);

} // namespace quartz