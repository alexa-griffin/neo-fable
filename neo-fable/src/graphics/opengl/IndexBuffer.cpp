#include "IndexBuffer.hpp"

namespace opengl {
	IndexBuffer::IndexBuffer(unsigned int length) :
		length(length)
	{
		glGenBuffers(1, &uid);
		bind();

		if (length < 4)
		{
			LOG_WARN("vertex buffer of length < 4 should not be made into an index buffer. ( length:", length, ")");
		}

		const unsigned int indexLength = length + 2;

		GLuint *ibo = new GLuint[indexLength];

		for (unsigned int i = 0; i < indexLength; i++) {
			//TODO: refactor this because there is no way this is preformant...
			ibo[i] = (((i % 3) == 0 ? 0 : ((i % 3) + (std::floor(i / 3)))));
		}

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexLength * sizeof(GLuint), ibo, GL_STATIC_DRAW);

		delete ibo;
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