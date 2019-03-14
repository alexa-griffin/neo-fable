#pragma once

#include <string>
#include <map>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace graphics {
	class Renderer
	{
	public:
		Renderer() {};
		~Renderer();

		void clearScreen();
		void clearScreen(float r, float g, float b, float a);

		void createShader(std::string identifier, std::string vertPath, std::string fragPath);
		void resizeOrthoProj(int w, int h);

	private:
		// ortho matrix
		static glm::mat4 orthoProj;

		// shader list
		std::map<std::string, GLint> shaders;
	};
}