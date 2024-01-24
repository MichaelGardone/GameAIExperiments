#include "DSeek.h"

namespace AI::Movement::Dynamic
{
	DSeek::DSeek(Entity::GameObject* seeker)
	{
		m_self = seeker;
		m_target = NULL;
	}

	void DSeek::set_target(Entity::GameObject* target)
	{
		m_target = target;
	}

	SteeringOutput* DSeek::get_steering()
	{
		SteeringOutput* output = new SteeringOutput();

		output->linearVelocity = m_target->Transform->get_position() - m_self->Transform->get_position();

		output->linearVelocity = glm::normalize(output->linearVelocity);
		output->linearVelocity *= m_self->Rigidbody->get_max_acceleration();

		// Nein
		output->angularVelocity = 0;

		return output;
	}
}
