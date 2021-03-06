#pragma once
#include <iostream>
#include "SDL.h"

#include "../util/util.hpp"

#include "../graphics/graphics.hpp"

#define TILE_SIZE UNIT

namespace abstract {
	class Tile
	{
	public:
		Tile(int x, int y) 
			: x(x * TILE_SIZE), y(y * TILE_SIZE), obj{
				x * TILE_SIZE, y * TILE_SIZE,
				TILE_SIZE, TILE_SIZE 
			} {};
		Tile() : x(0), y(0), obj{0, 0, TILE_SIZE, TILE_SIZE} {};
		~Tile();

		void draw(int posX, int posY);
	private:
		int x;
		int y;
		SDL_Rect obj;
	};
}

