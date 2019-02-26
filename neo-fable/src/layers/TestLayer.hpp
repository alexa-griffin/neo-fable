#pragma once
#include "../application/Layer.hpp"
#include "../graphics/graphics.hpp"
#include "../graphics/graphics.hpp"
#include "../data_loader/util.hpp"

#include "../graphics/opengl.hpp"

namespace layers {
	using namespace ::application;
	using namespace ::events;

	class TestLayer : public Layer
	{
	public:
		TestLayer(std::string name);
		~TestLayer();

		virtual bool onEvent(Event& e);
		virtual void update();
		virtual void onMount();
	private:
		opengl::VertexBuffer vbo;
		opengl::IndexBuffer ibo;

		opengl::Shader vertShader;
		opengl::Shader fragShader;

		opengl::Program program;

		float h;
		float inc;
		int colorLocal;
	};
}

