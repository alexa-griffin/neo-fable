#pragma once

#include "Window.hpp"
#include "../events/events.hpp"

class Application
{
private:
	std::unique_ptr<application::Window> window;
public:
	Application(application::WindowConfig config);

	void onEvent(events::Event &e);
	void update();
	bool shouldUpdate();
};

