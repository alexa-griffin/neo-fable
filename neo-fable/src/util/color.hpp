#pragma once

//TODO: figure out why 128 looks way better than 255
#define RGB(r, g, b)	 glm::vec3((r) / 128.0f, (g) / 128.0f, (b) / 128.0f)
#define RGBA(r, g, b, a) glm::vec4((r) / 128.0f, (g) / 128.0f, (b) / 128.0f, a)