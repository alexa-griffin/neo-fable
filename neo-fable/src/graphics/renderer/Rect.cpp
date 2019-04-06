#include "Rect.hpp"


namespace graphics {
	GLuint Rect::indices[6] = { 0, 1, 2, 0, 2, 3 };

	Rect::Rect(float w, float h) : width(w), height(h)
	{
		float pos[8] = {
			0.0f,  0.0f,
			0.0f,  height,
			width, height,
			width, 0.0f,
		};

		opengl::Buffer posBuffer(pos, 8, 2);

		opengl::VertexArray vertices = opengl::VertexArray();

		vertices.addBuffer(posBuffer, I_POS_LOCATION);

		transforms = glm::mat4(1.0f); 
		vao = opengl::VertexArray(vertices);
		ibo = opengl::IndexBuffer(indices, 6);
	}

	Rect::~Rect()
	{
	}
}
