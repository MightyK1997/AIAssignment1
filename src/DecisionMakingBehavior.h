#pragma once
#include "Action.h"

class DecisionMakingBehavior
{
	public:
		virtual Action* GetAction() = 0;
};
