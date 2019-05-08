#pragma once
#include "../application/Layer.hpp"

#include <iostream>

namespace layers {
	class TestLayer : public application::Layer
	{
	public:
		TestLayer();
		~TestLayer();

		virtual void onUpdate();

	private:
		static int num;
	};
}

