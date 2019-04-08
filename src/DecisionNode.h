#pragma once
#include "DecisionTreeNode.h"


class DecisionNode:DecisionTreeNode
{
public:
	DecisionTreeNode* MakeDecision();

private:
	bool IsTrue();
	DecisionTreeNode* GetBranch();
	DecisionTreeNode * m_TrueNode;
	DecisionTreeNode * m_FalseNode;
};
