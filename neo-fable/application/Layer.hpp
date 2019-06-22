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

		// layer lifecycle
		virtual void onMount() {};
		virtual void onMounted() {};
		// repeat until unmounted
		virtual void onUpdate(unsigned int dT) = 0;
		virtual bool onEvent(SDL_Event* e) { return false; };
		// then
		virtual void onUnmount() {};

		// meta methods called by Layer not its children
		void __onMount() { if (!ready) std::cout << "[WARN] attempting to mount a layer that has not been applied to the application" << std::endl; };
		void __onMounted();

		void applyApplication(Application* app);

		virtual void applyRenderTransform();
		virtual void configRenderTransform();

	protected:
		friend class Application;

		std::string debugName;
		SDL_Renderer* renderer;
		application::Store* store;
		application::State* state;
		application::Window* window;

		bool ready;

		// these need to be updated on window resize
		SDL_Rect renderViewport;
		util::maths::Vec2 renderScalar;
	};
}

