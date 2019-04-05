#include "TileMap.hpp"


namespace layers {
	TileMap::TileMap(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win)
	{
		for (int i = 0; i < MAP_WIDTH; i++)
		{
			for (int j = 0; j < MAP_HEIGHT; j++)
			{
				map[i][j].rect = graphics::Rect(TILE_WIDTH, TILE_HEIGHT);

				map[i][j].position = glm::vec3(TILE_WIDTH * i, TILE_HEIGHT * j, 0.0f);
				map[i][j].rect.setFill(RGB(255, 0, 255));
			}
		}
	}


	TileMap::~TileMap()
	{
	}

	bool TileMap::onEvent(const events::Event &e)
	{
		return false;
	}

	void TileMap::update(unsigned int dT)
	{
		for (int i = 0; i < MAP_WIDTH; i++) 
		{
			for (int j = 0; j < MAP_HEIGHT; j++)
			{
				map[i][j].rect.resetTransforms();
				map[i][j].rect.translate(map[i][j].position);
				window->rCtx.submit(map[i][j].rect);
			}
		}
		window->rCtx.drawQue();
	}

	void TileMap::onMount()
	{

	}
}
