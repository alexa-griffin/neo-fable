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

			data.width = w;
			data.height = h;

			events::WindowResize ev(w, h);
			if (data.onEvent) { data.onEvent(ev); }
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
		{
			WindowConfig& data = *(WindowConfig*)glfwGetWindowUserPointer(window);

			events::WindowClosed ev;
			if (data.onEvent) { data.onEvent(ev); }
		});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowConfig& data = *(WindowConfig*)glfwGetWindowUserPointer(window);

			if(action == GLFW_PRESS) 
			{
				events::KeyDown ev(key);
				if (data.onEvent) { data.onEvent(ev); }
			} 
			else if (action == GLFW_RELEASE)
			{
				events::KeyUp ev(key);
				if (data.onEvent) { data.onEvent(ev); }
			}
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y)
		{
			WindowConfig& data = *(WindowConfig*)glfwGetWindowUserPointer(window);

			events::MouseMove ev(x, y);
			if (data.onEvent) { data.onEvent(ev); }
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowConfig& data = *(WindowConfig*)glfwGetWindowUserPointer(window);

			if (action == GLFW_PRESS)
			{
				events::MouseDown ev(button);
				if (data.onEvent) { data.onEvent(ev); }
			}
			else if (action == GLFW_RELEASE)
			{
				events::MouseUp ev(button);
				if (data.onEvent) { data.onEvent(ev); }
			}
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double x, double y)
		{
			WindowConfig& data = *(WindowConfig*)glfwGetWindowUserPointer(window);

			events::MouseScroll ev(x, y);
			if (data.onEvent) { data.onEvent(ev); }
		});

		glfwSetWindowPosCallback(window, [](GLFWwindow* window, int x, int y)
		{
			WindowConfig& data = *(WindowConfig*)glfwGetWindowUserPointer(window);

			events::WindowMove ev(x, y);
			if (data.onEvent) { data.onEvent(ev); }
		});

		glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focused)
		{
			WindowConfig& data = *(WindowConfig*)glfwGetWindowUserPointer(window);

			if (focused == GLFW_TRUE)
			{
				events::WindowFocus ev;
				if (data.onEvent) { data.onEvent(ev); }
			}
			else if (focused == GLFW_FALSE)
			{
				events::WindowBlur ev;
				if (data.onEvent) { data.onEvent(ev); }
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