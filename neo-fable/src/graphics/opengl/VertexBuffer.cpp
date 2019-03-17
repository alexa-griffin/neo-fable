#include "VertexBuffer.hpp"

namespace opengl {
	VertexBuffer::VertexBuffer(const void* data, unsigned int size)
	{
		GL_DEBUG_CALL(glGenBuffers(1, &uid));
		bind();
		GL_DEBUG_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}

	void VertexBuffer::bind()
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ARRAY_BUFFER, uid));
	}

	void VertexBuffer::unbind()
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}