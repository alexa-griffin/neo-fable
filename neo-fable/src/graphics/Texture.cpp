#include "Texture.hpp"

namespace graphics {
	Texture::Texture(unsigned char data, unsigned int w, unsigned int h) 
		: data(data), width(w), height(h) {}

	void Texture::bind() const
	{
		glBindTexture(GL_TEXTURE_2D, uid);
	}
}
