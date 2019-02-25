#pragma once

#include <GLEW/GL/glew.h>
#include <iostream>

#include "application/log.hpp"

#ifdef __PRODUCTION_BUILD__
	#define GL_ASSERT(f) (f)
	#define GL_DEBUG_CALL(f) (f)
#else
	#define GL_ASSERT(f) if(!(f)) __debugbreak()
	#define GL_DEBUG_CALL(f) ::graphics::glClearErrors(); \
							 GL_ASSERT(f); \
							 GL_ASSERT(::graphics::glLogErrors(#f, __FILE__, __LINE__))
#endif

namespace graphics {
	void glClearErrors();
	void glLogErrors(const char* f, const char* file, int line);
	void glShaderLogErrors(GLuint shader);
	void glProgramLogErrors(GLuint program);
}