#include "Action.h"

bool Action::CanInterrupt()
{
	return true;
}

bool Action::CanInterrupt(Action* i_Action)
{
	return true;
}

bool Action::CanDoBoth(Action* i_Action)
{
	return true;
}

bool Action::IsComplete()
{
	return false;
}

void Action::ExecuteAction()
{
	m_Function();
}

void Action::IncrementQueuedTime(float i_DeltaTime)
{
	m_QueuedTime += i_DeltaTime;
}
