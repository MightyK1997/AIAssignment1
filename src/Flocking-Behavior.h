#pragma once
#include "Boid.h"
#include "of3dPrimitives.h"
#include "Seek-Steering-Arrive.h"

class Flocking
{
public:
	Flocking(){}
	Flocking(int i_NumberOfBoidsInFlock) : m_NumberOfBoidsInFlock(i_NumberOfBoidsInFlock)
	{
		for (size_t i = 0; i < i_NumberOfBoidsInFlock; i++)
		{
			Boid* boid = new Boid();
			boid->SetBoidPosition(ofVec2f(ofGetWidth()/ 2 + (100 * i), ofGetHeight() / 2 + (10*i)));
			m_Boids.push_back(boid);
		}
		SetNextLeader();
		m_LeaderPosition = m_LeaderBoid->GetBoidKinematicData().Position;
	}
	~Flocking(){}
	void Update();
	void Draw();
	void SetLeaderPosition(ofVec2f i_Position);
	void SetNextLeader();
	void EnableSecondLeader(bool i_Choice) 
	{ 
		m_EnableSecondLeader = i_Choice;
		if (i_Choice)
		{
			for (auto m_Boid : m_Boids)
			{
				m_Boid->SetBoidColor(ofVec3f(0, 0, 0));
			}
			m_LeaderBoid = m_Boids[m_LeaderIndex];
			m_LeaderBoid->SetBoidColor(ofVec3f(0, 0, 255));
			m_Leader2Index = (m_Leader2Index++) % m_Boids.size();
			m_Leader2 = m_Boids[m_Leader2Index];
			m_Leader2->SetBoidColor(ofVec3f(0, 255, 0));
		}
		else
		{
			for (auto m_Boid : m_Boids)
			{
				m_Boid->SetBoidColor(ofVec3f(0, 0, 0));
			}
			m_LeaderBoid = m_Boids[m_LeaderIndex];
			m_LeaderBoid->SetBoidColor(ofVec3f(0, 0, 255));
		}
	}

private:
	std::vector<Boid*> m_Boids;
	Boid* m_LeaderBoid;
	Boid* m_Leader2;
	int m_NumberOfBoidsInFlock;
	float m_AvoidWeight = 2;
	float m_MatchWeight = 1;
	float m_CenterWeight = 3;
	float m_LookWeight = 2;
	int m_LeaderIndex = 0;
	int m_Leader2Index = 1;
	ofVec2f m_LeaderPosition;
	bool m_EnableSecondLeader = false;
};