#include "debug.hpp"

namespace opengl {
	void clearErrors()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	std::string formatError(GLenum err) 
	{
		//TODO: maybe not make this such a hack
		if (err == GL_INVALID_ENUM) return "GL_INVALID_ENUM";
		if (err == GL_INVALID_VALUE) return "GL_INVALID_VALUE";
		if (err == GL_INVALID_OPERATION) return "GL_INVALID_OPERATION";
		if (err == GL_STACK_OVERFLOW) return "GL_STACK_OVERFLOW";
		if (err == GL_STACK_UNDERFLOW) return "GL_STACK_UNDERFLOW";
		if (err == GL_OUT_OF_MEMORY) return "GL_OUT_OF_MEMORY";
		if (err == GL_INVALID_FRAMEBUFFER_OPERATION) return "GL_INVALID_FRAMEBUFFER_OPERATION";
		if (err == GL_CONTEXT_LOST) return "GL_CONTEXT_LOST";
		if (err == GL_TABLE_TOO_LARGE) return "GL_TABLE_TOO_LARGE";
		if (err == GL_NO_ERROR) return "GL_NO_ERROR";
		return "but there was no error";
	}

	bool logErrors(const char* f, const char* file, int line)
	{
		bool ret = false;
		while (GLenum err = glGetError())
		{
			LOG_ERROR(f, ":", line, " | ", err, "(", formatError(err), ")");
			ret = true;
		}
		return ret;
	}

	bool shaderLogErrors(GLuint shader)
	{
		int compiled;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (compiled != GL_TRUE)
		{
			int len;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
			char* err = new char[len];
			glGetShaderInfoLog(shader, len, &len, err);
			LOG_ERROR(err);

			delete err;
			return false;
		}
		return true;
	}

	bool programLogErrors(GLuint program)
	{
		int compiled;
		glGetProgramiv(program, GL_VALIDATE_STATUS, &compiled);
		if (compiled == GL_FALSE)
		{
			int len;
			glGetShaderiv(program, GL_INFO_LOG_LENGTH, &len);
			char* err = new char[len];
			glGetShaderInfoLog(program, len, &len, err);
			LOG_ERROR(err);

			delete err;
			return false;
		}
		LOG_INFO("program: ", program, " compiled successfully");

		return true;
	}
}