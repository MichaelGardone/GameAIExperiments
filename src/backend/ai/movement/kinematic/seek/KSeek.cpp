#include "KSeek.h"

namespace AI::Movement::Kinematic
{
	KSeek::KSeek(Entity::GameObject* seeker)
	{
		self = seeker;
	}

	void KSeek::set_target(const glm::vec2& target_position)
	{
		target_pos = target_position;
	}

	SteeringOutput* KSeek::get_steering()
	{
		SteeringOutput* output = new SteeringOutput();

		output->linearVelocity = target_pos - self->Transform->get_position();

		if (glm::length2(output->linearVelocity) > 0)
		{
			output->linearVelocity = glm::normalize(output->linearVelocity);
			output->linearVelocity *= self->Rigidbody->get_max_speed();

			self->Transform->set_rotation(get_rotation_from_velocity(output->linearVelocity, self->Transform->get_rotation()));
		}

		// Nein
		output->angularVelocity = 0;

		return output;
	}
}
