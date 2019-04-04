#include "TestLayer.hpp"



namespace layers {
	using namespace application;
	using namespace events;

	TestLayer::TestLayer(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win), box(100, 100)
	{
		box.addTexture("./data/graphics/tile.png");
		box.setFill(RGB(0, 0, 255), RGB(0, 255, 0), RGB(0, 255, 255), RGB(255, 0, 255));
	};

	TestLayer::~TestLayer()
	{
	}

	void TestLayer::update()
	{
		window->rCtx.submit(box);
		
		window->rCtx.drawQue();
	}

	bool TestLayer::onEvent(const events::Event &event)
	{
		ON_EVENT(mouseMove, {
			box.resetTransforms();
			box.translate(glm::vec3(e.getX() / (window->getWidth() / 2), -e.getY() / (window->getHeight() / 2), 0.0f));
		});

		return false;
	}


	void TestLayer::onMount()
	{

	}
}
