#include "Blackboard.h"


void Blackboard::SetAction(std::string i_Key, Action* i_Action)
{
	m_Actions[i_Key] = i_Action;
}

void Blackboard::SetTask(std::string i_Key, Task* i_Task)
{
	m_Tasks[i_Key] = i_Task;
}

Action* Blackboard::GetAction(const std::string& i_Key)
{
	return m_Actions.find(i_Key) != m_Actions.end() ? m_Actions[i_Key] : nullptr;
}

Task* Blackboard::GetTask(const std::string& i_Key)
{
	return m_Tasks.find(i_Key) != m_Tasks.end() ? m_Tasks[i_Key] : nullptr;
}
