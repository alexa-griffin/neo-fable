#pragma once

#include <iostream>
#include "./maths.hpp"

namespace util {
	namespace maths {
		struct Vec2 {
			float x;
			float y;
			Vec2(float a) : x(a), y(a) {};
			Vec2(float a, float b) : x(a), y(b) {};
			Vec2() : x(0), y(0) {};
			void print() { std::cout << x << ", " << y << std::endl; };

			void limit(float m) { 
				x = fabs(x) > m ? m * sgn(x) : x;
				y = fabs(y) > m ? m * sgn(y) : y;
			}

			float mag() { return sqrt((x * x) + (y * y)); };

			void normalize() { 
				if (mag() != 0) {
					x /= mag(); 
					y /= mag(); 
				}
			}

			static float dist(Vec2 a, Vec2 b)
			{
				return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
			}

			Vec2 operator+(const Vec2& other) { return Vec2{ this->x + other.x, this->y + other.y }; };
			Vec2 operator-(const Vec2& other) { return Vec2{ this->x - other.x, this->y - other.y }; };
			Vec2 operator*(const Vec2& other) { return Vec2{ this->x * other.x, this->y * other.y }; };
			Vec2 operator/(const Vec2& other) { return Vec2{ this->x / other.x, this->y / other.y }; };

			Vec2 operator+(const float& a) { return Vec2{ this->x + a, this->y + a }; };
			Vec2 operator-(const float& a) { return Vec2{ this->x - a, this->y - a }; };
			Vec2 operator*(const float& a) { return Vec2{ this->x * a, this->y * a }; };
			Vec2 operator/(const float& a) { return Vec2{ this->x / a, this->y / a }; };

			Vec2* operator+=(const Vec2& other) { this->x += other.x; this->y += other.y; return this; };
			Vec2* operator-=(const Vec2& other) { this->x -= other.x; this->y -= other.y; return this; };
			Vec2* operator*=(const Vec2& other) { this->x *= other.x; this->y *= other.y; return this; };
			Vec2* operator/=(const Vec2& other) { this->x /= other.x; this->y /= other.y; return this; };

			Vec2* operator+=(const float& a) { this->x += a; this->y += a; return this; };
			Vec2* operator-=(const float& a) { this->x -= a; this->y -= a; return this; };
			Vec2* operator*=(const float& a) { this->x *= a; this->y *= a; return this; };
			Vec2* operator/=(const float& a) { this->x /= a; this->y /= a; return this; };
		};
	}
}