#pragma once
#include "Task.h"
#include <functional>

class BooleanTask : public Task
{
public:
	virtual TaskStatus OnEnter(Tick* i_Tick) override;
	virtual TaskStatus OnExit(Tick* i_Tick) override;
	virtual TaskStatus OnOpen(Tick* i_Tick) override;
	virtual TaskStatus OnClose(Tick* i_Tick) override;
	virtual TaskStatus OnExecute(Tick* i_Tick) override;
	virtual Action* GetAction() override { return nullptr; }
	virtual TaskStatus Run(Tick* i_Tick) override;
	void SetFunction(std::function<bool()> i_Function) { m_CheckFunction = i_Function; }

private:
	std::function<bool()> m_CheckFunction;
};
