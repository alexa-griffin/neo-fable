#pragma once

#include "../application/Window.hpp"
#include "../application/Layer.hpp"
#include "../graphics/graphics.hpp"
#include "../data_loader/util.hpp"

#include "../graphics/opengl.hpp"
#include "../graphics/graphics.hpp"
#include "../graphics/shaderLayout.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace layers {
	class TestLayer : public application::Layer
	{
	public:
		TestLayer(std::string name, std::shared_ptr<application::Window> win);
		~TestLayer();

		bool onEvent (const events::Event &e) override;
		virtual void update();
		virtual void onMount();
	private:

		opengl::Texture texture;

		opengl::Program program;

		GLuint tileTexture;

		graphics::Rect box;
	};
}

