#pragma once
#include <vector>
#include <functional>

template <typename T>
class PriorityQueue
{
public:
	PriorityQueue<T>(std::function<bool(T, T)> i_ComparatorFunction) : m_ComparatorFunction(i_ComparatorFunction) {};

public:
	bool Insert(const T& i_Element);
	bool Remove(const T& i_Element);
	bool Contains(const T& i_Element) const;
	bool Empty() const { return m_UnderlyingQueue.empty(); }
	bool Clear();
	T& operator[](std::size_t idx) { return m_UnderlyingQueue[idx]; }
	const T& operator[](std::size_t idx) const { return m_UnderlyingQueue[idx]; }
	const std::vector<T>& GetUnderlyingQueue() { return m_UnderlyingQueue; }

private:
	std::vector<T> m_UnderlyingQueue;
	std::function<bool(T,T)> m_ComparatorFunction;
};

template <typename T>
bool PriorityQueue<T>::Insert(const T& i_Element)
{
	m_UnderlyingQueue.push_back(i_Element);
	std::sort(m_UnderlyingQueue.begin(), m_UnderlyingQueue.end(), m_ComparatorFunction);
	return true;
}

template <typename T>
bool PriorityQueue<T>::Remove(const T& i_Element)
{
	auto beginSize = m_UnderlyingQueue.size();
	auto it = m_UnderlyingQueue.begin();
	while (it != m_UnderlyingQueue.end())
	{
		if ((*it) == i_Element)
		{
			it = m_UnderlyingQueue.erase(it);
		}
		++it;
	}
	return beginSize == m_UnderlyingQueue.size();
}

template <typename T>
bool PriorityQueue<T>::Contains(const T& i_Element) const
{
	for (auto element : m_UnderlyingQueue)
	{
		if (element == i_Element)
		{
			return true;
		}
	}
	return false;
}

template <typename T>
bool PriorityQueue<T>::Clear()
{
	for (auto i : m_UnderlyingQueue)
	{
		if (i != nullptr) delete(i);
	}
	return true;
}
