#include "Player.hpp"


namespace entity {
	Player::Player() : 
		Entity({ 0, 0 }, { UNIT, UNIT }), 
		rendered(new SDL_Rect{ 0, 0, UNIT, UNIT })
	{
	}


	Player::~Player()
	{
		delete rendered;
	}

	void Player::update()
	{

	}

	void Player::draw(abstract::Camera* cam)
	{
		graphics::direct([=](SDL_Renderer* renderer) {
			SDL_SetRenderDrawColor(renderer, RGB(255, 0, 255));

			rendered->x = (int)(pos.x - cam->pos.x) + (cam->viewport * UNIT);
			rendered->y = (int)(pos.y - cam->pos.y) + (cam->viewport * UNIT);

			SDL_RenderFillRect(renderer, rendered);
		});
	}
}
