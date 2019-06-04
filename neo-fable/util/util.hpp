#pragma once

#include "json.hpp"

namespace util {
	// rename for convenience
	using Json = nlohmann::json;

	struct Color {
		int r, g, b, a;
	};
}

#define RGB(r, g, b) (r), (g), (b), (255)
#define RGBA(r, g, b, a) (r), (g), (b), (a * 255)

#define UNIT 32