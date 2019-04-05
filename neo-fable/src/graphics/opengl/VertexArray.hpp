#pragma once

#include <map>

#include <GLEW/GL/glew.h>

#include "Buffer.hpp"
#include "debug.hpp"

namespace opengl {
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer b, GLuint index);
		void modBuffer(GLuint index, const float* data, GLuint length);

		void bind() const;
		void unbind() const;

	private:
		GLuint uid;
		unsigned int stride;

		std::map<GLuint, Buffer> buffers;
	};
}

