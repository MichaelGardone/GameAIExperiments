#include "WanderBoid.h"

namespace Frontend::Characters
{
	WanderBoid::WanderBoid(const glm::vec2& position, float rotation)
		: Boid(position, rotation)
	{
		m_behavior = new AI::Movement::Kinematic::KWander(this, 0.05f);
	}

	WanderBoid::~WanderBoid()
	{
		delete m_behavior;
	}

	void WanderBoid::update(float delta)
	{
		Boid::update(delta);

		AI::Movement::SteeringOutput* output = m_behavior->get_steering();

		Rigidbody->set_linear_velocity(Rigidbody->get_linear_velocity() + output->linearVelocity * delta);
		Rigidbody->set_angular_velocity(Rigidbody->get_angular_velocity() + output->angularVelocity * delta);

		delete output;
	}
}
