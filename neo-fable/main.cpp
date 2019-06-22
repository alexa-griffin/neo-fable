#include <iostream>
#include <string>

#include "SDL.h"
#undef main

#include "./application/Window.hpp"
#include "./application/Application.hpp"
#include "layers/TestLayer.hpp"
#include "layers/TileMap.hpp"
#include "layers/EntitySet.hpp"

int main()
{
	application::init();
	Application game("neo fable");
	
	layers::TileMap* map = new layers::TileMap();
	layers::EntitySet* ents = new layers::EntitySet();

	game.pushLayer(map);
	game.pushLayer(ents);

	while (game.shouldUpdate())
	{
		game.update();
	}

	game.destroy();

	return 0;
}