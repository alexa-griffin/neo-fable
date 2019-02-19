#include "Application.hpp"


Application::Application(application::WindowConfig config)
{
	window = std::unique_ptr<application::Window>(application::Window::create(config));

	window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

	window->createCallbacks();
}

void Application::onEvent(events::Event& e) 
{
	std::cout << "got event: " << e.getType() << std::endl;

	if (e.getType() == events::eventType::windowResize)
	{
		std::cout << window->getHeight() << ", " << window->getWidth() << std::endl;
	}

}

void Application::update()
{
	window->update();
}

// checks if all layers and the window are ok
bool Application::shouldUpdate()
{
	return window->shouldUpdate();
}