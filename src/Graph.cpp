#include "Graph.h"
std::vector<DirectedWeightedEdge*> Graph::GetConnections(Node* i_nodeRecord)
{
	std::vector<DirectedWeightedEdge*> o_Connections;

	for (auto edge : m_Edges)
	{
		if (edge->m_Source->m_Index == i_nodeRecord->m_Index)
		{
			o_Connections.emplace_back(edge);
		}
	}
	return o_Connections;
}
