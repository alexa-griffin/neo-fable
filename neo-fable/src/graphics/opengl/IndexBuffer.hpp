#pragma once

#include "GLEW/GL/glew.h"
#include "debug.hpp"

namespace opengl {
	class IndexBuffer
	{
	public:
		IndexBuffer(unsigned int length);
		IndexBuffer() {};

		void bind() const;
		void unbind() const;
		const unsigned int getLength() const { return indexLength; }
		const unsigned int getOriginLength() const { return length; }

	private:
		GLuint uid;
		unsigned int length;
		unsigned int indexLength;
	};
}