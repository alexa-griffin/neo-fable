#pragma once

#include <string>
#include <vector>

#include "Layer.hpp"
#include "Window.hpp"

class Application
{
public:
	Application(std::string name, SDL_WindowFlags flags =
		(SDL_WindowFlags)(SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE));

	~Application();

	void pushLayer(application::Layer* layer);
	void popLayer(application::Layer* layer);

private:
	std::vector<application::Layer*> layerStack;

	application::Window window
};

