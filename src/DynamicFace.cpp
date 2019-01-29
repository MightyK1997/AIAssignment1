#include "DynamicFace.h"
#include "DynamicAlign.h"

DynamicSteeringOutput DynamicFace::GetSteering(Kinematic i_Character, Kinematic i_Target)
{
	DynamicSteeringOutput steering;
	auto direction = i_Target.Position - i_Character.Position;
	if (direction.length() == 0) return steering;

	Kinematic arriveTarget;
	arriveTarget = i_Target;
	arriveTarget.Orientation = atan2(-direction.x, direction.y);

	DynamicAlign align;
	return align.GetSteering(i_Character, 0.5f, 0.5f, 1.0f, 0.5f, 10, i_Target);
}
