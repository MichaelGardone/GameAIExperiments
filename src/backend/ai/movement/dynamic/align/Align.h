#pragma once

#include "ai/movement/SteeringBehavior.h"

namespace AI::Movement::Dynamic
{
	class Align : public SteeringBehavior
	{
	public:
		Align(Entity::GameObject* self, float target_radius, float slow_radius, float time_to_target);

		void set_target(Entity::GameObject* target);

		virtual SteeringOutput* get_steering();

	protected:
		Entity::GameObject* m_self;
		Entity::GameObject* m_target;

		float m_target_radius;
		float m_slow_radius;
		float m_time_to_target;
	};
}
