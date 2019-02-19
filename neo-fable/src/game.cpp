#include <iostream>

#include "application/Application.hpp"
#include "layers/TestLayer.hpp"

Application neoFable({ "derp", 480, 480 });

layers::TestLayer test("test layer");

int main(void)
{
	neoFable.pushLayer(&test);

	while (neoFable.shouldUpdate())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		neoFable.update();
	}

	glfwTerminate();

	return 0;
}
