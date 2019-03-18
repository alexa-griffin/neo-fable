#include "VertexArray.hpp"


namespace opengl {
	VertexArray::VertexArray()
	{
		GL_DEBUG_CALL(glGenVertexArrays(1, &uid));
	}

	VertexArray::~VertexArray()
	{
		// for (int i = 0; i < buffers.size(); i++)
		// 	delete buffers[i].buffer;
	}

	void VertexArray::addBuffer(Buffer *buffer, GLuint index)
	{
		bind();
		buffer->bind();

		LOG_INFO("is: ", buffer->getCount(), ", ", buffer->getLength());
		LOG_INFO("be: ", "n",                ", ", (sizeof(float) * buffer->getCount()));

		GL_DEBUG_CALL(glEnableVertexAttribArray(index));
		GL_DEBUG_CALL(glVertexAttribPointer(index, buffer->getCount(), GL_FLOAT, GL_FALSE, buffer->getLength(), (void*)0));

		buffers.push_back({ buffer, index });

		buffer->unbind();
		unbind();
	}

	void VertexArray::bind() const
	{
		GL_DEBUG_CALL(glBindVertexArray(uid));
	}

	void VertexArray::unbind() const
	{
		GL_DEBUG_CALL(glBindVertexArray(0));
	}
}
