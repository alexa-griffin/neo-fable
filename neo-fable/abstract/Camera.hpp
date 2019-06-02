#pragma once

#include "../util/maths/vec2.hpp"

#define MAX_OFFSET 20

namespace abstract {
	class Camera
	{
	public:
		Camera(util::maths::Vec2 p);
		~Camera();

		void setTarget(util::maths::Vec2 t) { trg = t; };
		void moveTarget(util::maths::Vec2 t) { trg += t; };

		void update();

	public:
		util::maths::Vec2 pos;
		unsigned int viewport = 10;

	private:
		float maxSpeed;
		float maxForce;

		util::maths::Vec2 trg;

		util::maths::Vec2 vel;
		util::maths::Vec2 acc;
	};
}

