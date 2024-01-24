#pragma once

#include <glm/glm.hpp>
#include <glm/vec2.hpp>

namespace Entity::Components
{
	class Rigidbody2D
	{
	public:
		Rigidbody2D(float maxSpeed, float maxAngularSpeed, float maxAcceleration);
		Rigidbody2D(const Rigidbody2D& other);

		void set_linear_velocity(const glm::vec2& new_vel);
		void set_angular_velocity(float new_vel);

		const glm::vec2& get_linear_velocity() { return curr_linear_velocity; }
		float get_angular_velocity() const{ return curr_angular_velocity; }

		float get_max_angular_speed() { return max_angular_speed; }
		float get_max_speed() { return max_linear_speed; }

		void set_max_lspeed(float speed);
		void set_max_aspeed(float speed);

		void set_max_acceleration(float new_accl);
		float get_max_acceleration() { return max_acceleration; }

		void set_max_angular_acceleration(float new_accl);
		float get_max_angular_acceleration() { return max_angular_acceleration; }

	protected:
		float max_linear_speed;
		float max_angular_speed;

		float max_acceleration;
		float max_angular_acceleration;

		glm::vec2 curr_linear_velocity;
		float curr_angular_velocity;
	};
}
