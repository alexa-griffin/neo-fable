#include "TileMap.hpp"


namespace layers {
	TileMap::TileMap(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win),
		  program("./data/shaders/default/tinted.vert.shader", "./data/shaders/default/tinted.frag.shader")
	{
		for (int i = 0; i < MAP_WIDTH; i++)
		{
			for (int j = 0; j < MAP_HEIGHT; j++)
			{
				map[i * j].rect = graphics::Rect(32, 32);
				map[i * j].rect.setFill(RGB(255, 0, 255), RGB(0, 0, 255), RGB(0, 255, 255), RGB(255, 0, 255));
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
		rctx.setProgram(&program);
		for (int i = 0; i < (MAP_WIDTH * MAP_HEIGHT); i++)
		{
			rctx.submit(map[i].rect);
		}
		rctx.draw();
	}

	void TileMap::onMount()
	{

	}
}
