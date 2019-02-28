#include "Dijkstra.h"
#include <algorithm>

namespace
{
	bool SortHelperFunction(NodeRecord* n1, NodeRecord* n2) { return n1->m_EstimatedTotalCost < n2->m_EstimatedTotalCost; }

	void RemoveElementFromList(std::vector<NodeRecord*>& i_List, NodeRecord* i_Node)
	{
		auto it = i_List.begin();
		while (it!=i_List.end())
		{
			if ((*it) == i_Node)
			{
				it = i_List.erase(it);
				continue;
			}
			++it;
		}
	}

	bool DoesListContainElement(std::vector<NodeRecord*> i_List, NodeRecord* i_NodeRecord)
	{
		for (auto listelement:i_List)
		{
			if (listelement == i_NodeRecord)
			{
				return true;
			}
		}
		return false;
	}

	bool DoesListContainElement(std::vector<NodeRecord*> i_List, Node* i_NodeRecord)
	{
		for (auto listelement : i_List)
		{
			if (listelement->m_Node == i_NodeRecord)
			{
				return true;
			}
		}
		return false;
	}

	NodeRecord* GetNodeRecordForNode(std::vector<NodeRecord*> i_List, Node* i_Node)
	{
		for (auto listelement:i_List)
		{
			if (listelement->m_Node == i_Node)
			{
				return listelement;
			}
		}
		return nullptr;
	}
}

Path AStar::GetPath(Graph* i_WorldGraph, Node* i_StartNode, Node* i_EndNode)
{
	Path returnPath;
	NodeRecord* startRecord = new NodeRecord(i_StartNode, nullptr, 0, GetHeuristic(i_StartNode, i_EndNode));

	auto openList = std::vector<NodeRecord*>();
	auto closeList = std::vector<NodeRecord*>();

	openList.emplace_back(startRecord);
	NodeRecord* currentNode;

	while (!openList.empty())
	{
		currentNode = openList[0];
		if (currentNode->m_Node == i_EndNode) break;
		std::vector<DirectedWeightedEdge*> connections = i_WorldGraph->GetConnections(currentNode->m_Node);
		for (auto connection : connections)
		{
			Node* endNode = connection->m_Sink;
			float endNodeCost = currentNode->m_CostSoFar + connection->m_Cost;
			if (DoesListContainElement(closeList, endNode))
			{
				continue;
			}
			else
			{
				if (DoesListContainElement(openList, endNode))
				{
					if (endNodeCost < connection->m_Cost)
					{
						connection->m_Cost = endNodeCost;
					}
				}
				else
				{
					NodeRecord* newRecord = new NodeRecord(endNode, connection, endNodeCost, endNodeCost + GetHeuristic(endNode, i_EndNode));
					openList.emplace_back(newRecord);
				}
				std::sort(openList.begin(), openList.end(), SortHelperFunction);
			}
		}
		RemoveElementFromList(openList, currentNode);
		closeList.emplace_back(currentNode);
		std::sort(closeList.begin(), closeList.end(), SortHelperFunction);
	}
	if (currentNode->m_Node->m_Index != i_EndNode->m_Index)
	{
	}
	else
	{
		while (currentNode->m_Node->m_Index != i_StartNode->m_Index)
		{
			returnPath.m_Path.push_back(currentNode->m_IncomingEdge);
			currentNode = GetNodeRecordForNode(closeList, currentNode->m_IncomingEdge->m_Source);
		}
		std::reverse(returnPath.m_Path.begin(), returnPath.m_Path.end());
	}
	for (auto node : openList)
	{
		if (node)
		{
			delete(node);
		}
	}
	for (auto node : closeList)
	{
		if (node)
		{
			delete(node);
		}
	}
	return returnPath;
}

float AStar::GetHeuristic(Node* i_StartNode, Node* i_EndNode)
{
	switch (m_Heuristic)
	{
	case Heuristic::Euclidean:
		return Heuristics::Euclidean(i_StartNode, i_EndNode);
	case Heuristic::Manhattan:
	case Heuristic::Default:
		return Heuristics::Manhattan(i_StartNode, i_EndNode);
	case Heuristic::Diagonal:
		return Heuristics::Diagonal(i_StartNode, i_EndNode);
	case Heuristic::Zero:
		return 0;
	}
	return 0;
}
