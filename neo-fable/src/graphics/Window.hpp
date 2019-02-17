#pragma once

#include <iostream>
#include <string>

#include <GLEW/GL/glew.h>
#include <GLFW/glfw3.h>


namespace graphics {
	extern bool glfwInitialized;

	struct WindowConfig 
	{
		std::string title = "you forgot to give it a title you doof (also prob a width and height)";
		unsigned int width = 720;
		unsigned int height = 480;
	};


	class Window
	{
	private:
		GLFWwindow* window;
		bool open;
	public:
		Window();
		~Window();
		bool init(WindowConfig config);
		void makeCurrentContext();
		void update();
		bool shouldUpdate();
	};
}

