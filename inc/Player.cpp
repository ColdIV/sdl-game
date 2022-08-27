#include "Player.h"

int32_t Player::getSpeed () {
    return this->speed;
}

void Player::setSpeed (int32_t speed) {
    this->speed = speed;
}

void Player::move (int32_t x, int32_t y) {
    SDL_Point tPos = this->getPosition();
    this->setPosition(tPos.x + x, tPos.y + y);
}

// You are supposed to call this with 1 or 0s only
// But you can of course move by multiples...
void Player::move (int32_t w, int32_t a, int32_t s, int32_t d) {
    // reverse direction
    w *= -1; a *= -1;

    SDL_Point tPos = this->getPosition();

    int32_t x = tPos.x + this->speed * a + this->speed * d;
    int32_t y = tPos.y + this->speed * w + this->speed * s;
    
    this->setPosition(x, y);
}

// Overrides
void Player::draw (SDL_Renderer *renderer, SDL_Point gVPosition, int32_t gVWidth, int32_t gVHeight) {
    int32_t w, h;
	SDL_Point p;

    SDL_Rect Object_r;
	p = this->getPosition();
	w = this->getWidth();
	h = this->getHeight();

    // Translate coordinates according to gameViev
    p.x -= gVPosition.x;
    p.y -= gVPosition.y;

	Object_r.x = p.x;
	Object_r.y = p.y;
	Object_r.w = w;
	Object_r.h = h;

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &Object_r);
}