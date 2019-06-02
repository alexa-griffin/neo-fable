#pragma once

#include "SDL.h"
#include "Camera.hpp"

#include "../util/maths/Vec2.hpp"

namespace abstract {
	class Entity
	{
	public:
		//TODO: renderer+camera combination
		virtual void draw(Camera* cam) {};
		virtual void update() {};

		virtual util::maths::Vec2 getPos() { return pos; };
		virtual util::maths::Vec2 getSize() { return size; };

	protected:
		Entity() : pos(0.0f), size(0.0f) {};
		Entity(util::maths::Vec2 p) : pos(p), size(0.0f) {};
		Entity(util::maths::Vec2 p, util::maths::Vec2 s) : pos(p), size(s) {};
		~Entity();

		util::maths::Vec2 pos;
		util::maths::Vec2 size;
	};
}

