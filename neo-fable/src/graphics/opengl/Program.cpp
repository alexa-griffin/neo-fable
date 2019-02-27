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
		glAttachShader(uid, shader.uid);
	}

	void Program::use()
	{
		glUseProgram(uid);
	}

	bool Program::compile()
	{
		glLinkProgram(uid);
		glValidateProgram(uid);

		return programLogErrors(uid);
	}

	void Program::createUniform(const char* var)
	{
		if (uniformParams[var])
		{
			LOG_WARN("uniform: ", var, " already exists in program: ", uid);
		}
		else
		{
			uniformParams.insert(std::pair<std::string, GLint>(var, glGetUniformLocation(uid, var)));
		}
	}
}
