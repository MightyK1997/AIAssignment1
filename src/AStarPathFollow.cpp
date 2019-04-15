#include "AStarPathFollow.h"
#include "Grid.h"
#include "DynamicPathFollow.h"
#include "Graph.h"
#include "ofMesh.h"

void AStarPathFollow::Update()
{
	if (!m_Movement) return;
	auto movementVal = follow.GetSteering(m_Path, m_Boid->GetBoidKinematicData(), m_maxSpeed, 5.0f, 20.0f, m_MaxAcceleration, m_TimeToTarget);
	if (movementVal.LinearAcceleration == ofVec2f(0,0))
	{
		arrived = true;
	}
	m_Boid->Update(movementVal);
}

void AStarPathFollow::Draw()
{
	m_Boid->Draw();
}

void AStarPathFollow::AddNewTargetForBoid(float i_X, float i_Y)
{
	arrived = false;
	if (!m_EndNode)
	{
		m_EndNode = new Node(std::numeric_limits<int>().max() - 2, ofVec2f(i_X, i_Y));
	}
	else
	{
		m_EndNode->m_Position = ofVec2f(i_X, i_Y);
	}
}

bool AStarPathFollow::HasArrived()
{
	if (arrived)
	{
		AddNewTargetForBoid(rand() % ofGetHeight() + 1, rand() % ofGetWidth() + 1);
		CreateAndSetPathToFollow();
	}
	return false;
}

void AStarPathFollow::CreateAndSetPathToFollow()
{
	arrived = false;
	//m_StartNode->m_Position = m_Boid->GetBoidKinematicData().Position;
	m_Path = m_LocalAStar->GetPath(m_WorldGraph, m_StartNode, m_EndNode);
	ResetPath();
}

void AStarPathFollow::CreateAndSetPathToFollow(Grid* m_Grid, Node* i_Node)
{
	arrived = false;
	m_StartNode = m_Grid->GetNodeByPosition(m_Boid->GetBoidKinematicData().Position);
	m_Path = m_LocalAStar->GetPath(m_Grid, m_StartNode, m_EndNode);
	ResetPath();
}
