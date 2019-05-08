#include <iostream>
#include <string>

#include "SDL.h"
#undef main

#include "./application/Window.hpp"
#include "./application/Application.hpp"
#include "layers/TestLayer.hpp"

int main()
{
	application::init();
	Application game("hecka");

	layers::TestLayer* test = new layers::TestLayer();

	game.pushLayer(test);

	while (game.shouldUpdate())
	{
		game.update();
	}

	return 0;
}