#include "DWanderBoid.h"

namespace Frontend::EAE6900
{
	DWanderBoid::DWanderBoid(const glm::vec2& position, float rotation, float target_radius, float slow_radius, float time_to_target,
		float wander_offset, float wander_radius, float wander_rate)
		: Boid(position, rotation)
	{
		//m_behavior = new AI::EAE6900::Wander(this, target_radius, slow_radius, time_to_target, wander_offset, wander_radius, wander_rate);
	}

	DWanderBoid::~DWanderBoid()
	{
		delete m_behavior;
	}

	void DWanderBoid::update(float delta)
	{
		if (m_behavior != NULL)
		{
			AI::Movement::SteeringOutput* output = m_behavior->get_steering();
		
			if (output != NULL)
			{
				Boid::update(delta);
				Rigidbody->set_linear_velocity(Rigidbody->get_linear_velocity() + output->linearVelocity * delta);
				Rigidbody->set_angular_velocity(Rigidbody->get_angular_velocity() + output->angularVelocity * delta);

				delete output;
			}
			else
			{
				Rigidbody->set_linear_velocity(glm::vec2(0, 0));
				Rigidbody->set_angular_velocity(0);
			}
		}
	}
}