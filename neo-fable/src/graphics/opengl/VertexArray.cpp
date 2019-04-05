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

	void VertexArray::addBuffer(Buffer buffer, GLuint index)
	{
		bind();
		buffer.bind();

		GL_DEBUG_CALL(glEnableVertexAttribArray(index));
		GL_DEBUG_CALL(glVertexAttribPointer(index, buffer.getCount(), GL_FLOAT, GL_FALSE, buffer.getLength(), (void*)0));

		buffers.insert(std::pair<GLuint, Buffer>(index, buffer));

		buffer.unbind();
		unbind();
	}

	void VertexArray::modBuffer(GLuint index, const float* data, GLuint length)
	{
		if (buffers.find(index) == buffers.end())
		{
			LOG_ERROR("index: ", index, " does not exist in buffer");
			return;
		}

		bind();
		buffers[index].bind();

		buffers[index].setData(data, length);

		GL_DEBUG_CALL(glEnableVertexAttribArray(index));
		GL_DEBUG_CALL(glVertexAttribPointer(index, buffers[index].getCount(), GL_FLOAT, GL_FALSE, buffers[index].getLength(), (void*)0));


		buffers[index].unbind();
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
