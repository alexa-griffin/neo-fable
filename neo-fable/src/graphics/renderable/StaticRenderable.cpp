#include "StaticRenderable.hpp"


namespace graphics {
	StaticRenderable::StaticRenderable()
	{
	}

	StaticRenderable::StaticRenderable(opengl::VertexArray va, GLuint *data, GLuint count)
		: transforms(1.0f), vao(va), ibo(data, count)
	{
	}

	StaticRenderable::~StaticRenderable()
	{
	}

	void StaticRenderable::bindIBO()
	{
		ibo.bind();
	}

	void StaticRenderable::bindVAO() 
	{
		vao.bind();
	}

	void StaticRenderable::setUniforms(opengl::Program program) 
	{
		program.setUniform("translation", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(transforms));

		if (config.textured)
		{
			texture.bind();
			program.setUniform("img", glUniform1i, texture.getBoundSlot());
		}
	}


	void StaticRenderable::addTexture(std::string path)
	{
		float texCoords[] = {
			0.0f, 0.0f,
			0.0f, 1.0f,
			1.0f, 1.0f,
			1.0f, 0.0f
		};

		opengl::Buffer texBuffer(texCoords, 8, 2);
		vao.addBuffer(texBuffer, I_TEX_COORD_LOCATION);

		//TODO: have texture loading go through a central pipeline
		texture = opengl::Texture(path);
		config.textured = true;
	}

	void StaticRenderable::setFill(glm::vec3 color)
	{
		setFill(color, color, color, color);
	}

	void StaticRenderable::setFill(glm::vec3 bl, glm::vec3 tl, glm::vec3 tr, glm::vec3 br)
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
			vao.modBuffer(I_COLOR_LOCATION, colors, 12 * sizeof(float));
		}
	}

	// transform methods
	void StaticRenderable::translate(glm::vec3 m)
		{ transforms = glm::translate(transforms, m); }
	void StaticRenderable::scaleX(float m)
		{ transforms = glm::scale(transforms, glm::vec3(m, 0.0f, 0.0f)); }
	void StaticRenderable::scaleY(float m)
		{ transforms = glm::scale(transforms, glm::vec3(0.0f, m, 0.0f)); }
	void StaticRenderable::scaleZ(float m)
		{ transforms = glm::scale(transforms, glm::vec3(0.0f, 0.0f, m)); }
	void StaticRenderable::resetTransforms()
		{ transforms = glm::mat4(1.0f); }

	//TODO: make this rotate around object origin
	void StaticRenderable::rotateX(float m)
		{ transforms = glm::rotate(transforms, glm::radians(m), glm::vec3(1.0f, 0.0f, 0.0f)); }
	void StaticRenderable::rotateY(float m)
		{ transforms = glm::rotate(transforms, glm::radians(m), glm::vec3(0.0f, 1.0f, 0.0f)); }
	void StaticRenderable::rotateZ(float m)
		{ transforms = glm::rotate(transforms, glm::radians(m), glm::vec3(0.0f, 0.0f, 1.0f)); }
}
