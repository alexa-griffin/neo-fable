#include "texture_manager.hpp"

namespace resources {
	namespace textures {
		graphics::Texture load(std::string path)
		{
			int w, h, n;
			unsigned char* rawData = stbi_load(path.c_str(), &w, &h, &n, 0);

			return graphics::Texture(*rawData, w, h);
		}
	}
}