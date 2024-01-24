#include "FaceScene.h"

namespace Scenes
{
	void FaceScene::setup()
	{
		m_target_boid = new Frontend::Characters::Boid(glm::vec2(600, 200), 0);
		m_target_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));

		m_boid = new Frontend::Characters::FaceBoid(glm::vec2(300, 200), 0, 0.05f, 1.f, 0.1f);
		m_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));
		m_boid->set_target(m_target_boid);
		m_boid->Rigidbody->set_max_aspeed(0.5f);
		m_boid->Rigidbody->set_max_angular_acceleration(8.f);
	}

	void FaceScene::update(float delta)
	{
		m_boid->update(delta);
	}

	void FaceScene::draw()
	{
		m_target_boid->render();
		m_boid->render();
	}

	void FaceScene::key_pressed(int keycode)
	{
		switch (keycode)
		{
			case 'q':
				m_target_boid->Transform->set_y(200);
				break;
			case 'w':
				m_target_boid->Transform->set_y(400);
				break;
			case 'e':
				m_target_boid->Transform->set_y(600);
				break;
			case 'a':
				m_boid->Transform->set_y(200);
				break;
			case 's':
				m_boid->Transform->set_y(400);
				break;
			case 'd':
				m_boid->Transform->set_y(600);
				break;
		}
	}

	void FaceScene::key_released(int keycode)
	{

	}

	void FaceScene::mouse_pressed(int x, int y, int button)
	{
		
	}

	void FaceScene::mouse_released(int x, int y, int button)
	{

	}
}
