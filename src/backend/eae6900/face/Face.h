#pragma once

#include "eae6900/align/Align.h"

namespace AI::EAE6900
{
	class Face : public Align
	{
	public:
		Face();
		AI::Movement::SteeringOutput* get_steering();
	};
}
