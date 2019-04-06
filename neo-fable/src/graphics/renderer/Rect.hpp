#pragma once

#include <glm/glm.hpp>

#include "../opengl.hpp"

#include "./Renderable.hpp"

namespace graphics {
	class Rect : public Renderable
	{
	public:
		Rect(float w, float h);
		~Rect();
	private:
		float width;
		float height;

		static GLuint indices[6];
	};
}
