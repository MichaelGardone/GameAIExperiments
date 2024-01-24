#pragma once

#include "characters/boid/Boid.h"
#include "ai/movement/kinematic/flee/KFlee.h"

namespace Frontend::Characters
{
	class FleerBoid : public Boid
	{
	public:
		FleerBoid(const glm::vec2& position, float rotation);
		~FleerBoid();

		virtual void update(float delta);

		void set_target(const glm::vec2& target);
		void clear_target();

	private:
		AI::Movement::Kinematic::KFlee* m_behavior;
		glm::vec2 m_target;
		bool m_target_set = false;
	};
}
