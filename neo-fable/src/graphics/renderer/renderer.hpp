#pragma once

#include <map>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../application/log.hpp"
#include "../opengl.hpp"

namespace graphics {
	enum defaultProgram {
		none = 0,
		textured,
		tinted,
		tintedTextured
	};

	class Renderer
	{
	public:
		void loadDefaultPrograms(); // removed from constructor for hot reloading

		void resizeOrthoProj(float w, float h);

	protected:
		Renderer() {};
		~Renderer();

		// view matrix
		glm::mat4 orthoProj;

		static std::map<defaultProgram, opengl::Program*> defaultPrograms;
	};
}