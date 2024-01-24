#include "KWanderScene.h"

namespace Scenes
{
	void KWanderScene::setup()
	{
		boid = new Frontend::Characters::WanderBoid(glm::vec2(100, 100), 0);
		boid->Rigidbody->set_max_lspeed(250.f);
	}

	void KWanderScene::update(float delta)
	{
		boid->update(delta);
	}

	void KWanderScene::draw()
	{
		boid->render();
	}

	void KWanderScene::key_pressed(int keycode)
	{

	}

	void KWanderScene::key_released(int keycode)
	{

	}

	void KWanderScene::mouse_pressed(int x, int y, int button)
	{

	}

	void KWanderScene::mouse_released(int x, int y, int button)
	{

	}
}
