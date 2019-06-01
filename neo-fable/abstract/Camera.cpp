#include "Camera.hpp"


namespace abstract {
	Camera::Camera(util::maths::Vec2 p) : pos(p), trg(p), 
		maxSpeed(2), maxForce(1)
	{
	}


	Camera::~Camera()
	{
	}

	void Camera::update()
	{
		if (util::maths::Vec2::dist(pos, trg) > 20)
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

			acc += steer;
			vel += acc;
			vel.limit(maxSpeed);

			pos += vel;
		}
	}
}
