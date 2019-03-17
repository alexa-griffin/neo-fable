#include "Renderable.hpp"


namespace graphics {
	Renderable::Renderable()
	{
	}

	Renderable::Renderable(const void* data, unsigned int size, unsigned int indices)
		: transforms(1.0f)
	{
		vbo = opengl::VertexBuffer(data, size);
		ibo = opengl::IndexBuffer(indices);
	}

	Renderable::~Renderable()
	{
	}

	void Renderable::draw(opengl::Program program)
	{
		ibo.bind();
		vbo.bind();

		program.setUniform("translation", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(transforms));

		glDrawElements(GL_TRIANGLES, ibo.getLength(), GL_UNSIGNED_INT, nullptr);
	}

	// transform methods
	void Renderable::translate(glm::vec3 m)
		{ transforms = glm::translate(transforms, m); }

	void Renderable::scaleX(float m)
		{ transforms = glm::scale(transforms, glm::vec3(m, 0.0f, 0.0f)); }

	void Renderable::scaleY(float m)
		{ transforms = glm::scale(transforms, glm::vec3(0.0f, m, 0.0f)); }

	void Renderable::scaleZ(float m)
		{ transforms = glm::scale(transforms, glm::vec3(0.0f, 0.0f, m)); }

	void Renderable::rotateX(float m)
		{ transforms = glm::rotate(transforms, glm::radians(m), glm::vec3(1.0f, 0.0f, 0.0f)); }

	void Renderable::rotateY(float m)
		{ transforms = glm::rotate(transforms, glm::radians(m), glm::vec3(0.0f, 1.0f, 0.0f)); }

	void Renderable::rotateZ(float m)
		{ transforms = glm::rotate(transforms, glm::radians(m), glm::vec3(0.0f, 0.0f, 1.0f)); }

}
