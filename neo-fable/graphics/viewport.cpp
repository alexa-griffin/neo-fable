#include "viewport.hpp"

namespace viewport {
	Config getMapViewport(application::Window* window, abstract::Camera* camera)
	{
		Config out;

		int size = camera->viewport * TILE_SIZE * 2;

		float scalar = 1;

		int maxSize = std::min(window->getHeight() - 200, window->getWidth());
		if (maxSize < size) scalar = ((float)maxSize / (float)(size));

		out.viewport = SDL_Rect{
			(int)((window->getWidth() / 2) - ((size * scalar) / 2)),
			0,
			(int)(size * scalar),
			(int)(size * scalar)
		};

		out.scalar = { scalar, scalar };

		return out;
	}


	Config defaultView(application::Window* window)
	{
		Config out;
		out.scalar = { 1, 1 };
		out.viewport = SDL_Rect({ 0, 0, window->getWidth(), window->getHeight() });
		return out;
	}
}