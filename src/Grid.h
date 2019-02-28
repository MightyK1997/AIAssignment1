#pragma once
#include <ofImage.h>
#include "DataTypes-PathFinding.h"

//Loads Grid from a maze image

//Change this value for more precision

class Grid
{
public:

	Grid() = default;
	Grid(std::string i_ImagePath, bool i_bShouldVisualizeGraph) : m_bShouldVisualizeGraph(i_bShouldVisualizeGraph) { Load(i_ImagePath); }
	~Grid() = default;
	void Load(std::string i_ImagePath);

	std::vector<Node*> GetGraphNodes() const { return m_GraphNodes; }

	Node* GetNodeAtIndex(int i_Index) const { return m_GraphNodes[i_Index]; }

	Node* GetNodeByPosition(ofVec2f i_Position);
	std::vector<int> GetNeighboringTileIndices(int i_Index) const;
	std::vector<Node*> GetNeighboringNodesOfNode(int i_Index) const;
	std::vector<Node*> GetNeighboringNodesOfNode(Node*& i_Node) const;

	void VisualizeGraph(bool i_Option) { m_bShouldVisualizeGraph = i_Option; }

	//If needed to visualize
	void Draw();

public:
	static const uint8_t PixelsPerTile = 4;
	static const uint8_t TileCost = 4;

private:
	ofImage m_Image;
	bool m_bShouldVisualizeGraph = false;
	uint32_t m_GridWidth = 0;
	uint32_t m_GridHeight = 0;
	std::vector<Node*> m_GraphNodes;
};

