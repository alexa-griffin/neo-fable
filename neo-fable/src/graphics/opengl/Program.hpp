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
		Program(std::string vertPath, std::string fragPath);

		~Program();

		void attach(Shader shader);
		bool compile();
		void use();

		template<typename F, typename... Args>
		void setUniform(const char* var, F f, Args... args)
		{
			f(glGetUniformLocation(uid, var), args...);
		}

		inline const GLuint getUID() const { return uid; }

		void attribPointer(const char* name, unsigned int length, GLenum type, GLenum normalize, unsigned int stride, unsigned int offset);
	private:
		GLuint uid;
		std::map<std::string, GLint> uniformParams;

		friend class Shader;
	};
}