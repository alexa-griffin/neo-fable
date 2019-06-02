#pragma once

#include "../Entity.hpp"
#include "../../util/util.hpp"
#include "../../graphics/graphics.hpp"

namespace entity {
	class Player : public abstract::Entity
	{
	public:
		Player();
		~Player();

		void moveFor(util::maths::Vec2 dM) { pos += dM; };
		void moveTo(util::maths::Vec2 trg) { pos = trg; };

		virtual void update();
		virtual void draw(abstract::Camera* cam);
	};
}

