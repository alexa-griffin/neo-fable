#include "Application.hpp"

#include "Layer.hpp"


Application::Application(std::string name, SDL_WindowFlags flags) 
	: window(name, flags), running(true)
{
	renderer = SDL_CreateRenderer(window.getSDL(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}


Application::~Application()
{
}

void Application::pushLayer(application::Layer* layer)
{
	layer->applyApplication(this);
	layerStack.push_back(layer);
	layer->__onMount();
	layer->onMount();
}

void Application::popLayer(application::Layer *layer)
{
	auto it = std::find(layerStack.begin(), layerStack.end(), layer);
	if (it != layerStack.end()) layerStack.erase(it);
}

void Application::update()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	pollEvents();
	for (application::Layer* layer : layerStack)
	{
		layer->onUpdate(0);
		//TODO: make delta time work
	}
	SDL_RenderPresent(renderer);
}

void Application::pollEvents()
{
	while (SDL_PollEvent(&ev) != 0)
	{
		if (ev.type == SDL_QUIT) running = false;
		for (application::Layer* layer : layerStack)
		{
			if(layer->onEvent(&ev)) break;
		}
	}
}

void Application::destroy()
{
	SDL_DestroyWindow(window.getSDL());
	SDL_Quit();
}

namespace application {
	void init() 
	{
		SDL_Init(SDL_INIT_EVERYTHING);
	}
}