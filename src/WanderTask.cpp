#include "Tick.h"
#include "WanderTask.h"

TaskStatus ActionTask::OnEnter(Tick* i_Tick)
{
	i_Tick->GetBlackboard()->SetAction("Active", m_Action);
	return e_SUCCESS;
}

TaskStatus ActionTask::OnExit(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus ActionTask::OnOpen(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus ActionTask::OnClose(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus ActionTask::OnExecute(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus ActionTask::Run(Tick* i_Tick)
{
	OnEnter(i_Tick);
	return OnExecute(i_Tick);
}