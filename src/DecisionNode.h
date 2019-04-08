#pragma once
#include "DecisionTreeNode.h"


class DecisionNode:DecisionTreeNode
{
public:
	virtual DecisionTreeNode* MakeDecision() override;
	virtual Action* GetAction() override { return nullptr; }

private:
	bool IsTrue();
	DecisionTreeNode* GetBranch();
	DecisionTreeNode* m_TrueNode = nullptr;
	DecisionTreeNode* m_FalseNode = nullptr;
};
