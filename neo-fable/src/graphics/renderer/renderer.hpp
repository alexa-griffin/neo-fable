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

	struct RenderTarget{
		opengl::Program *program;
		Renderable *target;
	};

	//TODO: make thihs bitmap
	// loaded in RendererInit
	enum DefaultProgram
	{
		none = 0, 
		textured, 
		tinted, 
		texturedAndTinted, 
		other
	};

	class Renderer
	{
	public:
		Renderer(bool preOpengl = true);
		~Renderer();

		void clearScreen();
		void clearScreen(float r, float g, float b, float a);

		void resizeOrthoProj(float w, float h);

		void draw(Renderable &obj, opengl::Program program);

		void submit(Renderable &obj);
		void submit(Renderable &obj, opengl::Program &program);
		void drawQue();
	private:
		// view matrix
		glm::mat4 orthoProj;

		static std::map<DefaultProgram, opengl::Program> defaultPrograms;
		bool loadedDefaultPrograms;

		std::vector<RenderTarget> quedRenderables;
	};
}


#define TINTED_SHADER ::graphics::DefaultProgram::tinted
#define TEXTURED_SHADER ::graphics::DefaultProgram::textured
#define TINTED_TEXTURED_SHADER ::graphics::DefaultProgram::texturedAndTinted