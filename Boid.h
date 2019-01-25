#pragma once

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
	void Update();

private:

	Kinematic boidKinematicData;
	float circleRadius;
	ofVec2f triangleDimensions[3];
};

