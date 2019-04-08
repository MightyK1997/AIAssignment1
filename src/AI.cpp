#include "AI.h"

void AI::Update(float i_DeltaTime) const
{
	Action* newAction = m_DecisionMakingBehavior->GetAction();
	if (newAction != nullptr)
	{
		m_AIActionManager->AddToPending(newAction);
	}
	m_AIActionManager->Update(i_DeltaTime);
}