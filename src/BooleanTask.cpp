#include "Tick.h"
#include "BooleanTask.h"

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
	auto result = OnExecute(i_Tick);
	if(result == e_SUCCESS)
	{
		result = m_TrueTask->Run(i_Tick);
	}
	else
	{
		result = m_FalseTask->Run(i_Tick);
	}
	return result;

}