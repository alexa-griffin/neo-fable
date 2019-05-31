#pragma once
#include <iostream>
#include <SDL.h>

#define TILE_SIZE 32

namespace graphics {
	class Tile
	{
	public:
		Tile(int x, int y) 
			: x(x * TILE_SIZE), y(y * TILE_SIZE), obj{
				x * TILE_SIZE, y * TILE_SIZE,
				TILE_SIZE, TILE_SIZE 
			} {};
		Tile() {};
		~Tile();

		void draw(int posX, int posY, SDL_Renderer& ren);
	private:
		int x;
		int y;
		SDL_Rect obj;
	};
}

