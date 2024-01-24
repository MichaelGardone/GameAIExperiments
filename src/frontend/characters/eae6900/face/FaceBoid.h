#pragma once

#include "characters/boid/Boid.h"
#include "eae6900/face/Face.h"

namespace Frontend::EAE6900
{
	class FaceBoid : public Frontend::Characters::Boid
	{
	public:
		FaceBoid(const glm::vec2& position, float rotation, float target_radius, float slow_radius, float time_to_target);
		~FaceBoid();

		virtual void update(float delta);

		void set_target(Entity::GameObject*);
		void clear_target();

	protected:
		AI::EAE6900::Face* m_behavior;
		bool m_target_set = false;
		Entity::GameObject* m_target;
	};
}

