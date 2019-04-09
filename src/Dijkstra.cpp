#include "Dijkstra.h"
#include "Grid.h"
#include <algorithm>
#include "PriorityQueue.h"

namespace
{
	bool SortHelperFunction(NodeRecord* n1, NodeRecord* n2) { return n1->m_EstimatedTotalCost < n2->m_EstimatedTotalCost; }

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

	auto openList = PriorityQueue<NodeRecord*>(SortHelperFunction);
	auto closeList = PriorityQueue<NodeRecord*>(SortHelperFunction);

	openList.Insert(startRecord);
	NodeRecord* currentNode;

	while (!openList.Empty())
	{
		currentNode = openList[0];
		if (currentNode->m_Node == i_EndNode) break;
		std::vector<DirectedWeightedEdge*> connections = i_WorldGraph->GetConnections(currentNode->m_Node);
		for (auto connection : connections)
		{
			Node* endNode = connection->m_Sink;
			float endNodeCost = currentNode->m_CostSoFar + connection->m_Cost;
			if (DoesListContainElement(closeList.GetUnderlyingQueue(), endNode))
			{
				continue;
			}
			else
			{
				if (DoesListContainElement(openList.GetUnderlyingQueue(), endNode))
				{
					auto record = GetNodeRecordForNode(openList.GetUnderlyingQueue(), endNode);
					if (endNodeCost < record->m_CostSoFar)
					{
						record->m_CostSoFar = endNodeCost;
						record->m_IncomingEdge = connection;
					}
				}
				else
				{
					NodeRecord* newRecord = new NodeRecord(endNode, connection, endNodeCost, endNodeCost + GetHeuristic(endNode, i_EndNode));
					openList.Insert(newRecord);
				}
			}
		}
		openList.Remove(currentNode);
		closeList.Insert(currentNode);
	}
	if (currentNode->m_Node->m_Index != i_EndNode->m_Index)
	{
	}
	else
	{
		while (currentNode->m_Node->m_Index != i_StartNode->m_Index)
		{
			returnPath.m_Path.push_back(currentNode->m_IncomingEdge);
			currentNode = GetNodeRecordForNode(closeList.GetUnderlyingQueue(), currentNode->m_IncomingEdge->m_Source);
		}
		std::reverse(returnPath.m_Path.begin(), returnPath.m_Path.end());
	}
	openList.Clear();
	closeList.Clear();
	return returnPath;
}

Path AStar::GetPath(Grid* i_WorldGrid, Node* i_StartNode, Node* i_EndNode)
{
	Path returnPath;
	NodeRecord* startRecord = new NodeRecord(i_StartNode, nullptr, 0, GetHeuristic(i_StartNode, i_EndNode));

	auto openList = PriorityQueue<NodeRecord*>(SortHelperFunction);
	auto closeList = PriorityQueue<NodeRecord*>(SortHelperFunction);

	openList.Insert(startRecord);
	NodeRecord* currentNode;

	while (!openList.Empty())
	{
		currentNode = openList[0];
		if (currentNode->m_Node == i_EndNode) break;
		std::vector<Node*> Neighbors = i_WorldGrid->GetNeighboringNodesOfNode(currentNode->m_Node);
		for (auto neighbor : Neighbors)
		{
			Node* endNode = neighbor;
			float endNodeCost = currentNode->m_CostSoFar + Grid::TileCost;
			if (!endNode->b_IsWalkable || DoesListContainElement(closeList.GetUnderlyingQueue(), endNode))
			{
				continue;
			}
			else
			{
				if (DoesListContainElement(openList.GetUnderlyingQueue(), endNode))
				{
					auto record = GetNodeRecordForNode(openList.GetUnderlyingQueue(), endNode);
					if (endNodeCost < record->m_CostSoFar)
					{
						record->m_CostSoFar = endNodeCost;
						record->m_IncomingEdge = new DirectedWeightedEdge(Grid::TileCost, currentNode->m_Node, endNode);
					}
				}
				else
				{
					DirectedWeightedEdge* temp = new DirectedWeightedEdge(Grid::TileCost, currentNode->m_Node, endNode);
					NodeRecord* newRecord = new NodeRecord(endNode, temp, endNodeCost, endNodeCost + GetHeuristic(endNode, i_EndNode));
					openList.Insert(newRecord);
				}
			}
		}
		openList.Remove(currentNode);
		closeList.Insert(currentNode);
	}
	if (currentNode->m_Node->m_Index != i_EndNode->m_Index)
	{
	}
	else
	{
		while (currentNode->m_Node->m_Index != i_StartNode->m_Index)
		{
			returnPath.m_Path.push_back(currentNode->m_IncomingEdge);
			currentNode = GetNodeRecordForNode(closeList.GetUnderlyingQueue(), currentNode->m_IncomingEdge->m_Source);
		}
		std::reverse(returnPath.m_Path.begin(), returnPath.m_Path.end());
	}
	openList.Clear();
	closeList.Clear();
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
