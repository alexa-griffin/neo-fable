#pragma once
#include "../application/Layer.hpp"

namespace layers {
	using namespace ::application;

	class TestLayer : public Layer
	{
	public:
		TestLayer(std::string name) : Layer(name) {};
		~TestLayer();
	};
}

