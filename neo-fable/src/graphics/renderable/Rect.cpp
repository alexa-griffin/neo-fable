#include "rect.hpp"

namespace graphics {
	Rect::Rect(int w, int h) : width(w), height(h) 
	{
		vertices[0].pos = glm::vec2(0.0f,  0.0f);
		vertices[1].pos = glm::vec2(0.0f,  height);
		vertices[2].pos = glm::vec2(width, height);
		vertices[3].pos = glm::vec2(width, 0.0f);
	}
	
	Rect::~Rect() {}

	void Rect::setFill(glm::vec3 color)
	{
		setFill(color, color, color, color);
	}

	void Rect::setFill(glm::vec3 bl, glm::vec3 tl, glm::vec3 tr, glm::vec3 br)
	{
		vertices[0].color = bl;
		vertices[1].color = tl;
		vertices[2].color = br;
		vertices[3].color = tr;
	}
}