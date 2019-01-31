#include "DynamicVelocityMatch.h"

DynamicSteeringOutput VelocityMatch::GetSteering(Kinematic i_Character, Kinematic i_Target)
{
	DynamicSteeringOutput steering;
	steering.LinearAcceleration = i_Target.Velocity - i_Character.Velocity;
	steering.LinearAcceleration /= m_TimeToTarget;
	if (steering.LinearAcceleration.length() > m_MaxAcceleration)
	{
		steering.LinearAcceleration = steering.LinearAcceleration.normalize() * m_MaxAcceleration;
	}
	steering.AngularAcceleration = 0;
	return steering;
}
