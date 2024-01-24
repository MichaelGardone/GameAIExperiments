#pragma once

#include "characters/boid/Boid.h"
#include "ai/movement/dynamic/align/Align.h"

namespace Frontend::Characters
{
	class AlignBoid : public Boid
	{
	public:
		AlignBoid(const glm::vec2& position, float rotation, float target_radius, float slow_radius, float time_to_target);
		~AlignBoid();

		virtual void update(float delta);

		void set_target(Entity::GameObject*);
		void clear_target();

	protected:
		AI::Movement::Dynamic::Align* m_behavior;
		bool m_target_set = false;
		Entity::GameObject* m_target;
	};
}
