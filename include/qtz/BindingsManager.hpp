#pragma once
#include <qtz/core/EnumArray.hpp>
#include <functional>
#include <vector>
#include <memory>

namespace qtz {

enum class BindingLevel : int {
	Entry,
	Unit,
	Count
};

class BindingsManager final {
public:
	BindingsManager(const BindingsManager&) = delete;
	BindingsManager(BindingsManager&&) = delete;
	BindingsManager& operator=(const BindingsManager&) = delete;
	BindingsManager& operator=(BindingsManager&&) = delete;

	[[nodiscard]] static BindingsManager& get();
	void queue(BindingLevel level, std::function<void()>&& callback);
	void runQueue();

private:
	BindingsManager() = default;
	~BindingsManager() = default;
	
	EnumArray<std::vector<std::function<void()>>, BindingLevel, BindingLevel::Count> m_allQueued;
};

} // namespace qtz