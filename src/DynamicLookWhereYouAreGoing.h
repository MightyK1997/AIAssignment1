#pragma once
#include "DataTypes.h"
#include "DynamicAlign.h"

class DLookWhereYouAreGoing
{
public:
	DynamicSteeringOutput GetSteering(Kinematic i_Character);

private:
	DynamicAlign m_Arrive;

};