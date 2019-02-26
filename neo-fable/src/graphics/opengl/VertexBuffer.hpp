#pragma once

#include "GLEW/GL/glew.h"
#include "debug.hpp"

namespace opengl {
	class VertexBuffer
	{
	public:
		VertexBuffer(const void* data, unsigned int size);
		inline VertexBuffer() {};

		void bind();
		void unbind();
	private:
		GLuint uid;
	};
}