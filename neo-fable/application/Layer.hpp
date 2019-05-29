#pragma once

#include <string>

#include "SDL.h"

namespace application {
	class Layer
	{
	public:
		Layer(std::string name, SDL_Renderer *ren) 
			: debugName(name), renderer(ren) {};
		virtual ~Layer();

		virtual void onMount() {};
		virtual void onUnmount() {};
		virtual void onUpdate(unsigned int dT) = 0;
		virtual bool onEvent(SDL_Event* e) { return false; };

		void applyApplication(SDL_Renderer *ren);

	protected:
		std::string debugName;
		SDL_Renderer *renderer;
	};
}

