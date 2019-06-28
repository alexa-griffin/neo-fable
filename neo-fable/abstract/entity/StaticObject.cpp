#include "StaticObject.hpp"


namespace entity {
	StaticObject::StaticObject(util::maths::Vec2 pos, util::Color c) : 
		Entity(pos, { UNIT, UNIT }),
		rendered(new SDL_Rect{ 0, 0, UNIT, UNIT }),
		color(c)
	{
	}

	StaticObject::~StaticObject()
	{
		delete rendered;
	}

	void StaticObject::draw(abstract::Camera* cam)
	{
		std::cout << cam->pos.x << ", " << cam->pos.y << std::endl;

		graphics::direct([=](SDL_Renderer* renderer) {
			SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

			rendered->x = (int)(pos.x - cam->pos.x) + (cam->viewport * UNIT);
			rendered->y = (int)(pos.y - cam->pos.y) + (cam->viewport * UNIT);

			SDL_RenderFillRect(renderer, rendered);
		});
	}
}