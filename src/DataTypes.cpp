#include "DataTypes.h"
#include "of3dPrimitives.h"
#include "ofMain.h"

void Kinematic::Update(KinematicSteeringOutput i_SteeringInput)
{
	Velocity = (i_SteeringInput.Velocity * ofGetLastFrameTime());
	Rotation = (i_SteeringInput.Rotation * ofGetLastFrameTime());
	if (Velocity.length() > 500.0f)
	{
		Velocity = Velocity.normalize() * 500.0f;
	}

	Position += (Velocity * ofGetLastFrameTime());
	Orientation += (Rotation * ofGetLastFrameTime());
	
	
	if (Position.x > (ofGetViewportWidth() - 20.0f) || Position.y > (ofGetViewportHeight() - 20.0f) || Position.x < 20.0f || Position.y < 20.0f)
	{
		Position -= Velocity * ofGetLastFrameTime() * 10.0f;
		Orientation -= glm::radians(90.f);
	}

}

void Kinematic::Update(DynamicSteeringOutput i_SteeringInput)
{
	if ((i_SteeringInput.LinearAcceleration == ofVec2f(0,0)) && (i_SteeringInput.AngularAcceleration == 0))
	{
		Velocity = ofVec2f(0, 0);
		Rotation = 0;
	}
	Position += (Velocity * ofGetLastFrameTime());
	Orientation += (Rotation * ofGetLastFrameTime());
	Velocity += (i_SteeringInput.LinearAcceleration * ofGetLastFrameTime());
	Rotation += (i_SteeringInput.AngularAcceleration * ofGetLastFrameTime());
	if (Velocity.length() > 50)
	{
		Velocity = Velocity.normalize() * 50;
	}
}

DynamicSteeringOutput DynamicSteeringOutput::operator+(DynamicSteeringOutput & i_Dymamic)
{
	return DynamicSteeringOutput(LinearAcceleration + i_Dymamic.LinearAcceleration , AngularAcceleration + i_Dymamic.AngularAcceleration);
}

DynamicSteeringOutput DynamicSteeringOutput::operator-(DynamicSteeringOutput & i_Dymamic)
{
	return DynamicSteeringOutput(LinearAcceleration - i_Dymamic.LinearAcceleration, AngularAcceleration - i_Dymamic.AngularAcceleration);
}