#pragma once

#include "GLEW/GL/glew.h"
#include "debug.hpp"

namespace opengl {
	class IndexBuffer
	{
	public:
		IndexBuffer(GLuint *data, GLuint count);
		IndexBuffer() {};

		void bind() const;
		void unbind() const;
		const unsigned int getCount() const { return count; }

	private:
		GLuint uid;
		unsigned int count;
	};
}