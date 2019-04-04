#include "Program.hpp"


namespace opengl {
	Program::Program()
	{
		GL_DEBUG_CALL(uid = glCreateProgram());
	}
	
	//TODO: make this take a map so it supports other types of shaders
	Program::Program(std::string vertPath, std::string fragPath)
	{
		GL_DEBUG_CALL(uid = glCreateProgram());

		Shader vertShader = opengl::Shader(GL_VERTEX_SHADER, vertPath);
		Shader fragShader = opengl::Shader(GL_FRAGMENT_SHADER, fragPath);

		attach(vertShader);
		attach(fragShader);

		compile();
		use();
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

	void Program::attribPointer(const char* name, unsigned int length, GLenum type, GLenum normalize, unsigned int stride, unsigned int offset)
	{
		GL_DEBUG_CALL(GLuint attrib = glGetAttribLocation(uid, name));
		GL_DEBUG_CALL(glEnableVertexAttribArray(attrib));
		GL_DEBUG_CALL(glVertexAttribPointer(attrib, length, type, normalize, stride, (void*)(offset)));
	}
}
