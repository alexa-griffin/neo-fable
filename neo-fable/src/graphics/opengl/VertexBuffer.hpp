#pragma once

#include <GLEW/GL/glew.h>

#include "debug.hpp"

namespace graphics {
	class VertexBuffer
	{
	public:
		VertexBuffer(const void* data, int size);
		~VertexBuffer();

		void bind() const;
		void unbind() const;

	private:
		unsigned int rendererID;
	};
}
