#pragma once

#include "json.hpp"

// rename for convenience
namespace util {
	using Json = nlohmann::json;
}

#define RGB(r, g, b) (r), (g), (b), (255)
#define RGBA(r, g, b, a) (r), (g), (b), (a * 255)

#define UNIT 32