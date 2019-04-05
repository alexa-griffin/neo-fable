#include "Application.hpp"


Application::Application(application::WindowConfig config)
{
	// window setup
	window = std::unique_ptr<application::Window>(application::Window::create(config));
	window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
	window->createCallbacks();
	window->rCtx.resizeOrthoProj(config.width, config.height);
	window->rCtx.loadDefaultPrograms();
}

void Application::onEvent(events::Event& e) 
{
	for (application::Layer* overlay : overlayStack)
	{
		if (overlay->onEvent(e)) return;
	}

	for (application::Layer* layer : layerStack)
	{
		if (layer->onEvent(e)) return;
	}
}

void Application::update()
{
	window->rCtx.clearScreen();

	for (application::Layer* layer : layerStack)
	{
		layer->update(0);
	}

	for (application::Layer* overlay : overlayStack)
	{
		overlay->update(0);
	}

	window->update();
}

// checks if all layers and the window are ok
bool Application::shouldUpdate()
{
	return window->shouldUpdate();
}


// layer stack functionality (wrapper around multiple layer stacks for overlay render priority)
void Application::pushOverlay(application::Layer *layer)
{
	overlayStack.push(layer);
}

void Application::popOverlay(application::Layer *layer)
{
	overlayStack.pop(layer);
}

void Application::pushLayer(application::Layer *layer)
{
	layerStack.push(layer);
}

void Application::popLayer(application::Layer *layer)
{
	layerStack.pop(layer);
}