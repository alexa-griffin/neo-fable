#include "TestLayer.hpp"


namespace layers {
	using namespace application;
	using namespace events;

	TestLayer::TestLayer(std::string name) 
		: Layer(name), r(0), g(0), b(0), incR(0.1), incG(0.1), incB(0.1)
	{
		float positions[] = {
			// position     // colors           // texture coords
			 0.5f,  0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
			-0.5f,  0.5f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f,
			-0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
			 0.5f, -0.5f,   0.0f, 1.0f, 1.0f,   1.0f, 1.0f
		};

		vbo = opengl::VertexBuffer(positions, sizeof(positions));
		ibo = opengl::IndexBuffer(4);

		vertShader = opengl::Shader(GL_VERTEX_SHADER, "./data/shaders/texture.vert.shader");
		fragShader = opengl::Shader(GL_FRAGMENT_SHADER, "./data/shaders/texture.frag.shader");

		program = opengl::Program();

		program.attach(vertShader);
		program.attach(fragShader);

		program.compile();
		program.use();

		//TODO: abstract this into the Program class
		// program.attribPointer("name", size, type, normalize, stride, offset);

		GL_DEBUG_CALL(GLuint posAttrib = glGetAttribLocation(program.getUID(), "iPos"));
		GL_DEBUG_CALL(glEnableVertexAttribArray(posAttrib));
		GL_DEBUG_CALL(glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(0)));

		GL_DEBUG_CALL(GLuint colorAttrib = glGetAttribLocation(program.getUID(), "iColor"));
		GL_DEBUG_CALL(glEnableVertexAttribArray(colorAttrib));
		GL_DEBUG_CALL(glVertexAttribPointer(colorAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(2 * sizeof(float))));

		GL_DEBUG_CALL(GLuint texAttrib = glGetAttribLocation(program.getUID(), "iTexCoord"));
		GL_DEBUG_CALL(glEnableVertexAttribArray(texAttrib)); 
		GL_DEBUG_CALL(glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(5 * sizeof(float))));
		
		texture = opengl::Texture("./data/graphics/test.png");
		texture.bind();

		program.createUniform("img");
		program.setUniform("img", glUniform1i, 0);
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

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void TestLayer::onMount()
	{

	}
}
