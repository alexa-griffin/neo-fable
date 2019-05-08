#pragma once

#include "SDL.h"
#include <string>

namespace application {
	class Window
	{
	public:
		Window(std::string title, SDL_WindowFlags flags = 
			(SDL_WindowFlags)(SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE));
		~Window();

		SDL_Window* getSDL() { return win; };

	private:
		SDL_Window* win;
	};
}