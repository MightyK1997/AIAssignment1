#pragma once
#include "Boid.h"
#include "DynamicPathFollow.h"
#include "Dijkstra.h"

class Graph;
class AStarPathFollow
{
public:
	AStarPathFollow(){}
	AStarPathFollow(Heuristic i_Heuristic, Graph* i_WorldGraph, float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget) : 
		m_WorldGraph(i_WorldGraph), m_maxSpeed(i_MaxSpeed), m_MaxAcceleration(i_MaxAcceleration), m_TimeToTarget(i_TimeToTarget)
	{
		m_Boid.SetBoidPosition(ofVec2f(0, 0));
		m_Boid.SetBoidColor(ofVec3f(0, 0, 255));
		m_WorldGraph = i_WorldGraph;
		m_LocalAStar = new AStar(i_Heuristic);
		m_StartNode = new Node(std::numeric_limits<int>().max() - 1, m_Boid.GetBoidKinematicData().Position);
	}
	~AStarPathFollow() = default;
	void Update();
	void Draw();
	void UpdateGraph(Graph* i_Graph) { m_WorldGraph = i_Graph; }
	void SetStartNode(Node* i_Node) { m_StartNode = i_Node; }
	void AddNewTargetForBoid(float i_X, float i_Y);
	void AddNewTargetForBoid(Node* i_Node) { m_EndNode = i_Node; }
	void CreateAndSetPathToFollow();

private:
	Boid m_Boid;
	Path m_Path;
	DynamicPathFollow follow;
	Graph* m_WorldGraph = nullptr;
	AStar* m_LocalAStar = nullptr;
	Node* m_EndNode = nullptr;
	Node* m_StartNode = nullptr;
	float m_maxSpeed, m_MaxAcceleration, m_TimeToTarget;
};
