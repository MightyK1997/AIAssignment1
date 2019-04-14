#pragma once
#include "Task.h"

class Sequencer : public Task
{
public:
	virtual TaskStatus OnEnter(Tick* i_Tick) override;
	virtual TaskStatus OnExit(Tick* i_Tick) override;
	virtual TaskStatus OnOpen(Tick* i_Tick) override;
	virtual TaskStatus OnClose(Tick* i_Tick) override;
	virtual TaskStatus OnExecute(Tick* i_Tick) override;
	virtual Action* GetAction() override;
	virtual TaskStatus Run(Tick* i_Tick) override;
	void AddChild(Task* i_Task) { m_ChildTasks.push_back(i_Task); }
};