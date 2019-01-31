#include "DataTypes.h"
#include "of3dPrimitives.h"

void Kinematic::Update(KinematicSteeringOutput i_SteeringInput)
{
	Position += (Velocity * ofGetLastFrameTime());
	Orientation += (Rotation * ofGetLastFrameTime());
	Velocity += (i_SteeringInput.Velocity * ofGetLastFrameTime());
	Rotation += (i_SteeringInput.Rotation * ofGetLastFrameTime());
	if (Velocity.length() > 250)
	{
		Velocity = Velocity.normalize() * 250;
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