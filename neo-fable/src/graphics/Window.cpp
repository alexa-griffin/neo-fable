#include "Window.hpp"

namespace graphics {
	bool glfwInitialized = false;

	Window::Window() : open(true)
	{
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
	}

	bool Window::init(WindowConfig config)
	{
		// init glfw
		if (!glfwInitialized && !glfwInit())
		{
			glfwInitialized = true;
			std::cout << "glfwInit failed or was already initialized" << std::endl;
			return false;
		}

		// create a window
		if (window = glfwCreateWindow(config.width, config.height, config.title.c_str(), NULL, NULL); 
			!window)
		{
			std::cout << "glfwCreateWindow failed" << std::endl;
			glfwTerminate();
			return false;
		}

		makeCurrentContext();

		// init glew
		if (const GLenum err = glewInit(); GLEW_OK != err)
		{
			std::cout << "glewInit failed" << std::endl;
			return false;
		}

		return true;
	}

	void Window::makeCurrentContext() 
	{
		glfwMakeContextCurrent(window);
	}

	void Window::update()
	{
		glfwSwapBuffers(window);
		glfwPollEvents();

		open = !glfwWindowShouldClose(window);
	}

	// checks if all things are ok to update
	bool Window::shouldUpdate()
	{
		return open;
	}
}