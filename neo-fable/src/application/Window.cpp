#include "Window.hpp"

namespace application {
	bool glfwInitialized = false;

	Window* Window::create(const WindowConfig& config) 
	{
		return new Window(config);
	}

	Window::Window(WindowConfig config) : open(true)
	{
		init(config);
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
	}

	bool Window::init(WindowConfig config)
	{
		this->config.width = config.width;
		this->config.height = config.height;
		this->config.title = config.title;

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

	void Window::createCallbacks()
	{
		// store config data & callback handler
		glfwSetWindowUserPointer(window, &config);

		// create window events
		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int w, int h)
		{
			WindowConfig& data = *(WindowConfig*)glfwGetWindowUserPointer(window);

			std::cout << "derping" << std::endl;

			data.width = w;
			data.height = h;

			events::WindowResize ev(w, h);
			if (data.onEvent)
			{
				std::cout << "is true" << std::endl;
				data.onEvent(ev);
			}
			else
			{
				std::cout << "is false" << std::endl;
			}
		});
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

	unsigned int Window::getHeight()
	{
		return config.height;
	}
	
	unsigned int Window::getWidth()
	{
		return config.width;
	}


	void Window::setEventCallback(const windowEventCallback callback)
	{
		config.onEvent = callback;
		createCallbacks();
	}

}