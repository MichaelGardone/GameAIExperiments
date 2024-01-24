#pragma once

#include <ofMain.h>

#include "component/transform/Transform.h"
#include "component/rigidbody2d/Rigidbody2D.h"

namespace Entity
{
	class GameObject
	{
	public:
		GameObject();
		GameObject(float x, float y, float rotation);
		GameObject(const GameObject& other);
		GameObject(const glm::vec2& position, float rotation);

		virtual ~GameObject();

		virtual void update(float delta);
		virtual void render();

		Entity::Components::Transform* Transform;
		Entity::Components::Rigidbody2D* Rigidbody;
	};
}
