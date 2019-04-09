#pragma once
#include "DecisionTreeNode.h"
#include "Action.h"

class ActionNode : public DecisionTreeNode
{
public:
	DecisionTreeNode* MakeDecision() override;
	Action* GetAction() override { return m_NodeAction; }
	void SetAction(Action* i_Action) {
		m_NodeAction = i_Action;
	}
private:
	Action* m_NodeAction = nullptr;
};
