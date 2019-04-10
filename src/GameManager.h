#pragma once
#include "Boid.h"

class GameManager
{
public:
	ofVec2f GetPlayerPosition() const { return m_Player->GetBoidKinematicData().Position; }
	float GetDistanceToPlayer(ofVec2f i_CurrentPosition) const { return i_CurrentPosition.distance(m_Player->GetBoidKinematicData().Position); }
	bool CheckIfPlayerIsInRange();
	void SetPlayer(Boid* i_Player) { m_Player = i_Player; }
	void SetWanderNPC(Boid* i_NPC) { m_WanderNPC = i_NPC; }
	void SetNPCs(std::vector<Boid*> i_NPCs) { m_NPCs = i_NPCs; }
	void SetNPCs(Boid* i_NPC) { m_NPCs.push_back(i_NPC); }
private:
	Boid* m_Player = nullptr;
	Boid* m_WanderNPC = nullptr;
	std::vector<Boid*> m_NPCs;
};
