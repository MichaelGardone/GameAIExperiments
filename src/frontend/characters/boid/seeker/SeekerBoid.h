#pragma once

#include "characters/boid/Boid.h"

#include "ai/movement/kinematic/seek/KSeek.h"

namespace Frontend::Characters
{
	class SeekerBoid : public Boid
	{
	public:
		SeekerBoid(const glm::vec2& position, float rotation);
		~SeekerBoid();

		virtual void update(float delta);

		void set_target(const glm::vec2& target);
		void clear_target();

	private:
		AI::Movement::Kinematic::KSeek* m_behavior;
		glm::vec2 m_target;
		bool m_target_set = false;
	};
}
