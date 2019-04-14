#pragma once
#include "Task.h"

class Inverter : public Task
{
	virtual TaskStatus OnEnter(Tick* i_Tick) override;
	virtual TaskStatus OnExit(Tick* i_Tick) override;
	virtual TaskStatus OnOpen(Tick* i_Tick) override;
	virtual TaskStatus OnClose(Tick* i_Tick) override;
	virtual TaskStatus OnExecute(Tick* i_Tick) override;
	virtual Action* GetAction() override { return nullptr; }
	virtual TaskStatus Run(Tick* i_Tick) override;
};
