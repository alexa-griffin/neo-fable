#include "Renderable.hpp"


namespace graphics {
	Renderable::Renderable(const void* data, unsigned int dataLen, opengl::Program prog)
		: ibo(dataLen) ,vbo(data, dataLen), shader(prog), transform(1.0f), tint(1.0f)
	{

	}

	Renderable::~Renderable()
	{
	}

	// transform methods
	void Renderable::rotateX(float deg)
		{ transform = glm::rotate(transform, glm::radians(deg), glm::vec3(1, 0, 0)); }
		
	void Renderable::rotateY(float deg)
		{ transform = glm::rotate(transform, glm::radians(deg), glm::vec3(0, 1, 0)); }

	void Renderable::rotateZ(float deg)
		{ transform = glm::rotate(transform, glm::radians(deg), glm::vec3(0, 0, 1)); }

	void Renderable::scaleX(float s)
		{ transform = glm::scale(transform, glm::vec3(s, 0, 0)); }

	void Renderable::scaleY(float s)
		{ transform = glm::scale(transform, glm::vec3(0, s, 0)); }

	void Renderable::scaleZ(float s)
		{ transform = glm::scale(transform, glm::vec3(0, 0, s)); }

	void Renderable::translate(glm::vec3 trans)
		{ transform = glm::translate(transform, trans); }

	void Renderable::applyTransforms()
	{
		// all renderables are assumed to have a mat4 uniform "transform"
		shader.setUniform("transform", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(transform));
	}
}
