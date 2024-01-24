#pragma once

#include "ai/movement/SteeringBehavior.h"

namespace AI::Movement::Dynamic
{
	class DFlee : public SteeringBehavior
	{
	public:
		DFlee(Entity::GameObject* seeker);

		void set_target(Entity::GameObject* target);

		virtual SteeringOutput* get_steering();

	protected:
		Entity::GameObject* m_self;
		Entity::GameObject* m_target;
	};
}
