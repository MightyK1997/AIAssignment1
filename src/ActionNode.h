#pragma once
#include "DecisionTreeNode.h"
#include "Action.h"

class ActionNode : DecisionTreeNode
{
public:
	DecisionTreeNode* MakeDecision() override;
	Action* GetAction() override { return m_NodeAction; }

private:
	Action* m_NodeAction = nullptr;
};
