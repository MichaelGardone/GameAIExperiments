#pragma once

#include "ai/movement/SteeringBehavior.h"

namespace AI::EAE6900
{
	class Align : public AI::Movement::SteeringBehavior
	{
	public:
		Align();

		virtual AI::Movement::SteeringOutput* get_steering();

	protected:
		
	};
}
