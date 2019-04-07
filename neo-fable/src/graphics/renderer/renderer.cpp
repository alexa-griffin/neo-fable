#include "Renderer.hpp"


namespace graphics {
	std::map<defaultProgram, opengl::Program*> Renderer::defaultPrograms;

	Renderer::~Renderer()
	{
		defaultPrograms.clear();
	}

	void Renderer::resizeOrthoProj(float w, float h)
	{
		orthoProj = glm::ortho(0.0f, w, 0.0f, h, -1.0f, 1.0f);
	}

	void Renderer::loadDefaultPrograms()
	{
		//TODO: some kind of recording to prevent double loading
		LOG_INFO("loading default programs");

		LOG_INFO("defaultProgram::textured: ");
		defaultPrograms.insert(
			std::pair<defaultProgram, opengl::Program*>(defaultProgram::textured,
				new opengl::Program(
					"./data/shaders/default/textured.vert.shader",
					"./data/shaders/default/textured.frag.shader"
				)
			)
		);
		LOG_BLK();

		LOG_INFO("defaultProgram::tinted: ");
		defaultPrograms.insert(
			std::pair<defaultProgram, opengl::Program*>(defaultProgram::tinted,
				new opengl::Program(
					"./data/shaders/default/tinted.vert.shader",
					"./data/shaders/default/tinted.frag.shader"
				)
			)
		);
		LOG_BLK();

		LOG_INFO("defaultProgram::tintedTextured: ");
		defaultPrograms.insert(
			std::pair<defaultProgram, opengl::Program*>(defaultProgram::tintedTextured,
				new opengl::Program(
					"./data/shaders/default/tintedTextured.vert.shader",
					"./data/shaders/default/tintedTextured.frag.shader"
				)
			)
		);

		LOG_INFO("finished loading default programs");
	}

}