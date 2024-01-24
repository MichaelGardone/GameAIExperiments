#include "KSeekerScene.h"

#include "characters/boid/seeker/SeekerBoid.h"

namespace Scenes
{
	void KSeekerScene::setup()
	{
		boid = new Frontend::Characters::SeekerBoid(glm::vec2(500, 500), 0);
		boid->Rigidbody->set_max_lspeed(250.f);
		boid->Rigidbody->set_max_aspeed(1.f);
	}

	void KSeekerScene::update(float delta)
	{
		boid->update(delta);
	}

	void KSeekerScene::draw()
	{
		boid->render();
	}

	void KSeekerScene::key_pressed(int keycode)
	{

	}

	void KSeekerScene::key_released(int keycode)
	{

	}

	void KSeekerScene::mouse_pressed(int x, int y, int button)
	{
		if (button == 0)
			boid->set_target(glm::vec2(x, y));
		if (button == 2)
			boid->clear_target();
	}

	void KSeekerScene::mouse_released(int x, int y, int button)
	{

	}
}
