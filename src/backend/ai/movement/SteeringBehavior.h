#pragma once

#include "entity/GameObject.h"

namespace AI::Movement
{
	struct SteeringOutput
	{
		glm::vec2 linearVelocity;	// change of position
		float angularVelocity;		// change of rotation
	};

	class SteeringBehavior
	{
	public:
		virtual SteeringOutput* get_steering() = 0;

		float get_rotation_from_velocity(const glm::vec2 vel, float default_rot)
		{
			if (glm::length2(vel) > 0)
			{
				return 180 / PI * atan2(vel.y, vel.x);
			}
			return default_rot;
		}
	};
}
