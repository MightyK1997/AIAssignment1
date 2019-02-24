#pragma once
#include <vector>
#include "ofVec2f.h"

class Node
{
public:
	Node(float i_x, float i_y) :x(i_x), y(i_y), m_Parent(nullptr), b_IsWalkable(true) {}
	Node* m_Parent;
	float x, y;
	bool b_IsWalkable;
	uint64_t m_NodeValue;

	//G
	float m_CostOfGettingFromStartToNode = 1000.0f;
	//F
	float m_TotalCostOfGettingToGoalThroughNode = 1000.0f;
	//H
	float m_NodeHeuristic = 0.0f;

	bool b_InOpenList = false;
	bool b_InClosedList = false;

	friend bool operator==(const Node& i_Node1, const Node& i_Node2);
	friend bool operator!=(const Node& i_Node1, const Node& i_Node2);

	static std::vector<ofVec2f> GetPathFromNode(Node* i_Node);
};

class Graph
{
public:
	Graph() {}
	Graph(float i_Width, float i_Height) :m_Width(i_Width), m_Height(i_Height) { ConstructGraphNodes(i_Width, i_Height); }
	~Graph() = default;
	void ConstructGraphNodes(float i_Width, float i_Height);
	void ChangeNodeWalkable(float i_x, float i_y, bool i_bWalkable);
	inline void AddNodeToGraph(float i_x, float i_y);
	Node* GetNodeAtLocation(float i_x, float i_y) { return m_GraphNodes[i_y][i_x]; }
	inline bool IsNodeInsideGraph(float i_X, float i_Y) const {
		return (i_X >= 0 && i_X < m_Width) && (i_Y >= 0 && i_Y < m_Height);
	}
	inline bool IsNodeWalkable(float i_X, float i_Y);
	void ResetNodeData();

	std::vector<Node*> GetNeighborsOfNode(Node* i_Node);

private:
	float m_Width;
	float m_Height;
	std::vector<std::vector<Node*>> m_GraphNodes;
};
