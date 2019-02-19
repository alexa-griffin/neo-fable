#include "TestLayer.hpp"


namespace layers {
	using namespace ::application;
	using namespace ::events;

	TestLayer::~TestLayer()
	{
	}

	void TestLayer::onEvent(Event &e)
	{
		std::cout << "test layer event!" << std::endl;
		e.debugPrint();
	}

	void TestLayer::update()
	{
		std::cout << "updating" << std::endl;
	}
}
