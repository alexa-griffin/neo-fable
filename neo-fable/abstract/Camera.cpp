#include "Camera.hpp"


namespace abstract {
	Camera::Camera(util::maths::Vec2 p) : pos(p), trg(p)
	{
	}


	Camera::~Camera()
	{
	}

	void Camera::update()
	{
		pos += vel;
		vel += acc;

		
	}
}
