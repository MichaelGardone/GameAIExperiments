#include "Align.h"

namespace AI::Movement::Dynamic
{
	Align::Align(Entity::GameObject* self, float target_radius, float slow_radius, float time_to_target)
	{
		m_self = self;
		m_target_radius = target_radius;
		m_slow_radius = slow_radius;
		m_time_to_target = time_to_target;
		m_target = NULL;
	}

	void Align::set_target(Entity::GameObject* target)
	{
		m_target = target;
	}

	SteeringOutput* Align::get_steering()
	{
		// get and normalize rotation
		float rot = ofWrapRadians((m_target->Transform->get_rotation() * PI / 180 - m_self->Transform->get_rotation() * PI / 180));
		float rotSize = abs(rot);

		SteeringOutput* output = new SteeringOutput();
		if (rotSize < m_target_radius)
		{
			output->angularVelocity = 0;
			return output;
		}

		float target_rot_speed;
		if (rotSize > m_slow_radius)
			target_rot_speed = m_target->Rigidbody->get_max_angular_speed();
		else
			target_rot_speed = m_target->Rigidbody->get_max_angular_speed() * rotSize / m_slow_radius;


		target_rot_speed *= rot / rotSize;

		output->angularVelocity = target_rot_speed - m_self->Transform->get_rotation() * PI / 180;
		output->angularVelocity /= m_time_to_target;

		float angularAccel = abs(output->angularVelocity);
		if (angularAccel > m_self->Rigidbody->get_max_angular_acceleration())
		{
			output->angularVelocity /= angularAccel;
			output->angularVelocity *= m_self->Rigidbody->get_max_angular_acceleration();
		}

		output->linearVelocity = glm::vec2(0, 0);
		return output;
	}
}
