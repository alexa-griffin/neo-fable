#include "Layer.hpp"


namespace application {
	Layer::Layer(std::string name) 
		: debugName(name), ready(false), renderer(nullptr), renderScalar({ 1, 1 })
	{
	}

	Layer::~Layer()
	{
		delete renderViewport;
	}

	void Layer::applyRenderTransform()
	{
		SDL_RenderSetViewport(renderer, renderViewport);

		SDL_RenderSetScale(renderer, renderScalar.w, renderScalar.h);
	}

	void Layer::applyApplication(Application* app)
	{
		ready = true;
		renderer = app->renderer;
		store = &app->store;
		state = app->store.getState();
		window = &app->window;

		renderScalar = { 1, 1 };
		renderViewport = new SDL_Rect({ 0, 0, app->window.getWidth(), app->window.getHeight() });
	}
}
