#pragma once

#include "characters/boid/Boid.h"
#include "eae6900/align/Align.h"

namespace Frontend::EAE6900
{
	class AlignBoid : public Frontend::Characters::Boid
	{
	public:
		AlignBoid(const glm::vec2& position, float rotation, float target_radius, float slow_radius, float time_to_target);
		~AlignBoid();

		virtual void update(float delta);

		void set_target(Entity::GameObject*);
		void clear_target();

	protected:
		AI::EAE6900::Align* m_behavior;
		bool m_target_set = false;
		Entity::GameObject* m_target;
	};
}
