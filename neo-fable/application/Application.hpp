#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Window.hpp"
#include "Store.hpp"

namespace application {
	class Layer;
}

class Application
{
public:
	Application(std::string name, SDL_WindowFlags flags =
		(SDL_WindowFlags)(SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE));

	~Application();

	void pushLayer(application::Layer* layer);
	void popLayer(application::Layer* layer);

	void update();
	bool shouldUpdate() { return running; };
	void pollEvents();
	SDL_Window* getWindow() { return window.getSDL(); };

	void destroy();

private:
	std::vector<application::Layer*> layerStack;
	application::Window window;
	SDL_Renderer* renderer;
	bool running;
	SDL_Event ev;

	application::Store store;

	friend class Window;
	friend class application::Layer;
};

namespace application {
	void init();
}
