#pragma once

#include <string>

#include "SDL.h"

namespace application {
	class Layer
	{
	public:
		Layer(std::string name) : debugName(name) {};
		virtual ~Layer();

		virtual void onMount() {};
		virtual void onUnmount() {};
		virtual void onUpdate(unsigned int dT) = 0;
		virtual void onEvent(const SDL_Event* e) {};

	protected:
		std::string debugName;
	};
}

