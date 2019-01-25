#include "DataTypes.h"
#include "of3dPrimitives.h"

void Kinematic::Update(KinematicSteeringOutput i_SteeringInput)
{
	Position += (Velocity * ofGetLastFrameTime());
	Orientation += (Rotation * ofGetLastFrameTime());
	Velocity = (i_SteeringInput.Velocity * ofGetLastFrameTime());
	Rotation = (i_SteeringInput.Rotation * ofGetLastFrameTime());
}

void Kinematic::Update(DynamicSteeringOutput i_SteeringInput)
{
	Position += (Velocity * ofGetLastFrameTime());
	Orientation = (Rotation * ofGetLastFrameTime());
	Velocity = (i_SteeringInput.LinearAcceleration * ofGetLastFrameTime());
	Rotation = (i_SteeringInput.AngularAcceleration * ofGetLastFrameTime());
}
