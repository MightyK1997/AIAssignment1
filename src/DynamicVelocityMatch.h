#pragma once
#include "DataTypes.h"


class VelocityMatch
{
public:
	DynamicSteeringOutput GetSteering(Kinematic i_Character, Kinematic i_Target);

private:
	float m_MaxAcceleration = 50.f;
	float m_TimeToTarget = 0.1f;
};