#pragma once

#include <map>
#include <string>

#include "GLEW/GL/glew.h" 

#include "debug.hpp"
#include "Shader.hpp"

namespace opengl {
	class Program
	{
	public:
		Program();
		~Program();

		void attach(Shader shader);
		bool compile();
		void use();

		template<typename F, typename ...Args>
		void setUniform(const char* var, F f, Args... args);

		void createUniform(const char* var);
	private:
		GLuint uid;
		std::map<std::string, GLint> uniformParams;

		friend class Shader;
	};
}