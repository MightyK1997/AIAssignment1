#pragma once
#include <cstdint>
#include <vector>
#include <unordered_map>

class DirectedWeightedEdge
{
public:
	//Getters
	float GetCost() { return m_CostOfConnection; }
	uint64_t GetSourceNode() { return m_Source; }
	uint64_t GetSinkNode() { return m_Sink; }

	//Setters
	void SetCost(float i_Cost);
	void SetSource(uint64_t i_Node);
	void SetSink(uint64_t i_Sink);

private:
	float m_CostOfConnection;
	uint64_t m_Source;
	uint64_t m_Sink;
};

class NodeRecord
{
public:
	//Constructor and Destructor
	NodeRecord(){}
	NodeRecord(uint64_t i_NodeValue, DirectedWeightedEdge* i_IncomingEdge, float i_Cost) : m_NodeValue(i_NodeValue), m_IncomingEdge(i_IncomingEdge), m_CostSoFar(i_Cost){}
	~NodeRecord() = default;

	//
	uint64_t m_NodeValue = 0;
	DirectedWeightedEdge* m_IncomingEdge = nullptr;
	float m_CostSoFar = 0;
};


struct Path
{
	std::vector<DirectedWeightedEdge*> m_Path;
};

//class Graph
//{
//public:
//	//Getter
//	std::vector<DirectedWeightedEdge*> GetConnectionFromNode(NodeRecord* i_Node);
//
//	//Setter
//
//	void SetConnectionsFromNode(NodeRecord* i_Node, int i_NumberOfConnections, DirectedWeightedEdge* i_Connections[100]);
//
//private:
//	std::unordered_map<NodeRecord*, std::vector<DirectedWeightedEdge*>> m_Graph;
//};

struct Huristics
{
	static float Manhattan(float dx, float dy) { return dx + dy; }
	static float Euclidean(float dx, float dy) { return sqrt(dx * dx + dy * dy); }
};
