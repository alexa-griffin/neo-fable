#include "IndexBuffer.hpp"

namespace opengl {
	IndexBuffer::IndexBuffer(float *data, unsigned int length) :
		length(length)
	{
		glGenBuffers(1, &uid);
		bind();

		if (length < 4) 
			LOG_WARN("vertex buffer of length < 4 should not be made into an index buffer.");


		const unsigned int indexLength = length + 2;

		GLuint *ibo = new GLuint[indexLength];

		for (int i = 0; i < indexLength; i++) {
			ibo[i] = (((i % 3) == 0 ? 0 : ((i % 3) + (std::floor(i / 3)))));
			//TODO: refactor this because there is no way this is preformant...
		}

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexLength * sizeof(GLuint), ibo, GL_STATIC_DRAW);
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