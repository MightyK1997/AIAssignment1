#pragma once

#include "DataTypes-PathFinding.h"

class Dijkstra
{
public:
	Path* GetSteering(Graph i_WorldGraph, uint64_t i_Start, uint64_t i_End);

private:
	NodeRecord* GetElementWithLowestCost(NodeRecord* i_OpenList[100], size_t i_NumberOfElementsInList);
};