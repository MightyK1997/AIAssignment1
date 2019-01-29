#pragma once
#include "ofVec2f.h"

struct DynamicSteeringOutput
{
	ofVec2f LinearAcceleration = ofVec2f(0,0);
	float AngularAcceleration = 0;
};

struct KinematicSteeringOutput
{
	ofVec2f Velocity = ofVec2f(0, 0);
	float Rotation = 0;
};

class Kinematic
{
public:
	ofVec2f Position;
	float Orientation = 0;
	ofVec2f Velocity;
	float Rotation = 0;

	void Update(KinematicSteeringOutput i_SteeringInput);
	void Update(DynamicSteeringOutput i_SteeringInput);


private:

	float mMaxVelocity;
};