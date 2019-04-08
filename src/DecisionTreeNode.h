#pragma once
#include "Action.h"

class DecisionTreeNode
{
public:
	virtual DecisionTreeNode* MakeDecision();
	virtual Action* GetAction();
};
