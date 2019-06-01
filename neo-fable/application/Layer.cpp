#include "Layer.hpp"


namespace application {
	Layer::Layer(std::string name) 
		: debugName(name), ready(false), renderer(nullptr)
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::applyApplication(Application* app)
	{
		ready = true;
		renderer = SDL_CreateRenderer(app->window.getSDL(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		store = &app->store;
		state = app->store.getState();
	}
}
