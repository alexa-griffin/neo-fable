#include "TestLayer.hpp"


namespace layers {
	int TestLayer::num = 0;

	TestLayer::TestLayer() : 
		application::Layer("Test Layer" + num),
		obj(SDL_Rect{ 100, 100, 100, 100 })
	{
		num++;
	}

	TestLayer::~TestLayer()
	{
	}

	void TestLayer::onUpdate(unsigned int dT)
	{
		SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
		SDL_RenderFillRect(renderer, &obj);
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
