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

	class Renderer
	{
	public:
		Renderer() {};
		~Renderer();

		void clearScreen();
		void clearScreen(float r, float g, float b, float a);

		void resizeOrthoProj(float w, float h);

		void draw(Renderable &obj, opengl::Program program);

		void submit(Renderable &obj);
		void drawQue();
	private:
		// view matrix
		static glm::mat4 orthoProj;

		static std::map<std::string, opengl::Program> programs;
		
		std::vector<Renderable*> quedRenderables;
	};
}