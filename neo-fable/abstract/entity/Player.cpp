#include "Player.hpp"


namespace entity {
	Player::Player() : Entity({ 0, 0 }, { UNIT, UNIT })
	{
	}


	Player::~Player()
	{
	}

	void Player::update()
	{

	}

	void Player::draw(abstract::Camera* cam)
	{
		graphics::direct([=](SDL_Renderer* renderer) {
			SDL_SetRenderDrawColor(renderer, RGB(255, 0, 255));

			SDL_RenderFillRect(renderer, new SDL_Rect{
				(int)(pos.x - cam->pos.x) + (int)(cam->viewport * UNIT),
				(int)(pos.y - cam->pos.y) + (int)(cam->viewport * UNIT),
				(int)size.w,
				(int)size.h
			});
		});
	}
}
