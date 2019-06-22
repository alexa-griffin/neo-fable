#pragma once

#include <SDL.h>
#include "../util/maths/Vec2.hpp"
#include "../application/Window.hpp"
#include "../abstract/Tile.hpp"
#include "../abstract/Camera.hpp"

namespace viewport {
	struct Config {
		SDL_Rect viewport;
		util::maths::Vec2 scalar;
	};
	
	Config getMapViewport(application::Window* window, abstract::Camera* camera);
	Config defaultView(application::Window* window);
}