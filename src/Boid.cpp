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
	ofSetColor(m_Color.x, m_Color.y, m_Color.z);
	ofSetBackgroundColor(255, 0, 0);
	ofDrawCircle(boidKinematicData.Position, circleRadius);

	auto triangleHeight = sqrt(3) * 10;

	auto ax = circleRadius;
	auto ay = triangleHeight;
	auto bx = circleRadius;
	auto by = -triangleHeight;
	auto cx = circleRadius + triangleHeight;
	auto cy = 0.0f;

	ofPushMatrix(); 
	ofTranslate(boidKinematicData.Position);
	ofRotateRad(boidKinematicData.Orientation);
	ofDrawTriangle(ax, ay, bx, by, cx, cy);
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
		boidKinematicData.Position.x -= ofGetWidth();
	}
	else if (boidKinematicData.Position.y > (ofGetHeight()))
	{
		boidKinematicData.Position.y -= ofGetHeight();
	}
	boidKinematicData.Update(i_KinematicSteeringInput);
}

void Boid::Update(DynamicSteeringOutput i_DynamicSteeringInput)
{
	if (boidKinematicData.Position.x > (ofGetWidth()))
	{
		boidKinematicData.Position.x -= ofGetWidth();
	}
	else if (boidKinematicData.Position.y > (ofGetHeight()))
	{
		boidKinematicData.Position.y -= ofGetHeight();
	}
	else if (boidKinematicData.Position.x < 0)
	{
		boidKinematicData.Position.x += ofGetWidth();
	}
	else if (boidKinematicData.Position.y < 0)
	{
		boidKinematicData.Position.y += ofGetHeight();
	}
	boidKinematicData.Update(i_DynamicSteeringInput);
}

void Boid::SetBoidColor(ofVec3f rgb)
{
	m_Color = rgb;
}

void Boid::DrawBreadCrumbs()
{
	for (auto& a : breadCrumbPositions)
	{
		ofDrawCircle(a, breadcrumbRadius);
	}
}
