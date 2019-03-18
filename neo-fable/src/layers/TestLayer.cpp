#include "TestLayer.hpp"



namespace layers {
	using namespace application;
	using namespace events;

	TestLayer::TestLayer(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win)
	{
		float positions[] = {
			  0.0f, 0.0f, // bottom left clockwise  
			  0.0f, 100.0f,
		    100.0f, 100.0f, 
		    100.0f, 0.0f,  
		};

		opengl::Buffer posBuffer(positions, 8, 2);

		opengl::VertexArray vertices = opengl::VertexArray();

		program = opengl::Program("./data/shaders/tests/texture.vert.shader", "./data/shaders/tests/texture.frag.shader");

		vertices.addBuffer(&posBuffer, I_POS_LOCATION);

		box = graphics::Renderable(vertices, 4);

		box.addTexture("./data/graphics/test.png");
		box.addFill(RGB(100, 100, 255));
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
		ON_EVENT(mouseScroll, { // is this actually better?
			box.rotateZ(e.getY() * 3);
		});

		return false;
	}


	void TestLayer::onMount()
	{

	}
}
