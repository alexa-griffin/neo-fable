#pragma once

#include "../opengl.hpp"
#include "Renderer.hpp"


namespace graphics {
	class Renderable
	{
	public:
		Renderable();
		Renderable(const void* data, unsigned int size, unsigned int indices);

		virtual ~Renderable();

		virtual void draw();

	protected:
		opengl::VertexBuffer vbo;
		opengl::IndexBuffer  ibo;

		friend class Renderer;
	};
}

