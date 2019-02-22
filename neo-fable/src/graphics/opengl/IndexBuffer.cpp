#include "IndexBuffer.hpp"


namespace graphics {
	IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) : count(count)
	{
		GL_DEBUG_CALL(glGenBuffers(1, &rendererID));
		GL_DEBUG_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
		bind();
	}


	IndexBuffer::~IndexBuffer()
	{
		GL_DEBUG_CALL(glDeleteBuffers(1, &rendererID));
	}

	void IndexBuffer::bind() const
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererID));
	}

	void IndexBuffer::unbind() const
	{

	}
}

