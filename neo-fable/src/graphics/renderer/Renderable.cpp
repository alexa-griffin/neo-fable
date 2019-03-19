#include "Renderable.hpp"


namespace graphics {
	Renderable::Renderable()
	{
	}

	Renderable::Renderable(opengl::VertexArray va, unsigned int indices)
		: transforms(1.0f), vao(va), ibo(indices)
	{
	}

	Renderable::~Renderable()
	{
	}

	void Renderable::draw(opengl::Program program)
	{
		ibo.bind();
		vao.bind();

		program.setUniform("translation", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(transforms));
		if (config.textured)
		{
			texture.bind();
			program.setUniform("img", glUniform1i, texture.getBoundSlot());
		}
		glDrawElements(GL_TRIANGLES, ibo.getLength(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderable::addTexture(std::string path)
	{
		float texCoords[] = {
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f
		};

		opengl::Buffer texBuffer(texCoords, 8, 2);
		vao.addBuffer(texBuffer, I_TEX_COORD_LOCATION);

		//TODO: have this go through a central pipeline
		texture = opengl::Texture(path);
		config.textured = true;
	}

	void Renderable::setFill(glm::vec3 color)
	{
		setFill(color, color, color, color);
	}

	void Renderable::setFill(glm::vec3 bl, glm::vec3 tl, glm::vec3 tr, glm::vec3 br)
	{
		float colors[] = {
			bl.r, bl.g, bl.b,
			tl.r, tl.g, tl.b,
			tr.r, tr.g, tr.b,
			br.r, br.g, br.b,
		};

		if (!config.tinted)
		{
			opengl::Buffer colorBuffer(colors, 12, 3);
			config.tinted = true;
			vao.addBuffer(colorBuffer, I_COLOR_LOCATION);
		}
		else 
		{
			vao.modBuffer(I_COLOR_LOCATION, colors);
		}
	}

	// transform methods
	void Renderable::translate(glm::vec3 m)
		{ transforms = glm::translate(transforms, m); }
	void Renderable::scaleX(float m)
		{ transforms = glm::scale(transforms, glm::vec3(m, 0.0f, 0.0f)); }
	void Renderable::scaleY(float m)
		{ transforms = glm::scale(transforms, glm::vec3(0.0f, m, 0.0f)); }
	void Renderable::scaleZ(float m)
		{ transforms = glm::scale(transforms, glm::vec3(0.0f, 0.0f, m)); }

	//TODO: make this rotate around object origin
	void Renderable::rotateX(float m)
		{ transforms = glm::rotate(transforms, glm::radians(m), glm::vec3(1.0f, 0.0f, 0.0f)); }
	void Renderable::rotateY(float m)
		{ transforms = glm::rotate(transforms, glm::radians(m), glm::vec3(0.0f, 1.0f, 0.0f)); }
	void Renderable::rotateZ(float m)
		{ transforms = glm::rotate(transforms, glm::radians(m), glm::vec3(0.0f, 0.0f, 1.0f)); }
}
