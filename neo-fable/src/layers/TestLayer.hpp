#pragma once
#include "../application/Layer.hpp"
#include "../graphics/graphics.hpp"
#include "../data_loader/util.hpp"

#include "../graphics/opengl.hpp"

#include "glm/glm.hpp"

namespace layers {
	class TestLayer : public application::Layer
	{
	public:
		TestLayer(std::string name);
		~TestLayer();

		virtual bool onEvent(events::Event& e);
		virtual void update();
		virtual void onMount();
	private:
		opengl::VertexBuffer vbo;
		opengl::IndexBuffer ibo;

		opengl::Texture texture;

		opengl::Shader vertShader;
		opengl::Shader fragShader;

		opengl::Program program;

		GLuint tileTexture;

		float r;
		float incR;
		float g;
		float incG;
		float b;
		float incB;
	};
}

