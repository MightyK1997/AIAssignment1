#include "DynamicSeperation.h"
#include <algorithm>

DynamicSteeringOutput DynamicSeperation::GetSteering(Kinematic i_Character, Boid* i_Targets[100], float i_NumberOfTargets, float i_DistanceThreshold, float i_DecayCoefficient, float i_MaxAcceleration)
{
	DynamicSteeringOutput steering;

	for (size_t i = 0; i < i_NumberOfTargets; i++)
	{
		ofVec2f direction = i_Character.Position - i_Targets[i]->GetBoidKinematicData().Position ;
		float distance = direction.length();
		float strength = 0;
		if (distance >= i_DistanceThreshold) continue;
		else
		{
			 strength = std::min(i_DecayCoefficient / (distance * distance), i_MaxAcceleration);
			 direction = direction.normalize();
			 steering.LinearAcceleration += strength * direction;
		}
	}
	return steering;
}
