#include <iostream>

#include "application/Application.hpp"

Application neoFable({ "derp", 480, 480 });

int main(void)
{
	while (neoFable.shouldUpdate())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		neoFable.update();
	}

	glfwTerminate();

	return 0;
}
