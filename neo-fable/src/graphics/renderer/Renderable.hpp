#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../opengl.hpp"
#include "Renderer.hpp"


namespace graphics {
	class Renderable
	{
	public:
		Renderable(const void* data, unsigned int dataLen, opengl::Program prog);
		~Renderable();

		// transform methods
		void rotateX(float deg);
		void rotateY(float deg);
		void rotateZ(float deg);
		void scaleX(float scalar);
		void scaleY(float scalar);
		void scaleZ(float scalar);
		void translate(glm::vec3 trans);
		void applyTransforms();

		virtual void draw() {};

	protected:
		opengl::VertexBuffer vbo; // buffers
		opengl::IndexBuffer  ibo;

		glm::mat4 transform; // scale, rotation, etc

		glm::vec4 tint;
		opengl::Texture texture;

		opengl::Program shader;

		friend class Renderer;
	};

}
