#pragma once
#include "ofVec2f.h"

struct DynamicSteeringOutput
{
	ofVec2f LinearAcceleration;
	float AngularAcceleration;
};

struct KinematicSteeringOutput
{
	ofVec2f Velocity;
	float Rotation;
};

class Kinematic
{
public:
	ofVec2f Position;
	float Orientation;
	ofVec2f Velocity;
	float Rotation;

	void Update(KinematicSteeringOutput i_SteeringInput);
	void Update(DynamicSteeringOutput i_SteeringInput);


private:

	float mMaxVelocity;
};