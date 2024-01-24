#include "KArrive.h"

namespace AI::Movement::Kinematic
{
	KArrive::KArrive(Entity::GameObject* self, float stopping_radius, float time_to_target)
	{
		m_self = self;
		m_stopping_radius = stopping_radius;
		m_time_to_target = time_to_target;
	}

	void KArrive::set_target(glm::vec2 target_position)
	{
		m_target_position = target_position;
	}

	SteeringOutput* KArrive::get_steering()
	{
		SteeringOutput* result = new SteeringOutput();

		result->linearVelocity = m_target_position - m_self->Transform->get_position();

		float length = glm::length(result->linearVelocity);

		if (length < m_stopping_radius)
		{
			delete result;
			return NULL;
		}

		result->linearVelocity /= m_time_to_target;

		if (length > m_self->Rigidbody->get_max_speed())
		{
			result->linearVelocity = glm::normalize(result->linearVelocity);
			result->linearVelocity *= m_self->Rigidbody->get_max_speed();
		}

		m_self->Transform->set_rotation(get_rotation_from_velocity(result->linearVelocity, m_self->Transform->get_rotation()));

		result->angularVelocity = 0;
		return result;
	}
}
