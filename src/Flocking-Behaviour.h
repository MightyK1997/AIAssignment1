#pragma once
#include "DataTypes.h"

class FlockingBehavior
{
public:
	DynamicSteeringOutput GetSteering(Kinematic* i_Boids[100] );
};
