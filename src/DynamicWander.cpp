#include "DynamicWander.h"
#include "DynamicFace.h"

float RandomBinomial()
{
	return (((double)rand() / (RAND_MAX)) - ((double)rand() / (RAND_MAX)));
}

DynamicSteeringOutput DynamicWander::GetSteering(Kinematic i_Character)
{
	DynamicFace face;
	DynamicSteeringOutput steering;
	float val = RandomBinomial();
	wanderOrientation += val * wanderRate;
	auto targetOrientation = wanderOrientation + i_Character.Orientation;
	auto target = i_Character.Position + (wanderOffset * ofVec2f(sin(i_Character.Orientation), cos(i_Character.Orientation)));
	target += wanderRadius * ofVec2f(sin(targetOrientation), cos(targetOrientation));
	Kinematic oTarget;
	oTarget.Position = target;
	oTarget.Orientation = targetOrientation;
	steering = face.GetSteering(i_Character, oTarget);
	steering.LinearAcceleration = maxAcceleration * ofVec2f(sin(i_Character.Orientation), cos(i_Character.Orientation));
	return steering;
}
