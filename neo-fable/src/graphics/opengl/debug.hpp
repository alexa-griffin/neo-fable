#pragma once

#include <GLEW/GL/glew.h>
#include <iostream>

#include "application/log.hpp"

#ifdef __PRODUCTION_BUILD__
	#define GL_ASSERT(f) (f)
	#define GL_DEBUG_CALL(f) (f)
#else
	#define GL_ASSERT(e) if(!(e)) __debugbreak()
	#define GL_DEBUG_CALL(f) ::opengl::clearErrors(); \
							 f; \
							 GL_ASSERT(::opengl::logErrors(#f, __FILE__, __LINE__))
#endif

namespace opengl {
	void clearErrors();
	bool logErrors(const char* f, const char* file, int line);
	bool shaderLogErrors(GLuint shader);
	bool programLogErrors(GLuint program);
}