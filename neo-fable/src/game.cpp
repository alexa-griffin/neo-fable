#include <iostream>
#include "graphics/Window.hpp"


graphics::Window window;

int main(void)
{

	if (!window.init({ "Neo Fable" })) return -1;

	while (window.shouldUpdate())
	{
		glClear(GL_COLOR_BUFFER_BIT);

		window.update();
	}

	glfwTerminate();

	return 0;
}
