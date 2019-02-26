#pragma once

#include "Graph.h"
#include "DataTypes-PathFinding.h"

class AStar
{
public:
	AStar(){}
	AStar(Heuristic i_Heuristic) : m_Heuristic(i_Heuristic){}
	~AStar() = default;
	Path GetPath(Graph* i_WorldGraph, Node* i_StartNode, Node* i_EndNode);

private:
	float GetHeuristic(Node* i_StartNode, Node* i_EndNode);
	Heuristic m_Heuristic = Heuristic::Euclidean;
};