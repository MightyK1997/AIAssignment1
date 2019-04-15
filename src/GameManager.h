#pragma once
#include "Boid.h"
#include "ActionNode.h"
#include "DecisionNode.h"
#include <map>

class GameManager
{
public:
	ofVec2f GetPlayerPosition() const { return m_Player->GetBoidKinematicData().Position; }
	float GetDistanceToPlayer(ofVec2f i_CurrentPosition) const { return i_CurrentPosition.distance(m_Player->GetBoidKinematicData().Position); }
	bool CheckIfPlayerIsInRange();
	bool CheckIfPlayerIsInRanges();
	void SetPlayer(Boid* i_Player) { m_Player = i_Player; }
	void SetWanderNPC(Boid* i_NPC) { m_WanderNPC = i_NPC; }
	void SetNPCs(std::vector<Boid*> i_NPCs) { m_NPCs = i_NPCs; }
	void SetNPCs(Boid* i_NPC) { m_NPCs.push_back(i_NPC); }
	void AddActionNode(ActionNode* i_ActionNode,const std::string& i_Attribute) { m_ActionNodes[i_Attribute] = i_ActionNode; }
	void AddDecisionNode(DecisionNode* i_DecisionNode,const std::string& i_Attribute) { m_DecisionNodes[i_Attribute] = i_DecisionNode; }
	ActionNode* GetActionNodeForAttribute(std::string i_Attribute) { return m_ActionNodes[i_Attribute]; }
	DecisionNode* GetDecisionNodeForAttribute(std::string i_Attribute) { return m_DecisionNodes[i_Attribute]; }
private:
	Boid* m_Player = nullptr;
	Boid* m_WanderNPC = nullptr;
	std::vector<Boid*> m_NPCs;
	std::map<std::string, DecisionNode*> m_DecisionNodes;
	std::map<std::string, ActionNode*> m_ActionNodes;
};
