#include "DataTypes.h"
#include "of3dPrimitives.h"

void Kinematic::Update(KinematicSteeringOutput i_SteeringInput)
{
	Position += (Velocity * ofGetLastFrameTime());
	Orientation += (Rotation * ofGetLastFrameTime());
	Velocity += (i_SteeringInput.Velocity * ofGetLastFrameTime());
	Rotation = (i_SteeringInput.Rotation * ofGetLastFrameTime());
	if (Velocity.length() > 50)
	{
		Velocity = Velocity.normalize() * 50;
	}
	if (Position.x > (ofGetWidth() - 20))
	{
		Position.x = (ofGetWidth() - 20);
	}
	else if (Position.y > (ofGetHeight() - 20))
	{
		Position.y = ofGetHeight() - 20;
	}
	if (Position.x < 20)
	{
		Position.x = 20;
	}
	else if (Position.y < 20)
	{
		Position.y = 20;
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