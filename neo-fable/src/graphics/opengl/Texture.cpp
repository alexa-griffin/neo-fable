#include "Texture.hpp"

namespace opengl {
	Texture::Texture(unsigned char *data, unsigned int w, unsigned int h) 
		: buffer(data), width(w), height(h) 
	{
		glGenTextures(1, &uid);
		bind();
		configure();
	}

	Texture::Texture(std::string path) : path(path)
	{
		stbi_set_flip_vertically_on_load(1);
		auto img = data_loader::loadImage(path);
		width = img.width;
		height = img.height;
		bpp = 0;
		buffer = img.data;
		glGenTextures(1, &uid);
		bind();
		configure();

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
	}

	void Texture::bind(unsigned int slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, uid);
	}

	void Texture::unbind() const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void Texture::configure()
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	}
}
