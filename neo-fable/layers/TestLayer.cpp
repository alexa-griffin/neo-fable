#include "TestLayer.hpp"


namespace layers {
	int TestLayer::num = 0;

	TestLayer::TestLayer() : application::Layer("Test Layer" + num)
	{
		num++;
	}


	TestLayer::~TestLayer()
	{
	}

	void TestLayer::onUpdate(unsigned int dT)
	{
	}

	bool TestLayer::onEvent(SDL_Event *e)
	{
		if (e->type == SDL_MOUSEMOTION)
		{
			std::cout << "(" << e->motion.x << ", " << e->motion.y << ")" << std::endl;
		}
		return true;
	}
}
