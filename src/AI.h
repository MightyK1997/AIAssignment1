#pragma once
#include "ActionManager.h"
#include "DecisionMakingBehavior.h"

class AI
{
public:
	void Update(float i_DeltaTime) const;
	DecisionMakingBehavior* m_DecisionMakingBehavior = nullptr;
	ActionManager* m_AIActionManager = nullptr;
};
