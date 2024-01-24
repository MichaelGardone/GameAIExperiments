#include "KFleerScene.h"

namespace Scenes
{
	void KFleerScene::setup()
	{
		boid = new Frontend::Characters::FleerBoid(glm::vec2(100, 100), 0);
		boid->Rigidbody->set_max_lspeed(250.f);
	}

	void KFleerScene::update(float delta)
	{
		boid->update(delta);
	}

	void KFleerScene::draw()
	{
		boid->render();
	}

	void KFleerScene::key_pressed(int keycode)
	{

	}

	void KFleerScene::key_released(int keycode)
	{

	}

	void KFleerScene::mouse_pressed(int x, int y, int button)
	{
		if (button == 0)
			boid->set_target(glm::vec2(x, y));
		if (button == 2)
			boid->clear_target();
	}

	void KFleerScene::mouse_released(int x, int y, int button)
	{

	}
}