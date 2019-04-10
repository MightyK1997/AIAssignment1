#include "Wander-Steering-Dynamic.h"

void WanderDynamic::Update()
{
	m_Boid->Update(wander.GetSteering(m_Boid->GetBoidKinematicData()));
}

void WanderDynamic::Draw()
{
	m_Boid->Draw();
}


