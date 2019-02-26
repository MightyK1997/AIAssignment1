#pragma once
#include "Boid.h"
#include "DynamicPathFollow.h"
#include "Dijkstra.h"

class Graph;
class AStarPathFollow
{
//public:
//	AStarPathFollow(){}
//	AStarPathFollow(Heuristic i_Heuristic, float i_AStarWeight, float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget) : m_maxSpeed(i_MaxSpeed), m_MaxAcceleration(i_MaxAcceleration), m_TimeToTarget(i_TimeToTarget)
//	{
//		m_Boid.SetBoidPosition(ofVec2f(0, 0));
//		m_Boid.SetBoidColor(ofVec3f(0, 0, 255));
//		m_LocalAStar = new AStar(i_Heuristic, i_AStarWeight);
//		m_StartNode = new Node(0, 0);
//	}
//	~AStarPathFollow() = default;
//	void Update();
//	void Draw();
//	void SetPath(Path i_Path) { m_Path = i_Path; }
//	void CreateGraph(float i_Width, float i_Height);
//	void AddNewTargetForBoid(float i_X, float i_Y);
//	void CreateAndSetPathToFollow();
//
//private:
//	Boid m_Boid;
//	Path m_Path;
//	DynamicPathFollow follow;
//	Graph* m_WorldGraph = nullptr;
//	AStar* m_LocalAStar = nullptr;
//	Node* m_EndNode = nullptr;
//	Node* m_StartNode = nullptr;
//	float m_maxSpeed, m_MaxAcceleration, m_TimeToTarget;
};
