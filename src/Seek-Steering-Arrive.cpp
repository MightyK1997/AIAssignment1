#include "Seek-Steering-Arrive.h"
#include "of3dPrimitives.h"
#include "DynamicArrive.h"
#include "DynamicLookWhereYouAreGoing.h"

SeekSteeringArrive::SeekSteeringArrive(float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget)
{
	m_Boid.SetBoidPosition(ofVec2f(20, ofGetHeight() - 20));
	m_MaxSpeed = i_MaxSpeed;
	m_MaxAcceleration = i_MaxAcceleration;
	m_TimeToTarget = i_TimeToTarget;
	initialPosition = m_Boid.GetBoidKinematicData().Position;
	finalPosition = initialPosition;
}

void SeekSteeringArrive::Update()
{
	Kinematic targetKinematicData;
	targetKinematicData.Position = finalPosition;
	DynamicArrive dArrive;
	DLookWhereYouAreGoing lwyg;
	auto dArriveOutput = dArrive.GetSteering(m_Boid.GetBoidKinematicData(), targetKinematicData, m_MaxSpeed, 25.f, 45.f, m_MaxAcceleration, m_TimeToTarget);
	auto dLookWhereYouAreGoingOutput = lwyg.GetSteering(m_Boid.GetBoidKinematicData());
	m_Boid.Update(dArriveOutput + dLookWhereYouAreGoingOutput);
}

void SeekSteeringArrive::SetPosition(ofVec2f i_Position)
{
 	finalPosition = i_Position;
}

void SeekSteeringArrive::Draw()
{
	m_Boid.Draw();
}
