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
		m_Boid = new Boid();
		m_Boid->SetBoidPosition(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2));
	}
	~WanderDynamic() {}
	bool HasArrived() { return false; }
	void SetBoid(Boid* i_Boid) { m_Boid = i_Boid; }
	void Update();
	void Draw();

private:
	Boid* m_Boid = nullptr;
	SeekSteeringArrive m_Arrive;
	DynamicWander wander;
};