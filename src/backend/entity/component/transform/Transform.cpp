#include "Transform.h"

#include <iostream>

namespace Entity::Components
{
	Transform::Transform()
	{
		m_position = glm::vec2(0, 0);
		m_rotation = 0;
		m_scale = glm::vec2(1, 1);
	}

	Transform::Transform(float x, float y, float rotation)
	{
		m_position = glm::vec2(x, y);
		m_rotation = rotation;
		m_scale = glm::vec2(1, 1);
	}

	Transform::Transform(const glm::vec2& position, float rotation)
	{
		m_position = position;
		m_rotation = rotation;
		m_scale = glm::vec2(1, 1);
	}

	Transform::Transform(const Transform& other)
	{
		m_position = glm::vec2(other.m_position);
		m_rotation = other.m_rotation;
		m_scale = glm::vec2(m_scale);
	}

	Transform::~Transform() { }

	void Transform::set_position(float x, float y)
	{
		m_position.x = x;
		m_position.y = y;
	}

	void Transform::set_position(const glm::vec2& position)
	{
		m_position.x = position.x;
		m_position.y = position.y;
	}

	void Transform::set_x(float x)
	{
		m_position.x = x;
	}

	void Transform::set_y(float y)
	{
		m_position.y = y;
	}

	void Transform::set_rotation(float degs)
	{
		m_rotation = degs;
	}

	void Transform::set_rotation(const glm::vec2& direction)
	{
		m_rotation = atan2(direction.y, direction.x) * 180.f / glm::pi<float>();
	}

	void Transform::set_scale(float x, float y)
	{
		m_scale.x = x;
		m_scale.y = y;
	}

	void Transform::set_scale(const glm::vec2& scale)
	{
		m_scale.x = scale.x;
		m_scale.y = scale.y;
	}

	void Transform::set_x_scale(float x)
	{
		m_scale.x = x;
	}

	void Transform::set_y_scale(float y)
	{
		m_scale.y = y;
	}
}
