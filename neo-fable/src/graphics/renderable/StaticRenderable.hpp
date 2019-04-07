#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../opengl.hpp"
#include "../renderer/StaticRenderer.hpp"
#include "../util/util.hpp"
#include "../shaderLayout.hpp"

namespace graphics {
	class StaticRenderable
	{
	public:
		StaticRenderable();
		StaticRenderable(opengl::VertexArray va, GLuint *data, GLuint count);

		virtual ~StaticRenderable();
		
		virtual void addTexture(std::string path);
		virtual void setFill(glm::vec3 color);
		virtual void setFill(glm::vec3 bl, glm::vec3 tl, glm::vec3 tr, glm::vec3 br);
		
		unsigned int getIboCount() { return ibo.getCount(); };

		void bindVAO();
		void bindIBO();
		virtual void setUniforms(opengl::Program program);

		// transformation methods
		void translate(glm::vec3 m);
		void scaleX(float m);
		void scaleY(float m);
		void scaleZ(float m);
		void rotateX(float m);
		void rotateY(float m);
		void rotateZ(float m);
		void resetTransforms();
	public:
		struct {
			bool textured = false;
			bool tinted = false;
		} config;

	protected:
		opengl::VertexArray vao;
		opengl::IndexBuffer ibo;

		opengl::Texture texture;

		glm::mat4 transforms;

		friend class Renderer;
	};
}

