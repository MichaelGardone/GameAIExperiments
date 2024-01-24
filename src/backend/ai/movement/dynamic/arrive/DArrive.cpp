#include "DArrive.h"

namespace AI::Movement::Dynamic
{
	DArrive::DArrive(Entity::GameObject* self, float target_radius, float slow_radius, float time_to_target)
	{
		m_self = self;
		m_target_radius = target_radius;
		m_slow_radius = slow_radius;
		m_time_to_target = time_to_target;
		m_target = NULL;
	}

	void DArrive::set_target(Entity::GameObject* target)
	{
		m_target = target;
	}

	SteeringOutput* DArrive::get_steering()
	{
		glm::vec2 dir = m_target->Transform->get_position() - m_self->Transform->get_position();
		float dist = glm::length(dir);
		
		if (dist < m_target_radius)
		{
			return NULL;
		}

		float target_speed;

		if (dist > m_slow_radius)
		{
			target_speed = m_target->Rigidbody->get_max_speed();
		}
		else
		{
			target_speed = m_target->Rigidbody->get_max_speed() * dist / m_slow_radius;
		}

		SteeringOutput* output = new SteeringOutput();
		output->linearVelocity = glm::normalize(dir) * target_speed;

		if (glm::length(output->linearVelocity) > m_self->Rigidbody->get_max_acceleration())
		{
			output->linearVelocity = glm::normalize(output->linearVelocity);
			output->linearVelocity *= m_self->Rigidbody->get_max_acceleration();
		}

		output->angularVelocity = 0;
		return output;
	}
}
