#pragma once

#include "DataTypes.h"
#include <ofVec3f.h>

class Boid
{
public:
	Boid();
	~Boid();
	void SetBoidKinematicData(Kinematic i_KinematicData);
	void SetBoidPosition(ofVec2f i_Position);
	void SetBoidRotation(float i_Rotation);
	void SetBoidVelocity(ofVec2f i_Velocity);
	void SetBoidOrientation(float i_Orientation);
	void Draw();
	void Update(KinematicSteeringOutput i_KinematicSteeringInput);
	void Update(DynamicSteeringOutput i_DynamicSteeringInput);
	void SetBoidColor(ofVec3f rgb);

	Kinematic GetBoidKinematicData() { return boidKinematicData; }


private:
	void DrawBreadCrumbs();

private:

	Kinematic boidKinematicData;
	float circleRadius = 10;
	float breadcrumbRadius = 2;
	ofVec2f triangleDimensions[3];
	std::vector<ofVec2f> breadCrumbPositions;
	float breadcrumbTimer = 0;
	ofVec2f initialPosition;
	ofVec3f m_Color;
};

