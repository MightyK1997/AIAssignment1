#pragma once
#include "DataTypes.h"
#include "Boid.h"


class KinematicSeek 
{
public:
	void Draw();
	void Update();

private:
	Boid boid;
	KinematicSteeringOutput output;
};