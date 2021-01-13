#include "Game.h"

void Game::draw () {
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
	SDL_RenderClear(this->renderer);

	int32_t w, h;
	SDL_Point p;	
	
	SDL_Rect world_r;
	p = { 0, 0};
	w = this->world.getWidth();
	h = this->world.getHeight();
	world_r.x = p.x;
	world_r.y = p.y;
	world_r.w = w;
	world_r.h = h;

	// Draw World Border
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 0, 255);
	SDL_RenderDrawRect(this->renderer, &world_r);

	this->world.draw(this->renderer);
}