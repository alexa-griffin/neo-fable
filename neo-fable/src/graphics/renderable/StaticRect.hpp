#pragma once

#include <glm/glm.hpp>

#include "../opengl.hpp"

#include "./StaticRenderable.hpp"

namespace graphics {
	class StaticRect : public StaticRenderable
	{
	public:
		StaticRect(float w, float h);
		~StaticRect();
	private:
		float width;
		float height;

		static GLuint indices[6];
	};
}
