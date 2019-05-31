#pragma once
#include "../application/Layer.hpp"

#include <iostream>

namespace layers {
	class TestLayer : public application::Layer
	{
	public:
		TestLayer();
		~TestLayer();

		virtual void onUpdate(unsigned int dT);
		virtual bool onEvent(SDL_Event *e);

	private:
		static int num;

		SDL_Rect obj;
	};
}

