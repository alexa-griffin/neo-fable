#pragma once

#include "GLEW/GL/glew.h"
#include "debug.hpp"

namespace opengl {
	class IndexBuffer
	{
	public:
		IndexBuffer(float* data, unsigned int length);
		inline IndexBuffer() {};

		void bind() const;
		void unbind() const;
		const inline unsigned int getLength() const { return length; }
	private:
		GLuint uid;
		unsigned int length;
	};
}