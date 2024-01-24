#include "DWanderScene.h"

namespace Scenes
{
	void DWanderScene::setup()
	{
		m_boid = new Frontend::Characters::DWanderBoid(glm::vec2(300, 200), 0, 0.2f, 1.f, 0.1f, 10.f, 5.f, 0.5f);
		m_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));
		m_boid->Rigidbody->set_max_aspeed(20.f);
		m_boid->Rigidbody->set_max_angular_acceleration(20.f);
		m_boid->Rigidbody->set_max_lspeed(160.f);
		m_boid->Rigidbody->set_max_acceleration(30.f);
	}

	void DWanderScene::update(float delta)
	{
		m_boid->update(delta);

		if (m_boid->Transform->get_position().y > ofGetHeight())
			m_boid->Transform->set_y(0);
		else if (m_boid->Transform->get_position().y < 0)
			m_boid->Transform->set_y(ofGetHeight());

		if (m_boid->Transform->get_position().x > ofGetWidth())
			m_boid->Transform->set_x(0);
		else if (m_boid->Transform->get_position().x < 0)
			m_boid->Transform->set_x(ofGetWidth());
	}

	void DWanderScene::draw()
	{
		m_boid->render();
	}

	void DWanderScene::key_pressed(int keycode)
	{

	}

	void DWanderScene::key_released(int keycode)
	{

	}

	void DWanderScene::mouse_pressed(int x, int y, int button)
	{

	}

	void DWanderScene::mouse_released(int x, int y, int button)
	{

	}
}
