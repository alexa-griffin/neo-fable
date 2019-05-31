#include "TileMap.hpp"

namespace layers {
	TileMap::TileMap() : Layer("tilemap"), camera({ 11 * TILE_SIZE, 11 * TILE_SIZE })
	{
		for (int x = 0; x < MAP_SIZE; x++) 
		{
			for (int y = 0; y < MAP_SIZE; y++)
			{
				map[x][y] = graphics::Tile(x, y);
			}
		}
	}


	TileMap::~TileMap() {}

	void TileMap::onMount()
	{
		SDL_RenderSetClipRect(renderer, new SDL_Rect{
			0, 0, 
			(int)viewport * TILE_SIZE * 2, 
			(int)viewport * TILE_SIZE * 2
		});
	}

	void TileMap::onUpdate(unsigned int dT) 
	{
		float oX = camera.pos.x / TILE_SIZE;
		float oY = camera.pos.y / TILE_SIZE;
		int sX = floor(oX) - viewport;
		int sY = floor(oY) - viewport;

		std::cout << camera.pos.x << ", " << camera.pos.y << std::endl;

		for (int x = sX - 1; x < ceil(oX) + viewport + 1; x++)
		{
			for (int y = sY - 1; y < ceil(oY) + viewport + 1; y++)
			{	
				if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE)
				{
					map[x][y].draw(
						((x - sX) * TILE_SIZE) - ((int)camera.pos.x % TILE_SIZE),
						((y - sY) * TILE_SIZE) - ((int)camera.pos.y % TILE_SIZE),
						*renderer
					);
				}
			}
		}

		SDL_RenderFillRect(renderer, new SDL_Rect{
			(int)(((TILE_SIZE * viewport * 2) / 2) - 16),
			(int)(((TILE_SIZE * viewport * 2) / 2) - 16),
			32,
			32
		});
	}

	bool TileMap::onEvent(SDL_Event *e) 
	{
		if (e->type == SDL_KEYDOWN)
		{
			if (e->key.keysym.sym == SDLK_UP)			camera.pos.y -= 4;
			else if (e->key.keysym.sym == SDLK_DOWN)	camera.pos.y += 4;
			else if (e->key.keysym.sym == SDLK_LEFT)	camera.pos.x -= 4;
			else if (e->key.keysym.sym == SDLK_RIGHT)	camera.pos.x += 4;
		}
		else if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			camera.pos.y = 0;
			camera.pos.y = 0;
			camera.pos.x = 0;
			camera.pos.x = 0;
		}

		return false;
	}
}