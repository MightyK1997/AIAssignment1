#include "Tick.h"
#include "CheckDistanceTask.h"

TaskStatus BooleanTask::OnEnter(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus BooleanTask::OnExit(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus BooleanTask::OnOpen(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus BooleanTask::OnClose(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus BooleanTask::OnExecute(Tick* i_Tick)
{
	return m_CheckFunction() ? e_SUCCESS : e_FAILURE;
}

TaskStatus BooleanTask::Run(Tick* i_Tick)
{
	OnEnter(i_Tick);
	i_Tick->GetBlackboard()->SetTask("Running", this);
	return OnExecute(i_Tick);
}