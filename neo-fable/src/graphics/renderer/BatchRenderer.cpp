#include "BatchRenderer.hpp"

namespace graphics {
	BatchRenderer::BatchRenderer() 
		: ibo(nullptr, MAX_INDICES), numVertices(0), 
		  colorBuffer(nullptr, MAX_VERTICES * 3, 3), 
		  posBuffer(nullptr, MAX_VERTICES * 2, 2)
	{
		vao.addBuffer(colorBuffer, I_COLOR_LOCATION);
		vao.addBuffer(posBuffer, I_POS_LOCATION);
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
		numVertices += obj.getVertexCount();
		numIndices += (obj.getVertexCount() - 2) * 3;
		quedRenderables.push_back(&obj);
	}

	void BatchRenderer::draw()
	{
		activeProgram->use();
		activeProgram->setUniform("proj", glUniformMatrix4fv, 1, GL_FALSE, glm::value_ptr(orthoProj));

		float posData[MAX_VERTICES * 2] = {};
		float colorData[MAX_VERTICES * 3] = {};
		GLuint indexData[MAX_INDICES] = {};
		
		int iOff = 0;
		int vOff = 0;
		int rOff = 0;
		for (int i = 0; i < quedRenderables.size(); i++)
		{
			int localOff = 0;
			unsigned int len = quedRenderables[i]->getVertexCount();
			for (int j = 0; j < len; j++)
			{
				if (j < len - 2)
				{
					indexData[iOff] = rOff;
					indexData[iOff + 1] = rOff + localOff + 1;
					indexData[iOff + 2] = rOff + localOff + 2;

					iOff += 3;
					localOff++;
				}

				VertexData vertex = quedRenderables[i]->getVertex(j);

				posData[(vOff * 2) + 0] = vertex.pos.x;
				posData[(vOff * 2) + 1] = vertex.pos.y;

				colorData[(vOff * 3) + 0] = vertex.color.r;
				colorData[(vOff * 3) + 1] = vertex.color.g;
				colorData[(vOff * 3) + 2] = vertex.color.b;

				vOff++;
			}
			rOff += quedRenderables[i]->getVertexCount();
		}

		ibo.setData(indexData, MAX_INDICES);

		vao.modBuffer(I_POS_LOCATION, posData, MAX_VERTICES * 2 * sizeof(float));
		vao.modBuffer(I_COLOR_LOCATION, colorData, MAX_VERTICES * 3 * sizeof(float));

		vao.bind();
		ibo.bind();

		// GL_DEBUG_CALL(glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_INT, nullptr));

		GL_DEBUG_CALL(glDrawRangeElements(GL_TRIANGLES, 0, numIndices, ibo.getCount(), GL_UNSIGNED_INT, nullptr));

		for (int i = 0; i < quedRenderables.size(); i++)
		{
			// delete quedRenderables[i];
			quedRenderables.erase(quedRenderables.begin() + i);
		}

		numIndices = 0;
		numVertices = 0;
	}
}
