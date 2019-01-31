#pragma once

#include "Boid.h"


class DynamicSeperation
{
public:
	DynamicSteeringOutput GetSteering(Kinematic i_Character, Boid* i_Targets[100], float i_NumberOfTargets, float i_DistanceThreshold, float i_DecayCoefficient, float i_MaxAcceleration);
};