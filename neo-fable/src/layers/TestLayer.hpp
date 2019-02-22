#pragma once
#include "../application/Layer.hpp"
#include "../graphics/graphics.hpp"


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
		virtual void render();
		virtual void onMount();

	private:
		unsigned int bufferID;
	};
}

