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
	class TestRenderer : public application::Layer
	{
	public:
		TestRenderer(std::string name, std::shared_ptr<application::Window> win);
		~TestRenderer();

		bool onEvent(const events::Event &e) override;
		virtual void update(unsigned int dT);
		virtual void onMount();
	private:
		opengl::Program prog;
		graphics::Rect box;

		graphics::BatchRenderer rctx;
	};
}

