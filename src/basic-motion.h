#pragma once
#include "Boid.h"

class BasicMotion
{
public:
	BasicMotion()
	{
		m_Boid = nullptr;
	}
	BasicMotion(Boid* i_Boid, float i_MaxSpeed);
	~BasicMotion() {}

	KinematicSteeringOutput GetSteering(Kinematic i_Boid, Kinematic i_Target, float i_MaxSpeed);
	float GetNewOrientation(float i_CurrentOrientation, ofVec2f i_Velocity);
	void Update();
	bool HasArrived() { return false; }
	void Draw();

private:
	Boid* m_Boid = nullptr;
	float m_MaxSpeed;
	std::vector<ofVec2f> screenPositions;
	ofVec2f initialPosition = ofVec2f(0,0);
};