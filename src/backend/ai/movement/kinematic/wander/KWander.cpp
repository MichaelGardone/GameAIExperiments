#include "KWander.h"

#include "utility/Random.h"

namespace AI::Movement::Kinematic
{
	KWander::KWander(Entity::GameObject* self, float maxRotAllowed)
	{
		m_self = self;
		maxRotationActuallyAllowed = maxRotAllowed;
	}

	SteeringOutput* KWander::get_steering()
	{
		SteeringOutput* output = new SteeringOutput();

		// set the linear velocity
		output->linearVelocity = m_self->Rigidbody->get_max_speed() * m_self->Transform->get_rotation_as_vec2();

		// set the direction we want to face
		output->angularVelocity = RandomBinomial() * m_self->Rigidbody->get_max_angular_speed() * maxRotationActuallyAllowed;

		return output;
	}
}
