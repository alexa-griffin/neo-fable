#include "TestStatic.hpp"



namespace layers {
	TestStatic::TestStatic(std::string name, std::shared_ptr<application::Window> win)
		: Layer(name, win), box(100, 100)
	{
		box.setFill(RGB(0, 0, 255), RGB(0, 255, 0), RGB(0, 255, 255), RGB(255, 0, 255));
	};

	TestStatic::~TestStatic()
	{
	}

	void TestStatic::update(unsigned int dT)
	{
		rctx.submit(box);
		rctx.drawQue();
	}

	bool TestStatic::onEvent(const events::Event &event)
	{
		ON_WINDOW_RESIZE({
			rctx.resizeOrthoProj(e.getWidth(), e.getHeight());
		});
		
		ON_MOUSE_MOVE({
			box.setFill(RGB(e.getX(), 0, 255), RGB(e.getX(), 255, 0), RGB(e.getX(), 255, 255), RGB(255, e.getX(), 255));
		});

		return false;
	}

	void TestStatic::onMount()
	{
		rctx.resizeOrthoProj(window->getWidth(), window->getHeight());
		rctx.loadDefaultPrograms();
	}
}
