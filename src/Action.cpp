#include "Action.h"

bool Action::CanInterrupt()
{
	return false;
}

bool Action::CanInterrupt(Action* i_Action)
{
	return m_CanInterrupt;
}

bool Action::CanDoBoth(Action* i_Action)
{
	return true;
}

bool Action::IsComplete()
{
	return m_CheckCompleteFunction();
}

void Action::ExecuteAction()
{
	m_Function();
}

void Action::IncrementQueuedTime(float i_DeltaTime)
{
	m_QueuedTime += i_DeltaTime;
}
