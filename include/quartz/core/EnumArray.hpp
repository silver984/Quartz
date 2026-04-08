#pragma once
#include <array>
#include <cstddef>

template <typename T, typename Enum, Enum N>
class EnumArray {
public:
	T& operator[](Enum e) {
		return data[static_cast<size_t>(e)];
	}

	const T& operator[](Enum e) const {
		return data[static_cast<size_t>(e)];
	}

private:
	std::array<T, static_cast<size_t>(N)> data;
};