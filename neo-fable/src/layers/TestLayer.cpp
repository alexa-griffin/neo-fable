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
		opengl::Buffer posBuffer1(positions, 8, 2);

		opengl::VertexArray vertices = opengl::VertexArray();
		opengl::VertexArray vertices1 = opengl::VertexArray();

		program = opengl::Program("./data/shaders/tests/texture.vert.shader", "./data/shaders/tests/texture.frag.shader");

		vertices.addBuffer(posBuffer, I_POS_LOCATION);
		vertices1.addBuffer(posBuffer1, I_POS_LOCATION);

		box = graphics::Renderable(vertices, 4);
		box1 = graphics::Renderable(vertices1, 4);

		box.addTexture("./data/graphics/tile.png");
		box.setFill(RGB(255, 255, 255));

		box1.addTexture("./data/graphics/tile.png");
		box1.setFill(RGB(255, 255, 255));
	};

	TestLayer::~TestLayer()
	{
	}

	void TestLayer::update()
	{
		window->rCtx.submit(box, program);
		window->rCtx.submit(box1, program);

		window->rCtx.drawQue();
	}

	bool TestLayer::onEvent(const events::Event &event)
	{
		// ON_EVENT(mouseScroll, { // is this actually better?
		// 	box.rotateZ(e.getY() * 3);
		// });

		ON_EVENT(mouseMove, {
			box1.resetTransforms();
			box1.translate(glm::vec3(e.getX() / (window->getWidth() / 2), -e.getY() / (window->getHeight() / 2), 0.0f));
		});

		return false;
	}


	void TestLayer::onMount()
	{

	}
}
