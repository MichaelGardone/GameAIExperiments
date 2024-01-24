#pragma once

#include "characters/boid/Boid.h"
#include "ai/movement/dynamic/wander/Wander.h"

namespace Frontend::Characters
{
	class DWanderBoid : public Boid
	{
	public:
		DWanderBoid(const glm::vec2& position, float rotation, float target_radius, float slow_radius, float time_to_target,
			float wander_offset, float wander_radius, float wander_rate);
		~DWanderBoid();

		virtual void update(float delta);

	protected:
		AI::Movement::Dynamic::Wander* m_behavior;
	};
}
