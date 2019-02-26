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

	template<typename F, typename ...Args>
	void Program::setUniform(const char* var, F f, Args... args)
	{
		if (uniformParams[var])
		{
			F(uniformParams[var], args...);
		}
		else 
		{
			LOG_WARN("uniform: ", var, " does not exist in program: ", uid);
		}
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
