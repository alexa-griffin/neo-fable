#include "Renderer.hpp"


namespace graphics {
	glm::mat4 Renderer::orthoProj;
	std::map<std::string, opengl::Program> Renderer::programs;

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

	void Renderer::draw(Renderable obj, opengl::Program program)
	{
		program.use();
	
		// set ortho projection for renderable shader
		// all renderable shaders are assumed to have a mat4 uniform "orthoProj"
		//TODO: figure out if there is a way to warn if the uniform does not exist
		// program.setUniform("orthoProg", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(orthoProj));
		
		obj.draw();
	}
}
