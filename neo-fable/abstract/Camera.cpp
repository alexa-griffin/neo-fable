#include "Camera.hpp"


namespace abstract {
	Camera::Camera(util::maths::Vec2 p) : pos(p), trg(p), 
		maxSpeed(2), maxForce(3)
	{
	}


	Camera::~Camera()
	{
	}

	void Camera::update()
	{
		auto des = trg - pos;
		const float dM = des.mag();
		des.normalize();
		if (dM > 100)
		{
			des *= maxSpeed;
		}
		else {
			des *= util::maths::remap(dM, 0, 100, 0, maxSpeed);
		}
		auto steer = des - vel;
		steer.limit(maxForce);
		if (fabs(trg.x - pos.x) < MAX_OFFSET / 2)
		{
			steer.x = 0;
			acc.x = 0;
			vel.x = 0;
		}
		if (fabs(trg.y - pos.y) < MAX_OFFSET / 2)
		{
			steer.y = 0;
			acc.y = 0;
			vel.y = 0;
		}
		acc += steer;
		vel += acc;
		vel.limit(maxSpeed);

		pos += vel;
	}
}
