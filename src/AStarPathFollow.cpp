//#include "AStarPathFollow.h"
//#include "DynamicPathFollow.h"
//#include "Graph.h"
//
//void AStarPathFollow::Update()
//{
//	m_Boid.Update(follow.GetSteering(m_Path, m_Boid.GetBoidKinematicData(), m_maxSpeed, 5.0f, 20.0f, m_MaxAcceleration, m_TimeToTarget));
//}
//
//void AStarPathFollow::Draw()
//{
//	m_Boid.Draw();
//}
//
//void AStarPathFollow::CreateGraph(float i_Width, float i_Height)
//{
//	m_WorldGraph = new Graph(i_Width, i_Height);
//}
//
//void AStarPathFollow::AddNewTargetForBoid(float i_X, float i_Y)
//{
//	if (!m_EndNode)
//	{
//		m_EndNode = new Node(i_X, i_Y);
//	}
//	else
//	{
//		m_EndNode->x = i_X;
//		m_EndNode->y = i_Y;
//	}
//}
//
//void AStarPathFollow::CreateAndSetPathToFollow()
//{
//	m_StartNode->x = m_Boid.GetBoidKinematicData().Position.x;
//	m_StartNode->y = m_Boid.GetBoidKinematicData().Position.y;
//	m_Path = m_LocalAStar->GetPath(m_WorldGraph, m_StartNode, m_EndNode);
//	m_WorldGraph->ResetNodeData();
//	follow.ResetCount();
//}
