#include "TestLayer.hpp"

static void glClearErrors()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool glLogErrors(const char* f, const char* file, int line)
{
	GLenum err;
	while ((err = glGetError()) != GL_NO_ERROR)
	{
		LOG_ERROR(err, file, line);
		// return true;
	}
	return false;
}

namespace layers {
	using namespace ::application;
	using namespace ::events;

	TestLayer::TestLayer(std::string name) : Layer(name), h(0), inc(0.1)
	{
		float positions[] = {
			 0.5,  0.5,
			-0.5,  0.5,
			-0.5, -0.5,
			 0.5, -0.5
		};

		GLuint iBuffer[] = {
			0, 1, 3,
			1, 2, 3
		};

		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

		glGenBuffers(1, &ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(iBuffer), iBuffer, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

		auto vertShaderFile = data_loader::loadFileToString("./data/shaders/basic.vert.shader");
		auto fragShaderFile = data_loader::loadFileToString("./data/shaders/color.frag.shader");
		const char* vertShaderSrc = vertShaderFile.content.c_str();
		const char* fragShaderSrc = fragShaderFile.content.c_str();

		GLuint program = glCreateProgram();

		GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertShader, 1, &vertShaderSrc, nullptr);
		glCompileShader(vertShader);
		graphics::glShaderLogErrors(vertShader);

		GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragShader, 1, &fragShaderSrc, nullptr);
		glCompileShader(fragShader);
		graphics::glShaderLogErrors(fragShader);

		glAttachShader(program, vertShader);
		glAttachShader(program, fragShader);
		glLinkProgram(program);
		glValidateProgram(program);

		graphics::glProgramLogErrors(program);

		glUseProgram(program);

		colorLocal = glGetUniformLocation(program, "uColor");
	};

	TestLayer::~TestLayer()
	{
	}

	bool TestLayer::onEvent(Event &e)
	{
		return false;
	}

	void TestLayer::update()
	{
		if (h > 1)
		{
			inc = -0.1;
		}
		else if (h < 0)
		{
			inc = 0.1;
		}
		
		h += inc;

		LOG_VAR(h);
		LOG_VAR(inc);

		glUniform4f(colorLocal, h, 0.3, 0.8, 1.0);

		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void TestLayer::onMount()
	{

	}
}
