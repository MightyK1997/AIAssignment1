#include "DataTypes-PathFinding.h"


void Connection::SetCost(float i_Cost)
{
	m_CostOfConnection = i_Cost;
}

void Connection::SetSource(NodeRecord i_Node)
{
	m_Source = i_Node;
}

void Connection::SetSink(NodeRecord i_Sink)
{
	m_Sink = i_Sink;
}

void Graph::SetConnectionsFromNode(NodeRecord i_Node, int i_NumberOfConnections, Connection* i_Connections[100])
{
	if (m_Graph.find(i_Node) == m_Graph.end())
	{
		auto tempVec = std::vector<Connection*>();
		for (auto x = 0; x < i_NumberOfConnections; x++)
		{
			tempVec.push_back(i_Connections[x]);
		}
		m_Graph.insert(m_Graph.begin(), std::pair < NodeRecord, std::vector<Connection*>>(i_Node, tempVec));
	}
}
