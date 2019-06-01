#include "TileMap.hpp"

namespace layers {
	TileMap::TileMap() : Layer("tilemap"), 
		playerPos(11 * TILE_SIZE, 11 * TILE_SIZE)
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
		state->camera = new abstract::Camera({ 11 * TILE_SIZE, 11 * TILE_SIZE });

		SDL_RenderSetClipRect(renderer, new SDL_Rect{
			0, 0, 
			(int)viewport * TILE_SIZE * 2, 
			(int)viewport * TILE_SIZE * 2
		});
	}

	void TileMap::onUpdate(unsigned int dT) 
	{
		state->camera->update();
		state->camera->setTarget(playerPos);

		float oX = state->camera->pos.x / TILE_SIZE;
		float oY = state->camera->pos.y / TILE_SIZE;
		int sX = (int)(floor(oX) - viewport);
		int sY = (int)(floor(oY) - viewport);

		for (int x = sX - 1; x < ceil(oX) + viewport + 1; x++)
		{
			for (int y = sY - 1; y < ceil(oY) + viewport + 1; y++)
			{	
				if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE)
				{
					map[x][y].draw(
						((x - sX) * TILE_SIZE) - ((int)state->camera->pos.x % TILE_SIZE),
						((y - sY) * TILE_SIZE) - ((int)state->camera->pos.y % TILE_SIZE),
						*renderer
					);
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

		SDL_RenderFillRect(renderer, new SDL_Rect{
			(int)(playerPos.x - state->camera->pos.x) + (int)(viewport * TILE_SIZE),
			(int)(playerPos.y - state->camera->pos.y) + (int)(viewport * TILE_SIZE),
			32,
			32
		});
	}

	bool TileMap::onEvent(SDL_Event *e) 
	{
		if (e->type == SDL_KEYDOWN)
		{
			if (e->key.keysym.sym == SDLK_UP)			playerPos += {  0, -4 };
			else if (e->key.keysym.sym == SDLK_DOWN)	playerPos += {  0,  4 };
			else if (e->key.keysym.sym == SDLK_LEFT)	playerPos += { -4,  0 };
			else if (e->key.keysym.sym == SDLK_RIGHT)	playerPos += {  4,  0 };
		}

		return false;
	}
}