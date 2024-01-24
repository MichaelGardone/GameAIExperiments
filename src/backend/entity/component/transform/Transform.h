#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace Entity::Components
{
	class Transform
	{
	public:
		Transform();
		Transform(float x, float y, float rotation);
		Transform(const glm::vec2& position, float rotation);
		Transform(const Transform& other);
		~Transform();

		void set_position(float x, float y);
		void set_position(const glm::vec2& position);
		void set_x(float x);
		void set_y(float y);
		float get_xpos() const { return m_position.x; }
		float get_ypos() const { return m_position.y; }
		const glm::vec2& get_position() const { return m_position; }

		void set_rotation(float degs);
		void set_rotation(const glm::vec2& direction);
		float get_rotation() { return m_rotation; }
		const glm::vec2& get_rotation_as_vec2() { return glm::vec2(cos(m_rotation), sin(m_rotation)); }
		glm::vec2 get_rotation_as_modifiable_vec2() { return glm::vec2(cos(m_rotation), sin(m_rotation)); }

		void set_scale(float x, float y);
		void set_scale(const glm::vec2& scale);
		void set_x_scale(float x);
		void set_y_scale(float y);
		const glm::vec2& get_scale() const { return m_scale; }

		
	private:
		glm::vec2 m_position;
		glm::vec2 m_scale;

		float m_rotation;
	};
}

