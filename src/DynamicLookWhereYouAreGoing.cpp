#include "DynamicLookWhereYouAreGoing.h"

DynamicSteeringOutput DLookWhereYouAreGoing::GetSteering(Kinematic i_Character)
{
	DynamicSteeringOutput steering;
	if (i_Character.Velocity.length() == 0) return steering;
	Kinematic target;
	target.Orientation = atan2(i_Character.Velocity.y, i_Character.Velocity.x);
	steering = m_Arrive.GetSteering(i_Character, 5, 5, 5.f, 0.5f, 1, target);
	return steering;
}
