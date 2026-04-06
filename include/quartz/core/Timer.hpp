#pragma once
#include <chrono>

namespace quartz {

/// @brief Start a timer
/// @return Timepoint when this timer was started
inline std::chrono::steady_clock::time_point startTimer() {
	return std::chrono::high_resolution_clock::now();
}

/// @param start The timepoint when a timer was started
/// @return Elapsed in seconds
inline double endTimer(const std::chrono::steady_clock::time_point& start) {
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	return elapsed.count();
}

} // namespace quartz