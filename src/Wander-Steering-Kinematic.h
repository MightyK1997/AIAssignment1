#pragma once
#include "Boid.h"
#include "of3dPrimitives.h"

class WanderKinematic
{
public:
	WanderKinematic() 
	{
		m_Boid.SetBoidPosition(ofVec2f(20, 200));
	}
	~WanderKinematic() {}

	KinematicSteeringOutput getSteering(Kinematic i_Character, float i_MaxSpeed, float i_MaxRotation);
	void Update();
	void Draw();

private:
	Boid m_Boid;

};
