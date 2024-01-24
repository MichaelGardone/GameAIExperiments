#include "FleerBoid.h"

namespace Frontend::Characters
{
	FleerBoid::FleerBoid(const glm::vec2& position, float rotation)
		: Boid(position, rotation)
	{
		m_behavior = new AI::Movement::Kinematic::KFlee(this);
	}

	FleerBoid::~FleerBoid()
	{
		delete m_behavior;
	}

	void FleerBoid::update(float delta)
	{
		if (m_target_set)
		{
			Boid::update(delta);

			AI::Movement::SteeringOutput* output = m_behavior->get_steering();

			Rigidbody->set_linear_velocity(Rigidbody->get_linear_velocity() + output->linearVelocity * delta);
			Rigidbody->set_angular_velocity(Rigidbody->get_angular_velocity() + output->angularVelocity * delta);

			delete output;
		}
	}

	void FleerBoid::set_target(const glm::vec2& target)
	{
		m_target = target;
		m_behavior->set_target(m_target);
		m_target_set = true;
	}

	void FleerBoid::clear_target()
	{
		m_target_set = false;
	}
}
