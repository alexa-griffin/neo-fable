#include "graphics.hpp"

namespace graphics {

	void bind(SDL_Renderer* ren)
	{
		activeRenderer = ren;
	}

	void direct(std::function<void(SDL_Renderer*)> f)
	{
		f(activeRenderer);
	}
}