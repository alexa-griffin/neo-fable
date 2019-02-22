#include "debug.hpp"

namespace graphics {
	void glClearErrors()
	{
		while (glGetError() != GL_NO_ERROR);
	}

	bool glLogErrors(const char* f, const char* file, int line)
	{
		while (GLenum err = glGetError())
		{
			return false;
			std::cout << "[openGL error]: (" << err << ")" << f << ", " << file << ":" << line << std::endl;
		}
		return true;
	}
}