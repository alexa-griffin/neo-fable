namespace util {
	namespace maths {
		template<typename T = float>
		struct vec2 {
			T x;
			T y;
			vec2(T a) : x(a), y(a) {};
			vec2(T a, T b) : x(a), y(b) {};
			vec2() : x(0), y(0) {};
			void print() { std::cout << x << ", " << y << std::endl; };

			vec2 operator+(const vec2& other) { return vec2{ this->x + other.x, this->y + other.y }; };
			vec2 operator-(const vec2& other) { return vec2{ this->x - other.x, this->y - other.y }; };
			vec2 operator*(const vec2& other) { return vec2{ this->x * other.x, this->y * other.y }; };
			vec2 operator/(const vec2& other) { return vec2{ this->x / other.x, this->y / other.y }; };

			vec2* operator+=(const vec2& other) { this->x += other.x; this->y += other.y; return this; };
			vec2* operator-=(const vec2& other) { this->x -= other.x; this->y -= other.y; return this; };
			vec2* operator*=(const vec2& other) { this->x *= other.x; this->y *= other.y; return this; };
			vec2* operator/=(const vec2& other) { this->x /= other.x; this->y /= other.y; return this; };
		};
	}
}