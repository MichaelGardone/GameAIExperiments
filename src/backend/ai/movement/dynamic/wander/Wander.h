#pragma once

#include "ai/movement/dynamic/face/Face.h"

#include "utility/Random.h"

namespace AI::Movement::Dynamic
{
	class Wander : public Face
	{
	public:
		Wander(Entity::GameObject* self, float target_radius, float slow_radius, float time_to_target,
			float wander_offset, float wander_radius, float wanderRate);

		virtual SteeringOutput* get_steering();
		virtual void set_target(Entity::GameObject* self);

	protected:
		float m_wander_offset;
		float m_wander_radius;
		float m_wander_rate;
		float m_wander_orientation;
	};
}
