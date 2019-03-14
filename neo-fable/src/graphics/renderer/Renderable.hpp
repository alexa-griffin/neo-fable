#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../opengl.hpp"


namespace graphics {
	class Renderable
	{
	public:
		Renderable(float data, unsigned int dataLen, opengl::Program prog);
		~Renderable();

		// transforms
		void rotateX(float deg, float s);
		void rotateY(float deg, float s);
		void rotateZ(float deg, float s);

		void scaleX(float scalar, float s);
		void scaleY(float scalar, float s);
		void scaleZ(float scalar, float s);

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
