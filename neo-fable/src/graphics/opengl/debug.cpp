#include "debug.hpp"

namespace opengl {
	const char* formatError(GLenum err) 
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

	void clearErrors()
	{
		// LOG_WARN("clearing previous opengl errors");
		// GLenum err = glGetError();
		// do {
		// 	err = glGetError();
		// 	LOG_ERROR(formatError(err));
		// } while (err != GL_NO_ERROR);

		while (glGetError() != GL_NO_ERROR);
	}


	bool logErrors(const char* f, const char* file, int line)
	{
		bool ret = false;
		while (GLenum err = glGetError())
		{
			LOG_ERROR(f, ":", line, " | ", err, "(", formatError(err), ")");
			ret = true;
			// do not break here because i want to log all errors
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
		GL_DEBUG_CALL(glGetProgramiv(program, GL_VALIDATE_STATUS, &compiled));
		LOG_VAR(compiled);
		if (compiled == GL_FALSE)
		{
			int len;
			GL_DEBUG_CALL(glGetShaderiv(program, GL_INFO_LOG_LENGTH, &len));
			
			if (len < 0) 
			{ 
				LOG_WARN("log length of program: ", program, " is negative"); 
				return false;
			}

			char* err = new char[len];
			GL_DEBUG_CALL(glGetShaderInfoLog(program, len, &len, err));
			LOG_ERROR(err);

			delete err;
			return false;
		}
		LOG_INFO("program: ", program, " compiled successfully");

		return true;
	}
}