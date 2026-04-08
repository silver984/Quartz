#include <quartz/BindingsManager.hpp>

namespace quartz {

BindingsManager& BindingsManager::get() {
	static BindingsManager instance;
	return instance;
}

void BindingsManager::queue(BindingLevel level, std::function<void()>&& callback) {
	m_allQueued[level].emplace_back(std::move(callback));
}

void BindingsManager::runQueue() {
	auto& allEntries = m_allQueued[BindingLevel::Entry];
	auto& allUnits = m_allQueued[BindingLevel::Unit];

	for (auto& entry : allEntries) {
		entry();
	}

	allEntries.clear();

	for (auto& unit : allUnits) {
		unit();
	}

	allUnits.clear();
}

} // namespace quartz