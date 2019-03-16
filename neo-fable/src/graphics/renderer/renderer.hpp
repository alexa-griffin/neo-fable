#pragma once

#include <string>
#include <map>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../application/log.hpp"

#include "../opengl.hpp"
#include "Renderable.hpp"

namespace graphics {
	class Renderer
	{
	public:
		Renderer() {};
		~Renderer();

		void clearScreen();
		void clearScreen(float r, float g, float b, float a);

		void resizeOrthoProj(float w, float h);

		void draw(Renderable obj, opengl::Program program);
	private:
		// view matrix
		static glm::mat4 orthoProj;

		static std::map<std::string, opengl::Program> programs;
	};
}