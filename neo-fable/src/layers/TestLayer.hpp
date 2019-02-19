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

		void onEvent(Event& e);
		virtual void update();

	};
}

