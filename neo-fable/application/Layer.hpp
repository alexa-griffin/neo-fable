#pragma once

#include <string>
#include <iostream>

#include "SDL.h"

#include "Window.hpp"
#include "Application.hpp"

namespace application {
	class Layer
	{
	public:
		Layer(std::string name);
		virtual ~Layer();

		virtual void onMount() {};
		virtual void onUnmount() {};
		virtual void onUpdate(unsigned int dT) = 0;
		virtual bool onEvent(SDL_Event* e) { return false; };

		void __onMount() { if (!ready) std::cout << "[WARN] attempting to mount a layer that has not been applied to the application" << std::endl; };

		void applyApplication(Window* win);

	protected:
		friend class Application;

		std::string debugName;
		SDL_Renderer* renderer;

		bool ready;
	};
}

