#pragma once

#include "Scene.h"
#include "characters/boid/Boid.h"
#include "characters/boid/dynamic_wander/DWanderBoid.h"

#include "characters/eae6900/dynamic_wander/DWanderBoid.h"
#include "characters/eae6900/align/AlignBoid.h"
#include "characters/eae6900/face/FaceBoid.h"

namespace Scenes
{
	class EAE6900Scene : public Backend::Scene
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
		// My boid put out
		Frontend::Characters::DWanderBoid* m_my_boid;

		Frontend::Characters::Boid* m_target_boid;
		Frontend::EAE6900::AlignBoid* m_align_boid;
		Frontend::EAE6900::FaceBoid* m_face_boid;
		Frontend::EAE6900::DWanderBoid* m_their_boid;

		// 0 = my stuff, 1 = align, 2 = face, 3 = wander :)
		int curr_scene = 0;

	};
}
