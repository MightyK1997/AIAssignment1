#pragma once
#include "Boid.h"
#include "DynamicPathFollow.h"
#include "Dijkstra.h"

class Graph;
class AStarPathFollow
{
public:
	AStarPathFollow(){}
	AStarPathFollow(Boid* i_Boid, Heuristic i_Heuristic, Graph* i_WorldGraph, float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget) : 
		m_Boid (i_Boid), m_WorldGraph(i_WorldGraph), m_maxSpeed(i_MaxSpeed), m_MaxAcceleration(i_MaxAcceleration), m_TimeToTarget(i_TimeToTarget)
	{
		arrived = false;
		m_Boid->SetBoidPosition(ofVec2f(0, 0));
		m_Boid->SetBoidColor(ofVec3f(255, 0, 0));
		m_LocalAStar = new AStar(i_Heuristic);
		m_StartNode = new Node(std::numeric_limits<int>().max() - 1, m_Boid->GetBoidKinematicData().Position);
	}

	AStarPathFollow(Heuristic i_Heuristic, Grid* i_WorldGrid, float i_MaxAcceleration, float i_MaxSpeed, float i_TimeToTarget) :
		m_Grid(i_WorldGrid), m_maxSpeed(i_MaxSpeed), m_MaxAcceleration(i_MaxAcceleration), m_TimeToTarget(i_TimeToTarget)
	{
		m_Boid->SetBoidColor(ofVec3f(0, 0, 255));
		m_LocalAStar = new AStar(i_Heuristic);
	}
	~AStarPathFollow() = default;
	void Update();
	void Draw();
	void UpdateGraph(Graph* i_Graph) { m_WorldGraph = i_Graph; }
	void SetStartNode(Node* i_Node)
	{
		m_Boid->SetBoidPosition(i_Node->m_Position); 
		m_StartNode = i_Node;
	}
	void AddNewTargetForBoid(float i_X, float i_Y);
	void AddNewTargetForBoid(Node* i_Node) { m_EndNode = i_Node; }
	bool HasArrived();
	void CreateAndSetPathToFollow();
	void CreateAndSetPathToFollow(Grid* m_Grid, Node* i_Node);
	void UpdateAStarHeuristic(Heuristic i_Heuristic) const { m_LocalAStar->UpdateHeuristic(i_Heuristic); }
	void ResetPath(){ follow.ResetCount(); }
	void MovementInput(bool i_MovementInput) { m_Movement = i_MovementInput; }



private:
	Boid* m_Boid;
	Path m_Path;
	DynamicPathFollow follow;
	Graph* m_WorldGraph = nullptr;
	Grid* m_Grid = nullptr;
	AStar* m_LocalAStar = nullptr;
	Node* m_EndNode = nullptr;
	Node* m_StartNode = nullptr;
	float m_maxSpeed, m_MaxAcceleration, m_TimeToTarget;
	bool m_Movement = true;
	bool arrived = false;
};
