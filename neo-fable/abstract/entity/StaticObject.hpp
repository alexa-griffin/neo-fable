#pragma once

#include "../Entity.hpp"
#include "../../util/util.hpp"
#include "../../graphics/graphics.hpp"

namespace entity {
	class StaticObject : public abstract::Entity
	{
	public:
		StaticObject(util::maths::Vec2 pos, util::Color c);
		~StaticObject();

		virtual void draw(abstract::Camera* cam);

	private:
		SDL_Rect* rendered;
		util::Color color;
	};
}
