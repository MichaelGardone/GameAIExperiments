#pragma once

#include "ai/movement/SteeringBehavior.h"

namespace AI::Movement::Kinematic
{
	class KWander : public SteeringBehavior
	{
		float maxRotationActuallyAllowed;
	public:
		KWander(Entity::GameObject* self, float maxRotAllowed = 0.1);

		virtual SteeringOutput* get_steering();

	protected:
		Entity::GameObject* m_self;
	};
}
