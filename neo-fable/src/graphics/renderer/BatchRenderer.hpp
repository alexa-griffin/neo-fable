#pragma once

#include <vector>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

#include "../application/log.hpp"

#include "../opengl.hpp"
#include "Renderer.hpp"
#include "../renderable/DynamicRenderable.hpp"
#include "../shaderLayout.hpp"

#define MAX_VERTICES 4
#define MAX_INDICES 6

namespace graphics {
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

		opengl::Buffer colorBuffer;
		opengl::Buffer posBuffer;

		unsigned int numVertices;

		opengl::Program *activeProgram;

		std::vector<DynamicRenderable*> quedRenderables;
	};
}