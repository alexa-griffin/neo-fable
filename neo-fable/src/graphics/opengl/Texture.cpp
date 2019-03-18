#include "Texture.hpp"

namespace opengl {
	Texture::Texture(std::string path) : path(path), boundSlot(0)
	{
		stbi_set_flip_vertically_on_load(1);
		auto img = data_loader::loadImage(path);
		width = img.width;
		height = img.height;
		bpp = 0;
		buffer = img.data;
		glGenTextures(1, &uid);
		bind();
		GL_DEBUG_CALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer));
		// GL_DEBUG_CALL(glGenerateMipmap(GL_TEXTURE_2D));
		configure();
		unbind();
	}

	void Texture::bind(unsigned int slot)
	{
		boundSlot = slot;
		GL_DEBUG_CALL(glActiveTexture(GL_TEXTURE0 + slot));
		GL_DEBUG_CALL(glBindTexture(GL_TEXTURE_2D, uid));
	}

	void Texture::unbind() const
	{
		GL_DEBUG_CALL(glBindTexture(GL_TEXTURE_2D, 0));
	}

	void Texture::configure()
	{
		bind();
		//TODO: make these actually configurable
		GL_DEBUG_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		GL_DEBUG_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
		GL_DEBUG_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		GL_DEBUG_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		unbind();
	}
}
