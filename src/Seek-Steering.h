#pragma once
#include "Boid.h"

class SeekSteering
{
	public:
		SeekSteering() {}
		SeekSteering(float i_MaxSpeed);
		~SeekSteering() {}

		KinematicSteeringOutput GetSteering(Kinematic i_Boid, Kinematic i_Target, float i_MaxSpeed);
		float GetNewOrientation(float i_CurrentOrientation, ofVec2f i_Velocity);
		void Update();
		void SetPosition(ofVec2f i_Position);
		void Draw();

	private:
		Boid m_Boid;
		float m_MaxSpeed;
		ofVec2f initialPosition = ofVec2f(0, 0);
		ofVec2f finalPosition;
};
