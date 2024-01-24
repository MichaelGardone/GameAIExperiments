#include "Boid.h"

namespace Frontend::Characters
{
	Boid::Boid(const glm::vec2& position, float rotation)
		: GameObject(position, rotation)
	{ }

	Boid::~Boid()
	{ }

	void Boid::update(float delta)
	{
		// update position and orientation
		Transform->set_position(Transform->get_position() + Rigidbody->get_linear_velocity() * delta);
		Transform->set_rotation(Transform->get_rotation() + Rigidbody->get_angular_velocity() * delta);
	}

	void Boid::render()
	{
		ofPushMatrix();
		ofTranslate(Transform->get_position());
		ofRotateDeg(Transform->get_rotation());

		glm::vec2 scale = Transform->get_scale();
		ofScale(glm::vec3(scale.x, scale.y, 1));

		ofSetColor(255);
		ofDrawCircle(0, 0, 0, 10);
		ofDrawTriangle(5, 7, 18, 0, 5, -7);
		ofPopMatrix();
	}
}
