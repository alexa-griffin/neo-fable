#include "debug.hpp"

namespace graphics {
	void glClearErrors()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	void glLogErrors(const char* f, const char* file, int line)
	{
		while (GLenum err = glGetError())
		{
			std::cout << "[openGL error]: (" << err << ")" << f << ", " << file << ":" << line << std::endl;
		}
	}

	void glShaderLogErrors(GLuint shader)
	{
		int compiled;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (compiled == GL_FALSE)
		{
			int len;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
			char* err = new char[len];
			glGetShaderInfoLog(shader, len, &len, err);
			std::cout << err << std::endl;

			delete err;
		}
	}

	void glProgramLogErrors(GLuint program)
	{
		int len;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
		char* err = new char[len];
		glGetProgramInfoLog(program, len, &len, err);
		std::cout << err << std::endl;

		delete err;
	}
}