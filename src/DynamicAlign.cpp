#include "DynamicAlign.h"
#define PI 3.14159265358979323846

float MapToRange(float i_Rotation)
{
	/*if (i_Rotation == 0) return 0;
	float someVal = abs(i_Rotation);
	float mapValue = i_Rotation / someVal;
	return mapValue * (someVal - floor(abs(i_Rotation) / PI) * PI);*/
	while (i_Rotation > PI)
		i_Rotation -= 2 * PI;
	while (i_Rotation < -PI)
		i_Rotation += 2 * PI;

	return i_Rotation;
}


DynamicSteeringOutput DynamicAlign::GetSteering(Kinematic i_Character, float i_MaxAngularSpeed, float i_MaxAngularAcceleration, float i_SlowAngle, float i_TargetAngle, float i_TimeToTarget, Kinematic i_Target)
{
	DynamicSteeringOutput steering;
	auto rotation = i_Target.Orientation - i_Character.Orientation;
	rotation = MapToRange(rotation);
	float rotationSize = abs(rotation);
	float targetRotationSpeed = 0;
	if (rotationSize < i_TargetAngle) return steering;
	if (rotationSize > i_SlowAngle) targetRotationSpeed = i_MaxAngularSpeed;
	else { targetRotationSpeed = i_MaxAngularSpeed * (rotationSize / i_SlowAngle); }
	targetRotationSpeed *= rotation / rotationSize;
	steering.AngularAcceleration = (targetRotationSpeed - i_Character.Rotation) / i_TimeToTarget;
	if (steering.AngularAcceleration > i_MaxAngularAcceleration) { steering.AngularAcceleration = m_MaxAcceleration; }
	steering.LinearAcceleration = ofVec2f(0, 0);
	return steering;
}
