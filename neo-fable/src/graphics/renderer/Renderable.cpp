#include "Renderable.hpp"


namespace graphics {
	Renderable::Renderable()
	{

	}

	Renderable::~Renderable()
	{
	}

	// transform methods
	void Renderable::rotateX(float deg, float s)
		transform = glm::rotate(transform, glm::radians(deg), glm::vec3(s, 0, 0));

	void Renderable::rotateY(float deg, float s)
		transform = glm::rotate(transform, glm::radians(deg), glm::vec3(0, s, 0));

	void Renderable::rotateZ(float deg, float s)
		transform = glm::rotate(transform, glm::radians(deg), glm::vec3(0, 0, s));

	void Renderable::rotateX(float deg, float s)
		transform = glm::scale(transform, glm::radians(deg), glm::vec3(s, 0, 0));

	void Renderable::rotateY(float deg, float s)
		transform = glm::scale(transform, glm::radians(deg), glm::vec3(0, s, 0));

	void Renderable::rotateZ(float deg, float s)
		transform = glm::scale(transform, glm::radians(deg), glm::vec3(0, 0, s));

	void translate(glm::vec3 trans)
		transform = glm::translate(transform, trans);

}
