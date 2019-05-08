#include "TestLayer.hpp"


namespace layers {
	int TestLayer::num = 0;

	TestLayer::TestLayer(SDL_Window *win) 
		: application::Layer("Test Layer" + num), 
		  renderer(SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED))
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
