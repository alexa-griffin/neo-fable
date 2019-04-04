#pragma once

#include "GLEW/GL/glew.h"
#include "debug.hpp"

namespace opengl {
	class Buffer // assumes buffered data consists of floats
	{
	public:
		Buffer(const float* data, unsigned int length, unsigned int count);
		inline Buffer() {};
		~Buffer();
		void bind();
		void unbind();

		void setData(const float* data);

		inline unsigned int getSize() { return size; };
		inline unsigned int getLength() { return size / sizeof(float); };
		inline unsigned int getCount() { return count; };
		inline unsigned int getUID() { return uid; }
	private:
		GLuint uid;
		GLuint size;
		GLuint count;
	};
}