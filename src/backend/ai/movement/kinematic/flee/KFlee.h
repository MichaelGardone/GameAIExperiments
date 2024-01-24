#pragma once

#include "ai/movement/SteeringBehavior.h"

namespace AI::Movement::Kinematic
{
	class KFlee : public SteeringBehavior
	{
	public:
		KFlee(Entity::GameObject* fleer);

		void set_target(const glm::vec2& target_position);

		virtual SteeringOutput* get_steering();

	protected:
		Entity::GameObject* self;
		glm::vec2 target_pos;
	};
}
