#pragma once
#include <vector>
#include <cmath>

#include "../application/Layer.hpp"
#include "../graphics/Tile.hpp"

#include "../abstract/Camera.hpp"

#define MAP_SIZE 1000

namespace layers {
	class TileMap : public application::Layer 
	{
	public:
		TileMap();
		~TileMap();

		virtual void onUpdate(unsigned int dT);
		virtual void onMount();
		virtual bool onEvent(SDL_Event* e);
	private:
		unsigned int viewport = 10;
		abstract::Camera camera;

		graphics::Tile map[MAP_SIZE][MAP_SIZE];
	};
}