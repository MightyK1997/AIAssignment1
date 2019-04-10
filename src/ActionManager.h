#pragma once
#include "Action.h"
#include <queue>
#include "PriorityQueue.h"

class ActionManager
{
public:
	ActionManager() = default;
	~ActionManager() = default;
	void AddToPending(Action* i_Action);
	void RemoveFromPending(Action* i_Action);
	void AddToActive(Action* i_Action);
	void RemoveFromActive(Action* i_Action);
	void Start();
	void Update(float i_DeltaTime);

private:
	bool CheckCanDoBoth(Action* i_Action);
	PriorityQueue<Action*> m_PendingActions;
	PriorityQueue<Action*> m_ActiveActions;
};
