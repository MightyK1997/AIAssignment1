#include "DynamicSeek.h"

DynamicSteeringOutput DynamicSeek::GetSteering(Kinematic i_Character, Kinematic i_Target, float i_MaxAcceleration)
{
	DynamicSteeringOutput steering;
	steering.LinearAcceleration = i_Target.Position - i_Character.Position;
	steering.LinearAcceleration = steering.LinearAcceleration.normalize() * i_MaxAcceleration;
	steering.AngularAcceleration = 0;
	return steering;
}