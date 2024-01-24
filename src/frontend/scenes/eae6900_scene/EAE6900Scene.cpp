#include "EAE6900Scene.h"

namespace Scenes
{
	void EAE6900Scene::setup()
	{
		float target_radius = 0.2f;
		float slow_radius = 1.f;
		float time_to_target = 0.1f;
		float wander_offest = 10.f;
		float wander_radius = 5.f;
		float wander_rate = 0.5f;

		////////////////////////////////////////////////////
		m_my_boid = new Frontend::Characters::DWanderBoid(glm::vec2(300, 200), 0, target_radius, slow_radius, time_to_target,
															wander_offest, wander_radius, wander_rate);
		m_my_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));
		m_my_boid->Rigidbody->set_max_aspeed(20.f);
		m_my_boid->Rigidbody->set_max_angular_acceleration(20.f);
		m_my_boid->Rigidbody->set_max_lspeed(160.f);
		m_my_boid->Rigidbody->set_max_acceleration(30.f);

		////////////////////////////////////////////////////
		m_target_boid = new Frontend::Characters::Boid(glm::vec2(600, 200), 0);
		m_target_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));

		////////////////////////////////////////////////////
		m_align_boid = new Frontend::EAE6900::AlignBoid(glm::vec2(300, 200), 0, target_radius, slow_radius, time_to_target);
		m_align_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));
		m_align_boid->Rigidbody->set_max_aspeed(20.f);
		m_align_boid->Rigidbody->set_max_angular_acceleration(20.f);
		m_align_boid->Rigidbody->set_max_lspeed(160.f);
		m_align_boid->Rigidbody->set_max_acceleration(30.f);

		////////////////////////////////////////////////////
		m_face_boid = new Frontend::EAE6900::FaceBoid(glm::vec2(300, 200), 0, target_radius, slow_radius, time_to_target);
		m_face_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));
		m_face_boid->Rigidbody->set_max_aspeed(20.f);
		m_face_boid->Rigidbody->set_max_angular_acceleration(20.f);
		m_face_boid->Rigidbody->set_max_lspeed(160.f);
		m_face_boid->Rigidbody->set_max_acceleration(30.f);

		////////////////////////////////////////////////////
		m_their_boid = new Frontend::EAE6900::DWanderBoid(glm::vec2(300, 200), 0, target_radius, slow_radius, time_to_target,
															wander_offest, wander_radius, wander_rate);
		m_their_boid->Transform->set_scale(glm::vec2(1.5f, 1.5f));
		m_their_boid->Rigidbody->set_max_aspeed(20.f);
		m_their_boid->Rigidbody->set_max_angular_acceleration(20.f);
		m_their_boid->Rigidbody->set_max_lspeed(160.f);
		m_their_boid->Rigidbody->set_max_acceleration(30.f);
	}

	void EAE6900Scene::update(float delta)
	{
		if (curr_scene == 0)
		{
			m_my_boid->update(delta);

			if (m_my_boid->Transform->get_position().y > ofGetHeight())
				m_my_boid->Transform->set_y(0);
			else if (m_my_boid->Transform->get_position().y < 0)
				m_my_boid->Transform->set_y(ofGetHeight());

			if (m_my_boid->Transform->get_position().x > ofGetWidth())
				m_my_boid->Transform->set_x(0);
			else if (m_my_boid->Transform->get_position().x < 0)
				m_my_boid->Transform->set_x(ofGetWidth());
		}
		else if (curr_scene == 1)
		{
			m_target_boid->update(delta);
			m_align_boid->update(delta);
		}
		else if (curr_scene == 2)
		{
			m_target_boid->update(delta);
			m_face_boid->update(delta);
		}
		else if (curr_scene == 3)
		{
			m_their_boid->update(delta);

			if (m_their_boid->Transform->get_position().y > ofGetHeight())
				m_their_boid->Transform->set_y(0);
			else if (m_their_boid->Transform->get_position().y < 0)
				m_their_boid->Transform->set_y(ofGetHeight());

			if (m_their_boid->Transform->get_position().x > ofGetWidth())
				m_their_boid->Transform->set_x(0);
			else if (m_their_boid->Transform->get_position().x < 0)
				m_their_boid->Transform->set_x(ofGetWidth());
		}
	}

	void EAE6900Scene::draw()
	{
		if (curr_scene == 0)
		{
			m_my_boid->render();
		}
		else if (curr_scene == 1)
		{
			m_target_boid->render();
			m_align_boid->render();
		}
		else if (curr_scene == 2)
		{
			m_target_boid->render();
			m_face_boid->render();
		}
		else if (curr_scene == 3)
		{
			m_their_boid->render();
		}
	}

	void EAE6900Scene::key_pressed(int keycode)
	{
		if (curr_scene == 2)
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
				m_face_boid->Transform->set_y(200);
				break;
			case 's':
				m_face_boid->Transform->set_y(400);
				break;
			case 'd':
				m_face_boid->Transform->set_y(600);
				break;
			}
		}

		switch (keycode)
		{
		case '0':
			curr_scene = 0;
			break;
		case '1':
			curr_scene = 1;
			break;
		case '2':
			m_target_boid->Transform->set_rotation(0);
			curr_scene = 2;
			break;
		case '3':
			curr_scene = 3;
			break;
		}
	}

	void EAE6900Scene::key_released(int keycode)
	{

	}

	void EAE6900Scene::mouse_pressed(int x, int y, int button)
	{
		if (curr_scene == 1)
		{
			if (button == 0)
			{
				glm::vec2 dir = glm::vec2(x, y) - m_target_boid->Transform->get_position();
				float angle = atan2(dir.y, dir.x) * 180 / PI;
				m_target_boid->Transform->set_rotation(angle);
			}
		}
	}

	void EAE6900Scene::mouse_released(int x, int y, int button)
	{

	}
}
