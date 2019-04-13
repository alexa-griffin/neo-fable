#include "IndexBuffer.hpp"

namespace opengl {
	IndexBuffer::IndexBuffer(GLuint *data, GLuint count) :
		count(count)
	{
		GL_DEBUG_CALL(glGenBuffers(1, &uid));
		bind();

		GL_DEBUG_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
	}

	void IndexBuffer::bind() const
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, uid));
	}

	void IndexBuffer::unbind() const
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
	}

	void IndexBuffer::setData(GLuint *data, GLuint length)
	{
		if (count < length)
			{ LOG_WARN("data is larger than stored size"); }

		GL_DEBUG_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(GLuint), data, GL_STATIC_DRAW));
	}
}