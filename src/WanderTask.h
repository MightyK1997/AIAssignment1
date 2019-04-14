#pragma once
#include "Task.h"

class ActionTask : public Task
{
public:
	ActionTask() = default;
	ActionTask(Action* i_Action) : m_Action(i_Action) {}
	~ActionTask() = default;
	virtual TaskStatus OnEnter(Tick* i_Tick) override;
	virtual TaskStatus OnExit(Tick* i_Tick) override;
	virtual TaskStatus OnOpen(Tick* i_Tick) override;
	virtual TaskStatus OnClose(Tick* i_Tick) override;
	virtual TaskStatus OnExecute(Tick* i_Tick) override;
	virtual Action* GetAction() override { return m_Action; }
	virtual TaskStatus Run(Tick* i_Tick) override;
private:
	Action* m_Action;
};
