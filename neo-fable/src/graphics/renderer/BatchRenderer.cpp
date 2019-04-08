#include "BatchRenderer.hpp"

namespace graphics {
	BatchRenderer::BatchRenderer() 
		: vao()
	{

	}

	BatchRenderer::~BatchRenderer()
	{
	}

	void BatchRenderer::setProgram(opengl::Program *p)
	{
		activeProgram = p;
	}

	void BatchRenderer::submit(DynamicRenderable &obj)
	{
		quedRenderables.push_back(&obj);
	}

	void BatchRenderer::draw()
	{
		std::vector<float> posData;
		std::vector<float> colorData;
		
		std::vector<GLuint> indices;

		unsigned int offset = 0;

		for (int i = 0; i < quedRenderables.size(); i++)
		{
			posData.insert(posData.end(), quedRenderables[i]->getPosData().begin(), quedRenderables[i]->getPosData().end());

			for (int j = 0; j < quedRenderables[i]->getIndicesCount(); j++)
			{
				indices[j] = offset + j;
			}

			offset += quedRenderables[i]->getIndices();
		}

		opengl::Buffer posBuffer(&posData[0],     sizeof(float) * 2 * MAX_VERTICES, 2);
		opengl::Buffer colorBuffer(&colorData[0], sizeof(float) * 3 * MAX_VERTICES, 3);

		activeProgram->use();
		
		vao.addBuffer(posBuffer, I_POS_LOCATION);
		vao.addBuffer(colorBuffer, I_COLOR_LOCATION);

		ibo.bind();
		vao.bind();

		GL_DEBUG_CALL(glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, nullptr));

		for (int i = 0; i < quedRenderables.size(); i++)
		{
			delete quedRenderables[i];
			quedRenderables.erase(quedRenderables.begin() + i);
		}
	}
}