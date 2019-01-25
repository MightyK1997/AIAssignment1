#include "KinematicSeek.h"

void KinematicSeek::Draw()
{
	boid.Draw();
}

void KinematicSeek::Update()
{

	output.Velocity = ofVec2f(1000, 0);

	boid.Update(output);
}
