#include "TestLayer.hpp"

#define GL_ASSERT(f) if(!(f)) __debugbreak()
#define GL_DEBUG_CALL(f) glClearErrors(); \
						 (f); \
						 glLogErrors(#f, __FILE__, __LINE__)

static void glClearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool glLogErrors(const char* f, const char* file, int line)
{
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR)
	{
		std::cout << "[openGL error] (" << err << "): " << f << ", " << file << ": " << line << std::endl;
		// return true;
	}
	return false;
}

namespace layers {
	using namespace ::application;
	using namespace ::events;

	TestLayer::TestLayer(std::string name) : Layer(name) 
	{
		float positions[] = {
			-0.5, -0.5,
			 0.0,  0.5,
			 0.5, -0.5
		};

		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

		auto vertShaderFile = data_loader::loadFileToString("./data/shaders/basic.vert.shader");
		auto fragShaderFile = data_loader::loadFileToString("./data/shaders/basic.frag.shader");
		const char* vertShaderSrc = vertShaderFile.content.c_str();
		const char* fragShaderSrc = fragShaderFile.content.c_str();

		GLuint program = glCreateProgram();

		GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertShader, 1, &vertShaderSrc, nullptr);
		glCompileShader(vertShader);

		GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragShader, 1, &fragShaderSrc, nullptr);
		glCompileShader(fragShader);

		glAttachShader(program, vertShader);
		glAttachShader(program, fragShader);
		glLinkProgram(program);
		glValidateProgram(program);

		int len;

		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);

		char* err = new char[len];
		
		glGetProgramInfoLog(program, len, &len, err);

		std::cout << err << std::endl;
		GL_DEBUG_CALL(glUseProgram(program));
	};

	TestLayer::~TestLayer()
	{
	}

	bool TestLayer::onEvent(Event &e)
	{
		// std::cout << "test layer event!" << std::endl;
		return false;
	}

	void TestLayer::update()
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void TestLayer::onMount()
	{

	}
}
