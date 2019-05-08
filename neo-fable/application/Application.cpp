#include "Application.hpp"



Application::Application(std::string name, SDL_WindowFlags flags) : window(name, flags)
{
}


Application::~Application()
{
}

void Application::pushLayer(application::Layer* layer)
{
	layerStack.push_back(layer);
	layer->onMount();
}

void Application::popLayer(application::Layer *layer)
{
	auto it = std::find(layerStack.begin(), layerStack.end(), layer);
	if (it != layerStack.end()) layerStack.erase(it);
}