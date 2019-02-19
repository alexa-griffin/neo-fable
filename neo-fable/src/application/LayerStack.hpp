#pragma once
#include <vector>
#include <algorithm>

#include "Layer.hpp"

namespace application {
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void push(Layer* layer);
		void pop(Layer* layer);

		std::vector<Layer*>::iterator begin() { return layers.begin(); }
		std::vector<Layer*>::iterator end() { return layers.end(); }

	private:
		std::vector<Layer*> layers;
	};
}
