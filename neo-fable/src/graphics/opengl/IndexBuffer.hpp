#pragma once

#include <GLEW/GL/glew.h>

#include "debug.hpp"

namespace graphics {
	class IndexBuffer
	{
	public:
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();

		void bind() const;
		void unbind() const;
	private:
		unsigned int rendererID;
		unsigned int count;
	};
}
