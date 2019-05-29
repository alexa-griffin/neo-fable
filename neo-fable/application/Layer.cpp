#include "Layer.hpp"


namespace application {
	Layer::~Layer()
	{
	}

	void Layer::applyApplication(SDL_Renderer* ren)
	{
		renderer = ren;
	}
}
