#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../opengl.hpp"
#include "Renderer.hpp"
#include "../util/util.hpp"

namespace graphics {
	class Renderable
	{
	public:
		Renderable();
		Renderable(const void* data, unsigned int size, unsigned int indices);

		virtual ~Renderable();

		virtual void draw(opengl::Program program);

		// virtual void applyTransform(opengl::Program program);

		// transformation methods
		void translate(glm::vec3 m);
		void scaleX(float m);
		void scaleY(float m);
		void scaleZ(float m);
		void rotateX(float m);
		void rotateY(float m);
		void rotateZ(float m);

	protected:
		opengl::VertexBuffer vbo;
		opengl::IndexBuffer  ibo;

		glm::mat4 transforms;

		friend class Renderer;
	};
}

