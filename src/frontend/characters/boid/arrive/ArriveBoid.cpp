#include "ArriveBoid.h"

namespace Frontend::Characters
{
	ArriveBoid::ArriveBoid(const glm::vec2& position, float rotation)
		: Boid(position, rotation)
	{
		m_behavior = new AI::Movement::Kinematic::KArrive(this, 15.f, 0.25f);
	}

	ArriveBoid::~ArriveBoid()
	{
		delete m_behavior;
	}

	void ArriveBoid::update(float delta)
	{
		if (m_target_set)
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

	void ArriveBoid::set_target(const glm::vec2& target)
	{
		m_target = target;
		m_behavior->set_target(m_target);
		m_target_set = true;
	}

	void ArriveBoid::clear_target()
	{
		m_target_set = false;
	}
}
