#pragma once

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace graphics {
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void clearScreen();
		void clearScreen(float r, float g, float b, float a);

	private:
		// ortho matrix
		// 
	};
}