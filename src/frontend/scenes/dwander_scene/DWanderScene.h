#pragma once

#include "Scene.h"
#include "characters/boid/Boid.h"
#include "characters/boid/dynamic_wander/DWanderBoid.h"

namespace Scenes
{
	class DWanderScene : public Backend::Scene
	{
	public:
		virtual void setup();

		virtual void update(float delta);
		virtual void draw();

		virtual void key_pressed(int);
		virtual void key_released(int);

		virtual void mouse_pressed(int, int, int);
		virtual void mouse_released(int, int, int);

	protected:
		Frontend::Characters::Boid* m_target_boid;
		Frontend::Characters::DWanderBoid* m_boid;
	};
}
