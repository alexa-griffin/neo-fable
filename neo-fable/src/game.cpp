#include <iostream>

#include "application/log.hpp"
#include "application/Application.hpp"
#include "layers/TestLayer.hpp"
#include "data_loader/util.hpp"

Application neoFable({ "derp", 480, 360 });

layers::TestLayer test("test layer");

int main(void)
{
	neoFable.pushLayer(&test);

	LOG_ERROR("hello world", "error", 6);
	LOG_INFO("hello world", "info", 42);
	LOG_WARN("hello world", "warn", 5);

	float this_is_a_variable = 73;

	LOG_VAR(this_is_a_variable);

	while (neoFable.shouldUpdate())
	{
		// glClear(GL_COLOR_BUFFER_BIT);
		neoFable.update();
	}

	glfwTerminate();

	return 0;
}
