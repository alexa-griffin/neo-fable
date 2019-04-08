#pragma once

#include <vector>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

#include "../application/log.hpp"

#include "../opengl.hpp"
#include "Renderer.hpp"
#include "../renderable/DynamicRenderable.hpp"
#include "../shaderLayout.hpp"

#define MAX_VERTICES 100
#define MAX_INDICES 10000


namespace graphics {
	struct VertexData
	{
		glm::vec2 pos;
		glm::vec3 color;
		// glm::vec3 textureCoord;
	};

	class BatchRenderer : public Renderer 
	{
	public:
		BatchRenderer();
		~BatchRenderer();

		void setProgram(opengl::Program *p);

		void submit(DynamicRenderable &obj);

		void draw();

	private:
		opengl::IndexBuffer ibo;
		opengl::VertexArray vao;

		opengl::Program *activeProgram;

		std::vector<DynamicRenderable*> quedRenderables;
	};
}