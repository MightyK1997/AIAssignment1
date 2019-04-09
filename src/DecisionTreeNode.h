#pragma once
#include "Action.h"

class DecisionTreeNode
{
public:
	virtual DecisionTreeNode* MakeDecision() = 0;
	virtual Action* GetAction() = 0;
};
