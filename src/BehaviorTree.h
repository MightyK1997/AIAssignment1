#pragma once
#include "DecisionMakingBehavior.h"
#include "Blackboard.h"
#include "Tick.h"

class BehaviorTree : public DecisionMakingBehavior
{
public:
	virtual Action* GetAction() override;
	BehaviorTree(Task* i_Root) : m_Root(i_Root) { m_Tick = new Tick(this, m_Blackboard); }
private:
	Blackboard* m_Blackboard = new Blackboard();
	Tick* m_Tick;
	Task* m_Root = nullptr;
};
