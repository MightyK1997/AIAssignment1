#include "DataTypes-PathFinding.h"

void DirectedWeightedEdge::SetCost(float i_Cost)
{
	m_CostOfConnection = i_Cost;
}

void DirectedWeightedEdge::SetSource(uint64_t i_Node)
{
	m_Source = i_Node;
}

void DirectedWeightedEdge::SetSink(uint64_t i_Sink)
{
	m_Sink = i_Sink;
}

//std::vector<DirectedWeightedEdge*> Graph::GetConnectionFromNode(NodeRecord* i_Node)
//{
//	return m_Graph[i_Node];
//}
//
//void Graph::SetConnectionsFromNode(NodeRecord* i_Node, int i_NumberOfConnections, DirectedWeightedEdge* i_Connections[100])
//{
//	if (m_Graph.find(i_Node) == m_Graph.end())
//	{
//		auto tempVec = std::vector<DirectedWeightedEdge*>();
//		for (auto x = 0; x < i_NumberOfConnections; x++)
//		{
//			tempVec.push_back(i_Connections[x]);
//		}
//		m_Graph.insert(m_Graph.begin(), std::pair < NodeRecord*, std::vector<DirectedWeightedEdge*>>(i_Node, tempVec));
//	}
//}
