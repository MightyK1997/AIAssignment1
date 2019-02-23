#include "Graph.h"

void Graph::ConstructGraphNodes(float i_Width, float i_Height)
{
	for (int i = 0; i < i_Height; i++)
	{
		for (int j = 0; j < i_Width; j++)
		{
			m_GraphNodes[i][j] = new Node(j, i);
		}
	}
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
}
