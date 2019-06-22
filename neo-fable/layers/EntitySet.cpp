#include "EntitySet.hpp"


namespace layers {
	EntitySet::EntitySet() : Layer("entity set")
	{
		push(new entity::StaticObject({ 0, 0 }, { RGB(255, 255, 255) }));
		push(new entity::StaticObject({ 50, 50 }, { RGB(0, 255, 0) }));
		push(new entity::StaticObject({ 50, 100 }, { RGB(255, 0, 0) }));
		push(new entity::StaticObject({ 200, 50 }, { RGB(255, 0, 255) }));
		push(new entity::StaticObject({ 50, 150 }, { RGB(255, 255, 0) }));
		push(new entity::StaticObject({ 50, 200 }, { RGB(255, 0, 255) }));
	}

	EntitySet::~EntitySet()
	{
	}

	void EntitySet::configRenderTransform()
	{
		if (ready)
		{
			renderView = viewport::getMapViewport(window, state->camera);
		}
		else std::cout << "attempting to render transform an unmounted layer" << std::endl;
	}

	// void EntitySet::onMount()
	// {
	// 
	// }

	void EntitySet::onUpdate(unsigned int dT)
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
		SDL_RenderFillRect(renderer, new SDL_Rect({ 0, 0, 100, 100 }));
		
		// for (abstract::Entity* entity : entities)
		// {
		// 	entity->draw(state->camera);
		// }
	}

	bool EntitySet::onEvent(SDL_Event* e)
	{
		if (e->type == SDL_WINDOWEVENT && e->window.event == SDL_WINDOWEVENT_RESIZED)
		{
			renderView = viewport::getMapViewport(window, state->camera);
		}
		return false;
	}
}
