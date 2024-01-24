#include "KArriveScene.h"

namespace Scenes
{
	void KArriveScene::setup()
	{
		boid = new Frontend::Characters::ArriveBoid(glm::vec2(100, 100), 0);
		boid->Rigidbody->set_max_lspeed(250.f);
	}

	void KArriveScene::update(float delta)
	{
		boid->update(delta);
	}

	void KArriveScene::draw()
	{
		boid->render();
	}

	void KArriveScene::key_pressed(int keycode)
	{

	}

	void KArriveScene::key_released(int keycode)
	{

	}

	void KArriveScene::mouse_pressed(int x, int y, int button)
	{
		if (button == 0)
			boid->set_target(glm::vec2(x, y));
		if (button == 2)
			boid->clear_target();
	}

	void KArriveScene::mouse_released(int x, int y, int button)
	{

	}
}
