#include "VertexBuffer.hpp"


namespace graphics {
	VertexBuffer::VertexBuffer(const void* data, int size)
	{
		GL_DEBUG_CALL(glGenBuffers(1, &rendererID));
		GL_DEBUG_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
		bind();
	}


	VertexBuffer::~VertexBuffer()
	{
		GL_DEBUG_CALL(glDeleteBuffers(1, &rendererID));
	}

	void VertexBuffer::bind() const
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ARRAY_BUFFER, rendererID));
	}

	void VertexBuffer::unbind() const
	{
		GL_DEBUG_CALL(glDeleteBuffers(1, &rendererID))
	}
}

