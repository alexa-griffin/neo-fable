#pragma once
#include "../application/Layer.hpp"
#include "../graphics/graphics.hpp"
#include "../data_loader/util.hpp"

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
		GLuint buffer;
	};
}

