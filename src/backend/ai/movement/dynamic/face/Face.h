#pragma once

#include "ai/movement/dynamic/align/Align.h"

namespace AI::Movement::Dynamic
{
	class Face : public Align
	{
	public:
		Face(Entity::GameObject* self, float target_radius, float slow_radius, float time_to_target);
		SteeringOutput* get_steering();
	};
}
