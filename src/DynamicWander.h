#pragma once
#include "DataTypes.h"

class DynamicWander
{
public:
	DynamicSteeringOutput GetSteering(Kinematic i_Character);

private:
	float wanderOffset = 1 ;
	float wanderRadius = 5;
	float wanderRate = 1;
	float wanderOrientation = 0.5f;
	float maxAcceleration = 11;
};