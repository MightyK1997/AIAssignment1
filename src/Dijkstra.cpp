#include "Dijkstra.h"

namespace
{
	bool DoesContainElement(std::vector<NodeRecord*> i_List, NodeRecord* i_Value)
	{
		return(std::find(i_List.begin(), i_List.end(), i_Value) != i_List.end());
	}

	bool DoesContainElement(std::vector<NodeRecord*> i_List, uint64_t i_Node)
	{
		for (auto x: i_List)
		{
			return x->m_NodeValue == i_Node;
		}
	}

	NodeRecord* GetMatchingElementFromList(std::vector<NodeRecord*>i_List, uint64_t i_Node)
	{
		for (auto x : i_List)
		{
			if (x->m_NodeValue == i_Node) return x;
		}
		return nullptr;
	}

	void RemoveElementFromList(std::vector<NodeRecord*> i_List, NodeRecord* i_Node)
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

Path* Dijkstra::GetSteering(Graph i_WorldGraph, uint64_t i_Start, uint64_t i_End)
{

	auto startRecord = new NodeRecord(i_Start, nullptr, 0);
	std::vector<NodeRecord*> openList, closeList;
	openList.push_back(startRecord);
	NodeRecord* current = nullptr;
	while (!openList.empty())
	{
		current = GetElementWithLowestCost(&openList[0], openList.size());
		if (current->m_NodeValue == i_End) break;
		auto connections = i_WorldGraph.GetConnectionFromNode(current);
		for (auto connection:connections)
		{
			auto endNode = connection->GetSinkNode();
			auto endNodeCost = current->m_CostSoFar + connection->GetCost();
			if (DoesContainElement(closeList, endNode)) continue;
			if (DoesContainElement(openList, endNode))
			{
				auto endRecord = GetMatchingElementFromList(openList, endNode);
				if (endRecord->m_CostSoFar <= endNodeCost) continue;
			}
			else
			{
				auto endNodeRecord = new NodeRecord(endNode, connection, endNodeCost);
				openList.push_back(endNodeRecord);
			}
		}
		closeList.push_back(current);
		RemoveElementFromList(openList, current);
	}
	if (current && current->m_NodeValue != i_End) return nullptr;
	Path* returnPath = new Path();
	while (current->m_NodeValue != i_Start)
	{
		returnPath->m_Path.push_back(current->m_IncomingEdge);
		current = current->m_IncomingEdge->GetSourceNode();
	}
	std::reverse(returnPath->m_Path.begin(), returnPath->m_Path.end());
	return returnPath;
}

NodeRecord* Dijkstra::GetElementWithLowestCost(NodeRecord* i_OpenList[100], size_t i_NumberOfElementsInList)
{
	auto retNode = i_OpenList[0];
	for(size_t x=0;x<i_NumberOfElementsInList;x++)
	{
		if (i_OpenList[x]->m_CostSoFar < retNode->m_CostSoFar)
		{
			retNode = i_OpenList[x];
		}
	}
	return retNode;
}
