#include "Buffer.hpp"

namespace opengl {
	Buffer::Buffer(const float* data, unsigned int length, unsigned int count)
		: size(length * sizeof(float)), count(count)
	{
		GL_DEBUG_CALL(glGenBuffers(1, &uid));
		bind();
		GL_DEBUG_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
	}

	void Buffer::bind()
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ARRAY_BUFFER, uid));
	}

	void Buffer::unbind()
	{
		GL_DEBUG_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
	}
}