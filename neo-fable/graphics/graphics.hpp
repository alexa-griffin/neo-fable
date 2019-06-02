#pragma once

#include <functional>

#include "SDL.h"

namespace graphics {
	namespace { // private
		SDL_Renderer* activeRenderer;
	}

	void bind(SDL_Renderer* ren);
	void direct(std::function<void(SDL_Renderer*)> f);
}