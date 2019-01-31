#include "Flocking.h"
#include "DynamicSeperation.h"
#include "DynamicArrive.h"
#include "DynamicVelocityMatch.h"
#include "DynamicLookWhereYouAreGoing.h"

void Flocking::Update()
{
	m_Leader->Update();

	ofVec2f flockCenter;
	for (auto m_Boid:m_Boids)
	{
		flockCenter += m_Boid->GetBoidKinematicData().Position;
	}
	/*flockCenter += 1 * m_Leader->GetPosition();
	flockCenter /= (m_Boids.size() + 1);*/
	flockCenter /= m_Boids.size();
	flockCenter += m_Leader->GetPosition();
	flockCenter /= 2;

	for (auto& m_Boid : m_Boids)
	{
		DynamicSeperation seperation;
		VelocityMatch velocity;
		DynamicArrive arrive;
		DLookWhereYouAreGoing lwyg;
		Kinematic target;
		target.Position = flockCenter;
		auto avoidSteering = seperation.GetSteering(m_Boid->GetBoidKinematicData(), &(m_Boids[0]), m_Boids.size(), 100, 100.f, 500);
		auto velocitySteering = velocity.GetSteering(m_Boid->GetBoidKinematicData(), target);
		auto arriveSteering = arrive.GetSteering(m_Boid->GetBoidKinematicData(), target, 500, 50, 100, 100, 0.1);
		auto lookSteering = lwyg.GetSteering(m_Boid->GetBoidKinematicData());
		m_Boid->Update((avoidSteering * m_AvoidWeight) + (velocitySteering * m_MatchWeight) + (arriveSteering * m_CenterWeight) + lookSteering * 2);
	}
}

void Flocking::Draw()
{
	m_Leader->Draw();
	for (auto& m_Boid:m_Boids)
	{
		m_Boid->Draw();
	}
}

void Flocking::SetLeaderPosition(ofVec2f i_Position)
{
	m_Leader->SetPosition(i_Position);
}
