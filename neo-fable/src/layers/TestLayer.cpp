#include "TestLayer.hpp"


namespace layers {
	using namespace ::application;
	using namespace ::events;

	TestLayer::TestLayer(std::string name) 
		: Layer(name), r(0), g(0), b(0), incR(0.1), incG(0.1), incB(0.1)
	{
		float positions[] = {
			// position     // colors           // texture coords
			 0.5f,  0.5f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
			-0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
			-0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
			 0.5f, -0.5f,   0.0f, 1.0f, 1.0f,   0.0f, 1.0f
		};

		opengl::logErrors("before", "", 1);
		texture = opengl::Texture("./data/graphics/test.png");
		texture.bind();
		opengl::logErrors("after", "", 1);

		vbo = opengl::VertexBuffer(positions, 4 * 2 * sizeof(float));
		ibo = opengl::IndexBuffer(4);


		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(6 * sizeof(float)));

		vertShader = opengl::Shader(GL_VERTEX_SHADER, "./data/shaders/texture.vert.shader");
		fragShader = opengl::Shader(GL_FRAGMENT_SHADER, "./data/shaders/texture.frag.shader");

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
		if (r < 0) incR = 0.1f;
		else if (r > 1) incR = -0.1f;

		if (g < 0) incG = 0.15f;
		else if (g > 1) incG = -0.15f;

		if (b < 0) incB = 0.2f;
		else if (b > 1) incB = -0.2f;

		r += incR;
		g += incG;
		b += incB;

		program.setUniform("uColor", glUniform4f, r, g, b, 1.0f);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void TestLayer::onMount()
	{

	}
}
