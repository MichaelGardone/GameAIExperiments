#pragma once

#include "characters/boid/Boid.h"
#include "ai/movement/kinematic/arrive/KArrive.h"

namespace Frontend::Characters
{
	class ArriveBoid : public Boid
	{
	public:
		ArriveBoid(const glm::vec2& position, float rotation);
		~ArriveBoid();

		virtual void update(float delta);

		void set_target(const glm::vec2& target);
		void clear_target();

	private:
		AI::Movement::Kinematic::KArrive* m_behavior;
		glm::vec2 m_target;
		bool m_target_set = false;
	};
}
