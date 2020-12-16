#include "Game.h"

void Game::draw () {
    SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);

    SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 150;
	r.h = 200;
	
	SDL_RenderFillRect(this->renderer, &r);
}