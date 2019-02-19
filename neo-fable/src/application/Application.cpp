#include "Application.hpp"


Application::Application(application::WindowConfig config)
{
	window = std::unique_ptr<application::Window>(application::Window::create(config));

	window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

	window->createCallbacks();
}

void Application::onEvent(events::Event& e) 
{
	e.debugPrint();

	if (e.getType() == events::eventType::windowClose)
	{
		glfwTerminate();
	}
}

void Application::update()
{
	window->update();
	for (application::Layer* layer : layerStack)
	{
		layer->update();
	}

	for (application::Layer* overlay : overlayStack)
	{
		overlay->update();
	}
}

// checks if all layers and the window are ok
bool Application::shouldUpdate()
{
	return window->shouldUpdate();
}


// layer stack (wrapper around multiple layer stacks for overlay priority)
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