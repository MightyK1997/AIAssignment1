#pragma once
#include <vector>
#include "DecisionMakingConstants.h"

class Tick;
class Action;
class Task
{
public:
	virtual TaskStatus OnEnter(Tick* i_tick) = 0;
	virtual TaskStatus OnExit(Tick* i_tick) = 0;
	virtual TaskStatus OnOpen(Tick* i_tick) = 0;
	virtual TaskStatus OnClose(Tick* i_tick) = 0;
	virtual TaskStatus OnExecute(Tick* i_tick) = 0;
	virtual std::vector<Task*> GetChildren() { return m_ChildTasks; }
	virtual uint8_t GetID() { return m_Id; }
	virtual size_t GetChildrenCount() { return m_ChildTasks.size(); }
	virtual Action* GetAction() = 0;
	virtual TaskStatus Run(Tick* i_tick) = 0;

	bool operator ==(Task& i_Other);
	bool operator!=(Task& i_Other);

protected:
	std::vector<Task*> m_ChildTasks;
	uint8_t m_Id;
};

inline bool Task::operator==(Task& i_Other)
{
	return (m_Id == i_Other.m_Id);
}

inline bool Task::operator!=(Task& i_Other)
{
	return !(m_Id == i_Other.m_Id);
}
