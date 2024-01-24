#include "SeekerBoid.h"

namespace Frontend::Characters
{
	SeekerBoid::SeekerBoid(const glm::vec2& position, float rotation)
		: Boid(position, rotation)
	{
		m_behavior = new AI::Movement::Kinematic::KSeek(this);
	}
	
	SeekerBoid::~SeekerBoid()
	{
		delete m_behavior;
	}

	void SeekerBoid::update(float delta)
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

	void SeekerBoid::set_target(const glm::vec2& target)
	{
		m_target = target;
		m_behavior->set_target(m_target);
		m_target_set = true;
	}

	void SeekerBoid::clear_target()
	{
		m_target_set = false;
	}
}
