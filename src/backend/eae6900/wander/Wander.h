#pragma once

#include "eae6900/face/Face.h"

#include "utility/Random.h"

namespace EAE6900
{
	class Wander : public AI::EAE6900::Face
	{
	public:
		Wander();

		virtual AI::Movement::SteeringOutput* get_steering();

	protected:

	};
}
