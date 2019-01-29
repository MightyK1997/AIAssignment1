#pragma once
#include "DataTypes.h"

class DynamicArrive
{
public:
	DynamicSteeringOutput GetSteering(Kinematic i_Character, Kinematic i_Target, float i_maxSpeed, float i_TargetRadius, float i_SlowRadius,
		float i_MaxAcceleration, float i_TimeToTarget);
};