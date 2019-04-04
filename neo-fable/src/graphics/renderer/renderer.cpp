#include "Renderer.hpp"
#include "Renderable.hpp"


namespace graphics {
	std::map<defaultProgram, opengl::Program> Renderer::defaultPrograms;

	Renderer::~Renderer()
	{
	}

	void Renderer::loadDefaultPrograms()
	{
		LOG_INFO("loading default programs");
		defaultPrograms.insert(
			std::pair<defaultProgram, opengl::Program>(defaultProgram::tinted,
				opengl::Program(
					"./data/shaders/default/tinted.vert.shader",
					"./data/shaders/default/tinted.frag.shader"
				)
			)
		);

		defaultPrograms.insert(
			std::pair<defaultProgram, opengl::Program>(defaultProgram::textured,
				opengl::Program(
					"./data/shaders/default/textured.vert.shader",
					"./data/shaders/default/textured.frag.shader"
				)
			)
		);

		defaultPrograms.insert(
			std::pair<defaultProgram, opengl::Program>(defaultProgram::tintedTextured, 
				opengl::Program(
					"./data/shaders/default/tintedTextured.vert.shader", 
					"./data/shaders/default/tintedTextured.frag.shader"
				)
			)
		);
	}

	void Renderer::clearScreen(float r, float g, float b, float a) 
	{
		//TODO: make this check the current clear color
		GL_DEBUG_CALL(glClearColor(r, g, b, a));
		clearScreen();
	}

	void Renderer::clearScreen()
	{
		GL_DEBUG_CALL(glClear(GL_COLOR_BUFFER_BIT));
	}

	void Renderer::resizeOrthoProj(float w, float h)
	{
		orthoProj = glm::ortho(0.0f, w, h, 0.0f);
	}

	void Renderer::draw(Renderable &obj, opengl::Program program)
	{
		program.use();

		// set ortho projection for renderable shader
		// all renderable shaders are assumed to have a mat4 uniform "orthoProj"
		//TODO: figure out if there is a way to warn if the uniform does not exist
		program.setUniform("proj", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(orthoProj));
		
		obj.draw(program);
	}

	void Renderer::drawQue()
	{
		for (int i = 0; i < quedRenderables.size(); i++)
		{
			draw(*(quedRenderables[i].target), *(quedRenderables[i].program));
		}
	}

	void Renderer::submit(Renderable &obj, opengl::Program &program)
	{
		RenderTarget t;
		t.program = &program;
		t.target = &obj;
		quedRenderables.push_back(t);
		//TODO: some kind of buffer combination
	}

	void Renderer::submit(Renderable &obj)
	{
		RenderTarget t;
		t.target = &obj;

		if (obj.config.textured && obj.config.tinted)
		{
			t.program = &defaultPrograms[defaultProgram::tintedTextured];
		} 
		else if (obj.config.tinted)
		{
			t.program = &defaultPrograms[defaultProgram::tinted];
		}
		else if (obj.config.textured) 
		{
			t.program = &defaultPrograms[defaultProgram::textured];
		}
		
		quedRenderables.push_back(t);
		//TODO: some kind of buffer combination
	}
}
