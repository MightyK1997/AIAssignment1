#pragma once
#include <vector>
#include <functional>

template <typename T>
class PriorityQueue
{
	PriorityQueue<T>() = default;
	PriorityQueue<T>(std::function<void()> i_ComparatorFunction);
	~PriorityQueue() = default;
private:
	std::vector<T> m_UnderlyingQueue;
};
