#include "basic-motion.h"
#include "of3dPrimitives.h"


BasicMotion::BasicMotion(Boid* i_Boid, float i_MaxSpeed)
{
	m_Boid = (i_Boid != nullptr) ? i_Boid : new Boid();
	//m_Boid->SetBoidOrientation(0.f);
	//m_Boid->SetBoidPosition(ofVec2f(25, ofGetHeight() - 25));
	m_MaxSpeed = i_MaxSpeed;
	initialPosition = m_Boid->GetBoidKinematicData().Position;
}

KinematicSteeringOutput BasicMotion::GetSteering(Kinematic i_Boid, Kinematic i_Target, float i_MaxSpeed)
{
	KinematicSteeringOutput outputKinematicSteering;
	outputKinematicSteering.Velocity = ofVec2f(glm::cos(i_Boid.Orientation), glm::sin(i_Boid.Orientation)) * i_MaxSpeed;;
	return outputKinematicSteering;
}

float BasicMotion::GetNewOrientation(float i_CurrentOrientation, ofVec2f i_Velocity)
{
	return (i_Velocity.length() > 0) ? atan2(i_Velocity.y, i_Velocity.x) : i_CurrentOrientation;
}

void BasicMotion::Update()
{
	Kinematic targetKinematicData;
	m_Boid->Update(GetSteering(m_Boid->GetBoidKinematicData(), targetKinematicData, m_MaxSpeed));
}

void BasicMotion::Draw()
{
	m_Boid->Draw();
}
