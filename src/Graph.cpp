#include "Graph.h"

std::vector<ofVec2f> Node::GetPathFromNode(Node* i_Node)
{
	std::vector<ofVec2f> m_ReturnPath;
	m_ReturnPath.emplace_back(ofVec2f(i_Node->x, i_Node->y));
	while(i_Node->m_Parent)
	{
		i_Node = i_Node->m_Parent;
		m_ReturnPath.emplace_back(ofVec2f(i_Node->x, i_Node->y));
	}
	std::reverse(m_ReturnPath.begin(), m_ReturnPath.end());
	return m_ReturnPath;
}

void Graph::ConstructGraphNodes(float i_Width, float i_Height)
{
	for (int i = 0; i < i_Height; i++)
	{
		std::vector<Node*> columns;
		for (int j = 0; j < i_Width; j++)
		{
			columns.push_back(new Node(j, i));
		}
		m_GraphNodes.push_back(columns);
	}
}

void Graph::ChangeNodeWalkable(float i_x, float i_y, bool i_bWalkable)
{
	m_GraphNodes[i_y][i_x]->b_IsWalkable = i_bWalkable;
}

void Graph::AddNodeToGraph(float i_x, float i_y)
{
	m_GraphNodes[i_x][i_y] = new Node(i_x, i_y);
}

bool Graph::IsNodeWalkable(float i_X, float i_Y)
{
	return  IsNodeInsideGraph(i_X, i_Y) && m_GraphNodes[i_Y][i_X]->b_IsWalkable;
}

std::vector<Node*> Graph::GetNeighborsOfNode(Node* i_Node)
{
	auto x = i_Node->x;
	auto y = i_Node->y;

	std::vector<Node*> neighbors;

	if (IsNodeWalkable(x, y -1))
	{
		neighbors.push_back(m_GraphNodes[y - 1][x]);
	}
	if (IsNodeWalkable(x + 1, y)) {

		neighbors.push_back(m_GraphNodes[y][x + 1]);
	}
	if (IsNodeWalkable(x, y + 1)) {

		neighbors.push_back(m_GraphNodes[y + 1][x]);
	}
	if (IsNodeWalkable(x - 1, y)) {

		neighbors.push_back(m_GraphNodes[y][x - 1]);
	}

	return neighbors;
}

bool operator==(const Node& i_Node1, const Node& i_Node2)
{
	return (i_Node1.x == i_Node2.x) && (i_Node1.y == i_Node2.y);
}

bool operator!=(const Node& i_Node1, const Node& i_Node2)
{
	return !(i_Node1 == i_Node2);
}
