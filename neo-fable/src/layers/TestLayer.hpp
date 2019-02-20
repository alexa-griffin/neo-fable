#pragma once
#include "../application/Layer.hpp"

namespace layers {
	using namespace ::application;
	using namespace ::events;

	class TestLayer : public Layer
	{
	public:
		TestLayer(std::string name) : Layer(name) {};
		~TestLayer();

		virtual bool onEvent(Event& e);
		virtual void update();

	};
}

