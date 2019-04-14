#pragma once
#include "Task.h"
#include <functional>

class BooleanTask : public Task
{
public:
	BooleanTask() = default;
	BooleanTask(std::function<bool()> i_Function, Task* i_TrueTask, Task* i_FalseTask) : m_CheckFunction(i_Function) , m_TrueTask(i_TrueTask),m_FalseTask(i_FalseTask){}
	~BooleanTask() = default;
	virtual TaskStatus OnEnter(Tick* i_Tick) override;
	virtual TaskStatus OnExit(Tick* i_Tick) override;
	virtual TaskStatus OnOpen(Tick* i_Tick) override;
	virtual TaskStatus OnClose(Tick* i_Tick) override;
	virtual TaskStatus OnExecute(Tick* i_Tick) override;
	virtual Action* GetAction() override { return nullptr; }
	virtual TaskStatus Run(Tick* i_Tick) override;
	void SetFunction(std::function<bool()> i_Function) { m_CheckFunction = i_Function; }
	void SetTasks(Task* i_TrueTask, Task* i_FalseTask)
	{
		m_TrueTask = i_TrueTask;
		m_FalseTask = i_FalseTask;
	}

private:
	std::function<bool()> m_CheckFunction;
	Task* m_TrueTask;
	Task* m_FalseTask;
};
