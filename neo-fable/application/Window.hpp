#pragma once

#include "SDL.h"
#include <string>

namespace application {
	class Window
	{
	public:
		Window(std::string title, SDL_WindowFlags flags);
		~Window();

		SDL_Window* getSDL() { return win; };

		int getWidth() { return SDL_GetWindowSurface(win)->w; };
		int getHeight() { return SDL_GetWindowSurface(win)->h; };

	private:
		SDL_Window* win;
	};
}