#pragma once

#include "ai/movement/SteeringBehavior.h"
#include "entity/GameObject.h"

namespace AI::Movement::Kinematic
{
	class KArrive : public SteeringBehavior
	{
	public:
		KArrive(Entity::GameObject* self, float stopping_radius, float time_to_target);

		void set_target(glm::vec2 target_position);

		virtual SteeringOutput* get_steering();

	private:
		Entity::GameObject* m_self;
		glm::vec2 m_target_position;
		float m_stopping_radius;
		float m_time_to_target;
	};
}
