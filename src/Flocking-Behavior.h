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
		}
		SetNextLeader();
		m_LeaderPosition = m_LeaderBoid->GetBoidKinematicData().Position;
	}
	~Flocking(){}
	void Update();
	void Draw();
	void SetLeaderPosition(ofVec2f i_Position);
	void SetNextLeader();

private:
	std::vector<Boid*> m_Boids;
	Boid* m_LeaderBoid;
	SeekSteeringArrive* m_Leader;
	int m_NumberOfBoidsInFlock;
	float m_AvoidWeight = 2;
	float m_MatchWeight = 1;
	float m_CenterWeight = 3;
	float m_LookWeight = 2;
	int m_LeaderIndex = 0;
	ofVec2f m_LeaderPosition;
};