#pragma once
#include "DataTypes.h"


class DynamicFace
{
public:
	DynamicSteeringOutput GetSteering(Kinematic i_Character, Kinematic i_Target);
};
