#pragma once

#include <string>
#include <map>
#include <vector>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../application/log.hpp"

#include "../opengl.hpp"

namespace graphics {
	class Renderable;

	struct RenderTarget{
		opengl::Program *program;
		Renderable *target;
	};

	enum defaultProgram {
		none = 0,
		textured, 
		tinted,
		tintedTextured
	};

	class Renderer
	{
	public:
		Renderer() {};
		~Renderer();

		void loadDefaultPrograms(); // removed from constructor for hot reloading

		void clearScreen();
		void clearScreen(float r, float g, float b, float a);

		void resizeOrthoProj(float w, float h);

		void draw(Renderable &obj, opengl::Program program);

		// void submit(Renderable &obj);
		void submit(Renderable &obj, opengl::Program &program);
		void submit(Renderable &obj);
		void drawQue();
	private:
		// view matrix
		glm::mat4 orthoProj;

		static std::map<defaultProgram, opengl::Program> defaultPrograms;
		
		std::vector<RenderTarget> quedRenderables;
	};
}