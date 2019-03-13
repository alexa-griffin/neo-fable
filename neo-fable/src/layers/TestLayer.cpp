#include "TestLayer.hpp"



namespace layers {
	using namespace application;
	using namespace events;

	TestLayer::TestLayer(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win), i(0)
	{
		float positions[] = {
			// position     // colors           // texture coords
		   100.0f, 100.0f,   0.3f, 0.0f, 0.6f,   1.0f, 1.0f, // clockwise from bottom left
			 0.0f, 100.0f,   0.3f, 1.0f, 0.6f,   0.0f, 1.0f,
			 0.0f, 0.0f,     0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
		   100.0f, 0.0f,     0.0f, 0.6f, 0.6f,   1.0f, 0.0f
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

		// TODO: abstract this into the Program class
		// program.attribPointer("name", size, type, normalize, offset);
		// prob define stride in the vbo

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

		glm::mat4 proj = glm::ortho(0.0f, (float)window->getWidth(), 0.0f, (float)window->getHeight());
		
		program.createUniform("proj");
		program.setUniform("proj", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(proj));

		program.createUniform("translation");
	};

	TestLayer::~TestLayer()
	{
	}

	bool TestLayer::onEvent(const events::Event &event)
	{
		if (event.getType() == events::eventType::mouseScroll) // make this a macro?
		{
			events::MouseScroll& e = (events::MouseScroll&)event;
			i += e.getY() * 20;
			return false;
		}
		return false;
	}

	void TestLayer::update()
	{
		// i += 2;
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::rotate(transform, glm::radians((float)i), glm::vec3(0.0f, 1.0f, 1.0f));

		program.setUniform("translation", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(transform));
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void TestLayer::onMount()
	{

	}
}
