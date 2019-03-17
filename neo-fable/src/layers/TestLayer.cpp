#include "TestLayer.hpp"



namespace layers {
	using namespace application;
	using namespace events;

	TestLayer::TestLayer(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win)
	{
		float positions[] = {
			// position      // colors           // texture coords
		    100.0f, 100.0f,  0.3f, 0.0f, 0.6f,   1.0f, 1.0f, // clockwise from bottom left
			  0.0f, 100.0f,  0.3f, 1.0f, 0.6f,   0.0f, 1.0f,
			  0.0f, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
		    100.0f, 0.0f,    0.0f, 0.6f, 0.6f,   1.0f, 0.0f
		};

		box = graphics::Renderable(positions, sizeof(positions), 4);

		program = opengl::Program("./data/shaders/tests/texture.vert.shader", "./data/shaders/tests/texture.frag.shader");

		// actually prob define stride in the vbo idk
		program.attribPointer("iPos", 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, sizeof(float) * 0);
		program.attribPointer("iColor", 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, sizeof(float) * 2);
		program.attribPointer("iTexCoord", 2, GL_FLOAT, GL_FALSE, sizeof(float) * 7, sizeof(float) * 5);


		// renderable
		texture = opengl::Texture("./data/graphics/test.png");
		texture.bind();
		program.setUniform("img", glUniform1i, 0);
	};

	TestLayer::~TestLayer()
	{
	}

	void TestLayer::update()
	{

		window->rCtx.draw(box, program);
	}

	bool TestLayer::onEvent(const events::Event &event)
	{
		if (event.getType() == events::eventType::mouseScroll) // make this a macro?
		{
			events::MouseScroll& e = (events::MouseScroll&)event;
			box.rotateZ(e.getY());
		}
		return false;
	}


	void TestLayer::onMount()
	{

	}
}
