#pragma once
#include "DataTypes.h"

class DynamicWander
{
public:
	DynamicSteeringOutput GetSteering(Kinematic i_Character);

private:
	float wanderOffset = 50.0f ;
	float wanderRadius = 50.0f;
	float wanderRate = 50.0f;
	float wanderOrientation = 0;
	float maxAcceleration = 10.0f;
};