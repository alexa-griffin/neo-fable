#include "Layer.hpp"


namespace application {
	Layer::Layer(std::string name) 
		: debugName(name), ready(false), renderer(nullptr)
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::applyRenderTransform()
	{
		SDL_RenderSetViewport(renderer, new SDL_Rect{
			0,
			0,
			window->getWidth(),
			window->getHeight()
		});

		SDL_RenderSetScale(renderer, 1, 1);
	}

	void Layer::applyApplication(Application* app)
	{
		ready = true;
		renderer = app->renderer;
		store = &app->store;
		state = app->store.getState();
		window = &app->window;
	}
}
