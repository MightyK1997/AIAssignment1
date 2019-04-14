#include "BehaviorTree.h"

#include "Task.h"
#include "Tick.h"
Action* BehaviorTree::GetAction()
{
	m_Root->Run(m_Tick);
	return m_Blackboard->GetAction("Active");
}
