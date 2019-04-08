#include "StaticRenderer.hpp"
#include "../renderable/StaticRenderable.hpp"


namespace graphics {
	StaticRenderer::~StaticRenderer()
	{
	}

	defaultProgram StaticRenderer::getDefaultProgram(StaticRenderable &obj) {
		if (obj.config.textured && obj.config.tinted)
			return defaultProgram::tintedTextured;
		
		else if (obj.config.tinted)
			return defaultProgram::tinted;

		else if (obj.config.textured)
			return defaultProgram::textured;
		
		else LOG_ERROR("obj does not have a valid default program");

		return defaultProgram::none;
	}

	void StaticRenderer::draw(StaticRenderable &obj, opengl::Program program)
	{
		program.use();

		// set ortho projection for renderable shader
		// all renderable shaders are assumed to have a mat4 uniform "proj"
		//TODO: figure out if there is a way to warn if the uniform does not exist
		program.setUniform("proj", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(orthoProj));
		
		obj.setUniforms(program);
		obj.bindVAO();
		obj.bindIBO();

		GL_DEBUG_CALL(glDrawElements(GL_TRIANGLES, obj.getIboCount(), GL_UNSIGNED_INT, nullptr));
	}

	void StaticRenderer::drawQue()
	{
		for (int i = 0; i < quedRenderables.size(); i++)
		{
			draw(*(quedRenderables[i]->target), *(quedRenderables[i]->program));
			delete quedRenderables[i];
			quedRenderables.erase(quedRenderables.begin() + i);
		}
	}

	void StaticRenderer::submit(StaticRenderable &obj, opengl::Program &program)
	{
		StaticRenderTarget *t = new StaticRenderTarget;
		t->program = &program;
		t->target = &obj;
		quedRenderables.push_back(t);
		//TODO: some kind of buffer combination
	}

	void StaticRenderer::submit(StaticRenderable &obj)
	{
		StaticRenderTarget *t = new StaticRenderTarget;
		t->target = &obj;

		t->program = defaultPrograms[getDefaultProgram(obj)];
		
		quedRenderables.push_back(t);
	}
}
