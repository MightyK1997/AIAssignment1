#pragma once

#include "DataTypes-PathFinding.h"

class Dijkstra
{
public:
	NodeRecord GetSteering(Graph i_WorldGraph, NodeRecord i_Start, NodeRecord i_End);
};