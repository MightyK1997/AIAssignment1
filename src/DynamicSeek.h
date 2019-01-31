#pragma once
#include "DataTypes.h"


class DynamicSeek
{
public:
	DynamicSteeringOutput GetSteering(Kinematic i_Character, Kinematic i_Target, float i_MaxAcceleration);
};