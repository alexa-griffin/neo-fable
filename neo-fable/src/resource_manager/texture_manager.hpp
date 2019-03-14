#pragma once

#include <map>
#include <string>

#include "stb_image/stb_image.h"

#include "graphics/opengl/Texture.hpp"


namespace resources {
	namespace textures {
		std::map<unsigned int, opengl::Texture> allTextures;
		opengl::Texture load(std::string path);
	}
}

