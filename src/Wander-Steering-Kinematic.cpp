#include "Wander-Steering-Kinematic.h"

KinematicSteeringOutput WanderKinematic::getSteering(Kinematic i_Character, float i_MaxSpeed, float i_MaxRotation)
{
	KinematicSteeringOutput steering;
	steering.Velocity = ofVec2f(cos(i_Character.Orientation), sin(i_Character.Orientation)) * i_MaxSpeed;
	steering.Rotation = i_MaxRotation * (((double)rand() / (RAND_MAX)) - ((double)rand() / (RAND_MAX)));
	return steering;
}

void WanderKinematic::Update()
{
	m_Boid.Update(getSteering(m_Boid.GetBoidKinematicData(), 5, 10 ));
}

void WanderKinematic::Draw()
{
	m_Boid.Draw();
}
