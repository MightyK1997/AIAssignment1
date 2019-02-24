#pragma once
#include "DynamicArrive.h"
#include "DataTypes-PathFinding.h"
#include "Boid.h"

class DynamicPathFollow
{
public:
	DynamicSteeringOutput GetSteering(Path i_Path, Kinematic i_Character, float i_maxSpeed, float i_TargetRadius, float i_SlowRadius, float i_MaxAcceleration, float i_TimeToTarget);

private:
	int currentPointCount = 0;
};
