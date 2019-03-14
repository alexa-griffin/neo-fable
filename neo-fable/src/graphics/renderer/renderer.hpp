#pragma once

#include <string>
#include <map>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../application/log.hpp"

namespace graphics {
	class Renderer
	{
	public:
		Renderer() {};
		~Renderer();

		void clearScreen();
		void clearScreen(float r, float g, float b, float a);

		void resizeOrthoProj(float w, float h);

	private:
		// ortho matrix
		static glm::mat4 orthoProj;

		// shader list
		std::map<std::string, GLint> shaders;
	};
}