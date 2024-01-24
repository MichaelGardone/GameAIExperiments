#include "KFlee.h"

namespace AI::Movement::Kinematic
{
	KFlee::KFlee(Entity::GameObject* fleer)
	{
		self = fleer;
	}

	void KFlee::set_target(const glm::vec2& target_position)
	{
		target_pos = target_position;
	}

	SteeringOutput* KFlee::get_steering()
	{
		SteeringOutput* output = new SteeringOutput();

		output->linearVelocity = self->Transform->get_position() - target_pos;

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
