#include "Boid.h"
#include "ofGraphics.h"
#include "of3dPrimitives.h"


Boid::Boid()
{
	boidKinematicData.Position = ofVec2f(10, 10);
	initialPosition = boidKinematicData.Position;
}


Boid::~Boid()
{
}

void Boid::SetBoidKinematicData(Kinematic i_KinematicData)
{
	boidKinematicData = i_KinematicData;
}

void Boid::SetBoidPosition(ofVec2f i_Position)
{
	boidKinematicData.Position = i_Position;
}

void Boid::SetBoidRotation(float i_Rotation)
{
	boidKinematicData.Rotation = i_Rotation;
}

void Boid::SetBoidVelocity(ofVec2f i_Velocity)
{
	boidKinematicData.Velocity = i_Velocity;
}

void Boid::SetBoidOrientation(float i_Orientation)
{
	boidKinematicData.Orientation = i_Orientation;
}

void Boid::Draw()
{
	ofSetBackgroundColor(255, 0, 0);

	ofPushMatrix(); 

	circleRadius = 10;
	triangleDimensions[0] = boidKinematicData.Position + ofVec2f(0,10);
	triangleDimensions[1] = boidKinematicData.Position + ofVec2f(20,0);
	triangleDimensions[2] = boidKinematicData.Position - ofVec2f(0, 10);

	//ofTranslate(20, 10);
	ofRotateZ(boidKinematicData.Orientation);

	ofDrawCircle(boidKinematicData.Position, circleRadius);
	ofDrawTriangle(triangleDimensions[0], triangleDimensions[1], triangleDimensions[2]);
	ofPopMatrix();

	if (boidKinematicData.Position != initialPosition)
	{
		breadcrumbTimer += ofGetLastFrameTime();
		if (breadcrumbTimer >= 0.5f)
		{
			breadCrumbPositions.push_back(boidKinematicData.Position);
			breadcrumbTimer = 0;
		}
	}
	DrawBreadCrumbs();
}

void Boid::Update(KinematicSteeringOutput i_KinematicSteeringInput)
{
	if (boidKinematicData.Position.x > (ofGetWidth()))
	{
		i_KinematicSteeringInput.Velocity = ofVec2f(0, 0);
		i_KinematicSteeringInput.Rotation = 0;
		boidKinematicData.Position.x = (ofGetWidth() - 20);
	}
	else if (boidKinematicData.Position.y > (ofGetHeight()))
	{
		i_KinematicSteeringInput.Velocity = ofVec2f(0, 0);
		i_KinematicSteeringInput.Rotation = 0;
		boidKinematicData.Position.y = ofGetHeight() - 10;
	}
	boidKinematicData.Update(i_KinematicSteeringInput);
}

void Boid::Update(DynamicSteeringOutput i_DynamicSteeringInput)
{
	if (boidKinematicData.Position.x > (ofGetWidth() - 20))
	{
		i_DynamicSteeringInput.LinearAcceleration = ofVec2f(0, 0);
		i_DynamicSteeringInput.AngularAcceleration = 0;
	}
	else if (boidKinematicData.Position.x > (ofGetHeight() - 10))
	{
		i_DynamicSteeringInput.LinearAcceleration = ofVec2f(0, 0);
		i_DynamicSteeringInput.AngularAcceleration = 0;
	}
	boidKinematicData.Update(i_DynamicSteeringInput);
}

void Boid::DrawBreadCrumbs()
{
	for (auto& a : breadCrumbPositions)
	{
		ofDrawCircle(a, breadcrumbRadius);
	}
}
