#include "Renderable.hpp"


namespace graphics {
	Renderable::Renderable()
	{
	}

	Renderable::Renderable(const void* data, unsigned int size, unsigned int indices)
	{
		vbo = opengl::VertexBuffer(data, size);
		ibo = opengl::IndexBuffer(indices);
	}

	Renderable::~Renderable()
	{
	}

	void Renderable::draw()
	{
		// ibo.bind();
		// vbo.bind();
		glDrawElements(GL_TRIANGLES, ibo.getLength(), GL_UNSIGNED_INT, nullptr);
	}
}
