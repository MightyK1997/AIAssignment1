#pragma once

#include "Graph.h"
#include "DataTypes-PathFinding.h"

class AStar
{
public:
	AStar(){}
	AStar(Heuristic i_Heuristic, float i_Weight) : m_Heuristic(i_Heuristic), m_Weight(i_Weight){}
	~AStar() = default;
	Path GetPath(Graph* i_WorldGraph, Node* i_StartNode, Node* i_EndNode);

private:
	float GetHeuristic(float dx, float dy);
	Heuristic m_Heuristic = Heuristic::Euclidean;
	float m_Weight = 0;
};