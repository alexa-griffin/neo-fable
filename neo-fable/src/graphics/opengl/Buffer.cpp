#include "Buffer.hpp"

namespace opengl {
	Buffer::Buffer(const float* data, unsigned int length, unsigned int count)
		: size(length * sizeof(float)), count(count)
	{
		GL_DEBUG_CALL(glGenBuffers(1, &uid));
		bind();
		setData(data, size);
	}

	Buffer::~Buffer()
	{
		// glDeleteBuffers(1, &uid);
	}

	void Buffer::bind()
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ARRAY_BUFFER, uid));
	}

	void Buffer::unbind()
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}

	void Buffer::setData(const float* data, GLuint length)
	{
		if (size < length) 
			{ LOG_WARN("data is larger than stored size"); }

		GL_DEBUG_CALL(glBufferData(GL_ARRAY_BUFFER, length, data, GL_STATIC_DRAW));
	}
}