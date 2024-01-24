#pragma once

#include "characters/boid/Boid.h"
#include "ai/movement/kinematic/wander/KWander.h"

namespace Frontend::Characters
{
	class WanderBoid : public Boid
	{
	public:
		WanderBoid(const glm::vec2& position, float rotation);
		~WanderBoid();

		virtual void update(float delta);

	private:
		AI::Movement::Kinematic::KWander* m_behavior;
	};
}
