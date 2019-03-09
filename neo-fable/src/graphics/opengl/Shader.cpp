#include "Shader.hpp"
#include "Program.hpp"

namespace opengl {
	Shader::Shader(GLenum type, std::string path)
		: path(path), type(type)
	{
		//logErrors("before", "", 0);
		GL_DEBUG_CALL(uid = glCreateShader(type));

		load();
		compile();
	}

	Shader::~Shader()
	{
		// glDeleteShader(uid);
	}

	bool Shader::load()
	{
		auto shaderFile = data_loader::loadFileToString(path);
		if (shaderFile.success)
		{
			src = shaderFile.content;
			const char* tmp = src.c_str(); //HACK: here to make glShaderSource happy
			GL_DEBUG_CALL(glShaderSource(uid, 1, &tmp, nullptr));
			return true;
		}
		else
		{
			LOG_ERROR("Failed to load shader file: ", path);
			return false;
		}
	}

	bool Shader::compile()
	{
		GL_DEBUG_CALL(glCompileShader(uid));
		return shaderLogErrors(uid);
	}

	void Shader::attachTo(Program program)
	{
		GL_DEBUG_CALL(glAttachShader(program.uid, uid));
	}
}
