#pragma once

#include <string>

#include "GLEW/GL/glew.h"

namespace graphics {
	class Texture
	{
	public:
		Texture(unsigned char data, unsigned int w, unsigned int h);
		const GLuint getUID() const { return uid; }
		void bind() const;
	private:
		// for now useless
		std::string path; //IDEA: use this to do hot reloading?

		unsigned char data;
		unsigned int width, height;

		GLuint uid;
	};
}
