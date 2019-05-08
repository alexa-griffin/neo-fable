#include "Window.hpp"


namespace application {
	Window::Window(std::string title, SDL_WindowFlags flags)
	{
		win = SDL_CreateWindow(title.c_str(), 0, 0, 0, 0, flags);
	}

	Window::~Window() {}
}