#include "AStarPathFollow.h"
#include "DynamicPathFollow.h"

void AStarPathFollow::Update()
{
	m_Boid.Update(follow.GetSteering(m_Path, m_Boid.GetBoidKinematicData(), m_maxSpeed, 5.0f, 10.0f, m_MaxAcceleration, m_TimeToTarget));
}

void AStarPathFollow::Draw()
{
	m_Boid.Draw();
}
