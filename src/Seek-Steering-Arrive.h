#pragma once
#include "Boid.h"


class SeekSteeringArrive
{
public:
	SeekSteeringArrive()
	{
		m_Boid = new Boid();
	}
	SeekSteeringArrive(Boid* i_Boid, float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget);
	~SeekSteeringArrive() {}
	void SetBoid(Boid* i_Boid) { m_Boid = i_Boid; }
	void Update();
	void SetPosition(ofVec2f i_Position);
	ofVec2f GetPosition() { return m_Boid->GetBoidKinematicData().Position; }
	bool HasArrived();
	void Draw();

private:
	Boid* m_Boid = nullptr;
	float m_MaxSpeed;
	float m_MaxAcceleration;
	float m_TimeToTarget;
	bool b_HasArrived;
	ofVec2f initialPosition = ofVec2f(0, 0);
	ofVec2f finalPosition;
};
