#pragma once
#include <vector>
#include "DataTypes-PathFinding.h"

class Graph
{
public:
	std::vector<DirectedWeightedEdge*> GetConnections(Node* i_nodeRecord);
	void AddEdgeToGraph(DirectedWeightedEdge* i_Edge) { m_Edges.emplace_back(i_Edge); }

private:
	std::vector<DirectedWeightedEdge*> m_Edges;
};
