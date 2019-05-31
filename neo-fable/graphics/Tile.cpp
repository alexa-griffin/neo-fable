#include "Tile.hpp"

namespace graphics {
	Tile::~Tile()
	{
	}

	void Tile::draw(int posX, int posY, SDL_Renderer& ren)
	{
		obj.x = posX;
		obj.y = posY;

		SDL_SetRenderDrawColor(&ren, 255, 255, 255, 255);
		SDL_RenderDrawRect(&ren, &obj);
	}
}
