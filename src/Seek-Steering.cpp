#include "Seek-Steering.h"
#include "of3dPrimitives.h"

SeekSteering::SeekSteering(float i_MaxSpeed)
{
	m_Boid.SetBoidPosition(ofVec2f(20, ofGetHeight() - 20));
	m_MaxSpeed = i_MaxSpeed;
	initialPosition = m_Boid.GetBoidKinematicData().Position;
	finalPosition = initialPosition;
}

KinematicSteeringOutput SeekSteering::GetSteering(Kinematic i_Boid, Kinematic i_Target, float i_MaxSpeed)
{
	KinematicSteeringOutput outputKinematicSteering;
	outputKinematicSteering.Velocity = i_Target.Position - i_Boid.Position;

	outputKinematicSteering.Velocity = outputKinematicSteering.Velocity.normalize() * i_MaxSpeed;
	outputKinematicSteering.Rotation = 0;
	//m_Boid.SetBoidOrientation(GetNewOrientation(i_Boid.Orientation, outputKinematicSteering.Velocity));
	return outputKinematicSteering;
}

float SeekSteering::GetNewOrientation(float i_CurrentOrientation, ofVec2f i_Velocity)
{
	return (i_Velocity.length() > 0) ? atan2(i_Velocity.y, i_Velocity.x) : i_CurrentOrientation;
}

void SeekSteering::Update()
{
	Kinematic targetKinematicData;
	ofVec2f currentPosition = m_Boid.GetBoidKinematicData().Position;
	targetKinematicData.Position = finalPosition;
	m_Boid.Update(GetSteering(m_Boid.GetBoidKinematicData(), targetKinematicData, m_MaxSpeed));
}

void SeekSteering::SetPosition(ofVec2f i_Position)
{
	finalPosition = i_Position;
}

void SeekSteering::Draw()
{
	m_Boid.Draw();
}
