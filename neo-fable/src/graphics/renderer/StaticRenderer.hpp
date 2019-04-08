#pragma once

#include <vector>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

#include "../application/log.hpp"

#include "../opengl.hpp"
#include "Renderer.hpp"

namespace graphics {
	class StaticRenderable;

	struct StaticRenderTarget{
		opengl::Program *program;
		StaticRenderable *target;
	};

	class StaticRenderer : public Renderer
	{
	public:
		StaticRenderer() {};
		~StaticRenderer();

		void draw(StaticRenderable &obj, opengl::Program program);

		void submit(StaticRenderable &obj, opengl::Program &program);
		void submit(StaticRenderable &obj);

		void drawQue();
	private:		
		std::vector<StaticRenderTarget*> quedRenderables;

	private:
		static defaultProgram getDefaultProgram(StaticRenderable &obj);
	};
}