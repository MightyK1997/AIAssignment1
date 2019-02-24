#pragma once
#include "Boid.h"
#include "DynamicPathFollow.h"


class AStarPathFollow
{
public:
	AStarPathFollow(){}
	AStarPathFollow(float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget) : m_maxSpeed(i_MaxSpeed), m_MaxAcceleration(i_MaxAcceleration), m_TimeToTarget(i_TimeToTarget)
	{
		m_Boid.SetBoidPosition(ofVec2f(0, 0));
		m_Boid.SetBoidColor(ofVec3f(0, 0, 255));
	}
	~AStarPathFollow() = default;
	void Update();
	void Draw();
	void SetPath(Path i_Path) { m_Path = i_Path; }

private:
	Boid m_Boid;
	Path m_Path;
	DynamicPathFollow follow;
	float m_maxSpeed, m_MaxAcceleration, m_TimeToTarget;
};
