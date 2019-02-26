#pragma once

#include <map>
#include <string>

#include "stb_image/stb_image.h"

#include "graphics/Texture.hpp"


namespace resources {
	namespace textures {
		std::map<unsigned int, graphics::Texture> allTextures;
		graphics::Texture load(std::string path);
		
	}
}

