#pragma once
#include "DataTypes.h"

class DynamicAlign
{
public:
	DynamicSteeringOutput GetSteering(Kinematic i_Character, float i_MaxAngularSpeed, float i_MaxAngularAcceleration, float i_SlowAngle,
		float i_TargetAngle, float i_TimeToTarget, Kinematic i_Target);


private:
	float m_MaxAcceleration = 200;
};