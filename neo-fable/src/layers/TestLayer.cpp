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

		program = opengl::Program("./data/shaders/tests/basic.vert.shader", "./data/shaders/tests/basic.frag.shader");

		opengl::Buffer posBuffer(positions, 8, 2);

		opengl::VertexArray vertices = opengl::VertexArray();

		vertices.addBuffer(posBuffer, I_POS_LOCATION);

		box = graphics::Renderable(vertices, 4);

		// box.addTexture("./data/graphics/tile.png");
		// box.setFill(RGB(255, 255, 255));
	};

	TestLayer::~TestLayer()
	{
	}

	void TestLayer::update()
	{
		box.draw(program);

		// window->rCtx.submit(box, program);
		// window->rCtx.drawQue();
	}

	bool TestLayer::onEvent(const events::Event &event)
	{
		// ON_EVENT(mouseScroll, { // is this actually better?
		// 	box.rotateZ(e.getY() * 3);
		// });

		// ON_EVENT(MouseMove, {
		// 	box1.resetTransforms();
		// 	box1.translate(glm::vec3(e.getX() / (window->getWidth() / 2), -e.getY() / (window->getHeight() / 2), 0.0f));
		// });

		return false;
	}


	void TestLayer::onMount()
	{

	}
}
