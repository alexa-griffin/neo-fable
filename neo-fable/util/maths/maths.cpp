#include "maths.hpp"

namespace util {
	namespace maths {
		int sgn(float x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }

		// remap a number x from one range to another
		float remap(float x, float fi, float fa, float ti, float ta)
		{
			return ti + (ta - ti) / (fa - fi) * (x - fi);
		}
	}
}