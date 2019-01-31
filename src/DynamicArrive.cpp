#include "DynamicArrive.h"

DynamicSteeringOutput DynamicArrive::GetSteering(Kinematic i_Character, Kinematic i_Target, float i_maxSpeed, float i_TargetRadius, float i_SlowRadius, float i_MaxAcceleration, float i_TimeToTarget)
{
	DynamicSteeringOutput steering;
	auto direction = i_Target.Position - i_Character.Position;
	auto distance = direction.length();
	float targetSpeed = 0;
	if (distance < i_TargetRadius) return steering;
	if (distance > i_SlowRadius) targetSpeed = i_maxSpeed;
	else { targetSpeed = i_maxSpeed * (distance / i_SlowRadius); }
	ofVec2f targetVelocity = direction.normalize() * targetSpeed;
	steering.LinearAcceleration = targetVelocity - i_Character.Velocity;
	steering.LinearAcceleration /= i_TimeToTarget;
	if (steering.LinearAcceleration.length() > i_MaxAcceleration)
	{
		steering.LinearAcceleration = (steering.LinearAcceleration.normalize() * i_MaxAcceleration);
	}
	steering.AngularAcceleration = 0.0f;
	return steering;
}
