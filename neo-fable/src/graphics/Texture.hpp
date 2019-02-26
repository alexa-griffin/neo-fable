#pragma once

#include <string>

namespace graphics {
	class Texture
	{
	public:
		Texture(unsigned char data, unsigned int w, unsigned int h);
		~Texture();
	private:
		std::string path;

		unsigned char data;
		unsigned int width, height;

	};
}
