#include "Wander.h"

namespace AI::Movement::Dynamic
{
	Wander::Wander(Entity::GameObject* self, float target_radius, float slow_radius, float time_to_target,
		float wander_offset, float wander_radius, float wander_rate)
		: Face(self, target_radius, slow_radius, time_to_target)
	{
		m_wander_offset = wander_offset;
		m_wander_radius = wander_radius;
		m_wander_rate = wander_rate;

		// make a copy of self -- wander is forwards
		m_target = new Entity::GameObject(*self);
	}

	void Wander::set_target(Entity::GameObject* self)
	{
		// do nothing, ignore this
	}

	SteeringOutput* Wander::get_steering()
	{
		m_wander_orientation += RandomBinomial() * m_wander_rate;

		float target_rotation = m_wander_orientation + m_self->Transform->get_rotation();
		glm::vec2 target = m_self->Transform->get_position() + m_wander_offset * m_self->Transform->get_rotation_as_vec2();

		target += m_wander_radius * glm::vec2(cos(target_rotation), sin(target_rotation));

		m_target->Transform->set_position(target);

		SteeringOutput* output = Face::get_steering();

		output->linearVelocity = m_self->Rigidbody->get_max_acceleration() * m_self->Transform->get_rotation_as_vec2();

		return output;
	}
}
