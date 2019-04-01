#include "application/log.hpp"
#include "application/Application.hpp"
#include "layers/TestLayer.hpp"
#include "data_loader/util.hpp"


int main(void)
{
	Application neoFable({ "derp", 700, 360 });
	LOG_INFO("created application");
	layers::TestLayer test("test layer", neoFable.getWindow());
	LOG_INFO("created layer");

	neoFable.pushLayer(&test);

	while (neoFable.shouldUpdate())
	{
		neoFable.update();
	}

	glfwTerminate();

	return 0;
}
