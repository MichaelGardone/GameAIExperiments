#include "Face.h"

namespace AI::Movement::Dynamic
{
	Face::Face(Entity::GameObject* self, float target_radius, float slow_radius, float time_to_target)
		: Align(self, target_radius, slow_radius, time_to_target)
	{ }

	SteeringOutput* Face::get_steering()
	{
		glm::vec2 direction = m_target->Transform->get_position() - m_self->Transform->get_position();
		float dirMag = glm::length2(direction);
		
		// Hold a copy of the original rotation in degrees
		float rotation = m_target->Transform->get_rotation();
		
		if (dirMag > 0)
		{
			m_target->Transform->set_rotation(direction);
		}

		SteeringOutput* output = Align::get_steering();

		// Pop it back in place if we actually did modify rotation
		if (dirMag > 0)
			m_target->Transform->set_rotation(rotation);

		return output;
	}
}

