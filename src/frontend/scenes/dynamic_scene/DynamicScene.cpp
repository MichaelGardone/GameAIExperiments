#include "DynamicScene.h"

namespace Scenes
{
	void DynamicScene::setup()
	{
		m_target_boid = new Frontend::Characters::Boid(glm::vec2(600, 200), 0);
		m_target_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));

		m_boid = new Frontend::Characters::AlignBoid(glm::vec2(300, 200), 0, 0.2f, 1.f, 0.1f);
		m_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));
		m_boid->set_target(m_target_boid);
		m_boid->Rigidbody->set_max_aspeed(0.5f);
		m_boid->Rigidbody->set_max_angular_acceleration(8.f);
	}

	void DynamicScene::update(float delta)
	{
		m_boid->update(delta);
	}

	void DynamicScene::draw()
	{
		m_target_boid->render();
		m_boid->render();
	}

	void DynamicScene::key_pressed(int keycode)
	{

	}

	void DynamicScene::key_released(int keycode)
	{

	}

	void DynamicScene::mouse_pressed(int x, int y, int button)
	{
		if (button == 0)
		{
			glm::vec2 dir = glm::vec2(x, y) - m_target_boid->Transform->get_position();
			float angle = atan2(dir.y, dir.x) * 180 / PI;
			m_target_boid->Transform->set_rotation(angle);
		}
	}

	void DynamicScene::mouse_released(int x, int y, int button)
	{

	}
}
