#include "Texture.hpp"


namespace graphics {
	Texture::Texture(unsigned char data, unsigned int w, unsigned int h) 
		: data(data), width(w), height(h) 
	{
		
	}

	Texture::~Texture()
	{
	}
}
