#include "Seek-Steering-Arrive.h"
#include "of3dPrimitives.h"

#define PI 3.14159265358979323846

SeekSteeringArrive::SeekSteeringArrive(float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget)
{
	m_Boid.SetBoidPosition(ofVec2f(20, ofGetHeight() - 20));
	m_MaxSpeed = i_MaxSpeed;
	m_MaxAcceleration = i_MaxAcceleration;
	m_TimeToTarget = i_TimeToTarget;
	initialPosition = m_Boid.GetBoidKinematicData().Position;
	finalPosition = initialPosition;
}

DynamicSteeringOutput SeekSteeringArrive::GetSteering(Kinematic i_Character, Kinematic i_Target, float i_maxSpeed, float i_TargetRadius, float i_SlowRadius, float i_MaxAcceleration, float i_TimeToTarget)
{
	DynamicSteeringOutput steering;
	auto direction = i_Target.Position - i_Character.Position;
	auto distance = direction.length();
	float targetSpeed = 0;
	if (distance < i_TargetRadius) return steering;
	if (distance > i_SlowRadius) targetSpeed = i_maxSpeed;
	else{ targetSpeed = i_maxSpeed * (distance / i_SlowRadius);	}
	ofVec2f targetVelocity = direction.normalize() * targetSpeed;
	steering.LinearAcceleration = targetVelocity - i_Character.Velocity;
	steering.LinearAcceleration /= i_TimeToTarget;
	if (steering.LinearAcceleration.length() > i_MaxAcceleration)
	{
		steering.LinearAcceleration = (steering.LinearAcceleration.normalize() * i_MaxAcceleration);
	}
	steering.AngularAcceleration = GetSteering(i_Character, 0.5f, 0.5f, 5.0f, 0.5f, i_TimeToTarget, i_Target).AngularAcceleration;
	return steering;
}

float MapToRange(float i_Rotation)
{
	while (i_Rotation < -PI || i_Rotation > PI)
	{
		if (i_Rotation < -PI)
		{
			i_Rotation += (2 * PI);
		}
		else if (i_Rotation > PI)
		{
			i_Rotation -= (2 * PI);
		}
	}
	return i_Rotation;
}

DynamicSteeringOutput SeekSteeringArrive::GetSteering(Kinematic i_Character, float i_MaxAngularSpeed, float i_MaxAngularAcceleration, float i_SlowAngle, float i_TargetAngle, float i_TimeToTarget, Kinematic i_Target)
{
	DynamicSteeringOutput steering;
	auto rotation = i_Target.Orientation - i_Character.Orientation;
	rotation = MapToRange(rotation);
	float targetRotationSpeed = 0;
	if (abs(rotation) < i_TargetAngle) return steering;
	if (abs(rotation) > i_SlowAngle) targetRotationSpeed = i_MaxAngularSpeed;
	else { targetRotationSpeed = i_MaxAngularSpeed * (rotation / i_SlowAngle); }
	steering.AngularAcceleration = (targetRotationSpeed - i_Character.Rotation) / i_TimeToTarget;
	if (steering.AngularAcceleration > i_MaxAngularAcceleration) { steering.AngularAcceleration = m_MaxAcceleration; }
	steering.LinearAcceleration = ofVec2f(0,0);
	return steering;
}

void SeekSteeringArrive::Update()
{
	Kinematic targetKinematicData;
	targetKinematicData.Position = finalPosition;
	targetKinematicData.Orientation = 10;
	m_Boid.Update(GetSteering(m_Boid.GetBoidKinematicData(), targetKinematicData, m_MaxSpeed, 10.f, 15.f, m_MaxAcceleration, m_TimeToTarget));
}

void SeekSteeringArrive::SetPosition(ofVec2f i_Position)
{
 	finalPosition = i_Position;
}

void SeekSteeringArrive::Draw()
{
	m_Boid.Draw();
}
