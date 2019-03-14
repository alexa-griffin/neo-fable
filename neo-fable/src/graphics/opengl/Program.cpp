#include "Program.hpp"


namespace opengl {
	Program::Program()
	{
		uid = glCreateProgram();
	}

	Program::~Program()
	{
		// glDeleteProgram(uid);
	}

	void Program::attach(Shader shader)
	{
		GL_DEBUG_CALL(glAttachShader(uid, shader.uid));
	}

	void Program::use()
	{
		GL_DEBUG_CALL(glUseProgram(uid));
	}

	bool Program::compile()
	{
		GL_DEBUG_CALL(glLinkProgram(uid));
		GL_DEBUG_CALL(glValidateProgram(uid));
		return programLogErrors(uid);
	}

	void Program::createUniform(const char* var)
	{
		if (uniformParams.find(var) != uniformParams.end())
		{
			LOG_WARN("uniform: ", var, " already exists in program: ", uid);
		}
		else
		{
			uniformParams.insert(std::pair<std::string, GLint>(var, glGetUniformLocation(uid, var)));
		}
	}

	void Program::attribPointer(const char* name, unsigned int length, GLenum type, GLenum normalize, unsigned int stride, unsigned int offset)
	{
		GL_DEBUG_CALL(GLuint attrib = glGetAttribLocation(uid, name));
		GL_DEBUG_CALL(glEnableVertexAttribArray(attrib));
		GL_DEBUG_CALL(glVertexAttribPointer(attrib, length, type, normalize, stride, (void*)(offset)));
	}
}
