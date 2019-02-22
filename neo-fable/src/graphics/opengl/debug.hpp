#pragma once

#include <GLEW/GL/glew.h>
#include <iostream>


#ifdef __PRODUCTION_BUILD__
	#define GL_ASSERT(f) (f)
	#define GL_DEBUG_CALL(f) (f)
#else
	#define GL_ASSERT(f) if(!(f)) __debugbreak()
	#define GL_DEBUG_CALL(f) ::graphics::glClearErrors(); \
							 (f); \
							 GL_ASSERT(::graphics::glLogErrors(#f, __FILE__, __LINE__))
#endif

namespace graphics {
	void glClearErrors();
	bool glLogErrors(const char* f, const char* file, int line);
}