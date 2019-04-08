#pragma once

class DecisionTreeNode
{
public:
	virtual DecisionTreeNode* MakeDecision() = 0;
};