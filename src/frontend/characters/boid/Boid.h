#pragma once

#include "entity/GameObject.h"
#include "ai/movement/SteeringBehavior.h"

namespace Frontend::Characters
{
	class Boid : public Entity::GameObject
	{
	public:
		Boid(const glm::vec2& position, float rotation);
		virtual ~Boid();

		virtual void update(float delta);
		virtual void render();
	};
}

