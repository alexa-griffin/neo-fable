#include "TestRenderer.hpp"



namespace layers {
	TestRenderer::TestRenderer(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win), box(100, 100),
		  prog("./data/shaders/default/tinted.vert.shader", "./data/shaders/default/tinted.frag.shader")
	{
		rctx.setProgram(&prog);
		box.setFill(RGB(0, 0, 255), RGB(0, 255, 0), RGB(0, 255, 255), RGB(255, 0, 255));
	};

	TestRenderer::~TestRenderer()
	{
	}

	void TestRenderer::update(unsigned int dT)
	{
		rctx.submit(box);
		rctx.draw();
	}

	bool TestRenderer::onEvent(const events::Event &event)
	{
		ON_WINDOW_RESIZE({
			rctx.resizeOrthoProj(e.getWidth(), e.getHeight());
		});

		return false;
	}

	void TestRenderer::onMount()
	{
		rctx.resizeOrthoProj(window->getWidth(), window->getHeight());
		// rctx.loadDefaultPrograms();
	}
}
