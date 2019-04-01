#include "Renderer.hpp"
#include "Renderable.hpp"


namespace graphics {
	std::map<DefaultProgram, opengl::Program> Renderer::defaultPrograms;

	Renderer::Renderer(bool preOpengl)
	{
		if (loadedDefaultPrograms || !preOpengl) return;

		LOG_INFO("initing renderer");

		// load default programs
		defaultPrograms.insert(std::pair<DefaultProgram, opengl::Program>(
			TINTED_SHADER, opengl::Program(
				"./data/shaders/default/tinted.vert.shader",
				"./data/shaders/default/tinted.frag.shader"
			)
		));

		LOG_INFO("loaded default programs");

		// defaultPrograms.insert(std::pair<DefaultProgram, opengl::Program>(
		// 	TEXTURED_SHADER, opengl::Program(
		// 		"./data/shaders/default/texture.vert.shader",
		// 		"./data/shaders/default/texture.frag.shader"
		// 	)
		// ));
		// 
		// defaultPrograms.insert(std::pair<DefaultProgram, opengl::Program>(
		// 	TINTED_TEXTURED_SHADER, opengl::Program(
		// 		"./data/shaders/default/tintedTextured.vert.shader",
		// 		"./data/shaders/default/tintedTextured.frag.shader"
		// 	)
		// ));

		loadedDefaultPrograms = true;
	}

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
		DefaultProgram proj = DefaultProgram::none;
		if (obj.config.textured) 
		{
			if (obj.config.tinted) proj = TINTED_TEXTURED_SHADER;
			else proj = TEXTURED_SHADER;
		}
		else if (obj.config.tinted) 
		{
			proj = TINTED_SHADER;
		}
		t.program = &defaultPrograms[proj];
		quedRenderables.push_back(t);
		//TODO: some kind of buffer combination
	}
}
