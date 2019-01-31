#pragma once
#include "Boid.h"


class SeekSteeringArrive
{
public:
	SeekSteeringArrive() {}
	SeekSteeringArrive(float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget);
	~SeekSteeringArrive() {}
	void Update();
	void SetPosition(ofVec2f i_Position);
	ofVec2f GetPosition() { return m_Boid.GetBoidKinematicData().Position; }
	void Draw();

private:
	Boid m_Boid;
	float m_MaxSpeed;
	float m_MaxAcceleration;
	float m_TimeToTarget;
	ofVec2f initialPosition = ofVec2f(0, 0);
	ofVec2f finalPosition;
};
