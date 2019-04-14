#pragma once
#include <map>
#include "Action.h"
#include "Task.h"


class Blackboard
{
public:
	Blackboard() = default;
	~Blackboard() = default;
	void SetAction(std::string i_Key, Action* i_Action);
	void SetTask(std::string i_Key, Task* i_Task);
	void SetChild(uint8_t i_CurrentRunningChild) { m_RunningChild = i_CurrentRunningChild; }
	Action* GetAction(const std::string& i_Key);
	Task* GetTask(const std::string& i_Key);
	uint8_t GetChild() const { return m_RunningChild; }
private:
	Action* m_ActiveAction;
	uint8_t m_RunningChild;
	std::map<std::string, Task*> m_Tasks;
	std::map<std::string, Action*> m_Actions;

};
