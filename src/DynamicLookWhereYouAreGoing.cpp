#include "DynamicLookWhereYouAreGoing.h"

DynamicSteeringOutput DLookWhereYouAreGoing::GetSteering(Kinematic i_Character)
{
	DynamicSteeringOutput steering;
	if (i_Character.Velocity.length() == 0) return steering;
	Kinematic target;
	target.Orientation = atan2(-i_Character.Velocity.x, i_Character.Velocity.y);
	steering = m_Arrive.GetSteering(i_Character, 2, 2, 0.5f, 0.15f, 10, target);
	return steering;
}
