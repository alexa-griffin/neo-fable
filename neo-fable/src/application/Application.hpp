#pragma once

#include "Window.hpp"
#include "LayerStack.hpp"
#include "../events/events.hpp"

class Application
{
public:
	Application(application::WindowConfig config);

	void onEvent(events::Event &e);
	void update();
	bool shouldUpdate();

	void pushOverlay(Layer *layer);
	void popOverlay(Layer *layer);
	void pushLayer(Layer *layer);
	void popLayer(Layer *layer);

private:
	std::unique_ptr<application::Window> window;
	application::LayerStack overlayStack;
	application::LayerStack layerStack;
};

