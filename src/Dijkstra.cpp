#include "Dijkstra.h"
#include <algorithm>

namespace
{
	bool SortHelperFunction(Node* n1, Node* n2) { return n1->m_TotalCostOfGettingToGoalThroughNode < n2->m_TotalCostOfGettingToGoalThroughNode; }

	void RemoveElementFromList(std::vector<Node*>& i_List, Node* i_Node)
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
}

Path AStar::GetPath(Graph* i_WorldGraph, Node* i_StartNode, Node* i_EndNode)
{
	Path returnPath;
	auto startNode = i_StartNode;
	auto endNode = i_EndNode;
	auto openList = std::vector<Node*>();
	auto closeList = std::vector<Node*>();
	startNode->m_CostOfGettingFromStartToNode = 0;
	startNode->m_TotalCostOfGettingToGoalThroughNode = 0;

	openList.emplace_back(startNode);
	while (!openList.empty())
	{
		auto node = openList[0];
		RemoveElementFromList(openList, node);
		node->b_InClosedList = true;
		if ((node->x == i_EndNode->x) && (node->y == i_EndNode->y))
		{
			returnPath.m_Path = Node::GetPathFromNode(node);
			return returnPath;
		}
		auto neighbors = i_WorldGraph->GetNeighborsOfNode(node);
		for (auto neighbor:neighbors)
		{
			if (neighbor->b_InClosedList)
			{
				continue;
			}
			auto x = neighbor->x;
			auto y = neighbor->y;

			auto distanceBetweenCurrentAndNeighbor = node->m_CostOfGettingFromStartToNode + ((x - node->x == 0 || y - node->y == 0) ? 1 : sqrt(2));

			if (neighbor->b_InOpenList || distanceBetweenCurrentAndNeighbor < neighbor->m_CostOfGettingFromStartToNode)
			{
				neighbor->m_CostOfGettingFromStartToNode = distanceBetweenCurrentAndNeighbor;
				neighbor->m_NodeHeuristic = neighbor->m_NodeHeuristic || (m_Weight * GetHeuristic(abs(x - i_EndNode->x), abs(y - i_EndNode->y)));
				neighbor->m_TotalCostOfGettingToGoalThroughNode = neighbor->m_CostOfGettingFromStartToNode + neighbor->m_NodeHeuristic;
				neighbor->m_Parent = node;

				if (!neighbor->b_InOpenList)
				{
					openList.emplace_back(neighbor);
					neighbor->b_InOpenList = true;
					std::sort(openList.begin(), openList.end(), SortHelperFunction);
				}
				else
				{
					std::sort(openList.begin(), openList.end(), SortHelperFunction);
				}
			}
		}
	}
	return returnPath;
}

float AStar::GetHeuristic(float dx, float dy)
{
	switch (m_Heuristic)
	{
	case Heuristic::Euclidean:
		return Heuristics::Euclidean(dx, dy);
	case Heuristic::Manhattan:
	case Heuristic::Default:
		return Heuristics::Manhattan(dx, dy);
	case Heuristic::Zero:
		return Heuristics::Manhattan(0, 0);
	}
	return 0;
}
