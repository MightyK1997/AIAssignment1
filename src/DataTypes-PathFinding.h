#pragma once
#include <cstdint>
#include <vector>
#include <unordered_map>

class Connection;
class NodeRecord
{
public:
	uint32_t m_NodeValue;
	Connection m_Connection;
	float m_CostSoFar;
};

class Connection
{
public:
	//Getters
	float GetCost() { return m_CostOfConnection; }
	NodeRecord GetSourceNode() { return m_Source; }
	NodeRecord GetSinkNode() { return m_Sink; }

	//Setters
	void SetCost(float i_Cost);
	void SetSource(NodeRecord i_Node);
	void SetSink(NodeRecord i_Sink);

private:
	float m_CostOfConnection;
	NodeRecord m_Source;
	NodeRecord m_Sink;
};

class Graph
{
public:
	//Getter
	std::vector<Connection*> GetConnectionnFromNode(NodeRecord i_Node);

	//Setter

	void SetConnectionsFromNode(NodeRecord i_Node, int i_NumberOfConnections, Connection* i_Connections[100]);

private:
	std::unordered_map<NodeRecord, std::vector<Connection*>> m_Graph;
};
