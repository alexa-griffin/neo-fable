#include "Layer.hpp"


namespace application {
	Layer::Layer(std::string name) 
		: debugName(name), ready(false), renderer(nullptr), 
		  renderScalar({ 1, 1 }), renderViewport({ 0, 0, 0, 0 }) // will not work without mounting
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::applyRenderTransform()
	{
		SDL_RenderSetViewport(renderer, &renderViewport);

		SDL_RenderSetScale(renderer, renderScalar.w, renderScalar.h);
	}

	void Layer::applyApplication(Application* app)
	{
		renderer = app->renderer;
		store = &app->store;
		state = app->store.getState();
		window = &app->window;

		renderScalar = { 1, 1 };
		renderViewport = SDL_Rect({ 0, 0, app->window.getWidth(), app->window.getHeight() });
		
		ready = true;
	}
}
