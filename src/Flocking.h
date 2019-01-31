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
		m_Leader = new SeekSteeringArrive(5, 50, 10);
		for (size_t i = 0; i < i_NumberOfBoidsInFlock; i++)
		{
			Boid* boid = new Boid();
			boid->SetBoidPosition(ofVec2f(ofGetWidth()/ 2 + (100 * i), ofGetHeight() / 2 + (10*i)));
			m_Boids.push_back(boid);
			//m_BoidswLeader.push_back(boid);
		}
		//m_BoidswLeader.push_back(m_Leader);
	}
	~Flocking(){}
	void Update();
	void Draw();
	void SetLeaderPosition(ofVec2f i_Position);

private:
	std::vector<Boid*> m_Boids;
	std::vector<Boid*> m_BoidswLeader;
	SeekSteeringArrive* m_Leader;
	int m_NumberOfBoidsInFlock;
	float m_AvoidWeight = 5.5f;
	float m_MatchWeight = 0.6f;
	float m_CenterWeight = 1.f;
};