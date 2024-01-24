#pragma once

#include "Scene.h"
#include "characters/boid/Boid.h"
#include "characters/boid/face/FaceBoid.h"

namespace Scenes
{
	class FaceScene : public Backend::Scene
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
		Frontend::Characters::FaceBoid* m_boid;
	};
}
