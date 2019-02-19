#include "LayerStack.hpp"


namespace application {
	LayerStack::LayerStack() {}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : layers) 
		{
			delete layer;
		}
	}

	void LayerStack::push(Layer* layer)
	{
		layers.insert(myvector.begin(), layer)
	}

	void LayerStack::pop(Layer* layer)
	{
		auto it = std::find(layer.begin(), layer.end(), layer);
		if (it != layers.end())
		{
			layers.erase(it);
		}
	}
}
