#pragma once
#include "DecisionMakingBehavior.h"
#include <vector>
#include "Task.h"
#include "Blackboard.h"

class Tick
{
public:
	Tick() = default;
	Tick(DecisionMakingBehavior* i_BehaviorTreeRoot, Blackboard* i_Blackboard):m_BehaviorTree(i_BehaviorTreeRoot), m_Blackboard(i_Blackboard){}
	~Tick() = default;

	void OpenTask(Task* i_NewTask);
	void CloseTask(Task* i_Task);
	Blackboard* GetBlackboard() const { return m_Blackboard; }
private:
	DecisionMakingBehavior* m_BehaviorTree = nullptr;
	Blackboard* m_Blackboard = nullptr;
	std::vector<Task*> m_OpenTasks;
};

inline void Tick::OpenTask(Task* i_NewTask)
{
	m_OpenTasks.push_back(i_NewTask);
}

inline void Tick::CloseTask(Task* i_Task)
{
	auto it = m_OpenTasks.begin();
	while(it!=m_OpenTasks.end())
	{
		if ((*it) == i_Task)
		{
			it = m_OpenTasks.erase(it);
			continue;
		}
		++it;
	}
}
