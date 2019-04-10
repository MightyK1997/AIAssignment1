#include "ActionManager.h"

namespace
{
	bool SortHelperFunction(Action* a1, Action* a2) { return a1->GetPriority() > a2->GetPriority(); }
}

void ActionManager::AddToPending(Action* i_Action)
{
	if (m_PendingActions.Contains(i_Action)) return;
	m_PendingActions.Insert(i_Action);
}

void ActionManager::RemoveFromPending(Action* i_Action)
{
	m_PendingActions.Remove(i_Action);
}

void ActionManager::AddToActive(Action* i_Action)
{
	if (m_ActiveActions.Contains(i_Action)) return;
	m_ActiveActions.Insert(i_Action);
}

void ActionManager::RemoveFromActive(Action* i_Action)
{
	m_ActiveActions.Remove(i_Action);
}

void ActionManager::Start()
{
	m_PendingActions.SetComparatorFunction(SortHelperFunction);
	m_ActiveActions.SetComparatorFunction(SortHelperFunction);
}

void ActionManager::Update(float i_DeltaTime)
{
	Action* currentAction = nullptr;
	for(auto action : m_PendingActions.GetUnderlyingQueue())
	{
		action->IncrementQueuedTime(i_DeltaTime);
		if (!m_ActiveActions.Empty()) { currentAction = m_ActiveActions[0]; }
		if ((currentAction!=nullptr) && (currentAction->GetPriority() > action->GetPriority()))
		{
			continue;
		}
		if(action->CanInterrupt(currentAction))
		{
			m_ActiveActions.Clear();
			AddToActive(action);
		}
		if (action->GetQueuedTime() > action->GetExpiryTime()) { RemoveFromPending(action); }
		if (!CheckCanDoBoth(action)) continue;
		AddToActive(action);
		RemoveFromPending(action);
	}
	for(auto activeAction : m_ActiveActions.GetUnderlyingQueue())
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
	for(auto action : m_ActiveActions.GetUnderlyingQueue())
	{
		if(!(i_Action->CanDoBoth(action))) return false;
	}
	return true;
}
