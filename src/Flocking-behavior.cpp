#include "Flocking-behavior.h"
#include "DynamicSeperation.h"
#include "DynamicArrive.h"
#include "DynamicVelocityMatch.h"
#include "DynamicLookWhereYouAreGoing.h"
#include "DynamicWander.h"

void Flocking::Update()
{
	ofVec2f flockCenter;
	for (int i=0;i<m_Boids.size();i++)
	{
		if (i == m_LeaderIndex) continue;
		flockCenter += m_Boids[i]->GetBoidKinematicData().Position;
	}
	flockCenter /= m_Boids.size();

	for (int i = 0; i < m_Boids.size(); i++)
	{
		auto m_Boid = m_Boids[i];
		DynamicSeperation seperation;
		VelocityMatch velocity;
		DynamicArrive arrive;
		DLookWhereYouAreGoing lwyg;
		Kinematic target;
		DynamicWander wander;
		if (i == m_LeaderIndex)
		{
			auto avoidSteering = seperation.GetSteering(m_Boid->GetBoidKinematicData(), &(m_Boids[0]), m_Boids.size(), 100, 500000, 500000);
			target.Position = m_LeaderPosition;
			auto arriveSteering = arrive.GetSteering(m_Boid->GetBoidKinematicData(), target, 100.0f, 5.0f, 50.0f, 100.0f, 0.1f);
			auto lookSteering = lwyg.GetSteering(m_Boid->GetBoidKinematicData());
			m_Boid->Update((avoidSteering * (m_AvoidWeight / 2)) + (arriveSteering * m_CenterWeight) + (lookSteering * m_LookWeight));
			continue;
		}
		if ((i==m_Leader2Index) && m_EnableSecondLeader)
		{
			auto avoidSteering = seperation.GetSteering(m_Boid->GetBoidKinematicData(), &(m_Boids[0]), m_Boids.size(), 100, 500000, 500000);
			auto wanderSteering = wander.GetSteering(m_Boid->GetBoidKinematicData());
			m_Boid->Update(((avoidSteering * (m_AvoidWeight / 2))) + (wanderSteering * m_CenterWeight));
			continue;
		}
		if (m_EnableSecondLeader)
		{
			auto closest = (m_Boid->GetBoidKinematicData().Position - m_LeaderBoid->GetBoidKinematicData().Position).length() < (m_Boid->GetBoidKinematicData().Position - m_Leader2->GetBoidKinematicData().Position).length() ?
				m_LeaderBoid->GetBoidKinematicData().Position : m_Leader2->GetBoidKinematicData().Position;
			flockCenter += closest;
			flockCenter /= 2;
		}
		else
		{
			flockCenter += m_LeaderBoid->GetBoidKinematicData().Position;
			flockCenter /= 2;
		}
		target.Position = flockCenter;
		auto avoidSteering = seperation.GetSteering(m_Boid->GetBoidKinematicData(), &(m_Boids[0]), m_Boids.size(), 100, 500000, 500000);
		auto velocitySteering = velocity.GetSteering(m_Boid->GetBoidKinematicData(), target);
		auto arriveSteering = arrive.GetSteering(m_Boid->GetBoidKinematicData(), target, 50, 5, 50, 100, 0.1);
		auto lookSteering = lwyg.GetSteering(m_Boid->GetBoidKinematicData());
		m_Boid->Update((avoidSteering * m_AvoidWeight) + (velocitySteering * m_MatchWeight) + (arriveSteering * m_CenterWeight) + (lookSteering * m_LookWeight));
	}
}

void Flocking::Draw()
{
	for (auto& m_Boid:m_Boids)
	{
		m_Boid->Draw();
	}
}

void Flocking::SetLeaderPosition(ofVec2f i_Position)
{
	m_LeaderPosition = i_Position;
}

void Flocking::SetNextLeader()
{
	for (auto m_Boid : m_Boids)
	{
		m_Boid->SetBoidColor(ofVec3f(0, 0, 0));
	}
	m_LeaderIndex = (m_LeaderIndex++)%m_Boids.size();
	m_LeaderBoid = m_Boids[m_LeaderIndex];
	m_LeaderBoid->SetBoidColor(ofVec3f(0, 0, 255));
}
