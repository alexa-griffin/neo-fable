#include "TestLayer.hpp"


namespace layers {
	using namespace ::application;
	using namespace ::events;

	TestLayer::TestLayer(std::string name) 
		: Layer(name), h(0), inc(0.1)
	{
		float positions[] = {
			 0.5,  0.5,
			-0.5,  0.5,
			-0.5, -0.5,
			 0.5, -0.5
		};

		GLuint iBuffer[6] = {
			0, 1, 2,
			0, 2, 3
		};

		vbo = opengl::VertexBuffer(positions, 4 * 2 * sizeof(float));
		ibo = opengl::IndexBuffer(iBuffer, 6);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

		vertShader = opengl::Shader(GL_VERTEX_SHADER, "./data/shaders/basic.vert.shader");
		fragShader = opengl::Shader(GL_FRAGMENT_SHADER, "./data/shaders/basic.frag.shader");

		program = opengl::Program();

		program.attach(vertShader);
		program.attach(fragShader);

		program.compile();
		program.use();

		program.createUniform("uColor");
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
		if (h > 1) inc = -0.01;
		else if (h < 0) inc = 0.01;
		
		h += inc;

		// glUniform4f(colorLocal, h, 0.3, 0.8, 1.0);

		program.setUniform("uColor", glUniform4f, h, 0.3, 0.8, 1.0);

		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void TestLayer::onMount()
	{

	}
}
