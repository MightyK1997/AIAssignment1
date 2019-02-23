#pragma once
#include <vector>

class Node
{
public:
	Node(float i_x, float i_y) :x(i_x), y(i_y), m_Parent(nullptr), b_IsWalkable(true) {}
	Node* m_Parent;
	float x, y;
	bool b_IsWalkable;
};

class Graph
{
public:
	Graph() {}
	Graph(float i_Width, float i_Height) :m_Width(i_Width), m_Height(i_Height) { ConstructGraphNodes(i_Width, i_Height); }
	~Graph() {}
	void ConstructGraphNodes(float i_Width, float i_Height);
	void ChangeNodeWalkable(float i_x, float i_y, bool i_bWalkable);
	Node* GetNodeAtLocation(float i_x, float i_y) { return m_GraphNodes[i_y][i_x]; }
	inline bool IsNodeInsideGraph(float i_X, float i_Y) {
		return (i_X >= 0 && i_X < m_Width) && (i_Y >= 0 && i_Y < m_Height);
	}
	inline bool IsNodeWalkable(float i_X, float i_Y);

	std::vector<Node*> GetNeighborsOfNode(Node* i_Node);

private:
	float m_Width;
	float m_Height;
	std::vector<std::vector<Node*>> m_GraphNodes;
};
