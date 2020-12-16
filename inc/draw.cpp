#include "Game.h"

void Game::draw () {
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);

    SDL_Rect r;
	SDL_Point p = this->player.getPosition();
	int32_t w = this->player.getWidth();
	int32_t h = this->player.getHeight();
	r.x = p.x;
	r.y = p.y;
	r.w = w;
	r.h = h;
	
	SDL_RenderFillRect(this->renderer, &r);
}