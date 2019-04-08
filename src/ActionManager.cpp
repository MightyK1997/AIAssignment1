#include "ActionManager.h"

namespace
{
	bool SortHelperFunction(Action* a1, Action* a2) { return a1->GetPriority() > a2->GetPriority(); }
	void RemoveElementFromList(std::vector<Action*>& i_List, Action* i_Node)
	{
		auto it = i_List.begin();
		while (it != i_List.end())
		{
			if ((*it) == i_Node)
			{
				it = i_List.erase(it);
				continue;
			}
			++it;
		}
	}
}

void ActionManager::AddToPending(Action* i_Action)
{
	m_PendingActions.push_back(i_Action);
	std::sort(m_PendingActions.begin(), m_PendingActions.end(), SortHelperFunction);
}

void ActionManager::RemoveFromPending(Action* i_Action)
{
	RemoveElementFromList(m_PendingActions, i_Action);
}

void ActionManager::AddToActive(Action* i_Action)
{
	m_ActiveActions.push_back(i_Action);
	std::sort(m_ActiveActions.begin(), m_ActiveActions.end(), SortHelperFunction);
}

void ActionManager::RemoveFromActive(Action* i_Action)
{
	RemoveElementFromList(m_ActiveActions, i_Action);
}

void ActionManager::Update(float i_DeltaTime)
{
	Action* currentAction = nullptr;
	for(auto action : m_PendingActions)
	{
		action->IncrementQueuedTime(i_DeltaTime);
		if (!m_ActiveActions.empty()) { currentAction = m_ActiveActions[0]; }
		if ((currentAction!=nullptr) && (currentAction->GetPriority() > action->GetPriority()))
		{
			continue;
		}
		if(action->CanInterrupt(currentAction))
		{
			m_ActiveActions.clear();
			AddToActive(action);
		}
		if (action->GetQueuedTime() > action->GetExpiryTime()) { RemoveFromPending(action); }
		if (!CheckCanDoBoth(action)) continue;
		AddToActive(action);
		RemoveFromPending(action);
	}
	for(auto activeAction : m_ActiveActions)
	{
		if (activeAction->IsComplete())
		{
			RemoveFromActive(activeAction);
			continue;
		}
		activeAction->ExecuteAction();
	}
}

bool ActionManager::CheckCanDoBoth(Action* i_Action)
{
	for(auto action : m_ActiveActions)
	{
		if(!(i_Action->CanDoBoth(action))) return false;
	}
	return true;
}
