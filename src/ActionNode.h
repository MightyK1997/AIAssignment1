#pragma once
#include "DecisionTreeNode.h"
#include "Action.h"

class ActionNode : DecisionTreeNode
{
public:
	DecisionTreeNode* MakeDecision() override;
	Action* GetNodeAction() const { return m_NodeAction; }

private:
	Action* m_NodeAction;
};
