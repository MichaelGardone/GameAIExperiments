#include "FaceBoid.h"

namespace Frontend::Characters
{
	FaceBoid::FaceBoid(const glm::vec2& position, float rotation, float target_radius, float slow_radius, float time_to_target)
		: Boid(position, rotation)
	{
		m_behavior = new AI::Movement::Dynamic::Face(this, target_radius, slow_radius, time_to_target);
	}

	FaceBoid::~FaceBoid()
	{
		delete m_behavior;
	}

	void FaceBoid::update(float delta)
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

	void FaceBoid::set_target(Entity::GameObject* target)
	{
		m_target = target;
		m_behavior->set_target(m_target);
		m_target_set = true;
	}

	void FaceBoid::clear_target()
	{
		m_target_set = false;
	}
}
