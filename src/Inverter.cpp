#include "Inverter.h"
#include "Tick.h"
#include <RtAudio.h>

TaskStatus Inverter::OnEnter(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus Inverter::OnExit(Tick* i_Tick)
{
	return e_SUCCESS;
}

TaskStatus Inverter::OnOpen(Tick* i_Tick)
{
	i_Tick->GetBlackboard()->SetChild(0);
	return e_SUCCESS;
}

TaskStatus Inverter::OnClose(Tick* i_Tick)
{
	return e_SUCCESS;
}


TaskStatus Inverter::OnExecute(Tick* i_Tick)
{
	const auto childStatus = m_ChildTasks[0]->Run(i_Tick);
	return childStatus == e_SUCCESS ? e_FAILURE : e_SUCCESS;
}

TaskStatus Inverter::Run(Tick* i_Tick)
{
	OnOpen(i_Tick);
	return OnExecute(i_Tick);
}