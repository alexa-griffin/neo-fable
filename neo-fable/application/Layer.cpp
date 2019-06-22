#include "Layer.hpp"


namespace application {
	Layer::Layer(std::string name) 
		: debugName(name), ready(false), renderer(nullptr), 
		renderView{ { 0, 0, 0, 0},{ 1, 1 } } // will not work without mounting
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::applyRenderTransform()
	{
		SDL_RenderSetViewport(renderer, &renderView.viewport);

		SDL_RenderSetScale(renderer, renderView.scalar.w, renderView.scalar.h);
	}

	void Layer::configRenderTransform()
	{
		if (ready)
		{
			renderView = viewport::defaultView(window);
		}
		else std::cout << "attempting to rendertransform an unmounted layer." << std::endl;
	}

	void Layer::__onMounted()
	{
		configRenderTransform();
	}

	void Layer::applyApplication(Application* app)
	{
		renderer = app->renderer;
		store = &app->store;
		state = app->store.getState();
		window = &app->window;

		ready = true;
	}
}
