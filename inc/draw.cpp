#include "Game.h"

void Game::draw () {
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->renderer);

	this->world.draw(this->renderer);
}