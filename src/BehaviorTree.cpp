#include "BehaviorTree.h"

#include "Task.h"
#include "Tick.h"
Action* BehaviorTree::GetAction()
{
	auto result = m_Root->Run(m_Tick);
	//if (result == e_FAILURE)
	//{
	//	return nullptr;
	//}
	return m_Blackboard->GetAction("Active");
}
