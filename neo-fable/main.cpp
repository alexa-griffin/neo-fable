#include <iostream>
#include "SDL.h"

#undef main

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* win = SDL_CreateWindow("hecka", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	std::cout << "hello world!" << std::endl;

	SDL_ShowWindow(win);
	while (true)
	{
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}

	std::cin.get();
	return 0;
}