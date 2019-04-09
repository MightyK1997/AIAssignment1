#pragma once
#include "Boid.h"

class World
{
	World() = default;
	World(Boid* i_Player):m_Player(i_Player){}
	~World() = default;
	ofVec2f GetPlayerLocation() const { return m_Player->GetBoidKinematicData().Position; }
private:
	Boid* m_Player = nullptr;

};
