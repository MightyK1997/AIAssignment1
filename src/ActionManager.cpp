#include "ActionManager.h"

void ActionManager::AddToPending(Action* i_action)
{
	m_PendingActions.emplace(i_action);
}

void ActionManager::RemoveFromPending(Action* i_action)
{
	m_PendingActions.pop();
}

void ActionManager::AddToActive(Action* i_action)
{
	m_ActiveActions.emplace(i_action);
}

void ActionManager::RemoveFromActive(Action* i_action)
{
	m_ActiveActions.pop();
}