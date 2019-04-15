#pragma once

#include <glm/glm.hpp>

#include "DynamicRenderable.hpp"
#include "../shaderLayout.hpp"

namespace graphics {
	class Rect : public DynamicRenderable {
	public:
		Rect(int width, int height, glm::vec2 off = glm::vec2(0, 0));
		Rect() {};
		~Rect();

		virtual unsigned int getVertexCount() { return 4; };
		virtual unsigned int getIndexCount() { return 6; };

		virtual VertexData getVertex(unsigned int index) { return vertices[index]; };

		virtual void setFill(glm::vec3 color);
		virtual void setFill(glm::vec3 bl, glm::vec3 tl, glm::vec3 tr, glm::vec3 br);

	private:
		int width, height;

		VertexData vertices[4];
	};
}