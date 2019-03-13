#pragma once

#include <iostream>
#include <string>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>

#include "../events/events.hpp"

#include "../graphics/graphics.hpp"

namespace application {
	extern bool glfwInitialized;

	using windowEventCallback = std::function<void(events::Event&)>;

	struct WindowConfig 
	{
		std::string title = "you forgot to give it a title you doof (also prob a width and height)";
		unsigned int width = 720;
		unsigned int height = 480;
		bool open = true;
		windowEventCallback onEvent;
	};

	class Window
	{
	public:
		static Window* create(const WindowConfig& config);
		Window(WindowConfig config);
		~Window();

		bool init(WindowConfig config);
		void makeCurrentContext();
		void update();
		bool shouldUpdate();

		void createCallbacks();

		void setEventCallback(const windowEventCallback callback);

		unsigned int getHeight();
		unsigned int getWidth();

	private:
		GLFWwindow* window;
		WindowConfig config;

	public:
		graphics::Renderer renderCtx;
	};
}

