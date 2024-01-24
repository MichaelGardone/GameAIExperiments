#include "Rigidbody2D.h"

namespace Entity::Components
{
	Rigidbody2D::Rigidbody2D(float max_lin_speed, float max_ang_speed, float maxAcceleration)
	{
		max_linear_speed = max_lin_speed;
		max_angular_speed = max_ang_speed;
		max_acceleration = maxAcceleration;

		curr_linear_velocity = glm::vec2(0,0);
		curr_angular_velocity = 0;
	}

	Rigidbody2D::Rigidbody2D(const Rigidbody2D& other)
	{
		max_linear_speed = other.max_linear_speed;
		max_acceleration = other.max_acceleration;

		max_angular_speed = other.max_angular_speed;
		max_angular_acceleration = other.max_angular_acceleration;
	}

	void Rigidbody2D::set_linear_velocity(const glm::vec2& new_vel)
	{
		curr_linear_velocity = new_vel;

		if (glm::length(curr_linear_velocity) > max_linear_speed)
		{
			curr_linear_velocity = glm::normalize(curr_linear_velocity);
			curr_linear_velocity *= max_linear_speed;
		}
	}

	void Rigidbody2D::set_angular_velocity(float new_vel)
	{
		curr_angular_velocity = new_vel;
	}

	void Rigidbody2D::set_max_lspeed(float speed)
	{
		max_linear_speed = speed;
	}

	void Rigidbody2D::set_max_aspeed(float speed)
	{
		max_angular_speed = speed;
	}

	void Rigidbody2D::set_max_acceleration(float new_accl)
	{
		max_acceleration = new_accl;
	}

	void Rigidbody2D::set_max_angular_acceleration(float new_accl)
	{
		max_angular_acceleration = new_accl;
	}
}
