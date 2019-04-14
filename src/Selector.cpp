#include "Selector.h"
#include "Tick.h"

TaskStatus Selector::OnEnter(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus Selector::OnExit(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus Selector::OnOpen(Tick* i_Tick)
{
	i_Tick->GetBlackboard()->SetChild(0);
	return e_SUCCESS;
}

TaskStatus Selector::OnClose(Tick* i_Tick)
{
	return e_SUCCESS;
}


TaskStatus Selector::OnExecute(Tick* i_Tick)
{
	uint8_t runningChild = i_Tick->GetBlackboard()->GetChild();
	for (int i = runningChild; i < m_ChildTasks.size(); i++)
	{
		Task* childTask = GetChildren()[i];
		TaskStatus childStatus = childTask->Run(i_Tick);
		if (childStatus != e_FAILURE)
		{
			if (childStatus == e_RUNNING)
			{
				i_Tick->GetBlackboard()->SetChild(0);
			}
			return childStatus;
		}
	}
	return e_FAILURE;
}

TaskStatus Selector::Run(Tick* i_Tick)
{
	OnOpen(i_Tick);
	return OnExecute(i_Tick);
}