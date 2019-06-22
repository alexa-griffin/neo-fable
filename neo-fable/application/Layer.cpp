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

	void Layer::configRenderTransform()
	{
		if (ready)
		{
			renderScalar = { 1, 1 };
			renderViewport = SDL_Rect({ 0, 0, window->getWidth(), window->getHeight() });
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
