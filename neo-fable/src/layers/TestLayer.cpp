#include "TestLayer.hpp"


namespace layers {
	using namespace application;
	using namespace events;

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

		GL_DEBUG_CALL(GLuint posAttrib = glGetAttribLocation(program.getUID(), "position"));
		GL_DEBUG_CALL(glEnableVertexAttribArray(posAttrib));
		GL_DEBUG_CALL(glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(0)));

		// texture = opengl::Texture("./data/graphics/test.png");
		// texture.bind();

		vbo = opengl::VertexBuffer(positions, sizeof(positions));
		ibo = opengl::IndexBuffer(4);

		vertShader = opengl::Shader(GL_VERTEX_SHADER, "./data/shaders/basic.vert.shader");
		fragShader = opengl::Shader(GL_FRAGMENT_SHADER, "./data/shaders/basic.frag.shader");

		program = opengl::Program();

		program.attach(vertShader);
		program.attach(fragShader);

		//if (!program.compile()) { LOG_ERROR("program failed to compile"); }
		program.compile();
		program.use();


		//TODO: abstract this into the Program class
		// program.attribPointer("name", size, type, normalize, stride, offset);

		// GLuint texAttrib = glGetAttribLocation(program.getUID(), "iTexCoord");
		// glEnableVertexAttribArray(texAttrib); 
		// glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(5 * sizeof(float)));
		// 
		// GLuint colorAttrib = glGetAttribLocation(program.getUID(), "iColor");
		// glEnableVertexAttribArray(colorAttrib);
		// glVertexAttribPointer(colorAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(2 * sizeof(float)));

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
