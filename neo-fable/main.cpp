#include <iostream>
#include "SDL.h"

#undef main

#include "./application/Window.hpp"


int main()
{

	SDL_Init(SDL_INIT_EVERYTHING);
	application::Window win("hecka");
	SDL_Renderer* renderer = SDL_CreateRenderer(win.getSDL(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	SDL_ShowWindow(win.getSDL());

	std::cin.get();
	return 0;
}