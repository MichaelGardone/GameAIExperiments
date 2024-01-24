#include "GameObject.h"

namespace Entity
{
	GameObject::GameObject()
	{
		Transform = new Entity::Components::Transform();
		Rigidbody = new Entity::Components::Rigidbody2D(40.f, 15.f, 5.f);
	}

	GameObject::GameObject(float x, float y, float rotation)
	{
		Transform = new Entity::Components::Transform(x, y, rotation);
		Rigidbody = new Entity::Components::Rigidbody2D(40.f, 15.f, 5.f);
	}

	GameObject::GameObject(const glm::vec2& position, float rotation)
	{
		Transform = new Entity::Components::Transform(position, rotation);
		Rigidbody = new Entity::Components::Rigidbody2D(40.f, 15.f, 5.f);
	}

	GameObject::GameObject(const GameObject& other)
	{
		Transform = new Entity::Components::Transform(*(other.Transform));
		Rigidbody = new Entity::Components::Rigidbody2D(*(other.Rigidbody));
	}

	GameObject::~GameObject()
	{
		delete Transform;
		delete Rigidbody;
	}

	void GameObject::update(float delta) {}
	void GameObject::render() {}
}
