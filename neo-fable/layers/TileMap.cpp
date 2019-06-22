#include "TileMap.hpp"

namespace layers {
	TileMap::TileMap() : Layer("tilemap")
	{
		for (int x = 0; x < MAP_SIZE; x++) 
		{
			for (int y = 0; y < MAP_SIZE; y++)
			{
				map[x][y] = abstract::Tile(x, y);
			}
		}
	}


	TileMap::~TileMap() {}

	void TileMap::onMount()
	{
		state->camera = new abstract::Camera({ 11 * TILE_SIZE, 11 * TILE_SIZE });
		state->player = new entity::Player();

		state->player->moveTo({ 11 * TILE_SIZE, 11 * TILE_SIZE });

	}

	void TileMap::applyRenderTransform()
	{
		int size = state->camera->viewport * TILE_SIZE * 2;

		float scalar = 1;

		int maxSize = std::min(window->getHeight() - 200, window->getWidth());
		if (maxSize < size)
			scalar = ((float)maxSize / (float)(size));

		SDL_RenderSetViewport(renderer, new SDL_Rect{
			(int)((window->getWidth() / 2) - ((size * scalar) / 2)),
			0,
			(int)(size * scalar),
			(int)(size * scalar)
			});

		SDL_RenderSetScale(renderer, scalar, scalar);
	}

	void TileMap::onUpdate(unsigned int dT) 
	{
		state->camera->update();
		state->camera->setTarget(state->player->getPos());

		float oX = state->camera->pos.x / TILE_SIZE;
		float oY = state->camera->pos.y / TILE_SIZE;
		int sX = (int)(floor(oX) - state->camera->viewport);
		int sY = (int)(floor(oY) - state->camera->viewport);

		for (int x = sX - 1; x < ceil(oX) + state->camera->viewport + 1; x++)
		{
			for (int y = sY - 1; y < ceil(oY) + state->camera->viewport + 1; y++)
			{	
				if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE)
				{
					map[x][y].draw(
						((x - sX) * TILE_SIZE) - ((int)state->camera->pos.x % TILE_SIZE),
						((y - sY) * TILE_SIZE) - ((int)state->camera->pos.y % TILE_SIZE)
					);
				}
			}
		}

		state->player->draw(state->camera);
	}

	bool TileMap::onEvent(SDL_Event *e) 
	{
		if (e->type == SDL_KEYDOWN)
		{
			if (e->key.keysym.sym == SDLK_UP)			state->player->moveFor({  0, -4 });
			else if (e->key.keysym.sym == SDLK_DOWN)	state->player->moveFor({  0,  4 });
			else if (e->key.keysym.sym == SDLK_LEFT)	state->player->moveFor({ -4,  0 });
			else if (e->key.keysym.sym == SDLK_RIGHT)	state->player->moveFor({  4,  0 });
		}

		return false;
	}
}