#include "application/log.hpp"
#include "application/Application.hpp"
#include "layers/TestLayer.hpp"
#include "layers/TileMap.hpp"
#include "data_loader/util.hpp"

int main(void)
{
	Application neoFable({ "derp", 960, 360 });

	layers::TestLayer test("test layer", neoFable.getWindow());
	neoFable.pushLayer(&test);

	// layers::TileMap map("tile map", neoFable.getWindow());
	// neoFable.pushLayer(&map);

	while (neoFable.shouldUpdate())
	{
		neoFable.update();
	}

	glfwTerminate();

	return 0;
}
