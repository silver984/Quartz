#pragma once
#include <chrono>

namespace qtz {

std::chrono::steady_clock::time_point startTimer();
double endTimer(const std::chrono::steady_clock::time_point& start);

} // namespace qtz