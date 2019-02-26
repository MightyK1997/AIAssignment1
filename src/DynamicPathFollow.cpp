#include "DynamicPathFollow.h"
#include "DynamicLookWhereYouAreGoing.h"


bool IsPointInsideSlowRadius(ofVec2f i_Point, ofVec2f i_CharPos, float i_SlowRadius)
{
	return i_Point.distance(i_CharPos) < i_SlowRadius;
}

DynamicSteeringOutput DynamicPathFollow::GetSteering(Path i_Path, Kinematic i_Character, float i_maxSpeed, float i_TargetRadius, float i_SlowRadius, float i_MaxAcceleration, float i_TimeToTarget)
{
	DynamicSteeringOutput output;
	//if (i_Path.m_Path.empty()) return output;
	//auto tempPoint = i_Path.m_Path[currentPointCount];
	//Kinematic tempKinematic;
	//tempKinematic.Position = tempPoint;
	//DynamicArrive arrive;
	//DLookWhereYouAreGoing lwyg;
	//auto arr = arrive.GetSteering(i_Character, tempKinematic, i_maxSpeed, i_TargetRadius, i_SlowRadius, i_MaxAcceleration, i_maxSpeed);
	//auto look = lwyg.GetSteering(i_Character);
	//if (IsPointInsideSlowRadius(tempPoint, i_Character.Position, i_SlowRadius) && (currentPointCount < i_Path.m_Path.size() -1))
	//{
	//	currentPointCount++;
	//}
	return output;
}