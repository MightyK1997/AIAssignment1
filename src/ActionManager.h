#pragma once
#include "Action.h"
#include <queue>

class CompareFunctionClass
{
public:
	bool operator()(Action* i_Action1, Action* i_Action2) const { return i_Action1->GetPriority() > i_Action2->GetPriority(); }
};

class ActionManager
{
public:
	ActionManager() = default;
	~ActionManager() = default;
	void AddToPending(Action* i_action);
	void RemoveFromPending(Action* i_action);
	void AddToActive(Action* i_action);
	void RemoveFromActive(Action* i_action);
	void Update();

private:
	std::priority_queue<Action*, std::vector<Action*>, CompareFunctionClass> m_PendingActions;
	std::priority_queue<Action*, std::vector<Action*>, CompareFunctionClass> m_ActiveActions;
};
