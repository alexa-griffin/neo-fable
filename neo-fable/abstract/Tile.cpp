#include "Tile.hpp"

namespace abstract {
	Tile::~Tile()
	{
	}

	void Tile::draw(int posX, int posY)
	{
		obj.x = posX;
		obj.y = posY;
		graphics::direct([=](SDL_Renderer* renderer) 
			{
				SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
				SDL_RenderDrawRect(renderer, &obj);
			}
		);
	}
}
