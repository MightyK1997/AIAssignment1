#pragma once
#include "Boid.h"
#include "Seek-Steering-Arrive.h"

class WanderDynamic
{
public:
	WanderDynamic() {}
	~WanderDynamic() {}

	DynamicSteeringOutput getSteering(Kinematic i_Character, float i_MaxSpeed, float i_MaxRotation);
	void Update();
	void Draw();

private:
	Boid m_Boid;
	SeekSteeringArrive m_Arrive;
};