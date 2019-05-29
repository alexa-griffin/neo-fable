#include "TestLayer.hpp"


namespace layers {
	int TestLayer::num = 0;

	TestLayer::TestLayer(SDL_Window *win) 
		: application::Layer("Test Layer" + num, NULL)
	{
		obj.w = 100;
		obj.h = 100;
		obj.x = 100;
		obj.y = 100;
		num++;
	}

	TestLayer::~TestLayer()
	{
	}

	void TestLayer::onUpdate(unsigned int dT)
	{
		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		SDL_RenderDrawRect(renderer, &obj);
	}

	bool TestLayer::onEvent(SDL_Event *e)
	{
		 //if (e->type == SDL_MOUSEMOTION)
		 //{
		 //	std::cout << "(" << e->motion.x << ", " << e->motion.y << ")" << std::endl;
		 //}
		return true;
	}
}
