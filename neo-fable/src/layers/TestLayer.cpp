#include "TestLayer.hpp"



namespace layers {
	using namespace application;
	using namespace events;

	TestLayer::TestLayer(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win), i(0)
	{
		float positions[] = {
			// position      // colors           // texture coords
		    100.0f, 100.0f,  0.3f, 0.0f, 0.6f,   1.0f, 1.0f, // clockwise from bottom left
			  0.0f, 100.0f,  0.3f, 1.0f, 0.6f,   0.0f, 1.0f,
			  0.0f, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
		    100.0f, 0.0f,    0.0f, 0.6f, 0.6f,   1.0f, 0.0f
		};

		vbo = opengl::VertexBuffer(positions, sizeof(positions));
		opengl::IndexBuffer ibo = opengl::IndexBuffer(4);

		program = opengl::Program("./data/shaders/tests/texture.vert.shader", "./data/shaders/tests/texture.frag.shader");

		// actually prob define stride in the vbo idk
		program.attribPointer("iPos", 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, sizeof(float) * 0);
		program.attribPointer("iColor", 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, sizeof(float) * 2);
		program.attribPointer("iTexCoord", 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, sizeof(float) * 5);

		// renderable
		texture = opengl::Texture("./data/graphics/test.png");
		texture.bind();
		program.createUniform("img");
		program.setUniform("img", glUniform1i, 0);

		program.createUniform("translation");

		// this should be in the renderer
		//TODO: update on window resize
		glm::mat4 proj = glm::ortho(0.0f, (float)window->getWidth(), 0.0f, (float)window->getHeight());
		program.createUniform("proj");
		program.setUniform("proj", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(proj));
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
		glm::mat4 transform = glm::mat4(1.0f);
		transform = glm::rotate(transform, glm::radians((float)i), glm::vec3(0.0f, 1.0f, 1.0f));

		program.setUniform("translation", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(transform));
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
	}

	void TestLayer::onMount()
	{

	}
}
