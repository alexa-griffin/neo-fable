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
			LOG_ERROR(err);
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
			LOG_ERROR(err);

			delete err;
		}
	}

	void glProgramLogErrors(GLuint program)
	{
		int compiled;
		glGetShaderiv(program, GL_VALIDATE_STATUS, &compiled);
		if (compiled == GL_FALSE)
		{
			int len;
			glGetShaderiv(program, GL_INFO_LOG_LENGTH, &len);
			char* err = new char[len];
			glGetShaderInfoLog(program, len, &len, err);
			LOG_ERROR(err);

			delete err;
		}
	}
}