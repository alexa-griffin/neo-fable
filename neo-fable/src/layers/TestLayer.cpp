#include "TestLayer.hpp"



namespace layers {
	TestLayer::TestLayer(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win), box(100, 100), box1(100, 100), 
		program("./data/shaders/default/tinted.vert.shader", "./data/shaders/default/tinted.frag.shader")
	{
		// rctx.loadDefaultPrograms();
		// box.addTexture("./data/graphics/tile.png");
		box.setFill(RGB(0, 0, 255), RGB(0, 255, 0), RGB(0, 255, 255), RGB(255, 0, 255));
		box1.setFill(RGB(0, 0, 255), RGB(0, 255, 0), RGB(0, 255, 255), RGB(255, 0, 255));

		rctx.setProgram(&program);
	};

	TestLayer::~TestLayer()
	{
	}

	void TestLayer::update(unsigned int dT)
	{		
		rctx.submit(box);
		rctx.submit(box1);

		rctx.draw();
	}

	bool TestLayer::onEvent(const events::Event &event)
	{
		// ON_MOUSE_MOVE({
		// 	box.resetTransforms();
		// 	box.translate(glm::vec3(e.getX(), e.getY(), 0.0f));
		// 	box1.resetTransforms();
		// 	box1.translate(glm::vec3(e.getX() - 100, e.getY() - 100, 0.0f));
		// });

		ON_WINDOW_RESIZE({
			rctx.resizeOrthoProj(e.getWidth(), e.getHeight());
		});

		return false;
	}

	void TestLayer::onMount()
	{
		rctx.resizeOrthoProj(window->getWidth(), window->getHeight());
		rctx.loadDefaultPrograms();
	}
}
