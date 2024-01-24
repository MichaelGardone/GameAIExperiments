#pragma once

#include "ai/movement/SteeringBehavior.h"

namespace AI::Movement::Dynamic
{
	class DSeek : public SteeringBehavior
	{
	public:
		DSeek(Entity::GameObject* seeker);

		void set_target(Entity::GameObject* target);

		virtual SteeringOutput* get_steering();

	protected:
		Entity::GameObject* m_self;
		Entity::GameObject* m_target;
	};
}
