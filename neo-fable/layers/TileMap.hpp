#pragma once
#include <vector>
#include <cmath>

#include "../application/Layer.hpp"
#include "../graphics/graphics.hpp"

#include "../abstract/Camera.hpp"
#include "../abstract/entity/Player.hpp"
#include "../abstract/Tile.hpp"

#include "../util/maths/Vec2.hpp"

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
		
		virtual void configRenderTransform();

	private:
		abstract::Tile map[MAP_SIZE][MAP_SIZE];
	};
}