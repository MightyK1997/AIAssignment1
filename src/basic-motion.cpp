#include "basic-motion.h"
#include "of3dPrimitives.h"

BasicMotion::BasicMotion(float i_MaxSpeed)
{
	m_Boid.SetBoidPosition(ofVec2f(20, ofGetHeight() - 20));
	m_MaxSpeed = i_MaxSpeed;
	screenPositions.push_back(ofVec2f(ofGetWidth() - 20, ofGetHeight() - 20));
	screenPositions.push_back(ofVec2f(ofGetWidth() - 20, 20));
	screenPositions.push_back(ofVec2f(20, 20));
	screenPositions.push_back(m_Boid.GetBoidKinematicData().Position);
	initialPosition = m_Boid.GetBoidKinematicData().Position;
}

KinematicSteeringOutput BasicMotion::GetSteering(Kinematic i_Boid, Kinematic i_Target, float i_MaxSpeed)
{
	KinematicSteeringOutput outputKinematicSteering;
	outputKinematicSteering.Velocity = i_Target.Position - i_Boid.Position;

	outputKinematicSteering.Velocity = outputKinematicSteering.Velocity.normalize() * i_MaxSpeed;
	outputKinematicSteering.Rotation = 0;
	//m_Boid.SetBoidOrientation(GetNewOrientation(i_Boid.Orientation, outputKinematicSteering.Velocity));
	return outputKinematicSteering;
}

float BasicMotion::GetNewOrientation(float i_CurrentOrientation, ofVec2f i_Velocity)
{
	return (i_Velocity.length() > 0) ? atan2(i_Velocity.y, i_Velocity.x) : i_CurrentOrientation;
}

void BasicMotion::Update()
{
	Kinematic targetKinematicData;
	ofVec2f currentPosition = m_Boid.GetBoidKinematicData().Position;
	targetKinematicData.Position = screenPositions[0];
	if ((currentPosition.x > screenPositions[0].x))
	{
		m_Boid.SetBoidOrientation(90);
		targetKinematicData.Position = screenPositions[1];
	}
	if ( (currentPosition.y < screenPositions[1].y))
	{
		m_Boid.SetBoidOrientation(180);
		targetKinematicData.Position = screenPositions[2];
	}
	if ((currentPosition.x < screenPositions[2].x))
	{
		m_Boid.SetBoidOrientation(270);
		targetKinematicData.Position = screenPositions[3];
	}

	
	m_Boid.Update(GetSteering(m_Boid.GetBoidKinematicData(), targetKinematicData, m_MaxSpeed));
}

void BasicMotion::Draw()
{
	m_Boid.Draw();
}
