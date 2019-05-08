#include "TestLayer.hpp"


namespace layers {
	int TestLayer::num = 0;

	TestLayer::TestLayer() : application::Layer("Test Layer" + num)
	{
		num++;
	}


	TestLayer::~TestLayer()
	{
	}

	TestLayer::onUpdate()
	{
		std::cout << debugName << std::endl;
	}
}
