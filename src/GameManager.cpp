#include "GameManager.h"

bool GameManager::CheckIfPlayerIsInRange()
{
	return (GetDistanceToPlayer(m_WanderNPC->GetBoidKinematicData().Position) < 50);
}

bool GameManager::CheckIfPlayerIsInRanges()
{
	return (GetDistanceToPlayer(m_WanderNPC->GetBoidKinematicData().Position) < 100);
}
