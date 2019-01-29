#pragma once
#include "Boid.h"
#include "Seek-Steering-Arrive.h"
#include "DynamicWander.h"

class WanderDynamic
{
public:
	WanderDynamic() {}
	~WanderDynamic() {}

	void Update();
	void Draw();

private:
	Boid m_Boid;
	SeekSteeringArrive m_Arrive;
	DynamicWander wander;
};