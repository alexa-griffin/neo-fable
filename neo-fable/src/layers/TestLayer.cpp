#include "TestLayer.hpp"


namespace layers {
	using namespace ::application;
	using namespace ::events;

	TestLayer::TestLayer(std::string name) : Layer(name) 
	{
		glGenBuffers(1, &bufferID);
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);

		float pos[] = {
			 0.0f,  0.5f,
			-0.5f, -0.5f,
			-0.5f,  0.5f
		};

		glBufferData(bufferID, 6 * sizeof(float), pos, GL_STATIC_DRAW);
	};

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
		render();
	}

	void TestLayer::render()
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void TestLayer::onMount()
	{

	}
}
