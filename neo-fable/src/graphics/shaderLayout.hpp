#pragma once

#include <glm/glm.hpp>

// stores the various locations of glsl shader inputs 
// these are expected to be constant throughout all glsl shaders

#define I_POS_LOCATION 0       // vec2  
#define I_COLOR_LOCATION 1     // vec3
#define I_TEX_COORD_LOCATION 2 // vec2

namespace graphics {
	struct VertexData
	{
		glm::vec2 pos;
		glm::vec3 color;
		// glm::vec3 textureCoord;
	};
}