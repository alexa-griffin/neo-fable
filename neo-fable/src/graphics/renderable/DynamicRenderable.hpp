#pragma once

#include <vector>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

#include "../shaderLayout.hpp"

namespace graphics {

	class DynamicRenderable
	{
	public:
		DynamicRenderable();
		~DynamicRenderable();

		virtual unsigned int getVertexCount() = 0;

		virtual VertexData getVertex(unsigned int index) = 0;
	};
}
