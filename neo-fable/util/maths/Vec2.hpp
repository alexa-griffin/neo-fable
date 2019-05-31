#include <iostream>

namespace util {
	namespace maths {
		struct Vec2 {
			float x;
			float y;
			Vec2(float a) : x(a), y(a) {};
			Vec2(float a, float b) : x(a), y(b) {};
			Vec2() : x(0), y(0) {};
			void print() { std::cout << x << ", " << y << std::endl; };

			Vec2 operator+(const Vec2& other) { return Vec2{ this->x + other.x, this->y + other.y }; };
			Vec2 operator-(const Vec2& other) { return Vec2{ this->x - other.x, this->y - other.y }; };
			Vec2 operator*(const Vec2& other) { return Vec2{ this->x * other.x, this->y * other.y }; };
			Vec2 operator/(const Vec2& other) { return Vec2{ this->x / other.x, this->y / other.y }; };

			Vec2* operator+=(const Vec2& other) { this->x += other.x; this->y += other.y; return this; };
			Vec2* operator-=(const Vec2& other) { this->x -= other.x; this->y -= other.y; return this; };
			Vec2* operator*=(const Vec2& other) { this->x *= other.x; this->y *= other.y; return this; };
			Vec2* operator/=(const Vec2& other) { this->x /= other.x; this->y /= other.y; return this; };
		};
	}
}