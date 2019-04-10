#include "Seek-Steering-Arrive.h"
#include "of3dPrimitives.h"
#include "DynamicArrive.h"
#include "DynamicLookWhereYouAreGoing.h"

SeekSteeringArrive::SeekSteeringArrive(Boid* i_Boid, float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget)
{
	m_Boid = i_Boid;
	m_Boid->SetBoidPosition(ofVec2f(500, 500));
	m_Boid->SetBoidColor(ofVec3f(0, 0, 255));
	m_MaxSpeed = i_MaxSpeed;
	m_MaxAcceleration = i_MaxAcceleration;
	m_TimeToTarget = i_TimeToTarget;
	initialPosition = m_Boid->GetBoidKinematicData().Position;
	finalPosition = initialPosition;
}

void SeekSteeringArrive::Update()
{
	Kinematic targetKinematicData;
	targetKinematicData.Position = finalPosition;
	DynamicArrive dArrive;
	DLookWhereYouAreGoing lwyg;
	auto dArriveOutput = dArrive.GetSteering(m_Boid->GetBoidKinematicData(), targetKinematicData, m_MaxSpeed, 5.0f, 50.0f, m_MaxAcceleration, m_TimeToTarget);
	auto dLookWhereYouAreGoingOutput = lwyg.GetSteering(m_Boid->GetBoidKinematicData());
	m_Boid->Update(dArriveOutput + dLookWhereYouAreGoingOutput);
}

void SeekSteeringArrive::SetPosition(ofVec2f i_Position)
{
 	finalPosition = i_Position;
}

bool SeekSteeringArrive::HasArrived()
{
	if (m_Boid->GetBoidKinematicData().Position.distance(finalPosition) < 5)
	{
		return true;
	}
	return false;
}

void SeekSteeringArrive::Draw()
{
	m_Boid->Draw();
}
