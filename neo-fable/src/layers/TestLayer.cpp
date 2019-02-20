#include "TestLayer.hpp"


namespace layers {
	using namespace ::application;
	using namespace ::events;

	TestLayer::~TestLayer()
	{
	}

	bool TestLayer::onEvent(Event &e)
	{
		std::cout << "test layer event!" << std::endl;

		return false;
	}

	void TestLayer::update()
	{
		// std::cout << "updating" << std::endl;
	}
}
