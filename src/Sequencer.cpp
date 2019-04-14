#pragma once
#include "Sequencer.h"
#include "Tick.h"

TaskStatus Sequencer::OnEnter(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus Sequencer::OnExit(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus Sequencer::OnOpen(Tick* i_Tick)
{
	i_Tick->GetBlackboard()->SetChild(0);
	return e_SUCCESS;
}

TaskStatus Sequencer::OnClose(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus Sequencer::OnExecute(Tick* i_Tick)
{
	for (int i = 0; i < m_ChildTasks.size(); i++)
	{
		Task* childTask = GetChildren()[i];
		TaskStatus childStatus = childTask->Run(i_Tick);
		if (childStatus != e_SUCCESS)
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

Action* Sequencer::GetAction()
{
	return nullptr;
}

TaskStatus Sequencer::Run(Tick* i_Tick)
{
	OnOpen(i_Tick);
	return OnExecute(i_Tick);
}