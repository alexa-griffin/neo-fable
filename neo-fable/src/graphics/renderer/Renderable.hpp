#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../opengl.hpp"


namespace graphics {
	class Renderable
	{
	public:
		Renderable(const void* data, unsigned int dataLen, opengl::Program prog);
		~Renderable();

		// transforms
		void rotateX(float deg);
		void rotateY(float deg);
		void rotateZ(float deg);
		void scaleX(float scalar);
		void scaleY(float scalar);
		void scaleZ(float scalar);
		void translate(glm::vec3 trans);

	protected:
		opengl::VertexBuffer vbo; // buffers
		opengl::IndexBuffer  ibo;

		glm::mat4 transform; // transform (scale, rotation, etc)

		glm::vec4 tint;
		opengl::Texture texture;

		opengl::Program shader;
	};

}
