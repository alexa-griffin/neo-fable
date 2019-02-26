#include "IndexBuffer.hpp"

namespace opengl {
	IndexBuffer::IndexBuffer(const GLuint* data, unsigned int length) :
		length(length)
	{
		glGenBuffers(1, &uid);
		bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(GLuint), data, GL_STATIC_DRAW);
	}

	void IndexBuffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, uid);
	}

	void IndexBuffer::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}