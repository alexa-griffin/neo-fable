#include "Renderer.hpp"


namespace graphics {
	glm::mat4 Renderer::orthoProj;
	std::map<std::string, opengl::Program> Renderer::shaders;

	Renderer::~Renderer()
	{
	}

	void Renderer::clearScreen(float r, float g, float b, float a) 
	{
		//TODO: make this check the current clear color
		glClearColor(r, g, b, a);
		clearScreen();
	}

	void Renderer::clearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::resizeOrthoProj(float w, float h)
	{
		orthoProj = glm::ortho(0.0f, w, 0.0f, h);
	}
}
