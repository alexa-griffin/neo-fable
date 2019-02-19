#pragma once

#include "Window.hpp"
#include "LayerStack.hpp"
#include "Layer.hpp"
#include "../events/events.hpp"

class Application
{
public:
	Application(application::WindowConfig config);

	void onEvent(events::Event &e);
	void update();
	bool shouldUpdate();

	void pushOverlay(application::Layer *layer);
	void popOverlay(application::Layer *layer);
	void pushLayer(application::Layer *layer);
	void popLayer(application::Layer *layer);

private:
	std::unique_ptr<application::Window> window;
	application::LayerStack overlayStack;
	application::LayerStack layerStack;
};

