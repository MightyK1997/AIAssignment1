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
			boid->SetBoidPosition(ofVec2f(ofGetWidth()/ 2, ofGetHeight() / 2));
			m_Boids.push_back(boid);
		}
	}
	~Flocking(){}
	void Update();
	void Draw();
	void SetLeaderPosition(ofVec2f i_Position);

private:
	std::vector<Boid*> m_Boids;
	SeekSteeringArrive* m_Leader;
	int m_NumberOfBoidsInFlock;
	float m_AvoidWeight = 1.f;
	float m_MatchWeight = 0.6f;
	float m_CenterWeight = 1.5f;
};