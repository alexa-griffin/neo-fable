#include <iostream>
#include <string>

#include "SDL.h"
#undef main

#include "./application/Window.hpp"
#include "./application/Application.hpp"
#include "layers/TestLayer.hpp"
#include "layers/TileMap.hpp"

int main()
{
	application::init();
	Application game("neo fable");
	
	layers::TileMap* map = new layers::TileMap();

	game.pushLayer(map);

	while (game.shouldUpdate())
	{
		game.update();
	}

	game.destroy();

	return 0;
}