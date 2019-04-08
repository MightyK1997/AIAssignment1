#pragma once
#include "Action.h"
#include <queue>

class ActionManager
{
public:
	ActionManager() = default;
	~ActionManager() = default;
	void AddToPending(Action* i_Action);
	void RemoveFromPending(Action* i_Action);
	void AddToActive(Action* i_Action);
	void RemoveFromActive(Action* i_Action);
	void Update(float i_DeltaTime);

private:
	bool CheckCanDoBoth(Action* i_Action);
	std::vector<Action*> m_PendingActions;
	std::vector<Action*> m_ActiveActions;
};
