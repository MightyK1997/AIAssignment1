#include "DynamicLookWhereYouAreGoing.h"

DynamicSteeringOutput DLookWhereYouAreGoing::GetSteering(Kinematic i_Character)
{
	DynamicSteeringOutput steering;
	if (i_Character.Velocity.length() == 0) return steering;
	Kinematic target;
	target.Orientation = atan2(i_Character.Velocity.y, i_Character.Velocity.x);
	steering = m_Arrive.GetSteering(i_Character, 10, 50, 5.f, 0.01f, 0.1, target);
	return steering;
}
