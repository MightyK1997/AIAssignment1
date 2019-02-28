#pragma once
#include <vector>
#include <cmath>
#include "ofVec2f.h"
#include <algorithm>

struct Node
{
	Node() = default;
	Node(int i_index, ofVec2f i_pos, bool i_bIsWalkable = false) : m_Index(i_index), m_Position(i_pos), b_IsWalkable(i_bIsWalkable) {}
	~Node() = default;

	bool operator==(const Node* i_Node) const
	{
		return (m_Index == i_Node->m_Index && m_Position == i_Node->m_Position);
	}
	bool operator!= (const Node* i_Node) const
	{
		return !(this == i_Node);
	}

	int m_Index = 0;
	ofVec2f m_Position;
	bool b_IsWalkable = false;

};

struct DirectedWeightedEdge
{
	DirectedWeightedEdge() {}
	DirectedWeightedEdge(float i_Cost, Node* i_Source, Node* i_Sink) : m_Cost(i_Cost), m_Source(i_Source), m_Sink(i_Sink) {}
	~DirectedWeightedEdge() = default;

	bool operator==(const DirectedWeightedEdge* i_Edge)const
	{
		return (m_Source == i_Edge->m_Source && m_Sink == i_Edge->m_Sink);
	}

	bool operator!=(const DirectedWeightedEdge* i_Edge) const
	{
		return !(this == i_Edge);
	}

	float m_Cost = 0.0f;
	Node* m_Source = nullptr;
	Node* m_Sink = nullptr;
};

struct NodeRecord
{

	//ctor and dtor

	NodeRecord() {}
	NodeRecord(Node* i_Node, DirectedWeightedEdge* i_Edge, float i_Cost, float i_TotalCost) :
		m_Node(i_Node),
		m_IncomingEdge(i_Edge),
		m_CostSoFar(i_Cost),
		m_EstimatedTotalCost(i_TotalCost)
	{
	}

	~NodeRecord() = default;
	Node* m_Node = nullptr;
	DirectedWeightedEdge* m_IncomingEdge = nullptr;
	float m_CostSoFar = 0.0f;
	float m_EstimatedTotalCost = 0.0f;


	bool operator== (const NodeRecord* i_record) const
	{
		return (m_Node == i_record->m_Node && m_IncomingEdge == i_record->m_IncomingEdge);
	}
	bool operator!= (const NodeRecord* i_Record) const
	{
		return !(this == i_Record);
	}
};

struct Path
{
	std::vector<DirectedWeightedEdge*> m_Path;
};

enum class Heuristic
{
	Manhattan,
	Euclidean,
	Diagonal,
	Default,
	Zero
};

struct Heuristics
{
	//TODO:Need to fix manhattan distance
	static float Manhattan(Node* i_StartNode, Node* i_EndNode) { return abs(i_StartNode->m_Position.x - i_EndNode->m_Position.x) + abs(i_StartNode->m_Position.y - i_EndNode->m_Position.y); }
	static float Euclidean(Node* i_StartNode, Node* i_EndNode) { return i_StartNode->m_Position.distance(i_EndNode->m_Position); }
	static float Diagonal(Node* i_StartNode, Node* i_EndNode)
	{
		float dx = abs(i_StartNode->m_Position.x - i_EndNode->m_Position.x);
		float dy = abs(i_StartNode->m_Position.y - i_EndNode->m_Position.y);
		return (dx + dy) + std::min(dx, dy);
	}
};
