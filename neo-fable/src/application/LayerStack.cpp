#include "LayerStack.hpp"


namespace application {
	LayerStack::LayerStack() {}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : layers) 
			delete layer;
	}

	void LayerStack::push(Layer* layer)
	{
		layers.insert(layers.begin(), layer);
	}

	void LayerStack::pop(Layer* layer)
	{
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end())
			layers.erase(it);
	}
}
