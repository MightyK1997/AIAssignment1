#pragma once
#include "Boid.h"
#include "Seek-Steering-Arrive.h"
#include "DynamicWander.h"
#include "of3dPrimitives.h"

class WanderDynamic
{
public:
	WanderDynamic()
	{
		m_Boid.SetBoidPosition(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2));
	}
	~WanderDynamic() {}

	void Update();
	void Draw();

private:
	Boid m_Boid;
	SeekSteeringArrive m_Arrive;
	DynamicWander wander;
};