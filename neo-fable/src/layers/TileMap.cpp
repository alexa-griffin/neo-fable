#include "TileMap.hpp"


namespace layers {
	TileMap::TileMap(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win), tile(TILE_WIDTH, TILE_HEIGHT), program("./data/shaders/tileMap.vert.shader", "./data/shaders/tileMap.frag.shader")
	{
		// program = opengl::Program("./data/shaders/tileMap.vert.shader", "./data/shaders/tileMap.frag.shader");
		// 
		// for (int i = 0; i < MAP_WIDTH; i++)
		// {
		// 	for (int j = 0; j < MAP_HEIGHT; j++)
		// 	{
		// 		map[i * j].position = glm::vec2(TILE_WIDTH * i, TILE_HEIGHT * j);
		// 		map[i * j].color = RGB(255, 0, 255);
		// 	}
		// }
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
		// tile.use();
		// program.use();
		// for (int i = 0; i < (MAP_WIDTH * MAP_HEIGHT); i++)
		// {
		// 	std::string u = std::string("offsets[") + std::to_string(i) + "]";
		// 	program.setUniform(u.c_str(), glUniform2fv, 1, &(map[i].position[0]));
		// }
		// glDrawArraysInstanced(GL_TRIANGLES, 0, tile.getIboLen(), MAP_WIDTH * MAP_HEIGHT);
	}

	void TileMap::onMount()
	{

	}
}
