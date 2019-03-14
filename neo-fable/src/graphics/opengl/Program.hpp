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

		template<typename F, typename... Args>
		void setUniform(const char* var, F f, Args... args)
		{
			if (uniformParams.find(var) != uniformParams.end())
			{
				f(uniformParams[var], args...);
			}
			else
			{
				LOG_WARN("uniform: ", var, " does not exist in program: ", uid);
			}
		}

		void createUniform(const char* var);
		inline const GLuint getUID() const { return uid; }

		void attribPointer(const char* name, unsigned int length, GLenum type, GLenum normalize, unsigned int stride, unsigned int offset);
	private:
		GLuint uid;
		std::map<std::string, GLint> uniformParams;

		friend class Shader;
	};
}