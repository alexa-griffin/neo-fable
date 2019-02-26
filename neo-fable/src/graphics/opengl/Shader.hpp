#pragma once

#include <string>

#include "GLEW/GL/glew.h"

#include "../data_loader/util.hpp" 
#include "debug.hpp" 

namespace opengl {
	class Program;

	class Shader
	{
	public:
		Shader(GLenum type, std::string path);
		inline Shader() {};
		~Shader();

		bool load();
		bool compile();
		void attachTo(Program program);

	private:
		GLuint uid;
		GLenum type;

		std::string path; // for hot reloading
		std::string src;

		friend class Program;
	};
}

