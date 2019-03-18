#pragma once

#include <string>

#include "GLEW/GL/glew.h"

#include "data_loader/util.hpp"
#include "debug.hpp" 

namespace opengl {
	class Texture
	{
	public:
		Texture() {};
		Texture(std::string path);
		const GLuint getUID() const { return uid; }
		void bind(unsigned int slot = 0);
		void unbind() const;

		void configure(); //TODO: make this take params

		inline int getWidth() const { return width; }
		inline int getHeight() const { return height; }
		inline GLint getBoundSlot() const { return boundSlot; }
	private:
		// for now useless
		std::string path; //IDEA: use this to do hot reloading?

		unsigned char *buffer;
		int width, height, bpp;

		GLuint uid;
		unsigned int boundSlot;
	};
}
