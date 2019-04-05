#pragma once

#include "../application/Window.hpp"
#include "../application/Layer.hpp"
#include "../graphics/graphics.hpp"
#include "../data_loader/util.hpp"

#include "../graphics/graphics.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define MAP_WIDTH 4
#define MAP_HEIGHT 4

#define TILE_WIDTH 32
#define TILE_HEIGHT 32

namespace layers {
	struct Tile {
		glm::vec3 position;
		graphics::Rect rect;
		Tile() : rect(TILE_WIDTH, TILE_HEIGHT) {};
	};

	class TileMap : public application::Layer
	{
	public:
		TileMap(std::string name, std::shared_ptr<application::Window> win);
		~TileMap();

		bool onEvent(const events::Event &e) override;
		virtual void update(unsigned int dT);
		virtual void onMount();


	private:
		Tile map[MAP_WIDTH][MAP_HEIGHT];
	};
}
