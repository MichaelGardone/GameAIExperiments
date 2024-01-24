#pragma once

namespace Backend
{
	class Scene
	{
	public:
		virtual void setup() = 0;
		
		virtual void update(float) = 0;
		virtual void draw() = 0;

		virtual void key_pressed(int) = 0;
		virtual void key_released(int) = 0;

		virtual void mouse_pressed(int, int, int) = 0;
		virtual void mouse_released(int, int, int) = 0;
	};
}
