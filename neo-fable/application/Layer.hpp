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
		virtual bool onEvent(SDL_Event* e) { return false; };

	protected:
		std::string debugName;
	};
}

