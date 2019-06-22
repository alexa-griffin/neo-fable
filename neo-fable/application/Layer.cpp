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
		renderer = app->renderer;
		store = &app->store;
		state = app->store.getState();
		window = &app->window;
	}
}
