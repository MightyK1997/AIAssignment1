#pragma once
#include "Boid.h"


class SeekSteeringArrive
{
public:
	SeekSteeringArrive() {}
	SeekSteeringArrive(float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget);
	~SeekSteeringArrive() {}

	DynamicSteeringOutput GetSteering(Kinematic i_Character, Kinematic i_Boid, float i_maxSpeed, float i_TargetRadius, float i_SlowRadius,
		float i_MaxAcceleration, float i_TimeToTarget);

	DynamicSteeringOutput GetSteering(Kinematic i_Character, float i_MaxAngularSpeed, float i_MaxAngularAcceleration, float i_SlowAngle,
		float i_TargetAngle, float i_TimeToTarget, Kinematic i_Target);

	void Update();
	void SetPosition(ofVec2f i_Position);
	void Draw();

private:
	Boid m_Boid;
	float m_MaxSpeed;
	float m_MaxAcceleration;
	float m_TimeToTarget;
	ofVec2f initialPosition = ofVec2f(0, 0);
	ofVec2f finalPosition;
};
