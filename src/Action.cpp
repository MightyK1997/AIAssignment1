#include "Action.h"

bool Action::CanInterrupt()
{
	return true;
}

bool Action::CanInterruptAction(Action* i_Action)
{
	return true;
}

bool Action::CanDoBoth(Action* i_Action)
{
	return true;
}

bool Action::IsComplete()
{
	return true;
}

void Action::ExecuteAction()
{
}
