#pragma once

#include "characters/boid/Boid.h"
#include "eae6900/wander/Wander.h"

namespace Frontend::EAE6900
{
	class DWanderBoid : public Frontend::Characters::Boid
	{
	public:
		DWanderBoid(const glm::vec2& position, float rotation, float target_radius, float slow_radius, float time_to_target,
			float wander_offset, float wander_radius, float wander_rate);
		~DWanderBoid();

		virtual void update(float delta);

	protected:
		AI::EAE6900::Align* m_behavior = NULL;
	};
}
