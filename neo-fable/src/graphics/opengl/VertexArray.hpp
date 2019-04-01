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
		void modBuffer(GLuint index, const float* data);

		void bind() const;
		void unbind() const;

		void attribBuffers();
	private:
		GLuint uid;
		unsigned int stride;

		std::map<GLuint, Buffer> buffers;
	};
}

