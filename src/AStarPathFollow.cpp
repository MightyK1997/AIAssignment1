#include "AStarPathFollow.h"
#include "DynamicPathFollow.h"
#include "Graph.h"

void AStarPathFollow::Update()
{
	m_Boid.Update(follow.GetSteering(m_Path, m_Boid.GetBoidKinematicData(), m_maxSpeed, 5.0f, 50.0f, m_MaxAcceleration, m_TimeToTarget));
}

void AStarPathFollow::Draw()
{
	m_Boid.Draw();
}

void AStarPathFollow::AddNewTargetForBoid(float i_X, float i_Y)
{
	if (!m_EndNode)
	{
		m_EndNode = new Node(std::numeric_limits<int>().max() - 2, ofVec2f(i_X, i_Y));
	}
	else
	{
		m_EndNode->m_Position = ofVec2f(i_X, i_Y);
	}
}

void AStarPathFollow::CreateAndSetPathToFollow()
{
	//m_StartNode->m_Position = m_Boid.GetBoidKinematicData().Position;
	m_Path = m_LocalAStar->GetPath(m_WorldGraph, m_StartNode, m_EndNode);
	follow.ResetCount();
}

void AStarPathFollow::CreateAndSetPathToFollow(Grid* m_Grid, Node* i_Node)
{
	m_StartNode->m_Position = m_Boid.GetBoidKinematicData().Position;
	m_Path = m_LocalAStar->GetPath(m_Grid, m_StartNode, m_EndNode);
	follow.ResetCount();
}
