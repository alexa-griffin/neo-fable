#pragma once

#include <vector>

#include <GLEW/GL/glew.h>

#include "Buffer.hpp"
#include "debug.hpp"

namespace opengl {
	struct IndexedBuffer
	{
		Buffer *buffer;
		GLuint index;
	};

	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer *b, GLuint index);

		void bind() const;
		void unbind() const;

		void attribPointers();

	private:
		GLuint uid;
		unsigned int stride;

		std::vector<IndexedBuffer> buffers;
	};
}

