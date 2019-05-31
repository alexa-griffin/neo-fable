#include "Layer.hpp"


namespace application {
	Layer::Layer(std::string name) 
		: debugName(name), ready(false)
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::applyApplication(Window* win)
	{
		ready = true;
		renderer = SDL_CreateRenderer(win->getSDL(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
}
